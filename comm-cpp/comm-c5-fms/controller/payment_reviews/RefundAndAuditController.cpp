/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/12 21:11:44

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

#include "stdafx.h"
#include "RefundAndAuditController.h"
#include "../../service/payment_reviews/RefundAndAuditService.h"

// 退款申请接口
StringJsonVO::Wrapper RefundAndAuditController::execAddApply(const ApplyRefundDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 创建服务对象
    RefundAndAuditService service;
    // 设置负载数据
    dto->setPayload(&payload);
    // 调用方法执行退款申请业务
    return service.applyRefund(dto);
}

// 批量审核接口
StringJsonVO::Wrapper RefundAndAuditController::execQueryBatch(const BatchAuditDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 创建服务对象
    RefundAndAuditService service;
    // 设置负载数据
    dto->setPayload(&payload);
    // 调用方法执行批量审核业务
    return service.batchAudit(dto);
}

// 费用审核接口
StringJsonVO::Wrapper RefundAndAuditController::execModifyAudit(const AuditFeeDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 创建服务对象
    RefundAndAuditService service;
    // 设置负载数据
    dto->setPayload(&payload);
    // 调用方法执行费用审核业务
    return service.auditFee(dto);
}