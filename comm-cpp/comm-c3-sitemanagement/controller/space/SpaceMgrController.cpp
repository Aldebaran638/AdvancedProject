#include "stdafx.h"
#include "SpaceMgrController.h"
#include "../../service/space/SpaceService.h"

// 添加场地执行函数
StringJsonVO::Wrapper SpaceMgrController::execAddSpace(const SpaceAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->name || !dto->feeMoney || !dto->adminName || !dto->tel || !dto->state)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->feeMoney < 0 || dto->name->empty() || dto->adminName->empty() || dto->tel->empty() || dto->state->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	SpaceService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.addSpace(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//响应结果
	return jvo;
}

// 修改场地执行函数
StringJsonVO::Wrapper SpaceMgrController::execModifySpace(const SpaceUpdateDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->spaceId || !dto->adminName || !dto->feeMoney || !dto->tel || !dto->name || !dto->state)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SpaceService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateSpace(dto)) {
		jvo->success(dto->spaceId);
	}
	else
	{
		jvo->fail(dto->spaceId);
	}
	// 响应结果
	return jvo;
}

// 删除场地执行函数
ListJsonVO<String>::Wrapper SpaceMgrController::execRemoveSpace(const List<String>& ids)
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
	SpaceService service;
	// 执行数据删除
	if (service.removeSpace(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// 响应结果
	return jvo;
}