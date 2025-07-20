#include "stdafx.h"
#include "CarPaymentDAO.h"
#include "CarPaymentMapper.h"
#include <sstream>
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
// GetVehicleFeeDAO methods
//std::list<GetVehicleFeeDO> GetVehicleFeeDAO::selectByName(const string& name)
//{
//	string sql = "SELECT fee_flag,fee_type_cd,fee_name,owner_name,link FROM sample WHERE `owner_name` LIKE CONCAT('%',?,'%')";
//	GetVehicleFeeMapper mapper;
//	return sqlSession->executeQuery<GetVehicleFeeDO>(sql, mapper, "%s", name);
//}

PtrGetVehicleFeeDO GetVehicleFeeDAO::selectById(std::string id)
{
	string sql = "SELECT `pfdm`.`fee_id`, `pfd`.`cycles` AS `cycle`, `pfdm`.`receivable_amount`, `pfdm`.`received_amount`, `pfdm`.`pay_fee_time`, `pfdm`.`create_time`, `pfdm`.`deadline_time`, `pfd`.`cashier_name`, `pfdm`.`status_cd`, `pfd`.`remark` FROM `pay_fee_detail_month` AS `pfdm` INNER JOIN `pay_fee_detail` AS `pfd` ON `pfdm`.`detail_id` = `pfd`.`detail_id` WHERE `pfdm`.`month_id` = ?";
	PtrGetVehicleFeeMapper mapper;
	return sqlSession->executeQueryOne<PtrGetVehicleFeeDO>(sql, mapper, "%s", id);
}


// GetPaymentRecordsDAO methods
std::string GetPaymentRecordsDAO::queryConditionBuilder(const GetPaymentRecordsQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->fee_name) {

		sqlCondition << " AND fee_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_name.getValue(""));
	}
	if (query->value) {

		sqlCondition << " AND value=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->value.getValue(""));
	}
	if (query->create_time)
	{
		sqlCondition << " AND create_time=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue(""));
	}

	return sqlCondition.str();
}


uint64_t GetPaymentRecordsDAO::count(const GetPaymentRecordsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "select count(*) from pay_fee_detail_month pfdm join pay_fee_attrs pfa on pfdm.fee_id = pfa.fee_id AND pfdm.community_id = pfa.community_id";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<GetPaymentRecordsDO> GetPaymentRecordsDAO::selectWithPage(const GetPaymentRecordsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT `pfdm`.`fee_name`, `pfa`.`value`, `pfd`.`cycles` AS `cycle`, `pfdm`.`receivable_amount`, `pfdm`.`received_amount`, `pfdm`.`create_time`, `pfdm`.`pay_fee_time`, `pfd`.`cashier_name`, `pfdm`.`status_cd`, `pfd`.`remark` FROM `pay_fee_detail_month` AS `pfdm` INNER JOIN `pay_fee_detail` AS `pfd` ON `pfdm`.`detail_id` = `pfd`.`detail_id` INNER JOIN `pay_fee_attrs` AS `pfa` ON `pfdm`.`fee_id` = `pfa`.`fee_id` AND `pfdm`.`community_id` = `pfa`.`community_id`";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY IFNULL(`receivable_amount`, `create_time`) DESC, `fee_id` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	GetPaymentRecordsMapper mapper;
	return sqlSession->executeQuery<GetPaymentRecordsDO>(sql, mapper, params);
}


// GetPaymentDetailedRecordDAO methods
PtrGetPaymentDetailedRecordDO GetPaymentDetailedRecordDAO::selectById(std::string id)
{
	string sql = "SELECT `pfdm`.`fee_id`, `pfd`.`cycles` AS `cycle`, `pfdm`.`receivable_amount`, `pfdm`.`received_amount`, `pfdm`.`pay_fee_time`, `pfdm`.`create_time`, `pfdm`.`deadline_time`, `pfd`.`cashier_name`, `pfdm`.`status_cd`, `pfd`.`remark` FROM `pay_fee_detail_month` AS `pfdm` INNER JOIN `pay_fee_detail` AS `pfd` ON `pfdm`.`detail_id` = `pfd`.`detail_id` WHERE `pfdm`.`month_id` = ?";
	PtrGetPaymentDetailedRecordMapper mapper;
	return sqlSession->executeQueryOne<PtrGetPaymentDetailedRecordDO>(sql, mapper, "%s", id);
}

// GetFeeModificationRecordsDAO Methods
std::string GetFeeModificationRecordsDAO::queryConditionBuilder(const GetFeeModificationRecordsQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->fee_name) {

		sqlCondition << " AND fee_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_name.getValue(""));
	}
	return sqlCondition.str();
}

