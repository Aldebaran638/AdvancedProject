#include "stdafx.h"
#include "HouseNameDAO.h"
#include "HouseNameMapper.h"
#include <sstream>

std::string HouseNameDAO::queryConditionBuilder(const HouseNameQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";
    if (query->floor_num)
    {
        sqlCondition << " AND `f_floor`.`name`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->floor_num.getValue(""));
    }
    if (query->unit_num)
    {
        sqlCondition << " AND `building_unit`.`unit_num`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->unit_num.getValue(""));
    }
    return sqlCondition.str();
}

std::list<HouseNameDO> HouseNameDAO::selectHouseName(const HouseNameQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT `building_room`.room_num, `building_owner`.`name`, "
        "`f_floor`.floor_num, `building_unit`.unit_num "
        "FROM `building_room` "
        "LEFT JOIN `building_unit` ON `building_room`.unit_id=`building_unit`.unit_id "
        "LEFT JOIN `f_floor` ON `building_unit`.floor_id=`f_floor`.floor_id "
        "LEFT JOIN `building_owner` ON `building_room`.user_id=`building_owner`.user_id";
    sql += queryConditionBuilder(query, params);
    HouseNameMapper mapper;
    return sqlSession->executeQuery<HouseNameDO>(sql, mapper, params);
}