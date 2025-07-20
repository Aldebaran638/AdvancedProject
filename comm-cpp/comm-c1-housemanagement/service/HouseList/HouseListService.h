#pragma once
#ifndef _HOUSELIST_SERVICE_
#define _HOUSELIST_SERVICE_

#include "domain/vo/HouseList/HouseListVO.h"
#include "domain/query/HouseList/HouseListQuery.h"
#include "domain/dto/HouseList/HouseListDTO.h"

class HouseListService
{
public:
    HouseListPageDTO::Wrapper listHouse(const HouseListQuery::Wrapper& query);
};
#endif