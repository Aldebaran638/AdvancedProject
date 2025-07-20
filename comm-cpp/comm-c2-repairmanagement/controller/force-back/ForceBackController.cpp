#include "stdafx.h"
#include "ForceBackController.h"
#include "../../service/force-back/ForceBackService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//分页查询强制回单执行函数
ForceBackPageJsonVO::Wrapper ForceBackController::execQueryForceBack(const ForceBackQuery::Wrapper& query)
{
	// 定义一个Service
	ForceBackService service;
	// 查询数据
	auto result = service.ForceBack_listAll(query);
	// 响应结果
	auto jvo = ForceBackPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//修改强制回单状态
StringJsonVO::Wrapper ForceBackController::execModifyForceBack(const ForceBackModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->repair_id && !dto->context)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ForceBackService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.ForceBack_updateData(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// 响应结果
	return jvo;
}