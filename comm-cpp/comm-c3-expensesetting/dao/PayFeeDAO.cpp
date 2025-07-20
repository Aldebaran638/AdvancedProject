#include "stdafx.h"
#include "PayFeeDAO.h"
#include "PayFeeMapper.h"
#include <sstream>

std::string PayFeeDAO::queryConditionBuilder(const PayFeeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->community_id) {

		sqlCondition << " AND `community_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	if (query->fee_type_cd) {

		sqlCondition << " AND `fee_type_cd`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_type_cd.getValue(""));
	}
	if (query->feeId) {

		sqlCondition << " AND `config_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->feeId.getValue(""));
	}
	if (query->chargeItem) {

		sqlCondition << " AND fee_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->chargeItem.getValue(""));
	}
	if (query->fee_flag) {

		sqlCondition << " AND fee_flag=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_flag.getValue(""));
	}
	if (query->payment_cd) {

		sqlCondition << " AND payment_cd=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->payment_cd.getValue(""));
	}
	if (query->deduct_from) {

		sqlCondition << " AND deduct_from=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->deduct_from.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t PayFeeDAO::count(const PayFeeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM pay_fee_config ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<PayFeeDO> PayFeeDAO::selectWithPage(const PayFeeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT config_id, fee_type_cd, fee_name, fee_flag, payment_cd, payment_cycle, start_time, end_time, computing_formula, square_price, additional_amount, deduct_from FROM pay_fee_config";



	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY IFNULL(`end_time`, `start_time`) DESC, `config_id` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	PayFeeMapper mapper;
	return sqlSession->executeQuery<PayFeeDO>(sql, mapper, params);
}

std::list<ChargeItemDO> PayFeeDAO::selectByType(std::string community_id, std::string feeType)
{
	string sql = "SELECT config_id, fee_type_cd, fee_name FROM pay_fee_config WHERE community_id=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, community_id);
	if (feeType != "default") {
		sql += " AND fee_type_cd=?";
		SQLPARAMS_PUSH(params, "s", std::string, feeType);
	}
	ChargeItemMapper mapper;
	return sqlSession->executeQuery<ChargeItemDO>(sql, mapper, params);

}