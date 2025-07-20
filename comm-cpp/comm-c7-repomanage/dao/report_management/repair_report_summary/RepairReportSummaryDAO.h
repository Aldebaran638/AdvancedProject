#pragma once

#ifndef _REPAIR_REPORT_SUMMARY_DAO_
#define _REPAIR_REPORT_SUMMARY_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/repair_report_summary/RepairReportSummaryDO.h"
#include "../../../domain/query/repair_report_summary/RepairReportSummaryQuery.h"

/**
 * 报修汇总表数据库操作实现
 */
class RepairReportSummaryDAO : public BaseDAO
{
private:
	
	inline std::string queryConditionBuilder(const RepairReportSummaryQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询数据
	std::list<RepairReportSummaryDO> selectWithPage(const RepairReportSummaryQuery::Wrapper& query);
	// 统计数据条数
	uint64_t count(const RepairReportSummaryQuery::Wrapper& query);
	
};
#endif // !_REPAIR_REPORT_SUMMARY_DAO_

