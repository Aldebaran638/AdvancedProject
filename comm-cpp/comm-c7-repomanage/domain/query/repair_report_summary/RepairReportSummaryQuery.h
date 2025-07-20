#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _REPAIR_REPORT_SUMMARY_QUERY_
#define _REPAIR_REPORT_SUMMARY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修汇总表分页查询对象
 */
class RepairReportSummaryQuery : public PageQuery
{
	DTO_INIT(RepairReportSummaryQuery, PageQuery);
	// 创建开始时间
	DTO_FIELD(String, createStartTime);
	DTO_FIELD_INFO(createStartTime) {
		info->description = ZH_WORDS_GETTER("repair.time.create.begin");
	}
	// 创建结束时间
	API_DTO_FIELD_DEFAULT(String, createEndTime, ZH_WORDS_GETTER("repair.time.create.end"));
	//完结开始时间
	API_DTO_FIELD_DEFAULT(String, finishStartTime, ZH_WORDS_GETTER("repair.time.finish.begin"));
	//完结结束时间
	API_DTO_FIELD_DEFAULT(String, finishEndTime, ZH_WORDS_GETTER("repair.time.finish.end"));
	//选择小区
	API_DTO_FIELD_DEFAULT(String, communityName, ZH_WORDS_GETTER("repair.select.community"));
	//选择员工姓名
	API_DTO_FIELD_DEFAULT(String, staffName, ZH_WORDS_GETTER("repair.select.staffname"));
	//选择状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repair.select.state"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIR_REPORT_SUMMARY_QUERY_
