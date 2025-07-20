#include "YyycDisTypesController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "../../service/discount_types/YyycDisTypesService.h"

StringJsonVO::Wrapper YyycDisTypesController::execModifyTypes(const YyycDisTypesDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->type_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	YyycDisTypesService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->type_id);
	}
	else
	{
		jvo->fail(dto->type_id);
	}
	// 响应结果
	return jvo;
	//return {};
}

ListJsonVO<String>::Wrapper YyycDisTypesController::execRemoveTypes(const List<String>& ids)
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
	YyycDisTypesService service;
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