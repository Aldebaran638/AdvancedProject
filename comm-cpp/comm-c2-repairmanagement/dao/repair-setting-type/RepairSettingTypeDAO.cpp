#include "stdafx.h"
#include "RepairSettingTypeDAO.h"
#include <sstream>
#include "RepairSettingTypeMapper.h"

std::string RepairSettingDAO::RepairSettingTypeQuery_r_repair_setting_Builder(const RepairSettingGetQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	// 小区id，默认为111小区(2024022154856948)
	if (query->community_id)
	{
		sqlCondition << " AND r_s.`community_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue("2024022154856948"));
	}
	// 报修类型名称
	if (query->repair_type_name)
	{
		sqlCondition << " AND r_s.`repair_type_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_type_name.getValue(""));
	}
	// 派单方式 100 抢单 200 指派 300 轮训
	if (query->repair_way)
	{
		sqlCondition << " AND r_s.`repair_way`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_way.getValue("200"));
	}

	// 报修类型设置
	if (query->repair_setting_type)
	{
		sqlCondition << " AND r_s.`repair_setting_type`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_setting_type.getValue("200"));
	}

	// 区域
	if (query->public_area)
	{
		sqlCondition << " AND r_s.`public_area`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->public_area.getValue("F"));
	}

	// 是否回访 回访标识 001 都不回访 002 已评价不回访 003 都回访
	if (query->return_visit_flag)
	{
		sqlCondition << " AND r_s.`return_visit_flag`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->return_visit_flag.getValue("003"));
	}
	sqlCondition << " AND r_s.`status_cd`=\"0\"";
	return sqlCondition.str();
}

uint64_t RepairSettingDAO::RepairSettingTypecount(const RepairSettingGetQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM r_repair_setting r_s ";
	// 构建查询条件
	sql += RepairSettingTypeQuery_r_repair_setting_Builder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<RepairSettingDO> RepairSettingDAO::RepairSettingTypeSelect_r_repair_setting_WithPage(const RepairSettingGetQuery::Wrapper& query)
{
	SqlParams params;
	// 创建查询语句
	string sql = "SELECT \
        r_s.repair_type_name, \
        t_d_rst.description AS repair_setting_type, \
        t_d_rw.description AS repair_way, \
        t_d_pa.description AS public_area, \
        t_d_is.description AS is_show, \
        t_d_nw.description AS notify_way, \
        t_d_rvf.description AS return_visit_flag, \
        r_s.create_time \
        FROM r_repair_setting r_s \
        INNER JOIN t_dict t_d_rst \
        ON r_s.repair_setting_type = t_d_rst.status_cd AND 'repair_setting_type' = t_d_rst.table_columns AND 'r_repair_setting' = t_d_rst.table_name \
        INNER JOIN t_dict t_d_rw \
        ON r_s.repair_way = t_d_rw.status_cd AND 'repair_way' = t_d_rw.table_columns AND 'r_repair_setting' = t_d_rw.table_name \
        INNER JOIN t_dict t_d_pa \
        ON r_s.public_area = t_d_pa.status_cd AND 'public_area' = t_d_pa.table_columns AND 'r_repair_setting' = t_d_pa.table_name \
        INNER JOIN t_dict t_d_is \
        ON r_s.is_show = t_d_is.status_cd AND 'housekeeping_type' = t_d_is.table_name \
        INNER JOIN t_dict t_d_nw \
        ON r_s.notify_way = t_d_nw.status_cd AND 'owe_fee_callable' = t_d_nw.table_name \
        INNER JOIN t_dict t_d_rvf \
        ON r_s.return_visit_flag = t_d_rvf.status_cd AND 'return_visit_flag' = t_d_rvf.table_columns AND 'r_repair_setting' = t_d_rvf.table_name";
	// 构建查询条件
	sql += RepairSettingTypeQuery_r_repair_setting_Builder(query, params);
	// 构建排序语句（以创建时间排序）
	sql += " ORDER BY r_s.`create_time` DESC, r_s.community_id DESC";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// 执行查询
	RepairSettingMapper mapper;
	return sqlSession->executeQuery<RepairSettingDO>(sql, mapper, params);
}

int RepairSettingDAO::RepairSettingTypeAdd_r_repair_setting(const RepairSettingDO& iObj)
{
	string sql = "INSERT INTO `r_repair_setting` (`repair_type_name`,`repair_setting_type`,`repair_way`,`public_area`,`is_show`,`notify_way`,`return_visit_flag`,`community_id`,`remark`,`setting_id`,`repair_type`,`create_time`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s", \
		iObj.getRepairTypeName(),  iObj.getRepairSettingType(), \
		iObj.getRepairWay(), iObj.getPublicArea(), iObj.getIsShow(),\
		iObj.getNotifyWay(), iObj.getReturnVisitFlag(), \
		iObj.getCommunityId(), \
		iObj.getRemark(), iObj.getSettingId(), iObj.getRepairType(), iObj.getCreateTime());
}
int RepairSettingDAO::RepairSettingTypeModify_r_repair_setting(const RepairSettingDO& uObj)
{
	string sql = "UPDATE `r_repair_setting` SET `repair_type_name`=?, `repair_setting_type`=?, `repair_way`=?, `public_area`=?, `is_show`=?, `notify_way`=?, `return_visit_flag`=?, `remark`=? WHERE `setting_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s", \
		uObj.getRepairTypeName(), uObj.getRepairSettingType(), \
		uObj.getRepairWay(), uObj.getPublicArea(), uObj.getIsShow(), \
		uObj.getNotifyWay(), uObj.getReturnVisitFlag(), uObj.getRemark(), uObj.getSettingId());
}

int RepairSettingDAO::RepairSettingTypeDelete_r_repair_setting_ById(std::string id)
{
	string sql = "UPDATE `r_repair_setting` SET `status_cd`=1 WHERE `setting_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}