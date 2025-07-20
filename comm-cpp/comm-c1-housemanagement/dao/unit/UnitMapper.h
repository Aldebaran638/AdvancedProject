#pragma once

#ifndef _UNIT_MAPPER_
#define _UNIT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/UnitDO/UnitDO.h"

/**
 * unit表(单元表)字段匹配映射
 */
class UnitMapper : public Mapper<UnitDO> {
public:
	UnitDO mapper(ResultSet* resultSet) const override {
		UnitDO data;
		data.setUnitId(resultSet->getString(1));
		data.setBId(resultSet->getString(2));
		data.setUnitNum(resultSet->getString(3));
		data.setFloorId(resultSet->getString(4));
		data.setLayerCount(resultSet->getInt(5));
		data.setLift(resultSet->getString(6));
		data.setUserId(resultSet->getString(7));
		data.setRemark(resultSet->getString(8));
		data.setCreateTime(resultSet->getString(9));
		data.setStatusCd(resultSet->getString(10));
		data.setUnitArea(resultSet->getString(11));
		return data;
	}
};

class QueryUnitMapper : public Mapper<UnitDO>
{
public:
	UnitDO mapper(ResultSet* resultSet) const override
	{
		UnitDO data;
		data.setUnitNum(resultSet->getString(1));
		data.setLayerCount(resultSet->getInt(2));
		data.setLift(resultSet->getString(3));
		data.setRemark(resultSet->getString(4));
		data.setUnitArea(resultSet->getString(5));
		if (resultSet->getMetaData()->getColumnCount() == 6)
			data.setFloorNum(resultSet->getString(6));
		return data;
	}
};

/*
 * unit表(单元表)字段匹配映射-创建智能指针对象
 */
class PtrUnitMapper : public Mapper<PtrUnitDO> {
public:
	PtrUnitDO mapper(ResultSet* resultSet) const override {
		auto data = std::make_shared<UnitDO>();
		data->setUnitId(resultSet->getString(1));
		data->setBId(resultSet->getString(2));
		data->setUnitNum(resultSet->getString(3));
		data->setFloorId(resultSet->getString(4));
		data->setLayerCount(resultSet->getInt(5));
		data->setLift(resultSet->getString(6));
		data->setUserId(resultSet->getString(7));
		data->setRemark(resultSet->getString(8));
		data->setCreateTime(resultSet->getString(9));
		data->setStatusCd(resultSet->getString(10));
		data->setUnitArea(resultSet->getString(11));
		return data;
	}
};
#endif