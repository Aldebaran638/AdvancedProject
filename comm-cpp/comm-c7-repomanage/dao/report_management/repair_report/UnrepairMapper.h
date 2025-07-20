#ifndef _UNREPAIR_MAPPER_
#define _UNREPAIR_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/repair_report/UnrepairDO.h"

/**
 * 示例表字段匹配映射
 */
class UnrepairMapper : public Mapper<UnrepairDO>
{
public:
	UnrepairDO mapper(ResultSet* resultSet) const override
	{
		UnrepairDO data;
		data.setRepairId(resultSet->getString(1));
		data.setCreateTime(resultSet->getString(2));
		data.setRepairName(resultSet->getString(3));
		data.setTel(resultSet->getString(4));
		data.setRepairObjName(resultSet->getString(5));
		data.setStaffName(resultSet->getString(6));
		data.setEndTime(resultSet->getString(7));
		data.setState(resultSet->getString(8));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrUnrepairMapper : public Mapper<PtrUnrepairDO>
{
public:
	PtrUnrepairDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<UnrepairDO>();
		data->setRepairId(resultSet->getString(1));
		data->setCreateTime(resultSet->getString(2));
		data->setRepairName(resultSet->getString(3));
		data->setTel(resultSet->getString(4));
		data->setRepairObjName(resultSet->getString(5));
		data->setStaffName(resultSet->getString(6));
		data->setEndTime(resultSet->getString(7));
		data->setState(resultSet->getString(8));
		return data;
	}
};

#endif // !_UNREPAIR_MAPPER_
