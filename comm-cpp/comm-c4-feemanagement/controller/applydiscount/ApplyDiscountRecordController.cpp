#include "stdafx.h"
#include "ApplyDiscountRecordController.h"
#include "../../service/applydiscount/ApplyDiscountRecordService.h"
#include "../ApiDeclarativeServicesHelper.h"

ApplyDiscountRecordPageJsonVO::Wrapper ApplyDiscountRecordController::execQueryRecord(const ApplyDiscountRecordQuery::Wrapper& query)
{
	// 定义一个Service
	ApplyDiscountRecordService service;
	// 查询数据
	auto result = service.listRecord(query);
	// 响应结果
	auto jvo = ApplyDiscountRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}



StringJsonVO::Wrapper ApplyDiscountRecordController::execRemoveApplyDiscount(const ApplyDiscountDeleteDTO::Wrapper& id, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	//if (id->empty())
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// 定义一个Service
	if (!id->ard_id) {
		jvo->fail(String("need discount_id"));
		return jvo;
	}
	ApplyDiscountRecordService service;
	// 执行数据删除
	if (service.removeData(id,payload)) {
		jvo->success(String("delete success"));
	}
	else
	{
		jvo->fail(String("delete fail"));
	}
	// 响应结果
	return jvo;
}


StringJsonVO::Wrapper ApplyDiscountRecordController::execModifyState(const ApplyDiscountStateDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->state)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ApplyDiscountRecordService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateState(dto)) {
		jvo->success(dto->state);
	}
	else
	{
		jvo->fail(dto->state);
	}
	// 响应结果
	return jvo;
}
