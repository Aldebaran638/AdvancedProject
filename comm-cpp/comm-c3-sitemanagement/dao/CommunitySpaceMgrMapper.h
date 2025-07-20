#pragma once

#include "Mapper.h"
#include "domain/do/CommunitySpaceMgrDO.h"

/**
 * 示例表字段匹配映射
 */
class CommunitySpaceMgrMapper : public Mapper<CommunitySpaceMgrDO>
{
public:
	CommunitySpaceMgrDO mapper(ResultSet* resultSet) const override
	{
		CommunitySpaceMgrDO data;
		data.setSpace_Id(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setStart_Time(resultSet->getString(3));
		data.setEnd_Time(resultSet->getString(4));
		data.setFee_Money(resultSet->getDouble(5));
		data.setAdmin_Name(resultSet->getString(6));
		data.setTel(resultSet->getString(7));
		data.setState(resultSet->getString(8));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrCommunitySpaceMgrMapper : public Mapper<PtrCommunitySpaceMgrDO>
{
public:
	PtrCommunitySpaceMgrDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CommunitySpaceMgrDO>();
		data->setSpace_Id(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		data->setStart_Time(resultSet->getString(3));
		data->setEnd_Time(resultSet->getString(4));
		data->setFee_Money(resultSet->getDouble(5));
		data->setAdmin_Name(resultSet->getString(6));
		data->setTel(resultSet->getString(7));
		data->setState(resultSet->getString(8));
		return data;
	}
};



/**
 * 示例表字段匹配映射
 */
class CommunitySpaceTimeMgrMapper : public Mapper<CommunitySpaceTimeMgrDO>
{
public:
	CommunitySpaceTimeMgrDO mapper(ResultSet* resultSet) const override
	{
		CommunitySpaceTimeMgrDO data;
		data.setSpace_Id(resultSet->getString(1));
		data.setHours(resultSet->getInt(2));
		data.setIs_Open(resultSet->getString(3));
		data.setTime_Id(resultSet->getString(4));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrCommunitySpaceTimeMgrMapper : public Mapper<PtrCommunitySpaceTimeMgrDO>
{
public:
	PtrCommunitySpaceTimeMgrDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CommunitySpaceTimeMgrDO>();
		data->setSpace_Id(resultSet->getString(1));
		data->setHours(resultSet->getInt(2));
		data->setIs_Open(resultSet->getString(3));
		data->setTime_Id(resultSet->getString(4));
		return data;
	}
};
