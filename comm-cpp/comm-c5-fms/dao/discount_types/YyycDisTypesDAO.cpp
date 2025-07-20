#include "stdafx.h"
#include "YyycDisTypesDAO.h"
#include <sstream>

std::string YyycDisTypesDAO::queryConditionBuilder(const YyycDisTypesUpdateQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->type_name) {

		sqlCondition << " AND `type_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->type_name.getValue(""));
	}
	if (query->type_desc) {

		sqlCondition << " AND type_desc=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->type_desc.getValue(""));
	}
}
// 修改类型优惠
int YyycDisTypesDAO::update(const YyycDisTypesDO& uObj)
{
	string sql = "UPDATE `apply_room_discount_type` SET `type_name`=?, `type_desc`=? WHERE `apply_type`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getType_Name(), uObj.getType_Desc(), uObj.getType_Id());
}
// 删除优惠类型
int YyycDisTypesDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `apply_room_discount_type` WHERE `apply_type`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}