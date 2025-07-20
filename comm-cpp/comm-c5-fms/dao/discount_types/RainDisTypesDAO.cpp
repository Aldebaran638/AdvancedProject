#include "stdafx.h"
#include "RainDisTypesDAO.h"
#include "RainDisTypesMapper.h"
#include <sstream>

std::string RainDisTypesDAO::queryConditionBuilder(const RainDisTypesQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->apply_type)
	{

		sqlCondition << " AND `apply_type`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->apply_type.getValue(""));
	}
	if (query->type_name)
	{

		sqlCondition << " AND `type_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->type_name.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t RainDisTypesDAO::count(const RainDisTypesQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM apply_room_discount_type ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<RainDisTypesDO> RainDisTypesDAO::selectWithPage(const RainDisTypesQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT apply_type, type_name, community_id, type_desc, create_time, status_cd FROM apply_room_discount_type ";

	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY `create_time` DESC, `apply_type` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	RainDisTypesMapper mapper;
	return sqlSession->executeQuery<RainDisTypesDO>(sql, mapper, params);
}

std::list<RainDisTypesDO> RainDisTypesDAO::selectByName(const string& name)
{
	string sql = "SELECT apply_type, type_name, community_id, type_desc, create_time, status_cd FROM apply_room_discount_type WHERE `type_name`=?";
	RainDisTypesMapper mapper;
	return sqlSession->executeQuery<RainDisTypesDO>(sql, mapper, "%s", name);
}

int RainDisTypesDAO::insert(const RainDisTypesDO& iObj)
{
	string sql = "INSERT INTO `apply_room_discount_type` (`apply_type`, `type_name`, `community_id`, `type_desc`, `create_time`, `status_cd`) VALUES (?, ?, ?, ?, CURRENT_TIMESTAMP, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s", iObj.getApplyType(), iObj.getTypeName(), iObj.getCommunityId(), iObj.getTypeDesc(), iObj.getStatusCd());
}