#include "OwnerListService.h"
#include "stdafx.h"
#include "../../dao/owner-list/OwnerListDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"

OwnerListPageDTO::Wrapper OwnerListService::listAll(const OwnerListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = OwnerListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	OwnerListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OwnerListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OwnerListDO sub : result)
	{
		auto dto = OwnerListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, acct_id, AcctId, acct_type, AcctType, name, Name, id_card, IdCard, link, Link, amount, Amount, create_time, CreateTime, acct_type_text, AcctTypeText);

		pages->addData(dto);
	}
	return pages;
}
