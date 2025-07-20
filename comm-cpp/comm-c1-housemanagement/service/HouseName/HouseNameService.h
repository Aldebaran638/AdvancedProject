#pragma once
#ifndef _HOUSENAME_SERVICE_
#define _HOUSENAME_SERVICE_

#include "domain/vo/HouseName/HouseNameVO.h"
#include "domain/query/HouseName/HouseNameQuery.h"
#include "domain/dto/HouseName/HouseNameDTO.h"

class HouseNameService
{
public:
    oatpp::List<HouseNameDTO::Wrapper> listHouseName(const HouseNameQuery::Wrapper& query);
};

#endif