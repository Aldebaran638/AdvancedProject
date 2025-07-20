#include "stdafx.h"
#include "RoomDAO.h"
#include "RoomMapper.h"
#include <sstream>

std::string RoomDAO::queryConditionBuilder(const RoomQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->room_num) {
        sqlCondition << " AND `room_num`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->room_num.getValue(""));
    }
    return sqlCondition.str();
}

uint64_t RoomDAO::count(const RoomQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT COUNT(*) FROM building_room ";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<RoomDO> RoomDAO::selectWithPage(const RoomQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT `room_num`, `layer`, `built_up_area`, `state`, `room_type`, `room_rent` FROM building_room ";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 排序条件
    sql += " ORDER BY `room_num` DESC ";
    // 分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    RoomMapper mapper;
    return sqlSession->executeQuery<RoomDO>(sql, mapper, params);
}
//
//PtrRoomDO RoomDAO::selectById(std::string id)
//{
//    std::string sql = "SELECT room_num, layer, built_up_area, state, room_type, room_rent FROM building_room WHERE `room_num`=?";
//    PtrRoomMapper mapper;
//    return sqlSession->executeQueryOne<PtrRoomDO>(sql, mapper, "%s", id);
//}