// GetFeeModificationRecordsDAO methods
uint64_t GetFeeModificationRecordsDAO::count(const GetFeeModificationRecordsQuery::Wrapper& query)
{
	SqlParams params;
	std::string sql = " SELECT COUNT(*) FROM pay_fee_detail_month pfdm LEFT JOIN pay_fee_audit pfa ON pfdm.fee_id = pfa.fee_id ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<GetFeeModificationRecordsDO> GetFeeModificationRecordsDAO::selectWithPage(const GetFeeModificationRecordsQuery::Wrapper& query)
{
	SqlParams params;
	std::string sql = "";

	// Join with pay_fee_detail_month to get fee_name and cur_month_time
	sql += "SELECT pfdm.fee_name, pfdm.create_time, pfdm.cur_month_time AS start_time, pfb.create_user_name FROM pay_fee_detail_month pfdm LEFT JOIN pay_fee pf ON pfdm.fee_id = pf.fee_id LEFT JOIN pay_fee_batch pfb ON pf.batch_id = pfb.batch_id ;";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY IFNULL(`fee_name`, `create_time`) DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	GetFeeModificationRecordsMapper mapper;
	return sqlSession->executeQuery<GetFeeModificationRecordsDO>(sql, mapper, params);
}

std::string CarPaymentDAO::queryConditionBuilder(const CarPaymentQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->payer_obj_id) {

		sqlCondition << " AND `payer_obj_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->payer_obj_id.getValue(""));
	}
	
	return sqlCondition.str();
}

