#include "stdafx.h"
#include "RefundAndAuditService.h"
#include "../../dao/payment_reviews/RefundAndAuditDAO.h"
#include "id/SnowFlake.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>

// 获取当前时间的辅助函数
std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

StringJsonVO::Wrapper RefundAndAuditService::applyRefund(const ApplyRefundDTO::Wrapper& dto)
{
    // 定义返回对象
    auto vo = StringJsonVO::createShared();

    // 参数校验
    if (!dto->fee_id || !dto->reason) {
        vo->code = 400;
        vo->message = "empty";
        vo->data = dto->fee_id;
        return vo;
    }

    // 封装DO数据
    ApplyRefundDO data;
    data.setFee_id(dto->fee_id);
    data.setReason(dto->reason);
    // 设置创建人信息
    data.setApply_person_id(dto->getPayload()->getId());
    data.setApply_person_name(dto->getPayload()->getUsername());
    // 设置创建时间
    data.setCreate_time(getCurrentTime());

    // 调用DAO层执行数据插入
    RefundAndAuditDAO dao;
    if (dao.insert(data) > 0) {
        vo->code = 10000;
        vo->message = "success";
        vo->data = dto->fee_id;
    }
    else {
        vo->code = 400;
        vo->message = "fail";
        vo->data = dto->fee_id;
    }
    return vo;
}

StringJsonVO::Wrapper RefundAndAuditService::auditFee(const AuditFeeDTO::Wrapper& dto)
{
    // 定义返回对象
    auto vo = StringJsonVO::createShared();

    // 参数校验
    if (!dto->audit_id || !dto->state) {
        vo->code = 400;
        vo->message = "empty";
        return vo;
        vo->data = dto->audit_id;
    }

    // 封装DO数据
    AuditFeeDO data;
    data.setState(dto->state);
    data.setMessage(dto->message);
    // 设置审核人信息
    data.setAudit_user_id(dto->getPayload()->getId());
    data.setAudit_user_name(dto->getPayload()->getUsername());
    // 设置审核时间
    data.setCreate_time(getCurrentTime());
    data.setStatus_cd("0");

    // 调用DAO层执行更新
    RefundAndAuditDAO dao;
    if (dao.auditPayment(data, dto->audit_id) > 0) {
        vo->code = 10000;
        vo->message = "success";
        vo->data = dto->audit_id;
    }
    else {
        vo->code = 400;
        vo->message = "fail";
        vo->data = dto->audit_id;
    }
    return vo;
}

StringJsonVO::Wrapper RefundAndAuditService::batchAudit(const BatchAuditDTO::Wrapper& dto)
{
    // 定义返回对象
    auto vo = StringJsonVO::createShared();

    // 参数校验
    if (!dto->record_ids || dto->record_ids->empty() || !dto->state) {
        vo->code = 400;
        vo->message = "empty";
        return vo;
    }

    // 创建DAO对象并开启事务
    RefundAndAuditDAO dao;
    dao.getSqlSession()->beginTransaction();

    try {
        // 生成批次ID
        SnowFlake sf(1, 1);
        string batchId = to_string(sf.nextId());

        // 获取第一个审核记录的费用信息用于批量记录
        string firstFeeId = dao.getFeeIdByAuditId(dto->record_ids->front()->c_str());
        auto paymentInfo = dao.getPaymentInfoByFeeId(firstFeeId);
        if (!paymentInfo) {
            throw "Failed to get payment info";
        }

        // 创建批量审核记录
        BatchAuditDO batchData;
        batchData.setBatch_id(batchId);
        batchData.setCommunity_id(paymentInfo->getCommunity_id());
        batchData.setCreate_user_id(dto->getPayload()->getId());
        batchData.setCreate_user_name(dto->getPayload()->getUsername());
        batchData.setCreate_time(getCurrentTime());
        batchData.setStatus_cd("0");
        batchData.setState(dto->state);
        batchData.setMsg(dto->msg);
        batchData.setRemark("批量审核");

        // 插入批量审核记录
        if (dao.insertBatchAudit(batchData) <= 0) {
            throw "Failed to insert batch audit";
        }

        // 更新每条审核记录
        AuditFeeDO auditData;
        auditData.setState(dto->state);
        auditData.setMessage(dto->msg);
        auditData.setAudit_user_id(dto->getPayload()->getId());
        auditData.setAudit_user_name(dto->getPayload()->getUsername());
        auditData.setCreate_time(getCurrentTime());
        auditData.setStatus_cd("0");

        // 处理每条记录
        for (auto one : *dto->record_ids.get())
        {
            // 更新审核记录
            if (dao.auditPayment(auditData, one->c_str()) <= 0) {
                throw "Failed to update audit record";
            }

            // 获取费用ID并更新批次ID
            string feeId = dao.getFeeIdByAuditId(one->c_str());
            if (dao.updatePayFeeBatchId(feeId, batchId) <= 0) {
                throw "Failed to update pay fee batch id";
            }
        }

        // 提交事务
        dao.getSqlSession()->commitTransaction();
        vo->code = 10000;
        vo->message = "success";
    }
    catch (const char* msg) {
        // 回滚事务
        dao.getSqlSession()->rollbackTransaction();
        vo->code = 400;
        vo->message = msg;
    }
    catch (...) {
        // 回滚事务
        dao.getSqlSession()->rollbackTransaction();
        vo->code = 400;
        vo->message = "Unknown error occurred";
    }

    return vo;
}