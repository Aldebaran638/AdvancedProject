#include "stdafx.h"
#include "WaterMeterController.h"
#include "service/meterwater/WaterMeterService.h"
#include "../../lib-oatpp/include/ApiHelper.h"

WaterMeterPageJsonVO::Wrapper WaterMeterController::executeQueryMeter(const WaterMeterQuery::Wrapper& query)
{
	// 定义一个Service
	WaterMeterService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = WaterMeterPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper WaterMeterController::executeRemoveMeter(const WaterMeterDeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	if (!dto->water_id) {
		jvo->fail(String("need water_id"));
		return jvo;
	}
	WaterMeterService ser;
	ser.removeData(dto, payload);
	jvo->success(String("delete success"));
	return jvo;
}

StringJsonVO::Wrapper WaterMeterController::executeModifyMeter(const WaterMeterDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->water_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WaterMeterService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->water_id);
	}
	else
	{
		jvo->fail(dto->water_id);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper WaterMeterController::executeAddMeter(const WaterMeterAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->meter_type || !dto->obj_name || !dto->pre_degrees || !dto->pre_reading_time || !dto->cur_reading_time)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->pre_degrees < 0 || dto->cur_degrees < 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	WaterMeterService service;
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
