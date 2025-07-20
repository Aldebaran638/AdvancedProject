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
#ifndef _PRININFO_QUERY_
#define _PRINTINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 导出打印信息的分页查询对象
 */
class PrintInfoQuery : public PageQuery
{
	DTO_INIT(PrintInfoQuery, PageQuery);

	// 账户名称
	API_DTO_FIELD_DEFAULT(String, acct_name, ZH_WORDS_GETTER("PrintInfo.field.acct_name"));
	// 账户类型
	API_DTO_FIELD_DEFAULT(String, acct_type, ZH_WORDS_GETTER("PrintInfo.field.acct_type"));
	// 业主
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("PrintInfo.field.owner_name"));
	// 预存金额
	API_DTO_FIELD_DEFAULT(String, received_amount, ZH_WORDS_GETTER("PrintInfo.field.received_amount"));
	// 预存方式
	API_DTO_FIELD_DEFAULT(String, prime_rate, ZH_WORDS_GETTER("PrintInfo.field.prime_rate"));
	// 总金额
	API_DTO_FIELD_DEFAULT(String, amount, ZH_WORDS_GETTER("PrintInfo.field.amount"));
	// 预存时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("PrintInfo.field.create_time"));
	// 收据id
	API_DTO_FIELD_DEFAULT(String, ar_id, ZH_WORDS_GETTER("PrintInfo.field.ar_id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif