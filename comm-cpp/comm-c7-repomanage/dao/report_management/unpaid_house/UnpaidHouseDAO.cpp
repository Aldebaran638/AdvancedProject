#include "stdafx.h"
#include "UnpaidHouseDAO.h"
#include "UnpaidHouseMapper.h"

std::string UnpaidHouseDAO::queryConditionBuilder(const UnpaidHouseQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;

	sqlCondition << "INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' "
		"INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' "
		"LEFT JOIN building_owner_room_rel borr ON borr.room_id = t.room_id AND borr.status_cd ='0' "
		"LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
		"WHERE t.status_cd = '0' "
		"AND NOT EXISTS(SELECT 1 FROM pay_fee pf WHERE t.room_id = pf.payer_obj_id AND pf.status_cd = '0' AND pf.state = '2008001')";

	// 必填条件：communityId
	sqlCondition << " AND t.community_id=?";
	SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));

	if (query->floorId) {
		sqlCondition << " AND f.floor_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->floorId.getValue(""));
	}
	if (query->unitId) {
		sqlCondition << " AND bu.unit_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->unitId.getValue(""));
	}
	if (query->roomId) {
		sqlCondition << " AND t.room_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->roomId.getValue(""));
	}
	// 业主姓名模糊查询
	if (query->ownerName) {
		sqlCondition << " AND bo.name LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->ownerName.getValue("") + "%");
	}
	if (query->link) {
		sqlCondition << " AND bo.link=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t UnpaidHouseDAO::count(const UnpaidHouseQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM building_room t ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<UnpaidHouseDO> UnpaidHouseDAO::selectWithPage(const UnpaidHouseQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT t.room_id roomId, f.floor_num floorNum, bu.unit_num unitNum, t.room_num roomNum, "
		"bo.owner_id ownerId, bo.name ownerName, bo.link "
		"FROM building_room t ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY bo.name";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	UnpaidHouseMapper mapper;
	return sqlSession->executeQuery<UnpaidHouseDO>(sql, mapper, params);
}

std::list<UnpaidHouseDO> UnpaidHouseDAO::selectAll(const UnpaidHouseQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT t.room_id roomId, f.floor_num floorNum, bu.unit_num unitNum, t.room_num roomNum, "
		"bo.owner_id ownerId, bo.name ownerName, bo.link "
		"FROM building_room t ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY bo.name";
	// 构建分页条件
	//sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	UnpaidHouseMapper mapper;
	return sqlSession->executeQuery<UnpaidHouseDO>(sql, mapper, params);

}

std::list<FloorDO> FloorDAO::selectAll(const FloorQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT floor_id, floor_num "
		"FROM f_floor "
		"WHERE status_cd = '0' "
		" AND community_id=?";
	SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	// 构建排序语句
	sql += " ORDER BY floor_num";

	// 执行查询
	FloorMapper mapper;
	return sqlSession->executeQuery<FloorDO>(sql, mapper, params);
}

std::list<UnitDO> UnitDAO::selectAll(const UnitQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT unit_id, unit_num "
		"FROM building_unit "
		"WHERE status_cd = '0' "
		//" AND community_id=?"
		" AND floor_id=?";
	//SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	SQLPARAMS_PUSH(params, "s", std::string, query->floorId.getValue(""));
	// 构建排序语句
	sql += " ORDER BY unit_num";

	// 执行查询
	UnitMapper mapper;
	return sqlSession->executeQuery<UnitDO>(sql, mapper, params);
}

std::list<RoomDO> RoomDAO::selectAll(const RoomQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT room_id, room_num "
		"FROM building_room "
		"WHERE status_cd = '0' "
		" AND community_id=?"
		" AND unit_id=?";
	SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	SQLPARAMS_PUSH(params, "s", std::string, query->unitId.getValue(""));
	// 构建排序语句
	sql += " ORDER BY room_num";

	// 执行查询
	RoomMapper mapper;
	return sqlSession->executeQuery<RoomDO>(sql, mapper, params);
}
