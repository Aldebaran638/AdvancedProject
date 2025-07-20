#include "stdafx.h"
#include "DepositReportDAO.h"
#include "DepositReportMapper.h"
#include <sstream>

uint64_t DepositReportDAO::count(const DepositReportQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*)";
	sql += "FROM ";
	sql += "business_pay_fee bpf ";
	sql += "LEFT JOIN ";
	sql += "community_location cl ON bpf.community_id = cl.community_id ";
	sql += "LEFT JOIN ";
	sql += "building_owner bo ON bpf.payer_obj_id = bo.b_id ";
	sql += "LEFT JOIN ";
	sql += "report_owe_fee rof ON bpf.fee_id = rof.fee_id ";
	sql += "LEFT JOIN ";
	sql += "pay_fee_detail pfd ON bpf.fee_id = pfd.fee_id ";
	sql += "LEFT JOIN ";
	sql += "return_pay_fee rpf ON bpf.payer_obj_id = rpf.b_id ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
std::string DepositReportDAO::queryConditionBuilder(const DepositReportQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->location_obj_name) {
		sqlCondition << " AND cl.location_obj_name=?";
		SQLPARAMS_PUSH(params, "s", string, query->location_obj_name.getValue(0));
	}
	if (query->fee_id) {
		sqlCondition << " AND bpf.fee_id=?";
		SQLPARAMS_PUSH(params, "s", string, query->fee_id.getValue(0));
	}
	if (query->fee_type_cd) {
		sqlCondition << " AND bpf.fee_type_cd=?";
		SQLPARAMS_PUSH(params, "s", string, query->fee_type_cd.getValue(""));
	}
	if (query->pay_state) {
		sqlCondition << " AND bpf.state=?";
		SQLPARAMS_PUSH(params, "s", string, query->pay_state.getValue(""));
	}
	if (query->income_obj_id) {
		sqlCondition << " AND bpf.income_obj_id=?";
		SQLPARAMS_PUSH(params, "s", string, query->income_obj_id.getValue(""));
	}
	if (query->start_time) {
		sqlCondition << " AND bpf.start_time=?";
		SQLPARAMS_PUSH(params, "s", string, query->start_time.getValue(""));
	}
	if (query->end_time) {
		sqlCondition << " AND bpf.end_time=?";
		SQLPARAMS_PUSH(params, "s", string, query->end_time.getValue(""));
	}
	if (query->return_state) {
		sqlCondition << " AND rpf.state=?";
		SQLPARAMS_PUSH(params, "s", string, query->return_state.getValue(""));
	}
	// sqlCondition << ";";
	return sqlCondition.str();
}

std::list<DepositReportDO> DepositReportDAO::selectWithPage(const DepositReportQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT ";
	sql += "bpf.fee_id, ";
	sql += "bpf.fee_type_cd, ";
	sql += "bpf.start_time, ";
	sql += "bpf.end_time, ";
	sql += "bpf.create_time, ";
	sql += "bpf.income_obj_id, ";
	sql += "bpf.payer_obj_id, ";
	sql += "bpf.state AS pay_state, ";
	sql += "bpf.community_id, ";
	sql += "cl.location_obj_name, ";
	sql += "bo.name AS owner_name, ";
	sql += "rof.config_name, ";
	sql += "pfd.receivable_amount, ";
	sql += "rpf.state AS return_state ";
	sql += "FROM ";
	sql += "business_pay_fee bpf ";
	sql += "LEFT JOIN ";
	sql += "community_location cl ON bpf.community_id = cl.community_id ";
	sql += "LEFT JOIN ";
	sql += "building_owner bo ON bpf.payer_obj_id = bo.b_id ";
	sql += "LEFT JOIN ";
	sql += "report_owe_fee rof ON bpf.fee_id = rof.fee_id ";
	sql += "LEFT JOIN ";
	sql += "pay_fee_detail pfd ON bpf.fee_id = pfd.fee_id ";
	sql += "LEFT JOIN ";	
	sql += "return_pay_fee rpf ON bpf.payer_obj_id = rpf.b_id ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY bpf.create_time DESC";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	DepositReportMapper mapper;
	return sqlSession->executeQuery<DepositReportDO>(sql, mapper, params);
}

std::list<DepositReportDO> DepositReportDAO::selectByCommunityId(const oatpp::String& community_id)
{
	string sql = "SELECT ";
	sql += "bpf.fee_id, ";
	sql += "bpf.fee_type_cd, ";
	sql += "bpf.start_time, ";
	sql += "bpf.end_time, ";
	sql += "bpf.create_time, ";
	sql += "bpf.income_obj_id, ";
	sql += "bpf.payer_obj_id, ";
	sql += "bpf.state AS pay_state, ";
	sql += "bpf.community_id, ";
	sql += "cl.location_obj_name, ";
	sql += "bo.name AS owner_name, ";
	sql += "rof.config_name, ";
	sql += "pfd.receivable_amount, ";
	sql += "rpf.state AS return_state ";
	sql += "FROM ";
	sql += "business_pay_fee bpf ";
	sql += "LEFT JOIN ";
	sql += "community_location cl ON bpf.community_id = cl.community_id ";
	sql += "LEFT JOIN ";
	sql += "building_owner bo ON bpf.payer_obj_id = bo.b_id ";
	sql += "LEFT JOIN ";
	sql += "report_owe_fee rof ON bpf.fee_id = rof.fee_id ";
	sql += "LEFT JOIN ";
	sql += "pay_fee_detail pfd ON bpf.fee_id = pfd.fee_id ";
	sql += "LEFT JOIN ";
	sql += "return_pay_fee rpf ON bpf.payer_obj_id = rpf.b_id ";
	sql +="WHERE bpf.community_id=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, community_id);
	DepositReportMapper mapper;
	return sqlSession->executeQuery<DepositReportDO, DepositReportMapper>(sql, mapper, params);
}