#include "stdafx.h"
#include "modifyController.h"
#include "../../../service/PaysFee/modifyService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
modifyPageJsonVO::Wrapper modifyController::execQueryById(const modifyQuery::Wrapper& query)
{
	//auto jvo = modifyJsonVO::createShared();

	//if (!id)
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//modifyService service;
	//auto res = service.getById(id.getValue({}));
	//jvo->success(res);

	//return jvo;



	modifyService service;
	auto result = service.getById(query);
	auto jvo = modifyPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

