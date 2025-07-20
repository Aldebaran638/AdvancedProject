#pragma once
#ifndef _REPAIRREPORTQUERY_H_
#define _REPAIRREPORTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class RepairReportFeeQuery : public PageQuery
{
	DTO_INIT(RepairReportFeeQuery, PageQuery);

	// 订单号（支持模糊查询）
	API_DTO_FIELD_DEFAULT(String, repairId, ZH_WORDS_GETTER("repair-report-fee.field.repairId"));

	// 起始日期（格式：yyyy-MM-dd）
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("repair-report-fee.field.startDate"));

	// 终止日期（格式：yyyy-MM-dd）
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("repair-report-fee.field.endDate"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_