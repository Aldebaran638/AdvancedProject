#pragma once
#ifndef _HOUSENAME_DAO_
#define _HOUSENAME_DAO_

#include "BaseDAO.h"
#include "../../domain/do/HouseName/HouseNameDO.h"
#include "../../domain/query/HouseName/HouseNameQuery.h"

class HouseNameDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const HouseNameQuery::Wrapper& query, SqlParams& params);
public:
    std::list<HouseNameDO> selectHouseName(const HouseNameQuery::Wrapper& query);
};
#endif