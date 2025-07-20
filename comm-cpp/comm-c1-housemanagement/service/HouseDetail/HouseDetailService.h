#pragma once
#ifndef _HOUSE_DETAIL_SERVICE_
#define _HOUSE_DETAIL_SERVICE_

#include "domain/vo/HouseDetail/HouseDetailVO.h"
#include "domain/query/HouseDetail/HouseDetailQuery.h"
#include "domain/dto/HouseDetail/HouseDetailDTO.h"

class HouseDetailService
{
public:
    HouseDetailDTO::Wrapper getHouseDetail(const HouseDetailQuery::Wrapper& query);
};
#endif