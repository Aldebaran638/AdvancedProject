#include "stdafx.h"
#include "UnrepairService.h"
#include "../../../dao/report_management/repair_report/UnrepairDAO.h"
#include "../../../domain/do/repair_report/UnrepairDO.h"
#include "../../../../arch-demo/Macros.h"

UnrepairPageDTO::Wrapper UnrepairService::listAll(const UnrepairQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = UnrepairPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	UnrepairDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<UnrepairDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (UnrepairDO sub : result)
	{
		auto dto = UnrepairDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repairId, RepairId, createTime, CreateTime, repairName, RepairName, tel, Tel, repairObjName, RepairObjName, staffName, StaffName, endTime, EndTime, state, State);
		pages->addData(dto);
	}
	return pages;
}
