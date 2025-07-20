#pragma once
#ifndef _HOUSESELECT_MAPPER_
#define _HOUSESELECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/HouseSelect/HouseSelectDO.h"

class HouseSelectMapper : public Mapper<HouseSelectDO>
{
public:
    HouseSelectDO mapper(ResultSet* resultSet) const override
    {
        HouseSelectDO data;
        data.setHouse_id(resultSet->getString(1));
        data.setRoom_num(resultSet->getString(2));
        data.setFloor_num(resultSet->getString(3));
        data.setUnit_num(resultSet->getString(4));
        data.setLayer_num(resultSet->getString(5));
        return data;
    }
};

#endif