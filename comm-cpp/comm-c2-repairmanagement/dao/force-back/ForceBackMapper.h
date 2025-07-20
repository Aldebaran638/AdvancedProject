#pragma once
#ifndef _FORCEBACKMAPPER_H_
#define _FORCEBACKMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/force-back/ForceBackDO.h"

/**
 * 示例表字段匹配映射
 */
class ForceBackMapper : public Mapper<ForceBackDO>
{
public:
	ForceBackDO mapper(ResultSet* resultSet) const override
	{
		ForceBackDO data;
		//与sql查询顺序一致
		data.setRepairId(resultSet->getString(1));
		data.setRepairObjName(resultSet->getString(2));
		data.setRepairType(resultSet->getString(3));
		data.setRepairTypeDetail(resultSet->getString(4));
		data.setRepairName(resultSet->getString(5));
		data.setTel(resultSet->getString(6));
		data.setAppointmentTime(resultSet->getString(7));
		data.setCreateTime(resultSet->getString(8));
		data.setState(resultSet->getString(9));
		data.setStateDetail(resultSet->getString(10));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrForceBackMapper : public Mapper<PtrForceBackDO>
{
public:
	PtrForceBackDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ForceBackDO>();
		//与sql查询顺序一致
		data->setRepairId(resultSet->getString(1));
		data->setRepairObjName(resultSet->getString(2));
		data->setRepairType(resultSet->getString(3));
		data->setRepairTypeDetail(resultSet->getString(4));
		data->setRepairName(resultSet->getString(5));
		data->setTel(resultSet->getString(6));
		data->setAppointmentTime(resultSet->getString(7));
		data->setCreateTime(resultSet->getString(8));
		data->setState(resultSet->getString(9));
		data->setStateDetail(resultSet->getString(10));
		return data;
	}
};
// 处理意见：查询字段匹配映射
class PtrRepairToDoSelectToRemoveMapper : public Mapper<PtrForceBackDO>
{
public:
	PtrForceBackDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ForceBackDO>();
		data->setRuId(resultSet->getString(1));
		data->setBId(resultSet->getString(2));
		data->setCommunityId(resultSet->getString(3));
		data->setCreateTime(resultSet->getString(4));
		data->setState(resultSet->getString(5));
		data->setContext(resultSet->getString(6));
		data->setRuStatusCd(resultSet->getString(7));
		data->setRuStaffId(resultSet->getString(8));
		data->setRuStaffName(resultSet->getString(9));
		data->setPreStaffId(resultSet->getString(10));
		data->setPreStaffName(resultSet->getString(11));
		data->setStartTime(resultSet->getString(12));
		data->setEndTime(resultSet->getString(13));
		data->setRepairEvent(resultSet->getString(14));
		data->setPreRuId(resultSet->getString(15));
		return data;
	}
};
// 办结操作，查询库存
/*class RepairToDoSelectResourceByUseIdAndResIdMapper : public Mapper<ForceBackDO>
{
public:
	ForceBackDO mapper(ResultSet* resultSet) const override
	{
		ForceBackDO data;
		data.setStock(resultSet->getString(1));
		data.setStoreId(resultSet->getString(2));
		return data;
	}
};*/
#endif // !_FORCEBACKMAPPER_H_