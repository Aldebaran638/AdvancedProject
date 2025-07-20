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

#ifndef _REFUNDANDAUDITDTO_H_
#define _REFUNDANDAUDITDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 申请退费数据传输模型
*/
class ApplyRefundDTO : public oatpp::DTO
{
	DTO_INIT(ApplyRefundDTO, DTO);
	// 缴费ID
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("RefundAndAudit.field.fee_id"));
	// 退费原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("RefundAndAudit.field.reason"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
* 批量审核数据传输模型
*/
class BatchAuditDTO : public oatpp::DTO
{
	DTO_INIT(BatchAuditDTO, DTO);
	// 选中的记录ID列表
	API_DTO_FIELD_DEFAULT(List<String>, record_ids, ZH_WORDS_GETTER("RefundAndAudit.field.record_ids"));
	// 审核状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("RefundAndAudit.field.state"));
	// 审核原因
	API_DTO_FIELD_DEFAULT(String, msg, ZH_WORDS_GETTER("RefundAndAudit.field.msg"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
* 审核费用数据传输模型
*/
class AuditFeeDTO : public oatpp::DTO
{
	DTO_INIT(AuditFeeDTO, DTO);
	//id
	API_DTO_FIELD_DEFAULT(String, audit_id, ZH_WORDS_GETTER("RefundAndAudit.field.audit_id"));
	// 审核状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("RefundAndAudit.field.state"));
	// 审核原因
	API_DTO_FIELD_DEFAULT(String, message, ZH_WORDS_GETTER("RefundAndAudit.field.message"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_END(DTO);

#endif //!_REFUNDANDAUOITDTO_H_