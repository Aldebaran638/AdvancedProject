#pragma once
#ifndef _VENUERESERVATIONMGRMAPPER_H_
#define _VENUERESERVATIONMGRMAPPER_H_

#include "Mapper.h"
#include "../domain/do/VenueReservationMgrDo.h"
/**
 * 
 */
class VenueReservationMgrMapper : public Mapper<VenueReservationMgrDO>
{
public:
	VenueReservationMgrDO mapper(ResultSet* resultSet) const override
	{
		VenueReservationMgrDO data;
		data.setVenueName(resultSet->getString("venueName"));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrVenueReservationMgrMapperMapper : public Mapper<PtrVenueReservationMgrDO>
{
public:
	PtrVenueReservationMgrDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<VenueReservationMgrDO>();
		data->setVenueName(resultSet->getString(1));
		return data;
	}
};

#endif // !_VENUERESERVATIONMGR_H_