#include "stdafx.h"
#include "RepairReportSummaryDAO.h"
#include "RepairReportSummaryMapper.h"
#include <sstream>


std::string RepairReportSummaryDAO::queryConditionBuilder(const RepairReportSummaryQuery::Wrapper& query, SqlParams& params)
{
	std::stringstream sqlCondition;
	sqlCondition << " WHERE 1=1 ";
	//查询条件
	if (query->createStartTime) {
		sqlCondition << " AND DATE(r.create_time) >= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->createStartTime.getValue(""));
	}
	if (query->createEndTime) {
		sqlCondition << " AND DATE(r.create_time) <= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->createEndTime.getValue(""));
	}
	if (query->finishStartTime) {
		sqlCondition << " AND DATE(r.end_time) >= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->finishStartTime.getValue(""));
	}
	if (query->finishEndTime) {
		sqlCondition << " AND DATE(r.end_time) <= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->finishEndTime.getValue(""));
	}
	if (query->communityName) {
		sqlCondition << " AND sc.name=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityName.getValue(""));
	}
	if (query->staffName) {
		sqlCondition << " AND u.name=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->staffName.getValue(""));
	}
	if (query->state) {
		sqlCondition << " AND status_cd=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
	}
	
	return sqlCondition.str();
}


std::list<RepairReportSummaryDO> RepairReportSummaryDAO::selectWithPage(const RepairReportSummaryQuery::Wrapper& query) {
	SqlParams params;
	
	string sql = " SELECT (@row_num := @row_num + 1) AS summaryId, r.staff_id AS staffId, u.name AS staffName,  "
		" SUM(CASE WHEN r.state = '10001' THEN 1 ELSE 0 END) AS deal, "
		" SUM(CASE WHEN r.state = '10006' THEN 1 ELSE 0 END) AS sendList, "
		" SUM(CASE WHEN r.state = '10004' THEN 1 ELSE 0 END) AS transferList, "
		" SUM(CASE WHEN r.state = '10003' THEN 1 ELSE 0 END) AS chargeback, "
		" SUM(CASE WHEN r.state = '10008' THEN 1 ELSE 0 END) AS returnVisit, "
		" SUM(CASE WHEN r.state = '10002' THEN 1 ELSE 0 END) AS finish, "
		" COALESCE(u.score, '0') AS examineValue "
		" FROM r_repair_user r "
		" INNER JOIN u_user u ON u.user_id = r.staff_id AND u.status_cd = '0' "
		" left join t_dict td on r.state = td.status_cd and td.table_name = 'r_repair_user' "
		" and td.table_columns = 'state' "
		" left join s_community sc on r.community_id = sc.community_id ,(SELECT @row_num := 0) AS init ";
		
		
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " GROUP BY r.staff_id, u.name, u.score ";
	sql += " ORDER BY staffId ASC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	RepairReportSummaryMapper mapper;
	return sqlSession->executeQuery<RepairReportSummaryDO>(sql, mapper, params);
}


uint64_t RepairReportSummaryDAO::count(const RepairReportSummaryQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT count(*) total"
		" FROM r_repair_user r "
		" INNER JOIN u_user u ON u.user_id = r.staff_id AND u.status_cd = '0' "
		" left join t_dict td on r.state = td.status_cd and td.table_name = 'r_repair_user' "
		" and td.table_columns = 'state' "
		" left join s_community sc on r.community_id = sc.community_id ";
	/*string sql = "SELECT COUNT(DISTINCT r.staff_id) AS totalCount FROM r_repair_user r "
		"INNER JOIN u_user u ON u.user_id = r.staff_id AND u.status_cd = '0' ";*/
		/*"WHERE r.status_cd = '0' AND r.staff_id != '-1'; ";*/
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}



