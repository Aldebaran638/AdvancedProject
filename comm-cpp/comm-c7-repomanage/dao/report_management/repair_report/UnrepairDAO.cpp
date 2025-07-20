#include "stdafx.h"
#include "UnrepairDAO.h"
#include "UnrepairMapper.h"
#include <sstream>
//#include <service/report_management/repair_report/UnrepairService.h>
std::string UnrepairDAO::queryConditionBuilder(const UnrepairQuery::Wrapper& query, SqlParams& params)
{
	std::stringstream sqlCondition;

	// 处理开始时间和结束时间都存在的情况
	if (query->createTime && query->endTime) {
		sqlCondition << " AND DATE(r.create_time) BETWEEN DATE(STR_TO_DATE(?, '%Y-%m-%d')) AND DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->createTime.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->endTime.getValue(""));
	}
	// 处理开始时间存在和结束时间不存在的情况
	else if (query->createTime) {
		sqlCondition << " AND DATE(r.create_time) >= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->createTime.getValue(""));
	}
	// 处理开始时间不存在和结束时间存在的情况
	else if (query->endTime) {
		sqlCondition << " AND DATE(r.create_time) <= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->endTime.getValue(""));
	}
	// 处理开始时间和结束时间都不存在的情况
	else if (!query->createTime && !query->endTime) {
		sqlCondition << " AND 1 ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	return sqlCondition.str();
}

// 分页查询数据
std::list<UnrepairDO> UnrepairDAO::selectWithPage(const UnrepairQuery::Wrapper& query) {
	SqlParams params;
	std::string sql =
		"SELECT r.repair_id '订单号',r.create_time '报修日期', "
		"r.repair_name '报修人', r.tel '报修电话', r.repair_obj_name '报修位置',ru.staff_name '当前处理人', "
		"DATE_FORMAT(ru.start_time, '%Y-%m-%d %H:%i:%s') '结单时间', td.`name` '订单状态' "
		"from r_repair_pool r "
		"left join r_repair_user ru on r.repair_id = ru.repair_id and ru.status_cd = '0' and ru.state = '10001' "
		"left join t_dict td on r.state = td.status_cd and td.table_name = 'r_repair_pool' and td.table_columns = 'state' "
		"WHERE r.community_id = ?  "
		"AND r.state in(1000, 1100, 1200, 1300, 1400, 1500) ";

	// 获取条件字符串，去掉开头的AND
	std::string conditions = queryConditionBuilder(query, params);
	if (!conditions.empty()) {
		// 如果条件不为空，直接拼接
		sql += conditions;
	}
	// 排序和分页
	sql += " ORDER BY r.create_time desc ";
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	UnrepairMapper mapper;
	return sqlSession->executeQuery<UnrepairDO>(sql, mapper, params);
}
uint64_t UnrepairDAO::count(const UnrepairQuery::Wrapper& query)
{
	SqlParams params;
	string sql =
		"SELECT count(1) total "
		"from r_repair_pool r "
		"left join r_repair_user ru on r.repair_id = ru.repair_id and ru.status_cd = '0' and ru.state = '10001' "
		"left join t_dict td on r.state = td.status_cd and td.table_name = 'r_repair_pool' and td.table_columns = 'state' "
		"WHERE r.community_id = ?  "
		"AND r.state in(1000, 1100, 1200, 1300, 1400, 1500) ";

	// 获取条件字符串，去掉开头的AND
	std::string conditions = queryConditionBuilder(query, params);
	if (!conditions.empty()) {
		// 如果条件不为空，直接拼接
		sql += conditions;
	}

	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}