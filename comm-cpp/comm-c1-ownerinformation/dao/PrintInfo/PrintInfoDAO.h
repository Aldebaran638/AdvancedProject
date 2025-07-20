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
#ifndef _PRINTINFO_DAO_H_
#define _PRINTINFO_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/account/accountDO.h"
#include "../../domain/do/account_receipt/account_receiptDO.h"
#include "../../domain/do/fee_print_page/fee_print_pageDO.h"
#include "../../domain/query/PrintInfo/PrintInfoQuery.h"

class PrintInfoDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const PrintInfoQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const PrintInfoQuery::Wrapper& query);
	// 分页查询数据
	std::list<AccountReceiptDO> selectWithPage(const PrintInfoQuery::Wrapper& query);
}; 

#endif