#include "stdafx.h"
#include "modifyDAO.h"
#include "modifyMapper.h"
#include <sstream>

std::string modifyDAO::queryConditionBuilder(const modifyQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->fee_id) {
		sqlCondition << " AND fee_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_id.getValue(""));
	}
	/*if (query->pay_time) {
		sqlCondition << " AND pay_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_time.getValue(""));
	}*/
	if (query->pay_start) {
		sqlCondition << " AND pay_start=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_start.getValue(""));
	}
	if (query->pay_end) {
		sqlCondition << " AND pay_end=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_end.getValue(""));
	}
	if (query->actions) {
		sqlCondition << " AND actions=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->actions.getValue(""));
	}
	if (query->oporator) {
		sqlCondition << " AND oporator=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->oporator.getValue(""));
	}
	if (query->opt_time) {
		sqlCondition << " AND opt_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->opt_time.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t modifyDAO::count(const modifyQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM pay_fee_detail";
	sql += queryConditionBuilder(query, params);
	return sqlSession->executeQueryNumerical(sql, params);
}
list<modifyDO> modifyDAO::selectById(const modifyQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "select pfd.fee_id,pfdm.fee_name,pfdm.obj_name,bpf.start_time,bpf.end_time,bpf.operate,pfd.cashier_name,bpf.create_time from business_pay_fee bpf,pay_fee_detail pfd,pay_fee_detail_month pfdm where pfd.fee_id=pfdm.fee_id AND pfd.fee_id=bpf.fee_id AND pfd.fee_id=?";
	sql += " ORDER BY IFNULL(pfd.b_id,'') DESC";
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	//params.push_back(query->fee_id);
	if (query->fee_id) {
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_id.getValue(""));
	}

	modifyMapper mapper;
	return sqlSession->executeQuery<modifyDO>(sql, mapper,params);
}
