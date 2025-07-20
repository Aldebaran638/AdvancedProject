#include "stdafx.h"
#include "OwnerPayController.h"
#include "../../../../service/report_management/owner_payment/OwnerPaymentService.h"


OwnerPaymentPageJsonVO::Wrapper OwnerPaymentController::execQueryAll(const OwnerPaymentQuery::Wrapper& query)
{
	// 定义一个Service
	OwnerPaymentService service;
	// 查询数据
	auto result = service.listOwnerPayment(query);  // listAll
	// 响应结果
	auto jvo = OwnerPaymentPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return OwnerPaymentPageJsonVO::Wrapper();
}

OwnerPaymentFeeTypeJsonVO::Wrapper OwnerPaymentController::execQueryOwnerPaymentFeeType(const OwnerPaymentListQuery::Wrapper& query)
{
	// 定义一个Service
	OwnerPaymentService service;
	// 查询数据
	auto result = service.listFeeTypeList(query);  // listAll
	// 响应结果
	auto jvo = OwnerPaymentFeeTypeJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

OwnerPaymentConfigNameJsonVO::Wrapper OwnerPaymentController::execQueryOwnerPaymentConfigName(const OwnerPaymentListQuery::Wrapper& query)
{
	// 定义一个Service
	OwnerPaymentService service;
	// 查询数据
	auto result = service.listConfigNametList(query);  // listAll
	// 响应结果
	auto jvo = OwnerPaymentConfigNameJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
