#pragma once
#ifndef _CLASSIFICATIONTABLE_MAPPER_
#define _CLASSIFICATIONTABLE_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/repair_report/ClassificationTableDO.h"

class ClassificationTableMapper : public Mapper<ClassificationTableDO>
{
public:
	ClassificationTableDO mapper(ResultSet* resultSet) const override
	{
		ClassificationTableDO data;
		data.setPublicArea(resultSet->getString(1));
		data.setRepairTypeName(resultSet->getString(2));
		data.setTypeCount(resultSet->getInt(3));
		return data;
	}
};
class PtrClassificationTableMapper : public Mapper<PtrClassificationTableDO>
{
public:
	PtrClassificationTableDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ClassificationTableDO>();
		data->setPublicArea(resultSet->getString(1));
		data->setRepairTypeName(resultSet->getString(2));
		data->setTypeCount(resultSet->getInt(3));
		return data;
	}
};
#endif // !CLASSIFICATIONTABLE_MAPPER