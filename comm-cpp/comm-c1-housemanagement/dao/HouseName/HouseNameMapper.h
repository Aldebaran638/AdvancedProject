#pragma once
#ifndef _HOUSENAME_MAPPER_
#define _HOUSENAME_MAPPER_

#include "Mapper.h"
#include "../../domain/do/HouseName/HouseNameDO.h"

class HouseNameMapper : public Mapper<HouseNameDO>
{
public:
    HouseNameDO mapper(ResultSet* resultSet) const override
    {
        HouseNameDO data;
        data.setHouse_num(resultSet->getString(1));
        data.setOwner_name(resultSet->getString(2));
        data.setFloor_num(resultSet->getString(3));
        data.setUnit_num(resultSet->getString(4));
        return data;
    }
};

#endif