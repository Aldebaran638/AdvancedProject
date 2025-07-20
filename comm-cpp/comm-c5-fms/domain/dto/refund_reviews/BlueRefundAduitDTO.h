#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 14:26:38

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
#ifndef _BLUEREFUNDADUITDTO_
#define _BLUEREFUNDADUITDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//退费审核传输对象
class ReviewDTO : public oatpp::DTO
{
	DTO_INIT(ReviewDTO, DTO);
	// 退款单号
	API_DTO_FIELD_DEFAULT(String, return_fee_id, ZH_WORDS_GETTER("blue.refundauditlist.return_fee_id"));
	// 缴费单号
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("blue.refundauditlist.detail_id"));
	// 费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("blue.refundauditlist.fee_type_cd"));
	// 费用对象
	API_DTO_FIELD_DEFAULT(String, Expense_object, ZH_WORDS_GETTER("blue.refundauditlist.Expense_object"));
	// 付费周期
	API_DTO_FIELD_DEFAULT(Int64, cycles, ZH_WORDS_GETTER("blue.refundauditlist.cycles"));
	// 应付金额
	API_DTO_FIELD_DEFAULT(String, Amount_Due, ZH_WORDS_GETTER("blue.refundauditlist.Amount_Due"));
	//申请时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("blue.refundauditlist.create_time"));
	//退费原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("blue.refundauditlist.reason"));
	//申请人
	API_DTO_FIELD_DEFAULT(String, applicant, ZH_WORDS_GETTER("blue.refundauditlist.applicant"));
	//审核状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("blue.refundauditlist.state"));
	//审核人
	API_DTO_FIELD_DEFAULT(String, Reviewers, ZH_WORDS_GETTER("blue.refundauditlist.Reviewers"));
	//退款情况
	API_DTO_FIELD_DEFAULT(String, Refund_status, ZH_WORDS_GETTER("blue.refundauditlist.Refund_status"));
	//操作
	API_DTO_FIELD_DEFAULT(String, operatedd, ZH_WORDS_GETTER("blue.refundauditlist.operatedd"));
};
class ReviewPageDTO : public PageDTO<ReviewDTO::Wrapper>
{
	DTO_INIT(ReviewPageDTO, PageDTO<ReviewDTO::Wrapper>);
};




//退费审核传输详情对象
class FeeDetailDTO : public oatpp::DTO
{
	DTO_INIT(FeeDetailDTO, DTO);
	// 缴费单号
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("blue.refundauditlist.detail_id"));
	// 费用标识
	API_DTO_FIELD_DEFAULT(String, fee_label, ZH_WORDS_GETTER("blue.refundauditlist.label"));
	// 费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("blue.refundauditlist.fee_type_cd"));
	//付费对象
	API_DTO_FIELD_DEFAULT(String, fee_object, ZH_WORDS_GETTER("blue.refundauditlist.object"));
	//费用项
	API_DTO_FIELD_DEFAULT(String, fee_item, ZH_WORDS_GETTER("blue.refundauditlist.item"));
	//费用状态
	API_DTO_FIELD_DEFAULT(String, fee_state, ZH_WORDS_GETTER("blue.refundauditlist.fee_state"));
};
//退费缴费历史列表对象
class HistoryDTO : public oatpp::DTO
{
	DTO_INIT(HistoryDTO, DTO);
	// 缴费单号
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("blue.refundauditlist.detail_id"));
	// 缴费方式
	API_DTO_FIELD_DEFAULT(String, prime_rate, ZH_WORDS_GETTER("blue.refundauditlist.submit"));
	//缴费时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("blue.refundauditlist.submittime"));
	//缴费起始时间
	API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("blue.refundauditlist.beginsubmittime"));
};

class FeeHistoryDTO : public PageDTO<HistoryDTO::Wrapper>
{
	DTO_INIT(FeeHistoryDTO, PageDTO<HistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_