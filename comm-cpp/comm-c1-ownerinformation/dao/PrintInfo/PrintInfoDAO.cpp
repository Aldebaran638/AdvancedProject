/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "PrintInfoDAO.h"
#include "PrintInfoMapper.h"
#include <sstream>

std::string PrintInfoDAO::queryConditionBuilder(const PrintInfoQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->acct_name) {
		sqlCondition << " AND account.acct_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acct_name.getValue(""));
	}
	if (query->acct_type) {
		sqlCondition << " AND account.acct_type=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acct_type.getValue(""));
	}
	if (query->owner_name) {
		sqlCondition << " AND account_receipt.owner_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->owner_name.getValue(""));
	}
	if (query->received_amount) {
		sqlCondition << " AND account_receipt.received_amount=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->received_amount.getValue(""));
	}
	if (query->prime_rate) {
		sqlCondition << " AND account_receipt.prime_rate=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->prime_rate.getValue(""));
	}
	if (query->amount) {
		sqlCondition << " AND account.amount=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->amount.getValue(""));
	}
	if (query->create_time) {
		sqlCondition << " AND account_receipt.create_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue(""));
	}
	if (query->ar_id) {
		sqlCondition << " AND account_receipt.ar_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ar_id.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t PrintInfoDAO::count(const PrintInfoQuery::Wrapper& query)
{
	SqlParams params;
	string sql = R"(
		SELECT 
			COUNT(*)
		FROM
			account_receipt
		LEFT JOIN account ON account.acct_id=account_receipt.acct_id 
		LEFT JOIN fee_print_page ON fee_print_page.community_id=account_receipt.community_id
		LEFT JOIN s_community ON account_receipt.community_id=s_community.community_id
	)";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<AccountReceiptDO> PrintInfoDAO::selectWithPage(const PrintInfoQuery::Wrapper& query) {
	SqlParams params;
	string sql = R"(
		SELECT
			account_receipt.ar_id,
			account_receipt.create_time,
			account.acct_name,
			account.acct_type,
			account_receipt.owner_name,
			account_receipt.receivable_amount,
			account_receipt.prime_rate,
			account.amount,
			account_receipt.remark,
			account_receipt.received_amount,
			fee_print_page.page_name,
			s_community.name
		FROM
			account_receipt
		LEFT JOIN account ON account.acct_id=account_receipt.acct_id 
		LEFT JOIN fee_print_page ON fee_print_page.community_id=account_receipt.community_id
		LEFT JOIN s_community ON account_receipt.community_id=s_community.community_id
    )";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY `create_time` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	PrintInfoMapper mapper;
	return sqlSession->executeQuery<AccountReceiptDO>(sql, mapper, params);
}