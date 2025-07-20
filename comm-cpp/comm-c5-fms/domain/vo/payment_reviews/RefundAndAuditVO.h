#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/17 19:38:42

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

#ifndef _REFUNDANDAUDITVO_H_
#define _REFUNDANDAUDITVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/payment_reviews/RefundAndAuditDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*获取申请退费表的json对象
*/
class ApplyRefundJsonVO : public JsonVO<ApplyRefundDTO::Wrapper>
{
	DTO_INIT(ApplyRefundDTO, JsonVO<ApplyRefundDTO::Wrapper>);
};
/*
*获取批量审核的json对象
*/
class BatchAuditJsonVO : public JsonVO<BatchAuditDTO::Wrapper>
{
	DTO_INIT(BatchAuditDTO, JsonVO<BatchAuditDTO::Wrapper>);
};
/*
*获取审核费用表的json对象
*/
class AuditFeeJsonVO : public JsonVO<AuditFeeDTO::Wrapper>
{
	DTO_INIT(AuditFeeDTO, JsonVO<AuditFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif