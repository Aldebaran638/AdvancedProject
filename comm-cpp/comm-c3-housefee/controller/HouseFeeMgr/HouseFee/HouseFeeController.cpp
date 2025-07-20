#include "stdafx.h"
#include "HouseFeeController.h"
#include "../../../service/HouseFeeMgrService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
HouseFeeMgrPageJsonVO::Wrapper HouseFeeController::execQueryAll(const HouseFeeMgrQuery::Wrapper& query)
{
	// 定义一个Service
	HouseFeeMgrService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = HouseFeeMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
HouseFeeMgrJsonVO::Wrapper HouseFeeController::execQueryByFeeId(const String& id)
{
	// 定义返回数据对象
	auto jvo = HouseFeeMgrJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	HouseFeeMgrService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;
}
HouseFeeMgrPageJsonVO::Wrapper HouseFeeController::execQueryByRoomNum(const HouseFeeMgrQueryByRoom::Wrapper& query)
{
	// 定义一个Service
	HouseFeeMgrService service;
	// 查询数据
	auto result = service.listByRoomNum(query);
	// 响应结果
	auto jvo = HouseFeeMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
