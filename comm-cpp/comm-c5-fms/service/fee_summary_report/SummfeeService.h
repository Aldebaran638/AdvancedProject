#pragma once
#ifndef _SUMMFEE_SERVICE_
#define _SUMMFEE_SERVICE_
#include "domain/vo/fee_summary_report/SummfeeVO.h"
#include "domain/query/fee_summary_report/SummfeeQuery.h"
#include "domain/dto/fee_summary_report/SummfeeDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class SummfeeService
{
public:
	// 分页查询所有数据
	FeeSummaryPageDTO::Wrapper listAll(const SummfeeQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_
