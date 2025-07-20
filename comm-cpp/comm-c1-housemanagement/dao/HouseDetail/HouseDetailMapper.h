#pragma once
#ifndef _HOUSE_DETAIL_MAPPER_
#define _HOUSE_DETAIL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/HouseDetail/HouseDetailDO.h"

class HouseDetailMapper : public Mapper<HouseDetailDO>
{
public:
    HouseDetailDO mapper(ResultSet* resultSet) const override
    {
        HouseDetailDO data;

        // 设置房屋基本信息
        data.setHouse_id(resultSet->getString(1));      // room_id
        data.setHouse_num(resultSet->getString(2));     // room_num
        data.setUnit_id(resultSet->getString(3));       // unit_id

        // 设置楼层信息
        data.setFloor_num(resultSet->getString(4));      // floor_num

        // 设置业主信息
        data.setOwner_name(resultSet->getString(5));     // name (业主姓名)
        data.setOwner_phone(resultSet->getString(6));    // link (业主联系方式)

        // 设置房屋属性
        data.setHouse_type(resultSet->getString(7));     // room_type
        data.setBuilt_area(resultSet->getDouble(8));     // built_up_area (建筑面积)
        data.setInner_area(resultSet->getDouble(9));     // room_area (室内面积)
        data.setRent_amount(resultSet->getDouble(10));   // room_rent (租金)

        // 设置状态和时间信息
        data.setHouse_status(resultSet->getString(11));  // section (房屋状态/分区)
        data.setCheck_in_date(resultSet->getString(12)); // create_time (创建时间作为入住时间)

        return data;
    }
};

#endif