/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/25 15:15:52

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
#include "BlueRefundAduitDAO.h"
#include "BlueRefundAduitMapper.h"
#include <sstream>

std::string ReviewPageDAO::queryConditionBuilder(const FeeReviewQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->id) {

		sqlCondition << " AND fee_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
	}
	if (query->range) {

		sqlCondition << " AND fee_type_cd=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->range.getValue(""));
	}
	if (query->status) {

		sqlCondition << " AND state=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue(""));
	}
	return sqlCondition.str();
}
uint64_t ReviewPageDAO::count(const FeeReviewQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM return_pay_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
std::list<ReviewPageDO> ReviewPageDAO::selectReviewPage(const FeeReviewQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT return_fee_id,detail_id,fee_type_cd,cycles,create_time,reason,state FROM return_pay_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ReviewPageMapper mapper;
	return sqlSession->executeQuery<ReviewPageDO>(sql, mapper, params);
}

FeeDetailDO ReviewPageDAO::selectById(std::string id)
{
	string sql = "SELECT detail_id,fee_id,fee_type_cd,remark,config_id,state FROM return_pay_fee WHERE `return_fee_id`=?";
	FeeDetailMapper mapper;
	return sqlSession->executeQueryOne<FeeDetailDO>(sql, mapper, "%s", id);
}


std::string FeeHistoryDAO::queryConditionBuilder(const FeeHistoryQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->begintime) {

		sqlCondition << " AND create_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
	}
	if (query->endtime) {

		sqlCondition << " AND pay_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
	}
	return sqlCondition.str();
}
uint64_t FeeHistoryDAO::count(const FeeHistoryQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM return_pay_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
std::list<FeeHistoryDO> FeeHistoryDAO::selectFeeHistory(const FeeHistoryQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT detail_id,prime_rate,create_time,pay_time FROM return_pay_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	FeeHistoryMapper mapper;
	return sqlSession->executeQuery<FeeHistoryDO>(sql, mapper, params);
}
