#pragma once

#ifndef _COMMUNITYVENUE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "domain/do/communityvenue/CommunityVenueDO.h"

class CommunityVenueMapper :public Mapper<CommunityVenueDO>
{
public:
	CommunityVenueDO mapper(ResultSet* resultSet)const override
	{
		CommunityVenueDO data;
		data.setVenueId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setRemark(resultSet->getString(3));
		data.setBId(resultSet->getString(4));
		data.setCommunityId(resultSet->getString(5));
		data.setCreateTime(resultSet->getString(6));
		data.setStatusCd(resultSet->getString(7));
		data.setStartTime(resultSet->getString(8));
		data.setEndTime(resultSet->getString(9));
		return data;
	}
};

class PtrCommunityVenueMapper :public Mapper<PtrCommunityVenueDO>
{
public:
	PtrCommunityVenueDO mapper(ResultSet* resultSet)const override
	{
		auto data=std::make_shared<CommunityVenueDO>();
		data->setVenueId(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		data->setRemark(resultSet->getString(3));
		data->setBId(resultSet->getString(4));
		data->setCommunityId(resultSet->getString(5));
		data->setCreateTime(resultSet->getString(6));
		data->setStatusCd(resultSet->getString(7));
		data->setStartTime(resultSet->getString(8));
		data->setEndTime(resultSet->getString(9));
		return data;
	}
};

#endif //!_COMMUNITY_MAPPER_