#ifndef _DISCOUNT_MAPPER_H_
#define _DISCOUNT_MAPPER_H_

#include "Mapper.h"
#include "domain/do/feediscount/DiscountDo.h"

class DiscountPageMapper : public Mapper<DiscountPageDo> {

public:
	DiscountPageDo mapper(ResultSet* resultSet) const override
	{
		DiscountPageDo data;
		//根据列索引来查询
		data.setDiscountId(resultSet->getString(1));
		data.setDiscountName(resultSet->getString(2));
		data.setDiscountType(resultSet->getString(3));
		data.setRuleName(resultSet->getString(4));
		data.setCreateTime(resultSet->getString(5));
		data.setRuleId(resultSet->getString(6));
		return data;
	}
};

class DiscountSpecPageMapper : public Mapper<DiscountSpecPageDo> {
public:
	DiscountSpecPageDo mapper(ResultSet* resultSet) const override
	{
		DiscountSpecPageDo data;
		//根据列索引来查询
		data.setSpecName(resultSet->getString(1));
		data.setSpecValue(resultSet->getString(2));
		return data;
	}

};

#endif //_DISCOUNT_MAPPER_H_