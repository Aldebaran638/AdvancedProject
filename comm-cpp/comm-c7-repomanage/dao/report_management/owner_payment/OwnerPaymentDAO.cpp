#include "stdafx.h"
#include "OwnerPaymentDAO.h"
#include "OwnerPaymentMapper.h"
#include <sstream>


std::string OwnerPaymentDAO::queryConditionBuilder(const OwnerPaymentQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " and 1=1 ";
	if (query->ownerName) {

		sqlCondition << " and pfa1.value=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
	}
	if (query->feeTypeCd) {

		sqlCondition << " and td.name=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->feeTypeCd.getValue(""));
	}
	if (query->configName) {

		sqlCondition << " and pfc.fee_name=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->configName.getValue(""));
	}
	if (query->pfYear) {

		sqlCondition << " and pfdm.detail_year=? ";
		SQLPARAMS_PUSH(params, "i", int, query->pfYear.getValue(0));
	}
	if (query->roomName) {

		sqlCondition << " and concat(ff.floor_num, '-', bu.unit_num, '-', br.room_num)=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->roomName.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t OwnerPaymentDAO::count(const OwnerPaymentQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "select count(1) count "
		"from pay_fee t "
		"inner join pay_fee_attrs pfa on t.fee_id = pfa.fee_id and pfa.community_id = t.community_id and pfa.spec_cd = '390007' and pfa.status_cd = '0' "
		"inner join pay_fee_attrs pfa1 on t.fee_id = pfa1.fee_id and pfa1.community_id = t.community_id and pfa1.spec_cd = '390008' and pfa1.status_cd = '0' "
		"left join pay_fee_attrs pfa2 on t.fee_id = pfa2.fee_id and pfa2.community_id = t.community_id and pfa2.spec_cd = '390002' and pfa2.status_cd = '0' "
		"inner join pay_fee_config pfc on t.config_id = pfc.config_id and pfc.community_id = t.community_id and pfc.status_cd = '0' "
		"inner join pay_fee_detail pfd on t.fee_id = pfd.fee_id and pfd.community_id = t.community_id and pfd.status_cd = '0' "
		"inner join pay_fee_detail_month pfdm on t.fee_id = pfdm.fee_id and pfdm.community_id = t.community_id and pfdm.status_cd = '0' and pfd.detail_id = pfdm.detail_id "
		"inner join t_dict td on td.status_cd = t.fee_type_cd "
		"LEFT JOIN building_room br on t.payer_obj_id = br.room_id and t.payer_obj_type = '3333' and br.status_cd = '0' "
		"LEFT JOIN building_unit bu on br.unit_id = bu.unit_id and bu.status_cd = '0' "
		"LEFT JOIN f_floor ff on bu.floor_id = ff.floor_id and ff.status_cd = '0' "
		"left join owner_car oc on t.payer_obj_id = oc.car_id and t.payer_obj_type = '6666' and oc.status_cd = '0' and oc.car_type_cd='1001' "
		"left join contract con on t.payer_obj_id = con.contract_id and t.payer_obj_type = '7777' and con.status_cd = '0' "
		"where 1 = 1 "
		"and t.end_time > '2000-01-01' "
		"and t.status_cd = '0' ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<OwnerPaymentDO> OwnerPaymentDAO::selectWithPage(const OwnerPaymentQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "select t.community_id communityId,pfa.value ownerId, pfa1.value ownerName,pfc.fee_name feeName,pfa2.value importFeeName,t.config_id configId,t.fee_id feeId, "
		"concat(ff.floor_num, '-', bu.unit_num, '-', br.room_num) roomName, t.payer_obj_type payerObjType, oc.car_num carNum,con.contract_code contractCode, "
		"pfd.receivable_amount receivableAmount, pfd.received_amount receivedAmount, pfd.payable_amount payableAmount, pfdm.detail_year detailYear, pfdm.detail_month detailMonth,td.name "
		"from pay_fee t "
		"inner join pay_fee_attrs pfa on t.fee_id = pfa.fee_id and pfa.community_id = t.community_id and pfa.spec_cd = '390007' and pfa.status_cd = '0' "
		"inner join pay_fee_attrs pfa1 on t.fee_id = pfa1.fee_id and pfa1.community_id = t.community_id and pfa1.spec_cd = '390008' and pfa1.status_cd = '0' "
		"left join pay_fee_attrs pfa2 on t.fee_id = pfa2.fee_id and pfa2.community_id = t.community_id and pfa2.spec_cd = '390002' and pfa2.status_cd = '0' "
		"inner join pay_fee_config pfc on t.config_id = pfc.config_id and pfc.community_id = t.community_id and pfc.status_cd = '0' "
		"inner join pay_fee_detail pfd on t.fee_id = pfd.fee_id and pfd.community_id = t.community_id and pfd.status_cd = '0' "
		"inner join pay_fee_detail_month pfdm on t.fee_id = pfdm.fee_id and pfdm.community_id = t.community_id and pfdm.status_cd = '0' and pfd.detail_id = pfdm.detail_id "
		"inner join t_dict td on td.status_cd = t.fee_type_cd "
		"left join building_room br on t.payer_obj_id = br.room_id and t.payer_obj_type = '3333' and br.status_cd = '0' "
		"left join building_unit bu on br.unit_id = bu.unit_id and bu.status_cd = '0' "
		"left join f_floor ff on bu.floor_id = ff.floor_id and ff.status_cd = '0' "
		"left join owner_car oc on t.payer_obj_id = oc.car_id and t.payer_obj_type = '6666' and oc.status_cd = '0' and oc.car_type_cd='1001' "
		"left join contract con on t.payer_obj_id = con.contract_id and t.payer_obj_type = '7777' and con.status_cd = '0' "
		"where 1 = 1 "
		"and t.end_time > '2000-01-01' "
		"and t.status_cd = '0' ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += "order by t.create_time desc ";
	// 构建分页条件
	if (query->pageIndex > 0 && query->pageSize > 0) {
		sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	}
	std::cout << " " + sql << std::endl;
	// 执行查询
	OwnerPaymentMapper mapper;
	return sqlSession->executeQuery<OwnerPaymentDO>(sql, mapper, params);
}

std::list<OwnerPaymentDO> OwnerPaymentDAO::listAllDO()
{
	string sql = "select t.community_id communityId,pfa.value ownerId, pfa1.value ownerName,pfc.fee_name feeName,pfa2.value importFeeName,t.config_id configId,t.fee_id feeId, "
		"concat(ff.floor_num, '-', bu.unit_num, '-', br.room_num) roomName, t.payer_obj_type payerObjType, oc.car_num carNum,con.contract_code contractCode, "
		"pfd.receivable_amount receivableAmount, pfd.received_amount receivedAmount, pfd.payable_amount payableAmount,pfdm.detail_year detailYear, pfdm.detail_month detailMonth, td.name "
		"from pay_fee t "
		"inner join pay_fee_attrs pfa on t.fee_id = pfa.fee_id and pfa.community_id = t.community_id and pfa.spec_cd = '390007' and pfa.status_cd = '0' "
		"inner join pay_fee_attrs pfa1 on t.fee_id = pfa1.fee_id and pfa1.community_id = t.community_id and pfa1.spec_cd = '390008' and pfa1.status_cd = '0' "
		"left join pay_fee_attrs pfa2 on t.fee_id = pfa2.fee_id and pfa2.community_id = t.community_id and pfa2.spec_cd = '390002' and pfa2.status_cd = '0' "
		"inner join pay_fee_config pfc on t.config_id = pfc.config_id and pfc.community_id = t.community_id and pfc.status_cd = '0' "
		"inner join pay_fee_detail pfd on t.fee_id = pfd.fee_id and pfd.community_id = t.community_id and pfd.status_cd = '0' "
		"inner join pay_fee_detail_month pfdm on t.fee_id = pfdm.fee_id and pfdm.community_id = t.community_id and pfdm.status_cd = '0' and pfd.detail_id = pfdm.detail_id "
		"inner join t_dict td on td.status_cd = t.fee_type_cd "
		"left join building_room br on t.payer_obj_id = br.room_id and t.payer_obj_type = '3333' and br.status_cd = '0' "
		"left join building_unit bu on br.unit_id = bu.unit_id and bu.status_cd = '0' "
		"left join f_floor ff on bu.floor_id = ff.floor_id and ff.status_cd = '0' "
		"left join owner_car oc on t.payer_obj_id = oc.car_id and t.payer_obj_type = '6666' and oc.status_cd = '0' and oc.car_type_cd='1001' "
		"left join contract con on t.payer_obj_id = con.contract_id and t.payer_obj_type = '7777' and con.status_cd = '0' "
		"where t.end_time > '2000-01-01' "
		"and t.status_cd = '0' ";
	OwnerPaymentMapper mapper;
	return sqlSession->executeQuery<OwnerPaymentDO>(sql, mapper);
}

std::list<OwnerPaymentDO> OwnerPaymentDAO::selectFeeTypeList(const OwnerPaymentListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT td1.name feeTypeCdName,t.fee_type_cd feeTypeCd "
		"FROM  pay_fee_config t "
		"LEFT JOIN t_dict td1 ON t.fee_type_cd = td1.status_cd  AND td1.table_name = 'pay_fee_config' AND td1.table_columns = 'fee_type_cd' "
		"LEFT JOIN t_dict td2 ON t.fee_flag = td2.status_cd AND td2.table_name = 'pay_fee_config'   AND td2.table_columns = 'fee_flag' "
		"LEFT JOIN t_dict td3 ON t.bill_type = td3.status_cd AND td3.table_name = 'pay_fee_config' "
		"AND td3.table_columns = 'bill_type' "
		"LEFT JOIN t_dict td4 ON t.computing_formula = td4.status_cd AND td4.table_name = 'pay_fee_config' AND td4.table_columns = 'computing_formula' "
		"WHERE 1 = 1 "
		"AND t.status_cd = 0 "
		"AND t.end_time > NOW() ";
	if (query->communityId) {
		sql += "AND t.community_id = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	if (query->feeTypeCd) {
		sql += "AND t.fee_type_cd = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->feeTypeCd.getValue(""));
	}
	// 构建分组语句
	sql += "group by feeTypeCdName";
	// 执行查询
	OwnerPaymentFeeTypeListMapper mapper;
	return sqlSession->executeQuery<OwnerPaymentDO>(sql, mapper, params);
}

std::list<OwnerPaymentDO> OwnerPaymentDAO::selectConfigNametList(const OwnerPaymentListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT t.fee_name feeName,t.config_id configId "
		"FROM  pay_fee_config t "
		"LEFT JOIN t_dict td1 ON t.fee_type_cd = td1.status_cd  AND td1.table_name = 'pay_fee_config' AND td1.table_columns = 'fee_type_cd' "
		"LEFT JOIN t_dict td2 ON t.fee_flag = td2.status_cd AND td2.table_name = 'pay_fee_config'   AND td2.table_columns = 'fee_flag' "
		"LEFT JOIN t_dict td3 ON t.bill_type = td3.status_cd AND td3.table_name = 'pay_fee_config' "
		"AND td3.table_columns = 'bill_type' "
		"LEFT JOIN t_dict td4 ON t.computing_formula = td4.status_cd AND td4.table_name = 'pay_fee_config' AND td4.table_columns = 'computing_formula' "
		"WHERE 1 = 1 "
		"AND t.status_cd = 0 "
		"AND t.end_time > NOW() ";
	if (query->communityId) {
		sql += "AND t.community_id = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	if (query->feeTypeCd) {
		sql += "AND t.fee_type_cd = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->feeTypeCd.getValue(""));
	}
	// 构建分组语句
	sql += "group by feeName ";
	// 执行查询
	OwnerPaymentConfigNameListMapper mapper;
	return sqlSession->executeQuery<OwnerPaymentDO>(sql, mapper, params);
}
