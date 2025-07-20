#pragma once
#ifndef _HOUSESELECT_DAO_
#define _HOUSESELECT_DAO_

#include "BaseDAO.h"
#include "../../domain/do/HouseSelect/HouseSelectDO.h"
#include "../../domain/query/HouseSelect/HouseSelectQuery.h"

class HouseSelectDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const HouseSelectQuery::Wrapper& query, SqlParams& params);
public:
    uint64_t count(const HouseSelectQuery::Wrapper& query);
    std::list<HouseSelectDO> selectHouse(const HouseSelectQuery::Wrapper& query);
};
#endif