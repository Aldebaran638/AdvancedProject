#pragma once
#ifndef _HOUSELIST_DAO_
#define _HOUSELIST_DAO_

#include "BaseDAO.h"
#include "../../domain/do/HouseList/HouseListDO.h"
#include "../../domain/query/HouseList/HouseListQuery.h"

class HouseListDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const HouseListQuery::Wrapper& query, SqlParams& params);
public:
    uint64_t count(const HouseListQuery::Wrapper& query);
    std::list<HouseListDO> selectHouseList(const HouseListQuery::Wrapper& query);
};
#endif