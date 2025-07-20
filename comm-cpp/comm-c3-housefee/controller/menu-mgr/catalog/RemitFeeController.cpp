#include "stdafx.h"
#include "RemitFeeController.h"
#include "../../../service/PaysFee/RemitFeeService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
RemitFeePageJsonVO::Wrapper RemitFeeController::execQueryRecord(const RemitFeeQuery::Wrapper& query)
{
	RemitFeeService service;
	auto result = service.listAll(query);
	auto jvo = RemitFeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
