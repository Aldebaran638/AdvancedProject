#include "YArrears_RemindersController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "../../service/arrears_reminders/YArrears_RemindersService.h"

StringJsonVO::Wrapper YArrears_RemindersController::execAddReminder(const YArrears_RemindersAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->owner_name || !dto->payer_obj_name
		|| !dto->fee_name || !dto->amountd_owed || !dto->start_time
		|| !dto->callable_way || !dto->staff_name || !dto->state
		|| !dto->remark || !dto->create_time)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->owner_name->empty() || dto->payer_obj_name->empty()
		|| dto->fee_name->empty() || dto->amountd_owed < 0 || dto->start_time->empty()
		|| dto->callable_way->empty() || dto->staff_name->empty() || dto->state->empty()
		|| dto->remark->empty() || dto->create_time->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	YArrears_RemindersService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.addData(dto);
	if (!id.empty()) {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//响应结果
	return jvo;
	
}
