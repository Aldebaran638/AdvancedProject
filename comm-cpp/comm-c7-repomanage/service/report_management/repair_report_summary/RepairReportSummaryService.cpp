#include "stdafx.h"
#include "RepairReportSummaryService.h"
#include "../../../dao/report_management/repair_report_summary/RepairReportSummaryDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

RepairReportSummaryPageDTO::Wrapper RepairReportSummaryService::listAll(const RepairReportSummaryQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairReportSummaryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RepairReportSummaryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RepairReportSummaryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RepairReportSummaryDO sub : result)
	{
		auto dto = RepairReportSummaryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, summaryId, SummaryId, staffId, StaffId, staffName, StaffName, deal, Deal, sendList, SendList);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, transferList, TransferList, chargeback, Chargeback, returnVisit, ReturnVisit, finish, Finish, examineValue, ExamineValue);
		// statusCd, StatusCd,
		pages->addData(dto);
	}
	return pages;
}

