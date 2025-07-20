#pragma once
#ifndef _HOUSEFEEMGRMAPPER_H_
#define _HOUSEFEEMGRMAPPER_H_

#include "Mapper.h"
#include "../domain/do/HouseFeeMgrDO.h"

/**
 * 示例表字段匹配映射
 */
class HouseFeeMgrMapper : public Mapper<HouseFeeMgrDO>
{
public:
	HouseFeeMgrDO mapper(ResultSet* resultSet) const override
	{
		HouseFeeMgrDO data;
		data.setFee_id(resultSet->getString(1));
		data.setFee_flag(resultSet->getString(2));
		data.setFee_type_cd(resultSet->getString(3));
		data.setPayer_obj_name(resultSet->getString(4));
		data.setConfig_name(resultSet->getString(5));
		data.setState(resultSet->getString(6));
		data.setEnd_time(resultSet->getString(7));
		data.setBatch_id(resultSet->getString(8));
		data.setDeadline_time(resultSet->getString(9));
		data.setFee_pay(resultSet->getDouble(10));
		data.setOwner_tel(resultSet->getString(11));
		data.setOwner_name(resultSet->getString(12));
		data.setOwner_id(resultSet->getString(13));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrHouseFeeMgrMapper : public Mapper<PtrHouseFeeMgrDO>
{
public:
	PtrHouseFeeMgrDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<HouseFeeMgrDO>();
		data->setFee_id(resultSet->getString(1));
		data->setFee_flag(resultSet->getString(2));
		data->setFee_type_cd(resultSet->getString(3));
		data->setPayer_obj_name(resultSet->getString(4));
		data->setConfig_name(resultSet->getString(5));
		data->setState(resultSet->getString(6));
		data->setEnd_time(resultSet->getString(7));
		data->setBatch_id(resultSet->getString(8));
		data->setDeadline_time(resultSet->getString(9));
		data->setFee_pay(resultSet->getDouble(10));
		data->setOwner_tel(resultSet->getString(11));
		data->setOwner_name(resultSet->getString(12));
		data->setOwner_id(resultSet->getString(13));
		return data;
	}
};

#endif // !_HOUSEFEEMGRMAPPER_H_
