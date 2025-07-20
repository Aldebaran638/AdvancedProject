#include "stdafx.h"
#include "CommunitySpaceMgrDAO.h"
#include "CommunitySpaceMgrMapper.h"
#include <sstream>

std::string CommunitySpaceMgrDAO::queryConditionBuilder(const CommunitySpaceMgrPageQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->space_id) {
	
		sqlCondition << " AND `space_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->space_id.getValue(""));
	}
	if (query->name) {
	
		sqlCondition << " AND `name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->start_time) {

		sqlCondition << " AND `start_time`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time) {

		sqlCondition << " AND `end_time`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	if (query->fee_money) {

		sqlCondition << " AND `fee_money`=?";
		SQLPARAMS_PUSH(params, "d", double, query->fee_money.getValue(0));
	}
	if (query->admin_name) {

		sqlCondition << " AND `admin_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->admin_name.getValue(""));
	}
	if (query->tel) {

		sqlCondition << " AND `tel`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue(""));
	}
	if (query->state) {

		sqlCondition << " AND `state`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
	}
	return sqlCondition.str();
}

std::string CommunitySpaceMgrDAO::queryConditionTimeBuilder(const CommunitySpaceTimeMgrPageQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->space_id) {
	
		sqlCondition << " AND `space_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->space_id.getValue(""));
	}
	
	if (query->hours) {
	
		sqlCondition << " AND `hours`=?";
		SQLPARAMS_PUSH(params, "i", int, query->hours.getValue(0));
	}
	if (query->is_open) {
	
		sqlCondition << " AND `is_open`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->is_open.getValue(""));
	}
	if (query->time_id) {

		sqlCondition << " AND `time_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->time_id.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t CommunitySpaceMgrDAO::count(const CommunitySpaceMgrPageQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM community_space ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

uint64_t CommunitySpaceMgrDAO::countTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM community_space_open_time ";
	// 构建查询条件
	sql += queryConditionTimeBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CommunitySpaceMgrDO> CommunitySpaceMgrDAO::selectWithPage(const CommunitySpaceMgrPageQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT space_id,name,start_time,end_time,fee_money,admin_name,tel,state FROM community_space ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY IFNULL(`create_time`, `start_time`) DESC, `space_id` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	CommunitySpaceMgrMapper mapper;
	return sqlSession->executeQuery<CommunitySpaceMgrDO>(sql, mapper, params);
}

std::list<CommunitySpaceTimeMgrDO> CommunitySpaceMgrDAO::selectTimeWithPage(const CommunitySpaceTimeMgrPageQuery::Wrapper& query)
{
	SqlParams params;
	string sql = " SELECT space_id,hours,is_open,time_id FROM community_space_open_time";
	// 构建查询条件
	sql += queryConditionTimeBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY  `hours` ASC ";
	// 构建分页条件
	//sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	CommunitySpaceTimeMgrMapper mapper;
	return sqlSession->executeQuery<CommunitySpaceTimeMgrDO>(sql, mapper, params);
}


int CommunitySpaceMgrDAO::update(const CommunitySpaceTimeMgrDO& uObj)
{
	string sql = "UPDATE `community_space_open_time` SET  `is_open`=? WHERE `hours`=? && `space_id`=?";
	return sqlSession->executeUpdate(sql, "%s%i%s", uObj.getIs_Open(), uObj.getHours(), uObj.getSpace_Id());
}


//std::list<CommunitySpaceTimeMgrDO> CommunitySpaceMgrDAO::selectTimeById(std::string id)
//{
//	string sql = "SELECT time_id,hours,is_open FROM community_space_open_time WHERE `space_id`=?";
//	sql += " ORDER BY  `hours` DESC ";
//	CommunitySpaceTimeMgrMapper mapper;
//	return sqlSession->executeQueryOne<CommunitySpaceTimeMgrDO>(sql, mapper, "%s", id);
//}

