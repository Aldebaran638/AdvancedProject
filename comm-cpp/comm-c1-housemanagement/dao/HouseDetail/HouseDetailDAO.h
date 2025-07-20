#pragma once
#ifndef _HOUSE_DETAIL_DAO_
#define _HOUSE_DETAIL_DAO_

#include "BaseDAO.h"
#include "../../domain/do/HouseDetail/HouseDetailDO.h"
#include "../../domain/query/HouseDetail/HouseDetailQuery.h"

class HouseDetailDAO : public BaseDAO
{
public:
    HouseDetailDO selectById(const HouseDetailQuery::Wrapper& query);
};
#endif