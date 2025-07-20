#pragma once
#ifndef _REPAIRWORKERNAMEMAPPER_H_
#define _REPAIRWORKERNAMEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/repair-worker-name/RepairWorkerNameDo.h"

/**
 * r_repair_type_user查询姓名字段匹配映射
 */
class RepairWorkerNameMapper : public Mapper<RepairWorkerNameDO>
{
public:
	RepairWorkerNameDO mapper(ResultSet* resultSet) const override
	{
		RepairWorkerNameDO data;
		data.setStaffName(resultSet->getString("staff_name"));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrRepairWorkerNameMapperMapper : public Mapper<PtrRepairWorkerNameDO>
{
public:
	PtrRepairWorkerNameDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairWorkerNameDO>();
		data->setStaffName(resultSet->getString(1));
		return data;
	}
};

#endif // !_REPAIRWORKERNAMEMAPPER_H_