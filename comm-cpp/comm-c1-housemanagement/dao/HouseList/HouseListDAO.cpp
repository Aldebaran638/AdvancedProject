#include "stdafx.h"
#include "HouseListDAO.h"
#include "HouseListMapper.h"
#include <sstream>

std::string HouseListDAO::queryConditionBuilder(const HouseListQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";

    // 必填条件:楼栋号
    sqlCondition << " AND `f_floor`.`name`=?";
    SQLPARAMS_PUSH(params, "s", std::string, query->floor_num.getValue(""));

    if (query->unit_num)
    {
        sqlCondition << " AND `building_unit`.`unit_num`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->unit_num.getValue(""));
    }
    if (query->house_id)
    {
        sqlCondition << " AND `building_room`.`room_id`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->house_id.getValue(""));
    }
    if (query->status_cd)
    {
        sqlCondition << " AND `building_room`.`status_cd`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->status_cd.getValue(""));
    }
    return sqlCondition.str();
}

uint64_t HouseListDAO::count(const HouseListQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM `building_room` "
        "LEFT JOIN `building_unit` ON `building_room`.`unit_id`=`building_unit`.`unit_id` "
        "LEFT JOIN `f_floor` ON `building_unit`.`floor_id`=`f_floor`.`floor_id`";
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<HouseListDO> HouseListDAO::selectHouseList(const HouseListQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT `building_room`.`room_id`, `building_room`.`room_num`, `f_floor`.`name`, "
        "`building_unit`.`unit_num`, `building_room`.`status_cd`, "
        "(SELECT COUNT(*) FROM `building_owner` WHERE `building_owner`.`user_id`=`building_room`.`user_id`) AS owner_count, "
        "(SELECT COUNT(*) FROM `owner_car` WHERE `owner_car`.`owner_id` IN "
        "(SELECT `owner_id` FROM `building_owner` WHERE `building_owner`.`user_id`=`building_room`.`user_id`)) AS car_count, "
        "(SELECT COUNT(*) FROM `complaint` WHERE `complaint`.`owner_id` IN "
        "(SELECT `owner_id` FROM `building_owner` WHERE `building_owner`.`user_id`=`building_room`.`user_id`)) AS complaint_count "
        "FROM `building_room` "
        "LEFT JOIN `building_unit` ON `building_room`.`unit_id`=`building_unit`.`unit_id` "
        "LEFT JOIN `f_floor` ON `building_unit`.`floor_id`=`f_floor`.`floor_id` ";
    sql += queryConditionBuilder(query, params);

    // 添加分页
    sql += " LIMIT " + std::to_string(query->pageSize.getValue(10)) +
        " OFFSET " + std::to_string((query->pageIndex.getValue(1) - 1) * query->pageSize.getValue(10));

    HouseListMapper mapper;
    return sqlSession->executeQuery<HouseListDO>(sql, mapper, params);
}