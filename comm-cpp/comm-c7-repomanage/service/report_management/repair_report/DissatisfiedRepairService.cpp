#include "stdafx.h"
#include "DissatisfiedRepairService.h"
#include "../comm-c7-repomanage/dao/report_management/repair_report/DissatisfiedRepairDAO.h"
#include "../../lib-common/include/id/SnowFlake.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"

DissatisfiedRepairPageDTO::Wrapper DissatisfiedRepairService::listAll(const DissatisfiedRepairQuery::Wrapper& query)
{

	auto pages = DissatisfiedRepairPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	DissatisfiedRepairDAO dao;
	uint64_t count = dao.count(query);

	pages->total = count;
	pages->calcPages();
	list<DissatisfiedRepairDO> result = dao.selectWithPage(query);

	for (DissatisfiedRepairDO sub : result)
	{
		auto dto = DissatisfiedRepairDTO::createShared();
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_time, RepairTime, repair_location, RepairLocation, repair_id, RepairId, status, Status, reason, Reason);

		pages->addData(dto);
	}
	return pages;
}

std::list<DissatisfiedRepairDO> DissatisfiedRepairService::listAllExport()
{
	DissatisfiedRepairDAO dao;
	return dao.listAllDO();
}