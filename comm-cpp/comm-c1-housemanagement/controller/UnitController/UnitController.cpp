#include "stdafx.h"
#include "UnitController.h"
#include "../../service/unit/UnitService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

//处理新增单元信息的函数
StringJsonVO::Wrapper UnitController::execAddUnit(const UnitDTO::Wrapper& dto, const PayloadDTO& payload){
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 暂时不进行非空校验，因为插入数据时不需要指定unit_id 和 b_id
		// 非空校验
	//if (!dto->unit_id || !dto->b_id)
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//	// 有效值校验
	//if (dto->unit_id->empty() || dto->b_id->empty())
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	
	// 定义一个Service
	UnitService service;
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

//修改单元信息
StringJsonVO::Wrapper UnitController::execModifyUnit(const UnitDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->unit_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	UnitService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->unit_id);
	}
	else
	{
		jvo->fail(dto->unit_id);
	}
	// 响应结果
	return jvo;
}

//删除单元信息
ListJsonVO<String>::Wrapper UnitController::execRemoveUnit(const List<String>& ids) {
	// 定义返回数据对象
	auto jvo = ListJsonVO<String>::createShared();
	// 参数校验
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	UnitService service;
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
}

UnitPageJsonVO::Wrapper UnitController::execQueryUnit(const UnitQuery::Wrapper& query)
{
	UnitService service;
	auto result = service.listUnit(query);
	auto jvo = UnitPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

UnitPageJsonVO::Wrapper UnitController::execQueryCommunityUnit(const UnitQuery::Wrapper& query)
{
	UnitService service;
	auto result = service.listCommunityUnit(query);
	auto jvo = UnitPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}