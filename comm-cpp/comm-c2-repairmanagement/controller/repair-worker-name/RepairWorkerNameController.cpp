#include "stdafx.h"
#include "RepairWorkerNameController.h"
#include "../../service/repair-woker-name/RepairWorkerNameService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

RepairWorkerNamePageJsonVO::Wrapper RepairWorkerNameController::execQueryByRepairTypeName(const RepairWorkerNameQuery::Wrapper& query)
{

	// 定义一个Service
	RepairWorkerNameService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RepairWorkerNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
