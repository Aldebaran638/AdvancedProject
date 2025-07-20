#pragma once

#ifndef _REPAIRTODO_MAPPER_
#define _REPAIRTODO_MAPPER_
#include "Mapper.h"
#include "../../domain/do/repair-todo/RepairToDoDO.h"


// 查询所有维修类型映射
class RepairToDoSelectAllRepairTypeMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setRepairType(resultSet->getString(1));
		data.setRepairTypeName(resultSet->getString(2));
		return data;
	}
};

// 查询所有报修师傅映射
class RepairToDoSelectAllStaffMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setRuStaffId(resultSet->getString(1));
		data.setStaffName(resultSet->getString(2));
		return data;
	}
};




/**
 * 示例表字段匹配映射
 */
class RepairToDoMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setRepairId(resultSet->getString(1));
		data.setRepairObjName(resultSet->getString(2));
		data.setRepairTypeName(resultSet->getString(3));
		data.setRepairName(resultSet->getString(4));
		data.setTel(resultSet->getString(5));
		data.setAppointmentTime(resultSet->getString(6));
		data.setState(resultSet->getString(7));
		data.setPreStaffId(resultSet->getString(8));
		data.setPreStaffName(resultSet->getString(9));
		return data;
	}
};


// 查询字段匹配映射
class RepairToDoSelectMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setRuId(resultSet->getString(1));
		data.setBId(resultSet->getString(2));
		data.setCommunityId(resultSet->getString(3));
		data.setRuStaffId(resultSet->getString(4));
		data.setRuStaffName(resultSet->getString(5));
		data.setPreStaffId(resultSet->getString(6));
		data.setPreStaffName(resultSet->getString(7));
		data.setPreRuId(resultSet->getString(8));
		return data;
	}
};

// 查询r_repair_type_user字段匹配映射
class PtrRepairToDoSelectStaffIdMapper : public Mapper<PtrRepairToDoDO>
{
public:
	PtrRepairToDoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairToDoDO>();
		data->setRuStaffName(resultSet->getString(1));
		return data;
	}
};


// 查询r_repair_pool字段匹配映射
class PtrRepairToDoSelectRepairPoolMapper: public Mapper<PtrRepairToDoDO>
{
public:
	PtrRepairToDoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairToDoDO>();
		data->setBId(resultSet->getString(1));
		data->setCommunityId(resultSet->getString(2));
		data->setRepairType(resultSet->getString(3));
		data->setRepairName(resultSet->getString(4));
		data->setTel(resultSet->getString(5));
		data->setContext(resultSet->getString(6));
		data->setCreateTime(resultSet->getString(7));
		data->setState(resultSet->getString(8));
		data->setStatusCd(resultSet->getString(9));
		data->setRepairObjType(resultSet->getString(10));
		data->setRepairObjId(resultSet->getString(11));
		data->setRepairObjName(resultSet->getString(12));
		data->setAppointmentTime(resultSet->getString(13));
		data->setMaintenanceType(resultSet->getString(14));
		data->setRepairChannel(resultSet->getString(15));
		data->setRepairMaterials(resultSet->getString(16));
		data->setRepairFee(resultSet->getString(17));
		data->setPayType(resultSet->getString(18));


		return data;
	}
};


/**
 * 查询表r_repair_user字段匹配映射-创建智能指针对象
 */
class PtrRepairToDoSelectMapper : public Mapper<PtrRepairToDoDO>
{
public:
	PtrRepairToDoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairToDoDO>();
		data->setRuId(resultSet->getString(1));
		data->setBId(resultSet->getString(2));
		data->setCommunityId(resultSet->getString(3));
		data->setRuStaffId(resultSet->getString(4));
		data->setRuStaffName(resultSet->getString(5));
		data->setPreStaffId(resultSet->getString(6));
		data->setPreStaffName(resultSet->getString(7));
		data->setStartTime(resultSet->getString(8));
		data->setPreRuId(resultSet->getString(9));
		
		return data;
	}
};


/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrRepairToDoMapper : public Mapper<PtrRepairToDoDO>
{
public:
	PtrRepairToDoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairToDoDO>();
		data->setRepairObjName(resultSet->getString(1));
		data->setRepairTypeName(resultSet->getString(2));
		data->setRepairName(resultSet->getString(3));
		data->setTel(resultSet->getString(4));
		data->setAppointmentTime(resultSet->getString(5));
		data->setState(resultSet->getString(6));
		return data;
	}
};


// 退单操作：查询字段匹配映射
class PtrRepairToDoSelectToRemoveMapper : public Mapper<PtrRepairToDoDO>
{
public:
	PtrRepairToDoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairToDoDO>();
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


// 办结操作，查询报修对象类型
class RepairToDoSelectRepairObjTypeMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setRepairObjType(resultSet->getString(1));
		return data;
	}
};

// 办结操作，查询库存
class RepairToDoSelectResourceByUseIdAndResIdMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setStock(resultSet->getString(1));
		data.setStoreId(resultSet->getString(2));
		return data;
	}
};

// 办结操作，查询房间业主
class PtrRepairToDoSelectOwnerIdByRoomIdMapper : public Mapper<PtrRepairToDoDO>
{
public:
	PtrRepairToDoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairToDoDO>();
		data->setOwnerId(resultSet->getString(1));
		return data;
	}
};

// 办结操作，查询业主名称
class RepairToDoSelectOwnerNameMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setOwnerName(resultSet->getString(1));
		return data;
	}
};

// 办结操作，查询物业ID
class RepairToDoSelectPropertyIdByStaffIdMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setStoreId(resultSet->getString(1));
		return data;
	}
};

// 办结操作，查询费用项ID
class RepairToDoSelectConfigIdByCommunitIdMapper : public Mapper<RepairToDoDO>
{
public:
	RepairToDoDO mapper(ResultSet* resultSet) const override
	{
		RepairToDoDO data;
		data.setConfigId(resultSet->getString(1));
		return data;
	}
};




#endif // !_REPAIRTODO_MAPPER_