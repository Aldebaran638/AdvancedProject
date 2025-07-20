#pragma once
#ifndef _INSPECTION_POINT_STATISTIC_MAPPER_H_
#define _INSPECTION_POINT_STATISTIC_MAPPER_H_
//InspectionPointStatisticMapper
#include "Mapper.h"
#include "domain/do/inspection_report/InspectionPointStatisticDO.h"

/**
 * 字段匹配映射
 */
class InspectionPointStatisticMapper : public Mapper<InspectionPointStatisticDO>
{
public:
	InspectionPointStatisticDO mapper(ResultSet* resultSet) const override
	{
		InspectionPointStatisticDO data;
		data.setInspectionPointName(resultSet->getString(1));
		data.setPointObjName(resultSet->getString(2));
		data.setStaffName(resultSet->getString(3));
		data.setInspectEd(resultSet->getInt(4));
		data.setUnInspection(resultSet->getInt(5));
		data.setState(resultSet->getString(6));
		return data;
	}
};

/**
 * 巡检统计表字段匹配映射-创建智能指针对象
 */
class PtrInspectionPointStatisticMapper : public Mapper<PtrInspectionPointStatisticDO>
{
public:
	PtrInspectionPointStatisticDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<InspectionPointStatisticDO>();
		data->setInspectionPointName(resultSet->getString(1));
		data->setPointObjName(resultSet->getString(2));
		data->setStaffName(resultSet->getString(3));
		data->setState(resultSet->getString(4));
		data->setInspectEd(resultSet->getInt(5));
		data->setUnInspection(resultSet->getInt(6));
		return data;
	}
};

#endif // !_INSPECTION_POINT_STATISTIC_MAPPER_H_