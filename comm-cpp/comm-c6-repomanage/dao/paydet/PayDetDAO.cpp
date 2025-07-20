#include "stdafx.h"
#include "PayDetDAO.h"
#include "PayDetMapper.h"
#include <sstream>

//缴费明细实现
std::string PayDetDAO::queryConditionBuilder(const oatpp::Object<GetPaydetQuery>& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE t.status_cd = '0' AND pf.status_cd = '0' AND t.state != '1500'";

	if (query->paymentStartTime) {
		sqlCondition << " AND t.paymentStartTime = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->paymentStartTime.getValue(""));
	}
	if (query->paymentEndTime) {
		sqlCondition << " AND t.paymentEndTime = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->paymentEndTime.getValue(""));
	}
	if (query->paymentMethod) {
		sqlCondition << " AND t.payment_method = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->paymentMethod.getValue(""));
	}
	if (query->expenseStatus) {
		sqlCondition << " AND t.expenseStatus = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->expenseStatus.getValue(""));
	}
	if (query->houseOrPlateNumber) {
		sqlCondition << " AND t.houseOrPlateNumber = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->houseOrPlateNumber.getValue(""));
	}
	if (query->expenseType) {
		sqlCondition << " AND t.expenseType = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->expenseType.getValue(""));
	}
	if (query->chargeItem) {
		sqlCondition << " AND t.chargeItem = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->chargeItem.getValue(""));
	}
	if (query->chargeStartTime) {
		sqlCondition << " AND t.chargeStartTime = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->chargeStartTime.getValue(""));
	}
	if (query->chargeEndTime) {
		sqlCondition << " AND t.chargeEndTime = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->chargeEndTime.getValue(""));
	}

	return sqlCondition.str();
}

uint64_t PayDetDAO::count(const oatpp::Object<GetPaydetQuery>& query)
{
	SqlParams params;
	string sql = "SELECT "
		"count( 1 ) count, "
		"SUM( t.received_amount ) totalReceivedAmount, "
		"SUM( t.receivable_amount ) totalReceivableAmount, "
		"sum( t.acct_amount ) accAmount, "
		"sum( t.discount_amount ) discountAmount, "
		"sum( t.deduction_amount ) deductionAmount, "
		"sum( t.late_amount ) lateAmount, "
		"sum( t.gift_amount ) giftAmount "
		"FROM "
		"pay_fee_detail t "
		"LEFT JOIN pay_fee pf ON t.fee_id = pf.fee_id "
		"AND pf.status_cd = '0' "
		"LEFT JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id "
		"AND pfc.status_cd = '0' "
		"WHERE "
		"t.status_cd = '0' "
		"AND pf.status_cd = '0' "
		"AND t.state != '1500' ";

	// 构建查询条件
	sql += queryConditionBuilder(query, params);

	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<PayDetDO> PayDetDAO::selectWithPage(const oatpp::Object<GetPaydetQuery>& query)
{
	SqlParams params;
	string sql = "SELECT "
		"count( 1 ) count, "
		"SUM( t.received_amount ) totalReceivedAmount, "
		"SUM( t.receivable_amount ) totalReceivableAmount, "
		"sum( t.acct_amount ) accAmount, "
		"sum( t.discount_amount ) discountAmount, "
		"sum( t.deduction_amount ) deductionAmount, "
		"sum( t.late_amount ) lateAmount, "
		"sum( t.gift_amount ) giftAmount "
		"FROM "
		"pay_fee_detail t "
		"LEFT JOIN pay_fee pf ON t.fee_id = pf.fee_id "
		"AND pf.status_cd = '0' "
		"LEFT JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id "
		"AND pfc.status_cd = '0' "
		"WHERE "
		"t.status_cd = '0' "
		"AND pf.status_cd = '0' "
		"AND t.state != '1500' ";

	// 构建查询条件
	sql += queryConditionBuilder(query, params);


	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	PayDetMapper mapper;

	return sqlSession->executeQuery<PayDetDO>(sql, mapper, params);
}
