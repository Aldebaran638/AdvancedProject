#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 14:12:29

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
#ifndef _BLUEREFUNDADUITQUERY_
#define _BLUEREFUNDADUITQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取退费审核列表
 */
class FeeReviewQuery : public PageQuery
{
	DTO_INIT(FeeReviewQuery, PageQuery);
	// 缴费单号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.id");
	}
	// 费用类型
	DTO_FIELD(String, range);
	DTO_FIELD_INFO(range) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.range");
	}
	// 审核状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.status");
	}
	// 申请人
	DTO_FIELD(String, applicant);
	DTO_FIELD_INFO(applicant) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.applicant");
	}
	// 审核人
	DTO_FIELD(String, Reviewers);
	DTO_FIELD_INFO(Reviewers) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.Reviewers");
	}
	// 房屋编号
	DTO_FIELD(String, Housenumber);
	DTO_FIELD_INFO(Housenumber) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.Housenumber");
	}
	// 申请开始时间
	DTO_FIELD(String, Applicationstarttime);
	DTO_FIELD_INFO(Applicationstarttime) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.Applicationstarttime");
	}
	// 申请结束时间
	DTO_FIELD(String, Applicatioendtime);
	DTO_FIELD_INFO(Applicatioendtime) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.Applicatioendtime");
	}
};
//获取缴费历史列表
class FeeHistoryQuery : public PageQuery
{
	DTO_INIT(FeeHistoryQuery, PageQuery);
	// 开始时间
	DTO_FIELD(String, begintime);
	DTO_FIELD_INFO(begintime) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.begin");
	}
	// 结束时间
	DTO_FIELD(String, endtime);
	DTO_FIELD_INFO(endtime) {
		info->description = ZH_WORDS_GETTER("blue.refundaduitlist.end");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_