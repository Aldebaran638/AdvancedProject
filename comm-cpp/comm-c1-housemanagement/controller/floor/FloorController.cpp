#include "stdafx.h"
#include "FloorController.h"
#include "service/floor/FloorService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"



FloorPageJsonVO::Wrapper FloorController::execQueryFloor(const FloorQuery::Wrapper& query)
{
	// 定义一个Service
	FloorService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FloorPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


FloorJsonVO::Wrapper FloorController::execQueryById(const String& id) {

	//定义返回数据对象
	auto jvo = FloorJsonVO::createShared();
	//参数检验
	//非空检验
	if (!id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个Service
	FloorService service;
	//执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//相应结果
	return jvo;

}

//新增数据
StringJsonVO::Wrapper FloorController::execAddFloor(const FloorAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if ( !dto->b_id || !dto->community_id || !dto->floor_area || !dto->floor_num || !dto->name) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	//有效值检验
	/*if (dto->floor_id->empty()) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}*/
	//定义一个service
	FloorService service;
	//执行数据新增
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


//修改数据
StringJsonVO::Wrapper FloorController::execModifyFloor(const FloorDTO::Wrapper& dto, const PayloadDTO& payload) {
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//参数校验
	if (!dto->floor_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个Service
	FloorService service;
	//执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->floor_id);
	}
	//响应结果
	return jvo;
}