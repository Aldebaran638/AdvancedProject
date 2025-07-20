#ifndef _TASKDETAIL_MAPPER_
#define _TASKDETAIL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/task-detail/TaskDetailDO.h"

/**
 * 工单详情字段匹配映射
 */
class TaskDetailGetMapper : public Mapper<TaskDetailGetDO>
{
public:
	TaskDetailGetDO mapper(ResultSet* resultSet) const override
	{
		TaskDetailGetDO data;
		data.setRepairId(resultSet->getString(1));
		data.setRepairType(resultSet->getString(2));
		data.setRepairTypeTxt(resultSet->getString(3));
		data.setRepairName(resultSet->getString(4));
		data.setTel(resultSet->getString(5));
		data.setRepairObjName(resultSet->getString(6));
		data.setAppointmentTime(resultSet->getString(7));
		data.setState(resultSet->getString(8));
		data.setStateTxt(resultSet->getString(9));
		data.setContext(resultSet->getString(10));
		data.setCreateTime(resultSet->getString(11));
		return data;
	}
};

/**
 * 工单详情字段匹配映射-创建智能指针对象
 */
class PtrTaskDetailGetMapper : public Mapper<PtrTaskDetailGetDO>
{
public:
	PtrTaskDetailGetDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TaskDetailGetDO>();
		data->setRepairId(resultSet->getString(1));
		data->setRepairType(resultSet->getString(2));
		data->setRepairTypeTxt(resultSet->getString(3)); // 添加 repairTypeTxt 字段映射
		data->setRepairName(resultSet->getString(4));
		data->setTel(resultSet->getString(5));
		data->setRepairObjName(resultSet->getString(6));
		data->setAppointmentTime(resultSet->getString(7));
		data->setState(resultSet->getString(8));
		data->setStateTxt(resultSet->getString(9)); // 添加 stateTxt 字段映射
		data->setContext(resultSet->getString(10));
		data->setCreateTime(resultSet->getString(11));
		return data;
	}
};

/**
 * 派单r_repair_pool查询结果字段匹配映射
 */
class RepairPoolMapper : public Mapper<TaskDetailDO>
{
public:
	TaskDetailDO mapper(ResultSet* resultSet) const override
	{
		TaskDetailDO data;
		data.setRepairType(resultSet->getString(1));
		data.setCommunityId(resultSet->getString(2));
		return data;
	}
};

/**
 * 派单r_repair_type_user查询结果字段匹配映射
 */
class RepairTypeUserMapper : public Mapper<TaskDetailDO>
{
public:
	TaskDetailDO mapper(ResultSet* resultSet) const override
	{
		TaskDetailDO data;
		data.setStaffId(resultSet->getString(1));
		data.setStaffName(resultSet->getString(2));
		return data;
	}
};
/**
 * 派单r_repair_user查询结果字段匹配映射
 */
class RepairUserMapper : public Mapper<TaskDetailDO>
{
public:
	TaskDetailDO mapper(ResultSet* resultSet) const override
	{
		TaskDetailDO data;
		data.setRuId(resultSet->getString(1));
		data.setStaffId(resultSet->getString(2));
		data.setStaffName(resultSet->getString(3));
		return data;
	}
};

class PtrExportTaskDetailMapper : public Mapper<PtrTaskDetailDO>
{
public:
	PtrTaskDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TaskDetailDO>();
		data->setRepairId(resultSet->getString(1));
		data->setRepairName(resultSet->getString(2));
		data->setTel(resultSet->getString(3));
		data->setRepairObjName(resultSet->getString(4));
		data->setTaskContext(resultSet->getString(5));
		data->setRepairTypeName(resultSet->getString(6));
		data->setMaintenanceTypeName(resultSet->getString(7));
		return data;
	}
};

class ExportCirculateMapper : public Mapper<TaskDetailDO>
{
public:
	TaskDetailDO mapper(ResultSet* resultSet) const override
	{
		TaskDetailDO data;
		data.setStaffName(resultSet->getString(1));
		data.setState(resultSet->getString(2));
		data.setStartTime(resultSet->getString(3));
		data.setCost(resultSet->getString(4));
		data.setUserContext(resultSet->getString(5));
		return data;
	}
};

#endif // !_TASKDETAIL_MAPPER_