uint64_t CarPaymentDAO::count(const CarPaymentQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM pay_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<Pay_FeeDO> CarPaymentDAO::selectWithPage(const CarPaymentQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT pfc.fee_name AS fee_name,pf.fee_flag,pf.fee_type_cd,pf.amount,pf.create_time,CONCAT(pf.start_time, ' - ', pf.end_time) AS rece_period,CONCAT('square_price: ', pfc.square_price, ',additional_price: ', pfc.additional_amount) AS description,pf.state FROM pay_fee pf JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY pf.create_time DESC";  // 明确指定表别名
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// 执行查询
	PayFeeMapper mapper;
	return sqlSession->executeQuery<Pay_FeeDO>(sql, mapper, params);
}
/*
std::list<Pay_FeeDO> CarPaymentDAO::selectById(const string& id)
{
	string sql = "SELECT pfc.fee_name AS fee_name,pf.flag,pf.fee_type_cd,pf.amount,pf.create_time,CONCAT(pf.start_time, ' - ', pf.end_time) AS rece_period,CONCAT('单价: ', pfc.square_price, ', 固定费: ', pfc.fixed_fee, ', 附加费: ', pfc.additional_amount) AS description,pf.state FROM pay_fee pf JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id  WHERE `pf.payer_obj_id` = ?";
	PayFeeMapper mapper;
	return sqlSession->executeQuery<Pay_FeeDO>(sql, mapper, "%s", id);
}
*/
int CarPaymentDAO::insert(const Pay_FeeDO& iObj)
{
	string sql = "INSERT INTO `pay_fee` (`fee_id`, `b_id`, `fee_type_cd`, `community_id`, `payer_obj_id`, `income_obj_id`, "
		"`start_time`, `end_time`, `amount`, `user_id`, `create_time`, `status_cd`, `fee_flag`, `state`, "
		"`config_id`, `payer_obj_type`, `batch_id`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%d%s%s%s%s%s%s%s%s",iObj.getFeeId(), iObj.getBId(),iObj.getFeeTypeCd(),	iObj.getCommunityId(),	iObj.getPayerObjId(),iObj.getIncomeObjId(),iObj.getStartTime(),	iObj.getEndTime(),iObj.getAmount(),	iObj.getUserId(),iObj.getCreateTime(),iObj.getStatusCd(),iObj.getFeeFlag(),iObj.getState(),iObj.getConfigId(),iObj.getPayerObjType(),	iObj.getBatchId());
}
/*
int CarPaymentDAO::insert(const Pay_Fee_ConfigDO& iObj)
{
	string sql = "INSERT INTO `pay_fee_config` (`config_id`, `b_id`, `community_id`, `fee_type_cd`, `square_price`, "
		"`additional_amount`, `create_time`, `status_cd`, `is_default`, `start_time`, `end_time`, `fee_flag`, "
		"`fee_name`, `computing_formula`, `bill_type`, `payment_cycle`, `payment_cd`, `computing_formula_text`, "
		"`deduct_from`, `pay_online`, `scale`, `decimal_place`, `units`, `prepayment_period`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%f%f%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s",
		iObj.getConfigId(),
		iObj.getBId(),
		iObj.getCommunityId(),
		iObj.getFeeTypeCd(),
		iObj.getSquarePrice(),
		iObj.getAdditionalAmount(),
		iObj.getCreateTime(),
		iObj.getStatusCd(),
		iObj.getIsDefault(),
		iObj.getStartTime(),
		iObj.getEndTime(),
		iObj.getFeeFlag(),
		iObj.getFeeName(),
		iObj.getComputingFormula(),
		iObj.getBillType(),
		iObj.getPaymentCycle(),
		iObj.getPaymentCd(),
		iObj.getComputingFormulaText(),
		iObj.getDeductFrom(),
		iObj.getPayOnline(),
		iObj.getScale(),
		iObj.getDecimalPlace(),
		iObj.getUnits(),
		iObj.getPrepaymentPeriod());
}
int CarPaymentDAO::insert(const Business_Pay_FeeDO& iObj)
{
	string sql = "INSERT INTO `business_pay_fee` (`fee_id`, `b_id`, `fee_type_cd`, `community_id`, `payer_obj_id`, `income_obj_id`, "
		"`start_time`, `end_time`, `amount`, `user_id`, `create_time`, `operate`, `fee_flag`, `state`, "
		"`config_id`, `payer_obj_type`, `batch_id`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%f%s%s%s%s%s%s%s%s",
		iObj.getFeeId(),
		iObj.getBId(),
		iObj.getFeeTypeCd(),
		iObj.getCommunityId(),
		iObj.getPayerObjId(),
		iObj.getIncomeObjId(),
		iObj.getStartTime(),
		iObj.getEndTime(),
		iObj.getAmount(),
		iObj.getUserId(),
		iObj.getCreateTime(),
		iObj.getOperate(),
		iObj.getFeeFlag(),
		iObj.getState(),
		iObj.getConfigId(),
		iObj.getPayerObjType(),
		iObj.getBatchId());
}
int CarPaymentDAO::insert(const Business_Pay_Fee_ConfigDO& iObj)
{
	string sql = "INSERT INTO `business_pay_fee_config` (`config_id`, `b_id`, `community_id`, `fee_type_cd`, `square_price`, "
		"`additional_amount`, `create_time`, `operate`, `is_default`, `start_time`, `end_time`, `fee_flag`, "
		"`fee_name`, `computing_formula`, `bill_type`, `payment_cycle`, `payment_cd`, `computing_formula_text`, "
		"`deduct_from`, `units`, `decimal_place`, `scale`, `pay_online`, `prepayment_period`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%f%f%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s",
		iObj.getConfigId(),
		iObj.getBId(),
		iObj.getCommunityId(),
		iObj.getFeeTypeCd(),
		iObj.getSquarePrice(),
		iObj.getAdditionalAmount(),
		iObj.getCreateTime(),
		iObj.getOperate(),
		iObj.getIsDefault(),
		iObj.getStartTime(),
		iObj.getEndTime(),
		iObj.getFeeFlag(),
		iObj.getFeeName(),
		iObj.getComputingFormula(),
		iObj.getBillType(),
		iObj.getPaymentCycle(),
		iObj.getPaymentCd(),
		iObj.getComputingFormulaText(),
		iObj.getDeductFrom(),
		iObj.getUnits(),
		iObj.getDecimalPlace(),
		iObj.getScale(),
		iObj.getPayOnline(),
		iObj.getPrepaymentPeriod());
}
int CarPaymentDAO::insert(const Report_Owe_FeeDO& iObj)
{
	string sql = "INSERT INTO `report_owe_fee` ("
		"`owe_id`, `config_id`, `config_name`, `fee_id`, `fee_name`, "
		"`amount_owed`, `owner_id`, `owner_name`, `owner_tel`, "
		"`payer_obj_id`, `payer_obj_name`, `payer_obj_type`, "
		"`community_id`, `create_time`, `update_time`, "
		"`end_time`, `deadline_time`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql,
		"%s%s%s%s%s%f%s%s%s%s%s%s%s%s%s%s%s", 
		iObj.getOweId(),          // owe_id
		iObj.getConfigId(),       // config_id
		iObj.getConfigName(),     // config_name
		iObj.getFeeId(),          // fee_id
		iObj.getFeeName(),        // fee_name
		iObj.getAmountOwed(),     // amount_owed (decimal 用 %f)
		iObj.getOwnerId(),        // owner_id
		iObj.getOwnerName(),      // owner_name
		iObj.getOwnerTel(),       // owner_tel
		iObj.getPayerObjId(),     // payer_obj_id
		iObj.getPayerObjName(),   // payer_obj_name
		iObj.getPayerObjType(),   // payer_obj_type
		iObj.getCommunityId(),    // community_id
		iObj.getCreateTime(),     // create_time
		iObj.getUpdateTime(),     // update_time
		iObj.getEndTime(),        // end_time
		iObj.getDeadlineTime()    // deadline_time
	);
}
*/
int CarPaymentDAO::update(const Pay_FeeDO& uObj)
{
	string sql = "UPDATE `pay_fee` SET "
		"`b_id`=?, `fee_type_cd`=?, `community_id`=?, `payer_obj_id`=?, `income_obj_id`=?, "
		"`start_time`=?, `end_time`=?, `amount`=?, `user_id`=?,`create_time`=?, `status_cd`=?, `fee_flag`=?, `state`=?, "
		"`config_id`=?, `payer_obj_type`=?, `batch_id`=? "
		"WHERE `fee_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%d%s%s%s%s%s%s%s%s%s",
		uObj.getBId(),
		uObj.getFeeTypeCd(),
		uObj.getCommunityId(),
		uObj.getPayerObjId(),
		uObj.getIncomeObjId(),
		uObj.getStartTime(),
		uObj.getEndTime(),
		uObj.getAmount(),
		uObj.getUserId(),
		uObj.getCreateTime(),
		uObj.getStatusCd(),
		uObj.getFeeFlag(),
		uObj.getState(),
		uObj.getConfigId(),
		uObj.getPayerObjType(),
		uObj.getBatchId(),
		uObj.getFeeId());
}
/*
int CarPaymentDAO::update(const Pay_Fee_ConfigDO& uObj)
{
	string sql = "UPDATE `pay_fee_config` SET "
		"`b_id`=?, `community_id`=?, `fee_type_cd`=?, `square_price`=?, `additional_amount`=?, "
		"`status_cd`=?, `is_default`=?, `start_time`=?, `end_time`=?, `fee_flag`=?, `fee_name`=?, "
		"`computing_formula`=?, `bill_type`=?, `payment_cycle`=?, `payment_cd`=?, "
		"`computing_formula_text`=?, `deduct_from`=?, `pay_online`=?, `scale`=?, "
		"`decimal_place`=?, `units`=?, `prepayment_period`=? "
		"WHERE `config_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%f%f%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s",
		uObj.getBId(),
		uObj.getCommunityId(),
		uObj.getFeeTypeCd(),
		uObj.getSquarePrice(),
		uObj.getAdditionalAmount(),
		uObj.getStatusCd(),
		uObj.getIsDefault(),
		uObj.getStartTime(),
		uObj.getEndTime(),
		uObj.getFeeFlag(),
		uObj.getFeeName(),
		uObj.getComputingFormula(),
		uObj.getBillType(),
		uObj.getPaymentCycle(),
		uObj.getPaymentCd(),
		uObj.getComputingFormulaText(),
		uObj.getDeductFrom(),
		uObj.getPayOnline(),
		uObj.getScale(),
		uObj.getDecimalPlace(),
		uObj.getUnits(),
		uObj.getPrepaymentPeriod(),
		uObj.getConfigId());
}
int CarPaymentDAO::update(const Business_Pay_FeeDO& uObj)
{
	string sql = "UPDATE `business_pay_fee` SET "
		"`b_id`=?, `fee_type_cd`=?, `community_id`=?, `payer_obj_id`=?, `income_obj_id`=?, "
		"`start_time`=?, `end_time`=?, `amount`=?, `user_id`=?, `operate`=?, `fee_flag`=?, `state`=?, "
		"`config_id`=?, `payer_obj_type`=?, `batch_id`=? "
		"WHERE `fee_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%f%s%s%s%s%s%s%s%s",
		uObj.getBId(),
		uObj.getFeeTypeCd(),
		uObj.getCommunityId(),
		uObj.getPayerObjId(),
		uObj.getIncomeObjId(),
		uObj.getStartTime(),
		uObj.getEndTime(),
		uObj.getAmount(),
		uObj.getUserId(),
		uObj.getOperate(),
		uObj.getFeeFlag(),
		uObj.getState(),
		uObj.getConfigId(),
		uObj.getPayerObjType(),
		uObj.getBatchId(),
		uObj.getFeeId());
}

int CarPaymentDAO::update(const Business_Pay_Fee_ConfigDO& uObj)
{
	string sql = "UPDATE `business_pay_fee_config` SET "
		"`b_id`=?, `community_id`=?, `fee_type_cd`=?, `square_price`=?, `additional_amount`=?, "
		"`operate`=?, `is_default`=?, `start_time`=?, `end_time`=?, `fee_flag`=?, `fee_name`=?, "
		"`computing_formula`=?, `bill_type`=?, `payment_cycle`=?, `payment_cd`=?, "
		"`computing_formula_text`=?, `deduct_from`=?, `units`=?, `decimal_place`=?, `scale`=?, "
		"`pay_online`=?, `prepayment_period`=? "
		"WHERE `config_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%f%f%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s",
		uObj.getBId(),
		uObj.getCommunityId(),
		uObj.getFeeTypeCd(),
		uObj.getSquarePrice(),
		uObj.getAdditionalAmount(),
		uObj.getOperate(),
		uObj.getIsDefault(),
		uObj.getStartTime(),
		uObj.getEndTime(),
		uObj.getFeeFlag(),
		uObj.getFeeName(),
		uObj.getComputingFormula(),
		uObj.getBillType(),
		uObj.getPaymentCycle(),
		uObj.getPaymentCd(),
		uObj.getComputingFormulaText(),
		uObj.getDeductFrom(),
		uObj.getUnits(),
		uObj.getDecimalPlace(),
		uObj.getScale(),
		uObj.getPayOnline(),
		uObj.getPrepaymentPeriod(),
		uObj.getConfigId());
}

int CarPaymentDAO::update(const Report_Owe_FeeDO& uObj)
{
	string sql = "UPDATE `report_owe_fee` SET "
		"`config_id`=?, `config_name`=?, `fee_id`=?, `fee_name`=?, `amount_owed`=?, "
		"`owner_id`=?, `owner_name`=?, `owner_tel`=?, `payer_obj_id`=?, `payer_obj_name`=?, "
		"`payer_obj_type`=?, `community_id`=?, `update_time`=?, `end_time`=?, `deadline_time`=? "
		"WHERE `owe_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%f%s%s%s%s%s%s%s%s%s%s%s",
		uObj.getConfigId(),
		uObj.getConfigName(),
		uObj.getFeeId(),
		uObj.getFeeName(),
		uObj.getAmountOwed(),
		uObj.getOwnerId(),
		uObj.getOwnerName(),
		uObj.getOwnerTel(),
		uObj.getPayerObjId(),
		uObj.getPayerObjName(),
		uObj.getPayerObjType(),
		uObj.getCommunityId(),
		uObj.getUpdateTime(),
		uObj.getEndTime(),
		uObj.getDeadlineTime(),
		uObj.getOweId());
}
*/
int CarPaymentDAO::update(const PtrReport_Owe_FeeDO& uObj)
{
	string sql = "UPDATE `report_owe_fee` SET "
		"`config_id`=?, `config_name`=?, `fee_id`=?, `fee_name`=?, `amount_owed`=?, "
		"`owner_id`=?, `owner_name`=?, `owner_tel`=?, `payer_obj_id`=?, `payer_obj_name`=?, "
		"`payer_obj_type`=?, `community_id`=?,`create_time`=?, `update_time`=?, `end_time`=?, `deadline_time`=? "
		"WHERE `owe_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%d%s%s%s%s%s%s%s%s%s%s%s%s",
		uObj->getConfigId(),
		uObj->getConfigName(),
		uObj->getFeeId(),
		uObj->getFeeName(),
		uObj->getAmountOwed(),
		uObj->getOwnerId(),
		uObj->getOwnerName(),
		uObj->getOwnerTel(),
		uObj->getPayerObjId(),
		uObj->getPayerObjName(),
		uObj->getPayerObjType(),
		uObj->getCommunityId(),
		uObj->getCreateTime(),
		uObj->getUpdateTime(),
		uObj->getEndTime(),
		uObj->getDeadlineTime(),
		uObj->getOweId());
}



