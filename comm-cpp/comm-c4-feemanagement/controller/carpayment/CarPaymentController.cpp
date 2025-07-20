#include "stdafx.h"
#include "CarPaymentController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/carpayment/CarPaymentService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

GetFeeModificationRecordsPageJsonVO::Wrapper CarPaymentController::execQueryGetFeeModificationRecords(const GetFeeModificationRecordsQuery::Wrapper& query)
{
	// 定义一个Service
	GetFeeModificationRecordsService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetFeeModificationRecordsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


GetPaymentDetailedRecordJsonVO::Wrapper CarPaymentController::execQueryGetPaymentDetailedRecordById(const String& id)
{ 
	// 定义返回数据对象
	auto jvo = GetPaymentDetailedRecordJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	GetPaymentDetailedRecordService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;
}

GetPaymentRecordsPageJsonVO::Wrapper CarPaymentController::execQueryGetPaymentRecords(const GetPaymentRecordsQuery::Wrapper& query)
{
	// 定义一个Service
	GetPaymentRecordsService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetPaymentRecordsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


//获取车辆费用详情
GetVehicleFeeJsonVO::Wrapper CarPaymentController::execQueryGetVehicleFeeById(const String& id)
{
	// 定义返回数据对象
	auto jvo = GetVehicleFeeJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	GetVehicleFeeService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;
}

CarPaymentPageJsonVO::Wrapper CarPaymentController::execQueryCarPayment(const CarPaymentQuery::Wrapper& query)
{
	auto jvo = CarPaymentPageJsonVO::createShared();
	if (!query->payer_obj_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CarPaymentService service;
	// 查询数据
	auto result = service.getById(query);
	// 响应结果
	jvo->success(result);
	return jvo;
}
/*
CarPaymentPageJsonVO::Wrapper CarPaymentController::execQueryById(const String& id)
{
	// 定义返回数据对象
	auto jvo = CarPaymentJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CarPaymentService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;
}
*/
StringJsonVO::Wrapper CarPaymentController::execAddCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->fee_type || !dto->fee_name || !dto->start_time||!dto->end_time)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if ( dto->fee_type->empty() || dto->fee_name->empty() || dto->start_time->empty() || dto->end_time->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CarPaymentService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
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

StringJsonVO::Wrapper CarPaymentController::execModifyCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->create_time||!dto->start_time||!dto->end_time)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CarPaymentService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->fee_id);
	}
	else
	{
		jvo->fail(dto->fee_id);
	}
	// 响应结果
	return jvo;
}
/*
StringJsonVO::Wrapper CarPaymentController :: execRemoveCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->fee_id || !dto->fee_item_id || !dto->owe_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CarPaymentService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.removeData(dto)) {
		jvo->success(dto->fee_id);
	}
	else
	{
		jvo->fail(dto->fee_id);
	}
	// 响应结果
	return jvo;
}

ListJsonVO<String>::Wrapper CarPaymentController::execRemoveCarPayment(const List<String>& ids)
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
	CarPaymentService service;
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
}*/

StringJsonVO::Wrapper CarPaymentController::execRemoveCarPayment(const CarPaymentDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	if (!dto->fee_id) {
		jvo->fail(String("need fee_id"));
		return jvo;
	}
	CarPaymentService ser;
	ser.removeData(dto, payload);
	jvo->success(String("delete success"));
	return jvo;
}


StringJsonVO::Wrapper CarPaymentController::execPayCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->pay_cycle|| !dto->amount||!dto->pay_type)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CarPaymentService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.payFee(dto)) {
		jvo->success(dto->fee_id);
	}
	else
	{
		jvo->fail(dto->fee_id);
	}
	// 响应结果
	return jvo;
}


