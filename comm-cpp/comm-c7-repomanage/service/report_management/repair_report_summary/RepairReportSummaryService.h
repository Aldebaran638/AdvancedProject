#pragma once
#ifndef _REPAIR_REPORT_SUMMARY_SERVICE_
#define _REPAIR_REPORT_SUMMARY_SERVICE_
#include "../../../domain/vo/repair_report_summary/RepairReportSummaryVO.h"
#include "../../../domain/query/repair_report_summary/RepairReportSummaryQuery.h"
#include "../../../domain/dto/repair_report_summary/RepairReportSummaryDTO.h"
#include "../../../domain/do/repair_report_summary/RepairReportSummaryDO.h"

class RepairReportSummaryService
{
public:
	// 分页查询所有数据
	RepairReportSummaryPageDTO::Wrapper listAll(const RepairReportSummaryQuery::Wrapper& query);	
};

#endif // !_REPAIR_REPORT_SUMMARY_SERVICE_