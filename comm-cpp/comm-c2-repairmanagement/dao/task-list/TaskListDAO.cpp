#include "stdafx.h"
#include "TaskListDAO.h"
#include "TaskListMapper.h"
#include <sstream>

std::string TaskListDAO::queryConditionBuilder(const TaskListQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	sqlCondition << " AND pool.status_cd = 0";
	//小区编号
	if (query->community_id) {
		sqlCondition << " AND pool.community_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	//工单编号
	if (query->repair_id) {
		sqlCondition << " AND pool.repair_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_id.getValue(""));
	}
	//报修人
	if (query->repair_name) {
		sqlCondition << " AND pool.repair_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_name.getValue(""));
	}
	//报修电话
	if (query->tel) {
		sqlCondition << " AND pool.tel=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue(""));
	}
	//报修类型
	if (query->repair_type) {
		sqlCondition << " AND pool.repair_type IN ("
			<< "SELECT setting.repair_type FROM r_repair_setting setting "
			<< "WHERE setting.repair_type_name=? AND setting.community_id=pool.community_id"
			<< ")";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_type.getValue(""));
	}
	//报修设置类型
	if (query->repair_setting_type) {
		std::string type = query->repair_setting_type.getValue("");
		std::string repairSettingTypeCode;
		if (type == ZH_WORDS_GETTER("taskpool.task-list.repair-setting-type-100")) {
			repairSettingTypeCode = "100";
		}
		else if (type == ZH_WORDS_GETTER("taskpool.task-list.repair-setting-type-200")) {
			repairSettingTypeCode = "200";
		}
		if (!repairSettingTypeCode.empty()) {
			sqlCondition << " AND pool.repair_type IN ("
				<< "SELECT setting.repair_type FROM r_repair_setting setting "
				<< "WHERE setting.repair_setting_type=? AND setting.community_id=pool.community_id"
				<< ")";
			SQLPARAMS_PUSH(params, "s", std::string, repairSettingTypeCode);
		}
		else {
			sqlCondition << " AND 1=0 ";
		}
	}
	//报修位置
	if (query->repair_obj_name) {
		sqlCondition << " AND pool.repair_obj_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_obj_name.getValue(""));
	}
	//维修类型
	if (query->maintenance_type) {
		std::string type = query->maintenance_type.getValue("");
		std::string maintenanceTypeCode;
		if (type == ZH_WORDS_GETTER("taskpool.task-list.maintenance-type-1001")) {
			maintenanceTypeCode = "1001";
		}
		else if (type == ZH_WORDS_GETTER("taskpool.task-list.maintenance-type-1002")) {
			maintenanceTypeCode = "1002";
		}
		else if (type == ZH_WORDS_GETTER("taskpool.task-list.maintenance-type-1003")) {
			maintenanceTypeCode = "1003";
		}
		else if(type == ZH_WORDS_GETTER("taskpool.task-list.maintenance-type-1004")) {
			maintenanceTypeCode = "1004";
		}
		if (!maintenanceTypeCode.empty()) {
			sqlCondition << " AND pool.maintenance_type=?";
			SQLPARAMS_PUSH(params, "s", std::string, maintenanceTypeCode);
		}
		else {
			sqlCondition << " AND 1=0 ";
		}
	}
	//开始时间
	if (query->start_time) {
		sqlCondition << " AND pool.appointment_time>=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	//结束时间
	if (query->end_time) {
		sqlCondition << " AND pool.create_time<=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t TaskListDAO::count_r_repair_pool(const TaskListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM r_repair_pool pool";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<TaskListDO> TaskListDAO::selectWithPage_r_repair_pool(const TaskListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = R"(
        SELECT
            pool.repair_id,
            pool.repair_obj_name,
            setting.repair_type_name,
            pool.maintenance_type,
            pool.repair_name,
            pool.tel,
            pool.appointment_time,
            pool.create_time,
            pool.state,
			mt_dict.name AS maintenance_type_txt,
            st_dict.name AS state_txt
        FROM
            r_repair_pool pool
        LEFT JOIN r_repair_setting setting
            ON pool.repair_type = setting.repair_type
               AND pool.community_id = setting.community_id
		LEFT JOIN t_dict mt_dict
			ON pool.maintenance_type = mt_dict.status_cd
			AND mt_dict.table_columns = 'maintenance_type'
        LEFT JOIN t_dict st_dict
            ON pool.state = st_dict.status_cd
            AND st_dict.table_name = 'housekeeping_serv_pool'
    )";
	// 拼接查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY IFNULL(pool.`appointment_time`, pool.`create_time`) DESC, pool.`repair_id` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	TaskListMapper mapper;
	return sqlSession->executeQuery<TaskListDO>(sql, mapper, params);
}

int TaskListDAO::deleteById_r_repair_pool(const TaskListDO& dObj)
{
	std::string sql = "UPDATE r_repair_pool SET status_cd = 1 WHERE repair_id = ?";
	return sqlSession->executeUpdate(sql, "%s", dObj.getRepairId());
}

int TaskListDAO::update_r_repair_pool(const TaskListDO& uObj)
{
	string sql = "UPDATE r_repair_pool pool "
		"JOIN r_repair_setting setting ON pool.community_id = setting.community_id AND setting.repair_type_name = ? AND setting.community_id = ? "
		"SET pool.repair_type = setting.repair_type, "
		"pool.repair_name = ?, pool.tel = ?, pool.appointment_time = ?, pool.context = ? "
		"WHERE pool.repair_id = ?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", uObj.getRepairTypeName(), uObj.getCommunityId(),uObj.getRepairName(), uObj.getTel(), uObj.getAppointmentTime(), uObj.getContext(), uObj.getRepairId());
}




