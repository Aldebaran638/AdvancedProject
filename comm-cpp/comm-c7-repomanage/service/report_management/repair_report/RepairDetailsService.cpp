#include "stdafx.h"
#include "RepairDetailsService.h"
#include "../../../dao/report_management/repair_report/RepairDetailsDAO.h"
#include "../../../domain/do/repair_report/RepairDetailsDO.h"
#include "../../../domain/dto/repair_report/RepairDetailsDTO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

RepairDetailsListPageDTO::Wrapper RepairDetailsService::listAll(const RepairDetailsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairDetailsListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RepairDetailsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RepairDetailsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RepairDetailsDO sub : result)
	{
		auto dto = RepairDetailsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, workOrderId, WorkOrderId, repairType, RepairType, requesterName, RequesterName,
			requestLocation, RequestLocation, requesterTelephone, RequesterTelephone, workOrderStatus, WorkOrderStatus, 
			requestTime, RequestTime, previousProcessor, PreviousProcessor, currentProcessor, CurrentProcessor, dispatchingTime, 
			DispatchingTime, handleTime, HandleTime, processorStatus, ProcessorStatus, requestContent, RequestContent);
		pages->addData(dto);
	}
	return pages;
}
