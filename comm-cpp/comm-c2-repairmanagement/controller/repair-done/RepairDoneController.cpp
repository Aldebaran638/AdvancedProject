#include "stdafx.h"
#include "RepairDoneController.h"
#include "../../service/repair-done/RepairDoneService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

RepairDonePageJsonVO::Wrapper RepairDoneController::execQueryAll(const RepairDoneQuery::Wrapper& query)
{
	// 定义一个Service
	RepairDoneService service;
	// 查询数据
	auto result = service.RepairDone_listAll(query);
	// 响应结果
	auto jvo = RepairDonePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
