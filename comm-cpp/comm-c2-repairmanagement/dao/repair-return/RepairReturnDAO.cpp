#include "stdafx.h"
#include "RepairReturnDAO.h"
#include "RepairReturnMapper.h" 
#include <sstream>
//查询条件封装 
std::string RepairReturnDAO::RepairReturn_queryConditionBuilder(const RepairReturnQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	sqlCondition << " AND rp.state IN ('1100', '1800', '1900')";
	if (query->community_id) {

		sqlCondition << " AND rp.community_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	if (query->repair_id) {

		sqlCondition << " AND rp.repair_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_id.getValue(""));
	}
	if (query->repair_type) {

		sqlCondition << " AND rp.repair_type=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_type.getValue(""));
	}
	if (query->repair_name) {

		sqlCondition << " AND rp.repair_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_name.getValue(""));
	}
	if (query->tel) {

		sqlCondition << " AND rp.tel=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue(""));
	}
	if (query->state) {

		sqlCondition << " AND rp.state=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
	}
	return sqlCondition.str();
}
//数据条数 r_repair_pool rp表 
uint64_t RepairReturnDAO::RepairReturn_count(const RepairReturnQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM r_repair_pool rp ";
	// 构建查询条件
	sql += RepairReturn_queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
//多表联查 r_repair_pool表、r_repair_setting表、t_dict表 state为 接单或待评价的工单数据 -- 对应报修回访
std::list<RepairReturnDO> RepairReturnDAO::RepairReturn_selectWithPage(const RepairReturnQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT rp.repair_id,rp.repair_obj_name,rp.repair_type,rs.repair_type_name AS repair_type_detail,\
		rp.repair_name,rp.tel,rp.appointment_time,rp.state,td_state.name AS state_detail\
		FROM r_repair_pool rp\
		LEFT JOIN r_repair_setting rs ON rp.repair_type = rs.repair_type\
		LEFT JOIN(SELECT status_cd, name FROM t_dict WHERE table_name = 'r_repair_pool') td_state ON rp.state = td_state.status_cd";
	//string sql = "SELECT rp.repair_id, rp.repair_obj_type, rp.repair_type, rp.repair_name, rp.tel, rp.appointment_time, rp.state \
                  FROM r_repair_pool rp ";
	// 构建查询条件
	sql += RepairReturn_queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY rp.`repair_id` ASC, rp.`tel` ASC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	RepairReturnMapper mapper;
	return sqlSession->executeQuery<RepairReturnDO>(sql, mapper, params);
}
//插入数据 r_repair_return_visit表

int RepairReturnDAO::RepairReturn_insert(const RepairReturnDO& iObj)
{
	string sql = "INSERT INTO `r_repair_return_visit` ( `visit_id`,`repair_id`,`community_id`,`visit_person_id`,`visit_person_name`,`visit_type`, `context`,`create_time`,`status_cd`) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s", iObj.getVisitId(), iObj.getRepairId(), iObj.getCommunityId(), iObj.getVisitPersonId(), iObj.getVisitPersonName(), iObj.getVisitType(), iObj.getContext(), iObj.getCreateTime(), iObj.getStatusCd());
}
