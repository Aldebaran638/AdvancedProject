#include "stdafx.h"
#include "detailDAO.h"
#include "detailMapper.h"
#include <sstream>

std::string detailDAO::queryConditionBuilder(const detailQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->fee_id) {
		sqlCondition << " AND fee_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_id.getValue(""));
	}
	if (query->cycle) {
		sqlCondition << " AND cycle=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cycle.getValue(""));
	}
	if (query->pay_path) {
		sqlCondition << " AND pay_path=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_path.getValue(""));
	}
	if (query->receivable_amount) {
		sqlCondition << " AND receivable_amount=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->receivable_amount.getValue(""));
	}
	if (query->amount) {
		sqlCondition << " AND amount=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->amount.getValue(""));
	}
	if (query->pay_time) {
		sqlCondition << " AND pay_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pay_time.getValue(""));
	}
	if (query->start_time) {
		sqlCondition << " AND start_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time) {
		sqlCondition << " AND end_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
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
	return sqlCondition.str();
}
PtrdetailDO detailDAO::selectById(std::string id)
{
	string sql = "SELECT pfd.detail_id,pfd.cycles,td1.`name` AS pay_type_name, pfd.receivable_amount,pfd.received_amount,pfd.create_time,pfd.start_time,pfd.end_time,pfd.cashier_name,td2.`name` AS state_name, pfd.remark FROM pay_fee_detail pfd JOIN t_dict td1 ON pfd.prime_rate = td1.status_cd AND td1.table_columns = 'pay_type' and table_name = 'parking_coupon_order' JOIN t_dict td2 ON pfd.state = td2.status_cd AND td2.table_name = 'pay_fee_detail' and td2.table_columns = 'state' WHERE pfd.detail_id = ? ";
	PtrdetailMapper mapper;
	return sqlSession->executeQueryOne<PtrdetailDO>(sql, mapper, "%s", id);
}