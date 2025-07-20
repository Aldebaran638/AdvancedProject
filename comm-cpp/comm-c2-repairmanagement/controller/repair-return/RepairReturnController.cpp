#include "stdafx.h"
#include "RepairReturnController.h"
#include "../../service/repair-return/RepairReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

//分页查询强制回单执行函数
RepairReturnPageJsonVO::Wrapper RepairReturnController::execQueryRepairReturn(const RepairReturnQuery::Wrapper& query)
{
	// 定义一个Service
	RepairReturnService service;
	// 查询数据
	auto result = service.RepairReturn_listAll(query);
	// 响应结果
	auto jvo = RepairReturnPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//添加强制回单结果执行函数
StringJsonVO::Wrapper RepairReturnController::execAddRepairReturnDetail(const RepairReturnAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->visit_type || !dto->context)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->visit_type->empty() || dto->context->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RepairReturnService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string repair_id = service.RepairReturn_saveData(dto);
	if (repair_id != "") {
		jvo->success(repair_id);
	}
	else
	{
		jvo->fail("");
	}
	//响应结果
	return jvo;
}

