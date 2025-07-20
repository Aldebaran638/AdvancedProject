#include "stdafx.h"
#include "RemitFeeDAO.h"
#include "RemitFeeMapper.h"
#include <sstream>

std::string RemitFeeDAO::queryConditionBuilder(const RemitFeeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->detail_id) {

		sqlCondition << " AND detail_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->detail_id.getValue(""));
	}
	if (query->receipt_id) {

		sqlCondition << " AND receipt_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->receipt_id.getValue(""));
	}
	if (query->pay_obj) {
		sqlCondition << " AND pay_obj=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_obj.getValue(""));
	}
	if (query->cycle) {
		sqlCondition << " AND cycle=?";
		SQLPARAMS_PUSH(params, "d", double, query->cycle.getValue(1.0));
	}
	if (query->receive_received) {
		sqlCondition << " AND receive_received=?";
		SQLPARAMS_PUSH(params, "s", string, query->receive_received.getValue(""));
	}

	if (query->pay_path) {
		sqlCondition << " AND pay_path=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_path.getValue(""));
	}
	if (query->pay_period) {
		sqlCondition << " AND pay_period=?";
		SQLPARAMS_PUSH(params, "s", string, query->pay_period.getValue(""));
	}
	if (query->pay_time) {
		sqlCondition << " AND pay_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_time.getValue(""));
	}
	if (query->receive_id) {
		sqlCondition << " AND receive_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->receive_id.getValue(""));
	}
	if (query->status_cd) {
		sqlCondition << " AND status_cd=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->status_cd.getValue(""));
	}
	if (query->remark) {
		sqlCondition << " AND remark=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->remark.getValue(""));
	}
	if (query->opt) {
		sqlCondition << " AND opt=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->opt.getValue(""));
	}
	/*if (query->age) {
	  
		sqlCondition << " AND age=?";
		SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0));
	}*/
	return sqlCondition.str();
}
uint64_t RemitFeeDAO::count(const RemitFeeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM pay_fee_detail";
	//构建查询条件
	sql += queryConditionBuilder(query, params);
	//执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<RemitFeeDO> RemitFeeDAO::selectWithPage(const RemitFeeQuery::Wrapper& query)
{
	SqlParams params;
	//pfd
	string sql = "select pfd.detail_id,pfdm.fee_name ,pfdm.obj_name ,pfd.cycles,pfd.receivable_amount,pfd.received_amount,td.`name`,pfd.start_time,pfd.end_time,pfd.create_time,pfd.cashier_name,pfb.msg,pfd.remark from pay_fee_detail pfd,pay_fee_detail_month pfdm,t_dict td,pay_fee_batch pfb where pfdm.detail_id=pfd.detail_id and pfd.prime_rate=td.status_cd and td.table_columns='pay_type' and pfd.status_cd=pfb.status_cd ";
	sql += "ORDER BY IFNULL(pfd.detail_id,0) DESC";
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	RemitFeeMapper mapper;
	return sqlSession->executeQuery<RemitFeeDO>(sql, mapper, params);

}