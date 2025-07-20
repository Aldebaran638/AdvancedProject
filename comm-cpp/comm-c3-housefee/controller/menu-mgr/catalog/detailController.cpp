#include "stdafx.h"
#include "detailController.h"
#include "../../../service/PaysFee/detailService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "NacosClient.h"
#include "FastDfsClient.h"


detailJsonVO::Wrapper detailController::execQueryDetail(const String &id)
{
	auto jvo = detailJsonVO::createShared();
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	detailService service;
	auto  res = service.getById(id.getValue({}));
	jvo->success(res);
	return jvo;
}

