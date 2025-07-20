#pragma once
#ifndef _REPAIRSETTINGMAPPER_H_
#define _REPAIRSETTINGMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/repair-setting-type/RepairSettingTypeDO.h"
/**
 * 获取报修类型设置字段匹配映射
 */
class RepairSettingMapper : public Mapper<RepairSettingDO>
{
public:
	RepairSettingDO mapper(ResultSet* resultSet) const override
	{
		RepairSettingDO data;
		data.setRepairTypeName(resultSet->getString(1));
		data.setRepairSettingType(resultSet->getString(2));
		data.setRepairWay(resultSet->getString(3));
		data.setPublicArea(resultSet->getString(4));
		data.setIsShow(resultSet->getString(5));
		data.setNotifyWay(resultSet->getString(6));
		data.setReturnVisitFlag(resultSet->getString(7));
		data.setCreateTime(resultSet->getString(8));

		return data;
	}
};

/**
 * 获取报修类型设置匹配映射-创建智能指针对象
 */
class PtrRepairSettingMapper : public Mapper<PtrRepairSettingDO>
{
public:
	PtrRepairSettingDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairSettingDO>();
		data->setRepairTypeName(resultSet->getString(1));
		data->setRepairSettingType(resultSet->getString(2));
		data->setRepairWay(resultSet->getString(3));
		data->setPublicArea(resultSet->getString(4));
		data->setIsShow(resultSet->getString(5));
		data->setNotifyWay(resultSet->getString(6));
		data->setReturnVisitFlag(resultSet->getString(7));
		data->setCreateTime(resultSet->getString(8));

		return data;
	}
};
#endif // !_REPAIRSETTINGMAPPER_H_