#pragma once
#ifndef _REPAIRWORKERMAPPER_H_
#define _REPAIRWORKERMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/repair-worker-name/RepairWorkerNameDo.h"

/**
 * r_repair_type_user查询姓名字段匹配映射
 */
class RepairWorkerQueryMapper : public Mapper<RepairWorkerQueryDO>
{
public:
	RepairWorkerQueryDO mapper(ResultSet* resultSet) const override
	{
		RepairWorkerQueryDO data;
		data.setStaffId(resultSet->getString("staff_id"));
		data.setStaffName(resultSet->getString("staff_name"));
		data.setRepairType(resultSet->getString("repair_type"));
		data.setRepairTypeName(resultSet->getString("repair_type_name"));
		data.setState(resultSet->getString("state"));
		data.setStateTxt(resultSet->getString("state_txt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCreateTime(resultSet->getString("create_time"));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrRepairWorkerQueryMapper : public Mapper<PtrRepairWorkerQueryDO>
{
public:
	PtrRepairWorkerQueryDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairWorkerQueryDO>();
		data->setStaffId(resultSet->getString("staff_id"));
		data->setStaffName(resultSet->getString("staff_name"));
		data->setRepairType(resultSet->getString("repair_type"));
		data->setRepairTypeName(resultSet->getString("repair_type_name"));
		data->setState(resultSet->getString("state"));
		data->setStateTxt(resultSet->getString("state_txt"));
		data->setRemark(resultSet->getString("remark"));
		data->setCreateTime(resultSet->getString("create_time"));
		return data;
	}
};
/**
 * r_repair_type_user修改状态字段匹配映射
 */
class RepairWorkerModifyMapper : public Mapper<RepairWorkerModifyDO>
{
public:
	RepairWorkerModifyDO mapper(ResultSet* resultSet) const override
	{
		RepairWorkerModifyDO data;
		data.setStaffId(resultSet->getString("staff_id"));
		data.setState(resultSet->getString("state"));
		data.setRemark(resultSet->getString("remark"));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrRepairWorkerModifyMapper : public Mapper<PtrRepairWorkerModifyDO>
{
public:
	PtrRepairWorkerModifyDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairWorkerModifyDO>();
		data->setStaffId(resultSet->getString("staff_id"));
		data->setState(resultSet->getString("state"));
		data->setRemark(resultSet->getString("remark"));
		data->setCommunityId(resultSet->getString("community_id"));
		return data;
	}
};

#endif // !_REPAIRWORKERMAPPER_H_