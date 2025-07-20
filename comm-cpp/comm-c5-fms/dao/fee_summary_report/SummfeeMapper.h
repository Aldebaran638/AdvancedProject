#pragma once
#ifndef _SUMMFEE_MAPPER_
#define _SUMMFEE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/fee_summary_report/SummfeeDO.h"

/**
 * 示例表字段匹配映射
 */
class SummfeeMapper : public Mapper<SummfeeDO>
{
public:
	SummfeeDO mapper(ResultSet* resultSet) const override
	{
		SummfeeDO data;
		// 
		data.setCreate_time(resultSet->getString(1));
		// 费用项id
		data.setObj_id(resultSet->getString(2));
		// 费用项名称
		data.setObj_name(resultSet->getString(3));
		// 应收金额
		data.setReceivable_amount(resultSet->getInt(4));
		// 实收金额
		data.setAmount(resultSet->getInt(5));
		return data;
	}
};

#endif // !_SUMMFEE_MAPPER_