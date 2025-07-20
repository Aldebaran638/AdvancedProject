#include "stdafx.h"
#include "ForceBackDAO.h"
#include "ForceBackMapper.h" 
#include <sstream>
//查询条件
std::string ForceBackDAO::queryConditionBuilder(const ForceBackQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	//筛选出1100（接单状态）的数据
	sqlCondition << " AND rp.state = '1100'";
	if (query->community_id) {

		sqlCondition << " AND rp.community_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
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
	return sqlCondition.str();
}
//数据条数 r_repair_pool rp表
uint64_t ForceBackDAO::ForceBack_count(const ForceBackQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM r_repair_pool rp ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
//多表联查r_repair_pool、r_repair_setting、t_dict 得到state为 1100 接单状态 的工单数据--用于衔接强制回单操作
std::list<ForceBackDO> ForceBackDAO::ForceBack_selectWithPage(const ForceBackQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT rp.repair_id,rp.repair_obj_name,rp.repair_type,rs.repair_type_name AS repair_type_detail,\
		rp.repair_name,rp.tel,rp.appointment_time,rp.create_time,rp.state,td_state.name AS state_detail\
		FROM r_repair_pool rp\
		LEFT JOIN r_repair_setting rs ON rp.repair_type = rs.repair_type\
		LEFT JOIN(SELECT status_cd, name FROM t_dict WHERE table_name = 'r_repair_pool') td_state ON rp.state = td_state.status_cd";
	//string sql = "SELECT rp.repair_id,  rp.repair_obj_type, rp.repair_type, rp.repair_name, rp.tel, rp.appointment_time, rp.create_time, rp.state \
                  FROM r_repair_pool rp ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY rp.repair_id ASC, rp.tel ASC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ForceBackMapper mapper;
	return sqlSession->executeQuery<ForceBackDO>(sql, mapper, params);
}
//更新r_repair_pool表数据
int ForceBackDAO::ForceBack_update(const ForceBackDO& uObj)
{
	string sql = "UPDATE `r_repair_pool` SET  `maintenance_type`=?, `repair_materials`=?, `repair_fee`=?, `pay_type`=?, `state`=? WHERE `repair_id`= ? ";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", uObj.getMaintenanceType(), uObj.getRepairMaterials(), uObj.getRepairFee(), uObj.getPayType(), uObj.getState(), uObj.getRepairId());
}
//更新r_repair_user表数据
int ForceBackDAO::ForceBack_update_Context(const ForceBackDO& uObj)
{
	string sql = "UPDATE `r_repair_user` SET   `context`=?, WHERE `repair_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s", uObj.getContext(), uObj.getRepairId());
}
//根据repair_id查询repair_user表 供使用
PtrForceBackDO ForceBackDAO::selectRepairUserData(std::string RepairId)
{
	string sql = "SELECT `ru_id`,`b_id`,`community_id`,`create_time`,`state`,`context`,`status_cd`,`staff_id`,`staff_name`,`pre_staff_id`,`pre_staff_name`, "
		"`start_time`,`end_time`,`repair_event`,`pre_ru_id` "
		"FROM r_repair_user WHERE repair_id= ? AND state='10001'";
	PtrRepairToDoSelectToRemoveMapper mapper;
	return sqlSession->executeQueryOne<PtrForceBackDO>(sql, mapper, "%s", RepairId);
}
//插入数据 repair_user表
int ForceBackDAO::insert_repair_user(const ForceBackDO& iObj)
{
	string sql = "INSERT INTO `r_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, context, `status_cd`, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time,end_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getState(), iObj.getContext(), iObj.getStatusCd(), iObj.getRuStaffId(), iObj.getRuStaffName(),
		iObj.getPreStaffId(), iObj.getPreStaffName(), iObj.getStartTime(), iObj.getEndTime(), iObj.getRepairEvent(),
		iObj.getPreRuId());
}
