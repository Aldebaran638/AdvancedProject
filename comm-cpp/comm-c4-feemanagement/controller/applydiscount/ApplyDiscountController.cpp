#include "stdafx.h"
#include "ApplyDiscountController.h"
#include "../../service/applydiscount/ApplyDiscountService.h"
#include "../ApiDeclarativeServicesHelper.h"

ApplyDiscountPageJsonVO::Wrapper ApplyDiscountController::execQueryAll(const ApplyDiscountQuery::Wrapper& query)
{
	// 定义一个Service
	ApplyDiscountService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ApplyDiscountPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ApplyDiscountController::execModifyAll(const ApplyDiscountDTO::Wrapper& dto, const PayloadDTO& payload)
{

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->ardId)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ApplyDiscountService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->ardId);
	}
	else
	{
		jvo->fail(dto->ardId);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper ApplyDiscountController::execAddAll(const ApplyDiscountAddDTO::Wrapper& addDto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!addDto->startTime || !addDto->endTime)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (addDto->startTime->empty() || addDto->endTime->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ApplyDiscountService service;
	// 执行数据新增
	addDto->setPayload(&payload);
	std::string id = service.saveData(addDto);
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
