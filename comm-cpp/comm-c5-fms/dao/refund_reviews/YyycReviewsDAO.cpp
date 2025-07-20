#include "stdafx.h"
#include "YyycReviewsDAO.h"
#include <sstream>


std::string YyycRevewsDAO::queryConditionBuilder(const YyycReviewsQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->state) {

		sqlCondition << " AND `state`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
	}
	if (query->reason) {

		sqlCondition << " AND reason=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->reason.getValue(""));
	}
}

// 修改类型优惠
int YyycRevewsDAO::update(const YyycReviewsDO& uObj)
{
	string sql = "UPDATE `return_pay_fee` SET `state`=?, `reason`=? WHERE `return_fee_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getState(), uObj.getReason(), uObj.getId());
}