/*
int CarPaymentDAO::deleteByIds(const CarPaymentDTO::Wrapper& dto)
{
	int totalAffected = 0;

	//try {
		// 1. 删除 pay_fee 表中的记录（使用 feeId）
		string sql1 = "DELETE FROM `pay_fee` WHERE `fee_id`=?";
		int result1 = sqlSession->executeUpdate(sql1, "%s", dto->fee_id);
		totalAffected += result1;

		
		/*
		// 2. 删除 pay_fee_config 表中的记录（使用 configId）
		string sql2 = "DELETE FROM `pay_fee_config` WHERE `config_id`=?";
		int result2 = sqlSession->executeUpdate(sql2, "%s", dto->fee_item_id);
		totalAffected += result2;

		// 3. 删除 report_owe_fee 表中的记录（使用 oweId）
		string sql3 = "DELETE FROM `report_owe_fee` WHERE `owe_id`=?";
		int result3 = sqlSession->executeUpdate(sql3, "%s", dto->owe_id);
		totalAffected += result3;
		
		return totalAffected;
	//}
		/*
	catch (const std::exception& e) {
		// 记录错误日志
		std::cerr << "Delete operation failed: " << e.what() << std::endl;
		return -1; // 返回错误代码
	}
}
/*
int CarPaymentDAO::deleteOweByIds(const CarPaymentDTO::Wrapper& dto)
{
	string sql3 = "DELETE FROM `report_owe_fee` WHERE `owe_id`=?";
	int result3 = sqlSession->executeUpdate(sql3, "%s", dto->owe_id);
	return result3;
}*/

