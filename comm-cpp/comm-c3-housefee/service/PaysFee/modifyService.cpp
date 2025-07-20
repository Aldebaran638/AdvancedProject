#include "stdafx.h"
#include "modifyService.h"
#include "../../dao/paysFee/modifyDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

modifyPageDTO::Wrapper modifyService::getById(const modifyQuery::Wrapper &query)
{
	auto pages = modifyPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	modifyDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
		return pages;
	pages->total = count;
	pages->calcPages();
	list<modifyDO> result = dao.selectById(query);
	for (modifyDO sub : result)
	{
		auto dto = modifyDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_id, FEE_ID, fee_pro,FEE_PRO, pay_start, PAY_START, pay_end, PAY_END, actions, ACTIONS, oporator, OPORATOR,opt_time,OPT_TIME);
		pages->addData(dto);
	}
	return pages;
}