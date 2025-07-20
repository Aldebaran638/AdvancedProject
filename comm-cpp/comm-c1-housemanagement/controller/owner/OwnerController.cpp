#include "stdafx.h"
#include "OwnerController.h"
#include "../../service/listOwnerService/listOwnerService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

OwnerPageJsonVO::Wrapper OwnerController::execQueryOwner(const OwnerQuery::Wrapper& query)
{
	listOwnerService service;
	auto result = service.listAll(query);
	// ÏìÓ¦½á¹û
	auto jvo = OwnerPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}