int CarPaymentDAO::deleteById(std::string id)
{
	string sql1 = "DELETE FROM `pay_fee` WHERE `fee_id`=?";
	return sqlSession->executeUpdate(sql1, "%s", id);
}

PtrPay_FeeDO CarPaymentDAO::queryPayFeeById(const std::string& feeId) {
	string sql = "SELECT * FROM `pay_fee` WHERE `fee_id`=?";
	PtrPayFeeMapper mapper;
	return sqlSession->executeQueryOne<PtrPay_FeeDO>(sql, mapper, "%s", feeId);
	
}

PtrPay_Fee_ConfigDO CarPaymentDAO::queryPayFeeConfigById(const std::string& configId) {
	string sql = "SELECT * FROM `pay_fee_config` WHERE `config_id`=?";
	PtrPayFeeConfigMapper mapper;
	return sqlSession->executeQueryOne<PtrPay_Fee_ConfigDO>(sql, mapper, "%s", configId);
}

PtrReport_Owe_FeeDO CarPaymentDAO::queryOweFeeById(const std::string& oweId) {
	string sql = "SELECT * FROM `report_owe_fee` WHERE `owe_id`=?";
	PtrReportOweFeeMapper mapper;
	return  sqlSession->executeQueryOne<PtrReport_Owe_FeeDO>(sql, mapper, "%s", oweId);
	
}
/*
int CarPaymentDAO::deleteById2(std::string config_id)
{
	string sql = "DELETE FROM `report_owe_fee` WHERE `config_id`=?";
	int result = sqlSession->executeUpdate(sql, "%s", config_id);
	return result;
}
*/