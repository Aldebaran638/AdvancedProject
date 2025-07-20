#pragma once
#ifndef _HOUSELIST_MAPPER_
#define _HOUSELIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/HouseList/HouseListDO.h"

class HouseListMapper : public Mapper<HouseListDO>
{
public:
    HouseListDO mapper(ResultSet* resultSet) const override
    {
        HouseListDO data;
        data.setHouse_id(resultSet->getString(1));
        data.setRoom_num(resultSet->getString(2));
        data.setFloor_num(resultSet->getString(3));
        data.setUnit_num(resultSet->getString(4));
        data.setStatus_cd(resultSet->getString(5));
        data.setOwner_count(resultSet->getInt(6));
        data.setCar_count(resultSet->getInt(7));
        data.setComplaint_count(resultSet->getInt(8));
        return data;
    }
};

#endif