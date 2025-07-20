#pragma once
#ifndef _REFUNDANDAUDITSERVICE_H_
#define _REFUNDANDAUDITSERVICE_H_

#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/payment_reviews/RefundAndAuditVO.h"
#include "../../domain/dto/payment_reviews/RefundAndAuditDTO.h"
#include "../../domain/do/payment_reviews/RefundAndAuditDO.h"


class RefundAndAuditService
{
public:
    // 申请退费
    StringJsonVO::Wrapper applyRefund(const ApplyRefundDTO::Wrapper& dto);
    
    // 审核费用
    StringJsonVO::Wrapper auditFee(const AuditFeeDTO::Wrapper& dto);

    // 批量审核费用
    StringJsonVO::Wrapper batchAudit(const BatchAuditDTO::Wrapper& dto);
};

#endif