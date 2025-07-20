#pragma once
#ifndef _RAINDISTYPESMAPPER_H_
#define _RAINDISTYPESMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/discount_types/RainDisTypesDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class RainDisTypesMapper : public Mapper<RainDisTypesDO>
{
public:
	RainDisTypesDO mapper(ResultSet* resultSet) const override
	{
		RainDisTypesDO data;
		data.setApplyType(resultSet->getString(1));
		data.setTypeName(resultSet->getString(2));
		data.setCommunityId(resultSet->getString(3));
		data.setTypeDesc(resultSet->getString(4));
		data.setCreateTime(resultSet->getString(5));
		data.setStatusCd(resultSet->getString(6));
		return data;
	}
};


#endif // !_RAINDISTYPESMAPPER_H_