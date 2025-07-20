#pragma once

#ifndef _UNPAIDHOUSESERVICE_
#define _UNPAIDHOUSESERVICE_

#include "domain/query/unpaid_house/UnpaidHouseQuery.h"
#include "domain/dto/unpaid_house/UnpaidHouseDTO.h"
#include "domain/vo/unpaid_house/UnpaidHouseVO.h"

class UnpaidHouseService
{
public:
	UnpaidHousePageDTO::Wrapper listWithPage(const UnpaidHouseQuery::Wrapper& query);
	oatpp::List<UnpaidHouseDTO::Wrapper> listAll(const UnpaidHouseQuery::Wrapper& query);
};

class FloorService
{
public:
	oatpp::List<FloorDTO::Wrapper> listAll(const FloorQuery::Wrapper& query);
};

class UnitService
{
public:
	oatpp::List<UnitDTO::Wrapper> listAll(const UnitQuery::Wrapper& query);
};

class RoomService
{
public:
	oatpp::List<RoomDTO::Wrapper> listAll(const RoomQuery::Wrapper& query);
};
#endif // !_UNPAIDHOUSESERVICE_