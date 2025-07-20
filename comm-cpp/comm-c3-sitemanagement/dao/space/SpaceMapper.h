#pragma once

#ifndef _SPACE_MAPPER_
#define _SPACE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/space/SpaceDO.h"

/**
 * space表字段匹配映射
 */
class SpaceMapper : public Mapper<SpaceDO>
{
public:
	SpaceDO mapper(ResultSet* resultSet) const override
	{
		SpaceDO data;
		data.setSpaceId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setStartTime(resultSet->getString(3));
		data.setEndTime(resultSet->getString(4));
		data.setFeeMoney(resultSet->getDouble(5));
		data.setAdminName(resultSet->getString(6));
		data.setTel(resultSet->getString(7));
		data.setCommunityId(resultSet->getString(8));
		data.setState(resultSet->getString(9));
		data.setCreateTime(resultSet->getString(10));
		data.setStatusCd(resultSet->getString(11));
		data.setVenueId(resultSet->getString(12));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrSpaceMapper : public Mapper<PtrSpaceDO>
{
public:
	PtrSpaceDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<SpaceDO>();
		data->setSpaceId(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		data->setStartTime(resultSet->getString(3));
		data->setEndTime(resultSet->getString(4));
		data->setFeeMoney(resultSet->getDouble(5));
		data->setAdminName(resultSet->getString(6));
		data->setTel(resultSet->getString(7));
		data->setCommunityId(resultSet->getString(8));
		data->setState(resultSet->getString(9));
		data->setCreateTime(resultSet->getString(10));
		data->setStatusCd(resultSet->getString(11));
		data->setVenueId(resultSet->getString(12));
		return data;
	}
};

#endif // !_SPACE_MAPPER_