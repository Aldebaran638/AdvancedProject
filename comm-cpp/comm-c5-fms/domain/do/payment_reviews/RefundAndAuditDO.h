#pragma once
#ifndef _REFUNDANDAUDITDO_H_
#define _REFUNDANDAUDITDO_H_
#include "../DoInclude.h"

class ApplyRefundDO
{
    //退费id
    CC_SYNTHESIZE(string, return_fee_id, Return_fee_id);
    //小区id
    CC_SYNTHESIZE(string, community_id, Community_id);
    // 业务id
    CC_SYNTHESIZE(string, b_id, B_id);
    // 费用项id
    CC_SYNTHESIZE(string, config_id, Config_id);
    // 费用id
    CC_SYNTHESIZE(string, fee_id, Fee_id);
    //费用类型
    CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
    // 缴费id
    CC_SYNTHESIZE(string, detail_id, Detail_id);
    // 周期（单位月）
    CC_SYNTHESIZE(double, cycles, Cycles);
    // 应收金额
    CC_SYNTHESIZE(double, receivable_amount, Receivable_amount);
    // 实收金额
    CC_SYNTHESIZE(double, received_amount, Received_amount);
    //支付方式
    CC_SYNTHESIZE(string, prime_rate, Prime_rate);
    // 备注
    CC_SYNTHESIZE(string, remark, Remark);
    // 审核状态
    CC_SYNTHESIZE(string, state, State);
    // 数据状态
    CC_SYNTHESIZE(string, status_cd, Status_cd);
    // 申请退费时间
    CC_SYNTHESIZE(string, create_time, Create_time);
    // 缴费时间
    CC_SYNTHESIZE(string, pay_time, Pay_time);
    // 退费原因
    CC_SYNTHESIZE(string, reason, Reason);
    // 申请人id
    CC_SYNTHESIZE(string, apply_person_id, Apply_person_id);
    // 申请人
    CC_SYNTHESIZE(string, apply_person_name, Apply_person_name);
    // 审核人id
    CC_SYNTHESIZE(string, audit_person_id, Audit_person_id);
    // 审核人
    CC_SYNTHESIZE(string, audit_person_name, Audit_person_name);

public:
    ApplyRefundDO() {
        return_fee_id = "";
        community_id = "";
        b_id = "";
        config_id = "";
        fee_id = "";
        fee_type_cd = "";
        detail_id = "";
        cycles = 0.0;
        receivable_amount = 0.0;
        received_amount = 0.0;
        prime_rate = "";
        remark = "";
        state = "";
        status_cd = "";
        create_time = "";
        pay_time = "";
        reason = "";
        apply_person_id = "";
        apply_person_name = "";
        audit_person_id = "";
        audit_person_name = "";
    }
};

class AuditFeeDO
{
    // 审核id
    CC_SYNTHESIZE(string, audit_id, Audit_id);
    // 费用id
    CC_SYNTHESIZE(string, fee_id, Fee_id);
    // 小区id
    CC_SYNTHESIZE(string, community_id, Community_id);
    // 消费id
    CC_SYNTHESIZE(string, fee_detail_id, Fee_detail_id);
    // 审核状态
    CC_SYNTHESIZE(string, state, State);
    // 审核原因
    CC_SYNTHESIZE(string, message, Message);
    // 审核人id
    CC_SYNTHESIZE(string, audit_user_id, Audit_user_id);
    // 审核人
    CC_SYNTHESIZE(string, audit_user_name, Audit_user_name);
    // 创建时间
    CC_SYNTHESIZE(string, create_time, Create_time);
    // 数据状态
    CC_SYNTHESIZE(string, status_cd, Status_cd);

public:
    AuditFeeDO() {
        audit_id = "";
        fee_id = "";
        community_id = "";
        fee_detail_id = "";
        state = "";
        message = "";
        audit_user_id = "";
        audit_user_name = "";
        create_time = "";
        status_cd = "";
    }
};

class BatchAuditDO
{
    //批次号
    CC_SYNTHESIZE(string, batch_id, Batch_id);
    // 小区id
    CC_SYNTHESIZE(string, community_id, Community_id);
    // 创建人
    CC_SYNTHESIZE(string, create_user_id, Create_user_id);
    // 创建人
    CC_SYNTHESIZE(string, create_user_name, Create_user_name);
    // 创建时间
    CC_SYNTHESIZE(string, create_time, Create_time);
    // 数据状态
    CC_SYNTHESIZE(string, status_cd, Status_cd);
    // 审核状态
    CC_SYNTHESIZE(string, state, State);
    // 审核原因
    CC_SYNTHESIZE(string, msg, Msg);
    // 备注
    CC_SYNTHESIZE(string, remark, Remark);

public:
    BatchAuditDO() {
        batch_id = "";
        community_id = "";
        create_user_id = "";
        create_user_name = "";
        create_time = "";
        status_cd = "";
        state = "";
        msg = "";
        remark = "";
    }
};

typedef std::shared_ptr<ApplyRefundDO> PtrApplyRefundDO;
typedef std::shared_ptr<AuditFeeDO> PtrAuditFeeDO;
typedef std::shared_ptr<BatchAuditDO> PtrBatchAuditDO;

#endif 
