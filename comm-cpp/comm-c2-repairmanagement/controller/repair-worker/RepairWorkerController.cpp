#include "stdafx.h"
#include "RepairWorkerController.h"
#include "../../service/repair-worker/RepairWorkerService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

RepairWorkerPageJsonVO::Wrapper RepairWorkerController::execQueryAll(const RepairWorkerQuery::Wrapper& query)
{
	// 定义一个Service
	RepairWorkerService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RepairWorkerPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper RepairWorkerController::execAddRepairWorker(const RepairWorkerAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->community_id || !dto->org_name || !dto->repair_type_name||!dto->staff_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->community_id->empty() || dto->org_name->empty() || dto->repair_type_name->empty() || dto->staff_name->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RepairWorkerService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("fail");
	}
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper RepairWorkerController::execModifyRepairWorker(const RepairWorkerModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->staff_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RepairWorkerService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->staff_id);
	}
	else
	{
		jvo->fail(dto->staff_id);
	}
	// 响应结果
	return jvo;
}

ListJsonVO<String>::Wrapper RepairWorkerController::execRemoveRepairWorker(const List<String>& ids)
{
	// 定义返回数据对象
	auto jvo = ListJsonVO<String>::createShared();
	// 参数校验
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RepairWorkerService service;
	// 执行数据删除
	if (service.removeData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// 响应结果
	return jvo;
}
