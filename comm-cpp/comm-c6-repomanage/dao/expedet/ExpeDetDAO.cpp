#include "stdafx.h"
#include "ExpeDetDAO.h"
#include "ExpeDetMapper.h"
#include <sstream>


//房屋费用明细实现--------------------
std::string ExpedetBuildingFeeDetailDAO::queryConditionBuilder(const ExpedetBuildingFeeDetailQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->start_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	if (query->room_name) {

		sqlCondition << " AND t.room_num like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->room_name.getValue(""));
	}
	if (query->name) {

		sqlCondition << " AND bo.`name` like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->link) {

		sqlCondition << " AND bo.link = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t ExpedetBuildingFeeDetailDAO::count(const ExpedetBuildingFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(1) count FROM ("
		"SELECT t.room_id "
		"FROM building_room t "
		"INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' "
		"INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' "
		"LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' "
		"LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
		"INNER JOIN report_owe_fee rof ON t.room_id = rof.payer_obj_id AND rof.payer_obj_type = '3333' ";





	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 补全sql
	sql += " group by t.room_id ) a ";

	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<ExpedetBuildingFeeDetailDO> ExpedetBuildingFeeDetailDAO::selectWithPage(const ExpedetBuildingFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT "
		"t.room_num, "
		"bo.name, "
		"bo.link, "
		"rof.amount_owed, "
		"t.community_id "
		"FROM building_room t "
		"LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' "
		"LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
		"INNER JOIN report_owe_fee rof ON t.room_id = rof.payer_obj_id "
		"AND rof.payer_obj_type = '3333' "
		"AND rof.amount_owed > 0 ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);

	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ExpedetBuildingFeeDetailMapper mapper;
	return sqlSession->executeQuery<ExpedetBuildingFeeDetailDO>(sql, mapper, params);
}

//业主费用明细实现--------------------
std::string ExpedetOwnerFeeDetailDAO::queryConditionBuilder(const ExpedetOwnerFeeDetailQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->start_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	if (query->room_name) {

		sqlCondition << " AND t.room_num like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->room_name.getValue(""));
	}
	if (query->name) {

		sqlCondition << " AND bo.`name` like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->link) {

		sqlCondition << " AND bo.link = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t ExpedetOwnerFeeDetailDAO::count(const ExpedetOwnerFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(DISTINCT t.room_id) count "
		"FROM building_room t "
		"INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' "
		"INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' "
		"LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' "
		"LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
		"INNER JOIN report_owe_fee rof ON t.room_id = rof.payer_obj_id AND rof.payer_obj_type = '3333' ";





	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 补全sql
	sql += " group by t.room_id ) a ";

	return sqlSession->executeQueryNumerical(sql, params);
}
std::list<ExpedetOwnerFeeDetailDO> ExpedetOwnerFeeDetailDAO::selectWithPage(const ExpedetOwnerFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT "
		"t.room_id AS roomId, "
		"t.room_num AS roomNum, "
		"bo.name AS ownerName, "
		"bo.link AS ownerPhone, "
		"bo.member_id AS ownerId, "
		"rof.amount_owed AS oweAmount, "
		"t.community_id AS communityId, "
		"bu.unit_num AS unitNum, "
		"f.floor_num AS floorNum, "
		"t.built_up_area AS roomArea "
		"FROM building_room t "
		"INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' "
		"INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' "
		"LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' "
		"LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
		"INNER JOIN report_owe_fee rof ON t.room_id = rof.payer_obj_id "
		"AND rof.payer_obj_type = '3333' "
		"AND rof.amount_owed > 0 ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);

	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ExpedetOwnerFeeDetailMapper mapper;
	return sqlSession->executeQuery<ExpedetOwnerFeeDetailDO>(sql, mapper, params);
}

//合同费用明细实现--------------------
std::string ExpedetContractFeeDetailDAO::queryConditionBuilder(const ExpedetContractFeeDetailQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->start_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	if (query->contract_name) {

		sqlCondition << " AND t.contract_name like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->contract_name.getValue(""));
	}
	if (query->name) {

		sqlCondition << " AND bo.`name` like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->link) {

		sqlCondition << " AND bo.link = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t ExpedetContractFeeDetailDAO::count(const ExpedetContractFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(1) count "
		"FROM contract t "
		"LEFT JOIN contract tt ON t.contract_parent_id = tt.contract_id AND tt.status_cd = '0' AND tt.store_id = t.store_id ";





	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 补全sql
	sql += " group by t.room_id ) a ";

	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<ExpedetContractFeeDetailDO> ExpedetContractFeeDetailDAO::selectWithPage(const ExpedetContractFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT "
		"t.contract_id AS contractId, "
		"t.contract_name AS contractName, "
		"t.party_b AS partyB, "
		"t.b_link AS contactPhone, "
		"t.store_id AS storeId, "
		"t.start_time AS startTime, "
		"t.end_time AS endTime, "
		"t.status_cd AS statusCd, "
		"tt.contract_name AS parentContractName "
		"FROM contract t "
		"LEFT JOIN contract tt ON t.contract_parent_id = tt.contract_id AND tt.status_cd = '0' AND tt.store_id = t.store_id ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);

	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ExpedetContractFeeDetailMapper mapper;
	return sqlSession->executeQuery<ExpedetContractFeeDetailDO>(sql, mapper, params);
}

//车辆费用明细实现--------------------
std::string ExpedetCarFeeDetailDAO::queryConditionBuilder(const ExpedetCarFeeDetailQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->start_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time) {
		sqlCondition << " AND rof.bill_date >= ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	if (query->car_num) {

		sqlCondition << " AND t.car_num like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->car_num.getValue(""));
	}
	if (query->name) {

		sqlCondition << " AND bo.`name` like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->link) {

		sqlCondition << " AND bo.link = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t ExpedetCarFeeDetailDAO::count(const ExpedetCarFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(1) count "
		"FROM owner_car t "
		"LEFT JOIN building_owner bow ON t.owner_id = bow.member_id AND bow.status_cd = '0' AND bow.community_id = t.community_id "
		"LEFT JOIN parking_space ps ON t.ps_id = ps.ps_id AND ps.status_cd = '0' "
		"LEFT JOIN parking_area pa ON ps.pa_id = pa.pa_id AND pa.status_cd = '0' ";





	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 补全sql
	sql += " group by t.room_id ) a ";

	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<ExpedetCarFeeDetailDO> ExpedetCarFeeDetailDAO::selectWithPage(const ExpedetCarFeeDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT "
		"t.car_id AS carId, "
		"t.car_num AS carNum, "
		"t.car_type_cd AS carTypeCd, "
		"t.car_brand AS carBrand, "
		"bow.name AS ownerName, "
		"bow.link AS ownerPhone, "
		"t.community_id AS communityId, "
		"t.start_time AS startTime, "
		"t.end_time AS endTime, "
		"FROM owner_car t "
		"LEFT JOIN building_owner bow ON t.owner_id = bow.member_id AND bow.status_cd = '0' AND bow.community_id = t.community_id "
		"LEFT JOIN parking_space ps ON t.ps_id = ps.ps_id AND ps.status_cd = '0' "
		"LEFT JOIN parking_area pa ON ps.pa_id = pa.pa_id AND pa.status_cd = '0' ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);

	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ExpedetCarFeeDetailMapper mapper;
	return sqlSession->executeQuery<ExpedetCarFeeDetailDO>(sql, mapper, params);
}