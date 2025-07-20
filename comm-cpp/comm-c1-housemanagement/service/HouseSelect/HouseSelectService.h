#pragma once
#ifndef _HOUSESELECT_SERVICE_
#define _HOUSESELECT_SERVICE_

#include "domain/vo/HouseSelect/HouseSelectVO.h"
#include "domain/query/HouseSelect/HouseSelectQuery.h"
#include "domain/dto/HouseSelect/HouseSelectDTO.h"

class HouseSelectService
{
public:
    HouseSelectPageDTO::Wrapper listHouse(const HouseSelectQuery::Wrapper& query);
};
#endif