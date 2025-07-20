#pragma once
#ifndef _ORDER_MAPPER_
#define _ORDER_MAPPER_

#include "Mapper.h"
#include "domain/do/venue-reservation/OrderDO.h"

/**
 * 示例表字段匹配映射
 */
class OrderMapper : public Mapper<OrderDO>
{
public:
	OrderDO mapper(ResultSet* resultSet) const override
	{
		OrderDO data;
		data.setVenueName(resultSet->getString(1));
		data.setSpaceName(resultSet->getString(2));
		data.setCspId(resultSet->getString(3));
		data.setPersonName(resultSet->getString(4));
		data.setPersonTel(resultSet->getString(5));
		data.setAppointmentTime(resultSet->getString(6));
		data.setReceivableAmount(resultSet->getString(7));
		data.setReceivedAmount(resultSet->getString(8));
		data.setPayWay(resultSet->getString(9));
		data.setState(resultSet->getString(10));
		data.setCreateTime(resultSet->getString(11));
		data.setRemark(resultSet->getString(12));
		data.setTimes(resultSet->getString(13));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrSampleMapper : public Mapper<PtrOrderDO>
{
public:
	PtrOrderDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OrderDO>();
		return data;
	}
};

#endif // !_ORDER_MAPPER_