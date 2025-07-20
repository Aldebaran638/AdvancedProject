#pragma once
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
#include "OwnerListDAO.h"
#include "OwnerListMapper.h"
#include <sstream>

std::string OwnerListDAO::queryConditionBuilder(const OwnerListQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE account.link=building_owner.link AND building_owner.name=account.acct_name";
	// 账户名称
	if (query->name) {
		//sqlCondition << " AND building_owner.name=account.acct_name";
		sqlCondition << " AND building_owner.name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	// 身份证号
	if (query->id_card) {
		sqlCondition << " AND building_owner.id_card=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue(""));
	}
	// 手机号
	if (query->link) {
		//sqlCondition << " AND account.link=building_owner.link";
		sqlCondition << " AND building_owner.link=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	// 小区ID
	if (query->community_id) {
		sqlCondition << " AND building_owner.community_id =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	// acct_type_text
	sqlCondition << " AND t_dict.status_cd=account.acct_type AND t_dict.table_name='account' AND t_dict.table_columns='acct_type'";
	// prime_rate


	return sqlCondition.str();
}

uint64_t OwnerListDAO::count(const OwnerListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM account, building_owner, t_dict";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<OwnerListDO> OwnerListDAO::selectWithPage(const OwnerListQuery::Wrapper& query)
{
	//acct_type_text:599-602行
	SqlParams params;
	string sql = 
		"SELECT account.acct_id, building_owner.name, building_owner.id_card, building_owner.link, account.acct_type, account.amount, building_owner.create_time, t_dict.name FROM account, building_owner, t_dict"
	;
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY building_owner.`create_time` DESC, account.`acct_id` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	OwnerListMapper mapper;
	return sqlSession->executeQuery<OwnerListDO>(sql, mapper, params);
}
