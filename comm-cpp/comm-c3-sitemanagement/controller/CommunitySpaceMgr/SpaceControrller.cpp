#include "stdafx.h" 
#include "SpaceController.h"
#include "../../service/CommunitySpaceMgrService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

CommunitySpaceMgrPageJsonVO::Wrapper SpaceController::execQueryList(const CommunitySpaceMgrPageQuery::Wrapper& query) {
	// 定义一个Service
	CommunitySpaceMgrService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CommunitySpaceMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


CommunitySpaceTimeMgrPageJsonVO::Wrapper SpaceController::execQueryTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query) {
	// 定义一个Service
	CommunitySpaceMgrService service;
	// 查询数据
	auto result = service.listTime(query);
	// 响应结果
	auto jvo = CommunitySpaceTimeMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}




StringJsonVO::Wrapper SpaceController::execModifyTime(const CommunitySpaceTimeMgrDTO::Wrapper& dto, const PayloadDTO& payload) {

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->space_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CommunitySpaceMgrService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateTimeData(dto)) {
		jvo->success(dto->space_id);
	}
	else
	{
		jvo->fail(dto->space_id);
	}
	// 响应结果
	return jvo;
}