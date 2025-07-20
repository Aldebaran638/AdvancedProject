#include "OwnerListController.h"
#include "../../service/owner-list/OwnerListService.h"
#pragma once

OwnerListPageJsonVO::Wrapper OwnerListController::execQueryAll(const OwnerListQuery::Wrapper& query)
{
	// 响应结果
	auto jvo = OwnerListPageJsonVO::createShared();

	// 数据校验
	// community_id
	if (!query->community_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// 定义一个Service
	OwnerListService service;
	// 查询数据
	auto result = service.listAll(query);

	jvo->success(result);
	return jvo;
}
