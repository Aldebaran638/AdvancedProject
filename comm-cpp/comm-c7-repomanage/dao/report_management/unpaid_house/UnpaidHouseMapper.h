#pragma once

#ifndef _UNPAIDHOUSEMAPPER_
#define _UNPAIDHOUSEMAPPER_

#include "Mapper.h"
#include "domain/do/unpaid_house/UnpaidHouseDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class UnpaidHouseMapper : public Mapper<UnpaidHouseDO>
{
public:
	UnpaidHouseDO mapper(ResultSet* resultSet) const override
	{
		UnpaidHouseDO data;
		data.setRoomId(resultSet->getString(1));
		data.setFloorNum(resultSet->getString(2));
		data.setUnitNum(resultSet->getString(3));
		data.setRoomNum(resultSet->getString(4));
		data.setOwnerId(resultSet->getString(5));
		data.setOwnerName(resultSet->getString(6));
		data.setLink(resultSet->getString(7));
		return data;
	}
};

class FloorMapper : public Mapper<FloorDO>
{
public:
	FloorDO mapper(ResultSet* resultSet) const override
	{
		FloorDO data;
		data.setFloorId(resultSet->getString(1));
		data.setFloorNum(resultSet->getString(2));
		return data;
	}
};

class UnitMapper : public Mapper<UnitDO>
{
public:
	UnitDO mapper(ResultSet* resultSet) const override
	{
		UnitDO data;
		data.setUnitId(resultSet->getString(1));
		data.setUnitNum(resultSet->getString(2));
		return data;
	}
};

class RoomMapper : public Mapper<RoomDO>
{
public:
	RoomDO mapper(ResultSet* resultSet) const override
	{
		RoomDO data;
		data.setRoomId(resultSet->getString(1));
		data.setRoomNum(resultSet->getString(2));
		return data;
	}
};

#endif // !_UNPAIDHOUSEMAPPER_