#include "stdafx.h"
#include "RainDisTypesController.h"
#include "../../service/discount_types/RainDisTypesService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//#include "../../service/discount_types/declarative/RainDisTypesApiClient.h"

//RainDisTypesJsonVO::Wrapper RainDisTypesController::execGetTypes(const RainDisTypesQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	RainDisTypesService service;
//	auto result = service.listAll(query);
//	auto jvo = RainDisTypesJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}

//RainDisTypesPageJsonVO::Wrapper RainDisTypesController::execQueryAll(const RainDisTypesQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// 创建客户端对象
//	API_CLIENT_CREATE(ac, om, RainDisTypesApiClient, "discount-type-api");
//	// 构建凭证
//	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
//	// 返回查询结果
//	return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->type_name))->readBodyToDto<RainDisTypesPageJsonVO::Wrapper>(om);
//}

RainDisTypesPageJsonVO::Wrapper RainDisTypesController::execQueryList(const String& type_name)
{
	// 定义返回数据对象
	auto jvo = RainDisTypesPageJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RainDisTypesService service;
	// 执行数据新增
	auto res = service.getByTypeName(type_name);
	jvo->success(res);

	//响应结果
	return jvo;
}

RainDisTypesPageJsonVO::Wrapper RainDisTypesController::execQueryAll(const RainDisTypesQuery::Wrapper& query)
{
	RainDisTypesService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RainDisTypesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper RainDisTypesController::execAddTypes(const RainDisTypesAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->type_name || !dto->type_desc)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->type_name->empty() || dto->type_desc->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RainDisTypesService service;
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