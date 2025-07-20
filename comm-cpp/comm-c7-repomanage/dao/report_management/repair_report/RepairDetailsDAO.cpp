#include "stdafx.h"
#include "RepairDetailsDAO.h"
#include "RepairDetailsMapper.h"
#include <sstream>
std::string RepairDetailsDAO::queryConditionBuilder(const RepairDetailsQuery::Wrapper& query, SqlParams& params)
{
	std::stringstream sqlCondition;

	SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	if (query->start_time)
	{
		sqlCondition << " and rp.create_time > ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time)
	{
		sqlCondition << " and rp.create_time < ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t RepairDetailsDAO::count(const RepairDetailsQuery::Wrapper& query)
{
	SqlParams params;
	string sql =
		"select count(*) "
		"from r_repair_user t	"
		"left join r_repair_pool rp on t.repair_id = rp.repair_id and rp.status_cd = '0' "
		"left join r_repair_setting rs on rp.repair_type = rs.repair_type and rs.status_cd = '0' "
		"left join t_dict td on td.table_name = 'r_repair_user' and td.table_columns = 'state' and td.status_cd = t.state "
		"left join t_dict td1 on td1.table_name = 'r_repair_pool' and td1.table_columns = 'state' and td1.status_cd = rp.state "
		"where t.status_cd = '0' "
		"and rp.repair_id is not null "
		"and t.community_id = ? ";

	//// 获取条件字符串，去掉开头的AND
	//std::string conditions = queryConditionBuilder(query, params);
	//if (!conditions.empty()) {
	//	// 如果条件不为空，直接拼接
	//	sql += conditions;
	//}
	sql += queryConditionBuilder(query, params);

	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

// 分页查询数据
std::list<RepairDetailsDO> RepairDetailsDAO::selectWithPage(const RepairDetailsQuery::Wrapper& query) {
	SqlParams params;
	std::string sql =
		"select t.repair_id '工单号', rs.repair_type_name '报修类型',	"
		"rp.repair_name '报修人', rp.repair_obj_name '报修位置', rp.tel '报修电话',  "
		"td1.`name` '工单状态', DATE_FORMAT(rp.create_time, '%Y-%m-%d %H:%i:%s') '报修时间', "
		"t.pre_staff_name '上一处理人',	t.staff_name '当前处理人', DATE_FORMAT(t.start_time, '%Y-%m-%d %H:%i:%s') '派单时间', "
		"DATE_FORMAT(t.end_time, '%Y-%m-%d %H:%i:%s') '处理时间', td.name '处理人状态',	"
		"rp.context '报修内容'	"
		"from r_repair_user t	"
		"left join r_repair_pool rp on t.repair_id = rp.repair_id and rp.status_cd = '0'	"
		"left join r_repair_setting rs on rp.repair_type = rs.repair_type and rs.status_cd = '0' "
		"left join t_dict td on td.table_name = 'r_repair_user' and td.table_columns = 'state' and td.status_cd = t.state "
		"left join t_dict td1 on td1.table_name = 'r_repair_pool' and td1.table_columns = 'state' and td1.status_cd = rp.state "
		"where t.status_cd = '0' "
		"and rp.repair_id is not null "
		"and t.community_id = ? ";

	//// 获取条件字符串，去掉开头的AND
	//std::string conditions = queryConditionBuilder(query, params);
	//if (!conditions.empty()) {
	//	// 如果条件不为空，直接拼接
	//	sql += conditions;
	//}
	sql += queryConditionBuilder(query, params);
	// 排序和分页
	
	sql += " ORDER BY t.repair_id, t.start_time desc ";
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	RepairDetailsMapper mapper;
	return sqlSession->executeQuery<RepairDetailsDO>(sql, mapper, params);
}


