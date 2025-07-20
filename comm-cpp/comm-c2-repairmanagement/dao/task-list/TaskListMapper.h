#pragma once
#ifndef _TASKLISTMAPPER_
#define _TASKLISTMAPPER_

#include "Mapper.h"
#include "../../domain/do/task-list/TaskListDO.h"

/**
 * 工单池工单列表字段匹配映射
 */
class TaskListMapper : public Mapper<TaskListDO>
{
public:
	TaskListDO mapper(ResultSet* resultSet) const override
	{
		TaskListDO data;
		data.setRepairId(resultSet->getString("repair_id"));
		data.setRepairObjName(resultSet->getString("repair_obj_name"));
		data.setRepairTypeName(resultSet->getString("repair_type_name"));
		data.setMaintenanceTypeName(resultSet->getString("maintenance_type"));
		data.setRepairName(resultSet->getString("repair_name"));
		data.setTel(resultSet->getString("tel"));
		data.setAppointmentTime(resultSet->getString("appointment_time"));
		data.setCreateTime(resultSet->getString("create_time"));
		data.setStateName(resultSet->getString("state"));
		data.setMaintenanceTypeTxt(resultSet->getString("maintenance_type_txt"));
		data.setStateTxt(resultSet->getString("state_txt"));
		return data;
	}
};

/**
 * 工单池工单列表字段匹配映射-创建智能指针对象
 */
class PtrTaskListMapper : public Mapper<PtrTaskListDO>
{
public:
	PtrTaskListDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TaskListDO>();
		data->setRepairId(resultSet->getString("repair_id"));
		data->setRepairObjName(resultSet->getString("repair_obj_name"));
		data->setRepairTypeName(resultSet->getString("repair_type_name"));
		data->setMaintenanceTypeName(resultSet->getString("maintenance_type_name"));
		data->setRepairName(resultSet->getString("repair_name"));
		data->setTel(resultSet->getString("tel"));
		data->setAppointmentTime(resultSet->getString("appointment_time"));
		data->setCreateTime(resultSet->getString("create_time"));
		data->setStateName(resultSet->getString("state_name"));
		return data;
	}
};

#endif // !_TASKLISTMAPPER_