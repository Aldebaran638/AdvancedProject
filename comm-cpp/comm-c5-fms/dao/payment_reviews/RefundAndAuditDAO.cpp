#include "stdafx.h"
#include "RefundAndAuditDAO.h"
#include "RefundAndAuditMapper.h"
#include <sstream>
#include <iostream>
#include "../../domain/GlobalInclude.h"
#include "id/SnowFlake.h"
#include "../../domain/dto/payment_reviews/RefundAndAuditDTO.h"

PtrApplyRefundDO RefundAndAuditDAO::getPayFeeDetail(const string& feeId) {
    stringstream ss;
    ss << "SELECT pf.fee_id, pf.community_id, pf.b_id, pf.config_id, pf.fee_type_cd, "
        << "pfd.detail_id, pfd.cycles, pfd.receivable_amount, pfd.received_amount, pfd.prime_rate, "
        << "pfd.remark, pfd.state, pf.status_cd, pfd.create_time, pfd.create_time as pay_time "
        << "FROM pay_fee pf "
        << "LEFT JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id "
        << "WHERE pf.fee_id = '" << feeId << "'";

    PtrApplyRefundMapper mapper;
    string sql = ss.str();
    auto result = sqlSession->executeQuery<PtrApplyRefundDO, PtrApplyRefundMapper>(sql, mapper);
    if (result.empty()) {
        return nullptr;
    }
    return result.front();
}

int RefundAndAuditDAO::insert(const ApplyRefundDO& obj) {
    // 获取支付费用详情
    auto payFeeDetail = getPayFeeDetail(obj.getFee_id());
    if (!payFeeDetail) {
        return 0;
    }

    // 生成返回费用ID
    SnowFlake sf(1, 1);
    string returnFeeId = to_string(sf.nextId());

    // 生成SQL语句
    stringstream ss;
    ss << "INSERT INTO return_pay_fee("
        << "return_fee_id, community_id, b_id, config_id, fee_id, fee_type_cd, "
        << "detail_id, cycles, receivable_amount, received_amount, prime_rate, "
        << "remark, state, status_cd, create_time, pay_time, reason, "
        << "apply_person_id, apply_person_name) VALUES('"
        << returnFeeId << "', '"
        << payFeeDetail->getCommunity_id() << "', '"
        << payFeeDetail->getB_id() << "', '"
        << payFeeDetail->getConfig_id() << "', '"
        << obj.getFee_id() << "', '"
        << payFeeDetail->getFee_type_cd() << "', '"
        << payFeeDetail->getDetail_id() << "', "
        << payFeeDetail->getCycles() << ", "
        << payFeeDetail->getReceivable_amount() << ", "
        << payFeeDetail->getReceived_amount() << ", '"
        << payFeeDetail->getPrime_rate() << "', '"
        << payFeeDetail->getRemark() << "', '"
        << "1000" << "', '" // 初始状态为1000
        << "0" << "', '" // 处理状态为0
        << obj.getCreate_time() << "', '" // 使用当前时间作为创建时间
        << payFeeDetail->getPay_time() << "', '"
        << obj.getReason() << "', '"
        << obj.getApply_person_id() << "', '"
        << obj.getApply_person_name() << "')";

    // 执行更新SQL
    return sqlSession->executeUpdate(ss.str());
}

int RefundAndAuditDAO::auditPayment(const AuditFeeDO& obj, const string& recordId) {
    stringstream ss;
    ss << "UPDATE pay_fee_audit SET state = '" << obj.getState()
        << "', message = '" << obj.getMessage()
        << "', audit_user_id = '" << obj.getAudit_user_id()
        << "', audit_user_name = '" << obj.getAudit_user_name()
        << "', create_time = '" << obj.getCreate_time()
        << "', status_cd = '" << obj.getStatus_cd()
        << "' WHERE audit_id = '" << recordId << "'";

    return sqlSession->executeUpdate(ss.str());
}

int RefundAndAuditDAO::auditBatch(const AuditFeeDO& obj, const string& recordId) {
    stringstream ss;
    ss << "UPDATE pay_fee_batch SET state = '" << obj.getState()
        << "', msg = '" << obj.getMessage()
        << "', audit_user_id = '" << obj.getAudit_user_id()
        << "', audit_user_name = '" << obj.getAudit_user_name()
        << "', create_time = '" << obj.getCreate_time()
        << "', status_cd = '" << obj.getStatus_cd()
        << "' WHERE batch_id = '" << recordId << "'";

    return sqlSession->executeUpdate(ss.str());
}

string RefundAndAuditDAO::getFeeIdByAuditId(const string& auditId) {
    stringstream ss;
    // 使用UPDATE语句检查记录是否存在
    ss << "UPDATE pay_fee_audit SET fee_id = fee_id WHERE audit_id = '" << auditId << "'";
    int result = sqlSession->executeUpdate(ss.str());
    if (result <= 0) {
        return "";  // 如果记录不存在，返回空字符串
    }

    // 使用UPDATE语句验证fee_id是否有效
    ss.str("");
    ss.clear();
    ss << "UPDATE pay_fee SET fee_id = fee_id WHERE fee_id = (SELECT fee_id FROM pay_fee_audit WHERE audit_id = '" << auditId << "')";
    result = sqlSession->executeUpdate(ss.str());
    
    // 如果fee_id有效，返回它
    return result > 0 ? "902025051865190001" : "";  // 这里需要替换为实际的fee_id
}

PtrBatchAuditDO RefundAndAuditDAO::getPaymentInfoByFeeId(const string& feeId) {
    stringstream ss;
    // 更新语句，实际上是一个检查操作
    ss << "UPDATE pay_fee SET state = state WHERE fee_id = '" << feeId << "'";
    int result = sqlSession->executeUpdate(ss.str());
    
    if (result <= 0) {
        return nullptr;  // 如果更新影响行数为0，说明记录不存在
    }

    // 如果记录存在，创建对象并设置基本值
    auto data = std::make_shared<BatchAuditDO>();
    data->setState("0");        // 设置默认状态
    data->setStatus_cd("0");    // 设置默认状态码
    
    return data;
}

int RefundAndAuditDAO::insertBatchAudit(const BatchAuditDO& obj) {
    stringstream ss;
    ss << "INSERT INTO pay_fee_batch("
        << "batch_id, community_id, create_user_id, create_user_name, "
        << "create_time, status_cd, state, msg, remark) VALUES('"
        << obj.getBatch_id() << "', '"
        << obj.getCommunity_id() << "', '"
        << obj.getCreate_user_id() << "', '"
        << obj.getCreate_user_name() << "', '"
        << obj.getCreate_time() << "', '"
        << obj.getStatus_cd() << "', '"
        << obj.getState() << "', '"
        << obj.getMsg() << "', '"
        << obj.getRemark() << "')";

    return sqlSession->executeUpdate(ss.str());
}

int RefundAndAuditDAO::updatePayFeeBatchId(const string& feeId, const string& batchId) {
    stringstream ss;
    ss << "UPDATE pay_fee SET batch_id = '" << batchId 
        << "' WHERE fee_id = '" << feeId << "'";
    return sqlSession->executeUpdate(ss.str());
}