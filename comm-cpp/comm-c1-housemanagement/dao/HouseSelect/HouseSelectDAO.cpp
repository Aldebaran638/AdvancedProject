#include "stdafx.h"
#include "HouseSelectDAO.h"
#include "HouseSelectMapper.h"
#include <sstream>

std::string HouseSelectDAO::queryConditionBuilder(const HouseSelectQuery::Wrapper& query, SqlParams& params)
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
    if (query->room_num)
    {
        sqlCondition << " AND `building_room`.`room_num` LIKE ?";
        SQLPARAMS_PUSH(params, "s", std::string, "%" + query->room_num.getValue("") + "%");
    }
    return sqlCondition.str();
}

uint64_t HouseSelectDAO::count(const HouseSelectQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM `building_room` "
        "LEFT JOIN `building_unit` ON `building_room`.`unit_id`=`building_unit`.`unit_id` "
        "LEFT JOIN `f_floor` ON `building_unit`.`floor_id`=`f_floor`.`floor_id` ";
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<HouseSelectDO> HouseSelectDAO::selectHouse(const HouseSelectQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT `building_room`.`room_id`, `building_room`.`room_num`, "
        "`f_floor`.`floor_num`, `building_unit`.`unit_num`, `building_room`.`layer` "
        "FROM `building_room` "
        "LEFT JOIN `building_unit` ON `building_room`.`unit_id`=`building_unit`.`unit_id` "
        "LEFT JOIN `f_floor` ON `building_unit`.`floor_id`=`f_floor`.`floor_id` ";
    sql += queryConditionBuilder(query, params);

    // Ìí¼Ó·ÖÒ³
    sql += " LIMIT " + std::to_string(query->pageSize.getValue(10)) +
        " OFFSET " + std::to_string((query->pageIndex.getValue(1) - 1) * query->pageSize.getValue(10));

    HouseSelectMapper mapper;
    return sqlSession->executeQuery<HouseSelectDO>(sql, mapper, params);
}