#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _REFUNDANDAUDITDAO_H_
#define _REFUNDANDAUDITDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/payment_reviews/RefundAndAuditDO.h"
#include "../../domain/query/payment_reviews/RefundAndAuditQuery.h"
#include "oatpp/core/Types.hpp"

class RefundAndAuditDAO : public BaseDAO
{
public:
    // 插入退费申请记录
    int insert(const ApplyRefundDO& obj);
    // 审核单个缴费记录
    int auditPayment(const AuditFeeDO& obj, const string& recordId);
    // 批量审核缴费记录
    int auditBatch(const AuditFeeDO& obj, const string& recordId);
    // 获取支付费用详情
    PtrApplyRefundDO getPayFeeDetail(const string& feeId);
    
    // 根据审核ID获取费用ID
    string getFeeIdByAuditId(const string& auditId);
    // 根据费用ID获取支付信息
    PtrBatchAuditDO getPaymentInfoByFeeId(const string& feeId);
    // 插入批量审核记录
    int insertBatchAudit(const BatchAuditDO& obj);
    // 更新支付表的批次ID
    int updatePayFeeBatchId(const string& feeId, const string& batchId);
};
#endif