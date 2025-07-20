#include "stdafx.h"
#include "CarController.h"
#include "../../service/listCarService/listCarService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

CarPageJsonVO::Wrapper CarController::execQueryCar(const CarQuery::Wrapper& query)
{
	listCarService service;
	auto result = service.listAll(query);
	// ÏìÓ¦½á¹û
	auto jvo = CarPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}