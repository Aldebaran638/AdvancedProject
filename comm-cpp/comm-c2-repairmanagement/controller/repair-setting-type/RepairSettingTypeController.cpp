#include "stdafx.h"
#include "RepairSettingTypeController.h"
#include "../../service/repair-setting-type/RepairSettingTypeService.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"

RepairSettingGetPageJsonVO::Wrapper RepairSettingController::RepairSettingTypeQueryAll(const RepairSettingGetQuery::Wrapper& userQuery)
{
	// 定义一个Service
	RepairSettingService service;
	// 查询数据
	auto result = service.RepairSettingTypeListAll(userQuery);
	// 响应结果
	auto jvo = RepairSettingGetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
StringJsonVO::Wrapper RepairSettingController::RepairSettingTypeAdd(const RepairSettingAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->repair_type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RepairSettingService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.RepairSettingTypeAddData(dto);
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

StringJsonVO::Wrapper RepairSettingController::RepairSettingTypeModify(const RepairSettingModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	if (!dto->repair_type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RepairSettingService service;
	// 执行数据修改
	dto->setPayload(&payload);
	// 这里应该是传唯一标识(setting_id)
	if (service.RepairSettingTypeModifyData(dto))
	{
		jvo->success(dto->setting_id);
	}
	else
	{
		jvo->fail(dto->setting_id);
	}
	// 响应结果
	return jvo;
}

ListJsonVO<oatpp::web::server::api::ApiController::String>::Wrapper RepairSettingController::RepairSettingTypeDelete(const List<String>& ids)
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
	RepairSettingService service;
	// 执行数据删除
	if (service.RepairSettingTypeDeleteData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// 响应结果
	return jvo;
}