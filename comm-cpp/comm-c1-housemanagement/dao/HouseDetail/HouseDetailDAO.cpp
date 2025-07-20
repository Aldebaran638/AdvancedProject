#include "stdafx.h"
#include "HouseDetailDAO.h"
#include "HouseDetailMapper.h"

HouseDetailDO HouseDetailDAO::selectById(const HouseDetailQuery::Wrapper& query)
{
    string sql = R"(
        SELECT 
            r.room_id,
            r.room_num,
            r.unit_id,
            r.layer,
            o.name,          
            o.link,
            r.room_type,
            r.built_up_area,
            r.room_area,
            r.room_rent,
            r.section,
            r.create_time
        FROM building_room r
        LEFT JOIN building_owner o ON r.user_id = o.user_id
        WHERE r.room_id = ? AND r.status_cd = '0'
    )";

    SqlParams params;
    SQLPARAMS_PUSH(params, "s", std::string, query->house_id.getValue(""));

    HouseDetailMapper mapper;
    auto result = sqlSession->executeQuery<HouseDetailDO>(sql, mapper, params);

    if (result.empty()) {
        throw std::runtime_error("未找到对应房屋信息");
    }
    return result.front();
}