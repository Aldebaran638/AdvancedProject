#include"stdafx.h"
#include"CancellationFeeController.h"
#include"service/fee_cancellations/CancellationFeeService.h"
#include "../ApiDeclarativeServicesHelper.h"

CancellationFeePageJsonVO::Wrapper CancellationFeeController::execQueryAll(const CancellationFeeQuery::Wrapper& query)
{
	// 定义一个Service
	CancellationFeeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CancellationFeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper CancellationFeeController::execApplyCancel(const CancellationFeeApplyDTO::Wrapper& dto, const PayloadDTO& payload)
{	
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//参数检验
	if (dto->msg.getValue("").empty()|| dto->batchId.getValue("").empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	CancellationFeeService service;
	if (service.applyCancel(dto))
	{
		jvo->success(dto->msg);
	}
	else
	{
		jvo->fail(dto->msg);
	}
	return jvo;
}

StringJsonVO::Wrapper CancellationFeeController::execAuditCancel(const CancellationFeeAuditDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//参数检验
	if (dto->remark.getValue("").empty()|| dto->batchId.getValue("").empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	CancellationFeeService service;
	if (service.auditCancel(dto))
	{
		jvo->success(dto->remark);
	}
	else
	{
		jvo->fail(dto->remark);
	}
	return jvo;
}
