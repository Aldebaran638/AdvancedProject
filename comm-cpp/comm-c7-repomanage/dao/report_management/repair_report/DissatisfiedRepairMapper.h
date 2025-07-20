#pragma once

#ifndef _DISSATISFIEDREPAIR_MAPPER_
#define _DISSATISFIEDREPAIR_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/repair_report/DissatisfiedRepairDO.h"

class DissatisfiedRepairMapper : public Mapper<DissatisfiedRepairDO>
{
public:
	DissatisfiedRepairDO mapper(ResultSet* resultSet) const override
	{
		DissatisfiedRepairDO data;
		data.setRepairTime(resultSet->getString(1));
		data.setRepairLocation(resultSet->getString(2));
		data.setRepairId(resultSet->getString(3));
		data.setStatus(resultSet->getString(4));
		data.setReason(resultSet->getString(5));
		return data;
	}
};
class PtrDissatisfiedRepairMapper : public Mapper<PtrDissatisfiedRepairDO>
{
public:
	PtrDissatisfiedRepairDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<DissatisfiedRepairDO>();
		data->setRepairTime(resultSet->getString(1));
		data->setRepairLocation(resultSet->getString(2));
		data->setRepairId(resultSet->getString(3));
		data->setStatus(resultSet->getString(4));
		data->setReason(resultSet->getString(5));
		return data;
	}
};

#endif // !_DISSATISFIEDREPAIR_MAPPER_