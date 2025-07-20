#include "stdafx.h"
#include "UnitDAO.h"
#include "UnitMapper.h"
#include <sstream>

std::string UnitDAO::queryConditionBuilder(const UnitQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1 ";
	if (query->unit_num)
	{
		sqlCondition << " AND `building_unit`.`unit_num`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->unit_num.getValue(""));
	}
	if (query->floor_id)
	{
		sqlCondition << " AND `building_unit`.`floor_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->floor_id.getValue(""));
	}
	if (query->floor_num)
	{
		sqlCondition << " AND `f_floor`.`floor_num`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->floor_num.getValue(""));
	}
	if (query->community_id)
	{
		sqlCondition << " AND `f_floor`.`community_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	return sqlCondition.str();
}

// 向building_unit表中插入数据
// DAO负责向数据表中写入数据，至于数据的组装由service层实现
int UnitDAO::insert(const UnitDO& iObj) {
    string sql = "INSERT INTO `building_unit` (`unit_id`, `b_id`, `unit_num`, `floor_id`, `layer_count`, `lift`, `user_id`, `remark`, `create_time`, `status_cd`, `unit_area`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%i%s%s%s%s%s%s",
        iObj.getUnitId(), iObj.getBId(), iObj.getUnitNum(),
        iObj.getFloorId(), iObj.getLayerCount(), iObj.getLift(),
        iObj.getUserId(), iObj.getRemark(), iObj.getCreateTime(),
        iObj.getStatusCd(), iObj.getUnitArea());
}

// 修改全部数据
int UnitDAO::update_all(const UnitDO& uObj) {
    string sql = "UPDATE `building_unit` SET `b_id`=?,`unit_num`=?,`floor_id`=?,`layer_count`=?,`lift`=?,`user_id`=?,`remark`=?,`create_time`=?,`status_cd`=?,`unit_area`=? WHERE `unit_id`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%s",
        uObj.getBId(), uObj.getUnitNum(), uObj.getFloorId(),
        uObj.getLayerCount(), uObj.getLift(), uObj.getUserId(),
        uObj.getRemark(), uObj.getCreateTime(), uObj.getStatusCd(),
        uObj.getUnitArea(), uObj.getUnitId());
}

// 修改数据
int UnitDAO::update(const UnitDO& uObj) {
    string sql = "UPDATE `building_unit` SET `unit_num`=?,`layer_count`=?,`lift`=?,`remark`=?,`unit_area`=? WHERE `unit_id`=?";
    return sqlSession->executeUpdate(sql, "%s%i%s%s%s%s",
        uObj.getUnitNum(),
        uObj.getLayerCount(), uObj.getLift(), 
        uObj.getRemark(),
        uObj.getUnitArea(), uObj.getUnitId());
}

// 通过ID删除building_unit表中数据
int UnitDAO::deleteById(std::string id) {
    string sql = "DELETE FROM `building_unit` WHERE `unit_id`=?";
    return sqlSession->executeUpdate(sql, "%s", id);
}

uint64_t UnitDAO::count(const UnitQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM `building_unit` ";
	sql += queryConditionBuilder(query, params);
	return sqlSession->executeQueryNumerical(sql, params);
}

uint64_t UnitDAO::countCommunityUnit(const UnitQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM `building_unit` LEFT JOIN `f_floor` ON `building_unit`.floor_id=`f_floor`.floor_id ";
	sql += queryConditionBuilder(query, params);
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<UnitDO> UnitDAO::selectUnit(const UnitQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT `building_unit`.unit_num, `building_unit`.layer_count, `building_unit`.lift, `building_unit`.remark, `building_unit`.unit_area FROM `building_unit` ";
	sql += queryConditionBuilder(query, params);
	QueryUnitMapper mapper;
	return sqlSession->executeQuery<UnitDO>(sql, mapper, params);
}

std::list<UnitDO> UnitDAO::selectCommunityUnit(const UnitQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT `building_unit`.unit_num, `building_unit`.layer_count, `building_unit`.lift, `building_unit`.remark, `building_unit`.unit_area, floor_num FROM `building_unit` LEFT JOIN `f_floor` ON `building_unit`.floor_id=`f_floor`.floor_id ";
	sql += queryConditionBuilder(query, params);
	QueryUnitMapper mapper;
	return sqlSession->executeQuery<UnitDO>(sql, mapper, params);
}