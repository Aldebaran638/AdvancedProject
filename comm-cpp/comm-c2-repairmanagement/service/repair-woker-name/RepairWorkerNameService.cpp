#include "stdafx.h"
#include "RepairWorkerNameService.h"
#include "../../dao/repair-worker-name/RepairWorkerNameDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
//查询维修师傅名称service层实现
RepairWorkerNamePageDTO::Wrapper RepairWorkerNameService::listAll(const RepairWorkerNameQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairWorkerNamePageDTO::createShared();
	
	RepairWorkerNameDAO dao;
	// 分页查询数据
	list<RepairWorkerNameDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RepairWorkerNameDO sub : result)
	{
		auto dto = RepairWorkerNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, staff_name, StaffName);
		pages->addData(dto);
	}
	return pages;
}

