#include "stdafx.h"
#include "RepairDoneDAO.h"
#include "RepairDoneMapper.h" 
#include <sstream>
//查询条件封装
std::string RepairDoneDAO::RepairDone_queryConditionBuilder(const RepairDoneQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	sqlCondition << " AND rp.state IN ('1800', '1900')";
	if (query->community_id) {

		sqlCondition << " AND rp.community_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	if (query->maintenance_type) {

		sqlCondition << " AND rp.maintenance_type=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->maintenance_type.getValue(""));
	}
	if (query->repair_name) {

		sqlCondition << " AND rp.repair_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_name.getValue(""));
	}
	if (query->tel) {

		sqlCondition << " AND rp.tel=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue(""));
	}
	if (query->repair_type) {

		sqlCondition << " AND rp.repair_type=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_type.getValue(""));
	}

	if (query->state) {

		sqlCondition << " AND rp.state=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
	}

	if (query->repair_id) {

		sqlCondition << " AND rp.repair_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_id.getValue(""));
	}
	return sqlCondition.str();
}
//数据条数 r_repair_pool表
uint64_t RepairDoneDAO::RepairDone_count(const RepairDoneQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM r_repair_pool rp ";
	// 构建查询条件
	sql += RepairDone_queryConditionBuilder(query, params);
	//条件：state=1900(办理完成)-- 对应报修已办
	/*if (!query->state) {
		sql += " AND rp.state IN ('1800', '1900')";
	}*/
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
//多表联查 r_repair_pool表、r_repair_setting表、t_dict表 查出state=1900（办理完成）的工单数据 -- 对应报修已办
std::list<RepairDoneDO> RepairDoneDAO::RepairDone_selectWithPage(const RepairDoneQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT rp.repair_id,rp.repair_obj_name,rp.repair_type,rs.repair_type_name AS repair_type_detail,rp.maintenance_type,\
		td_maint.name AS maintenance_type_detail,rp.repair_name,rp.tel,rp.appointment_time,rp.state,td_state.name AS state_detail\
		FROM r_repair_pool rp\
		LEFT JOIN r_repair_setting rs ON rp.repair_type = rs.repair_type\
		LEFT JOIN(SELECT status_cd, name FROM t_dict WHERE table_name = 'r_repair_pool') td_maint ON rp.maintenance_type = td_maint.status_cd\
		LEFT JOIN(SELECT status_cd, name FROM t_dict WHERE table_name = 'r_repair_pool') td_state ON rp.state = td_state.status_cd";
	// 构建查询条件
	sql += RepairDone_queryConditionBuilder(query, params);
	//sql += " AND rp.state=1900";
	//条件：state=1900(办理完成)-- 对应报修已办
	 /* if (!query->state) {
	sql += " AND rp.state=1900";
}*/
// 构建排序语句
	sql += " ORDER BY rp.repair_id ASC, rp.tel ASC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	RepairDoneMapper mapper;
	return sqlSession->executeQuery<RepairDoneDO>(sql, mapper, params);
}

