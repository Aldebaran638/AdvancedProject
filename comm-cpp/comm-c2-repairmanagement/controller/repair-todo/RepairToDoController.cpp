#include "stdafx.h"
#include "RepairToDoController.h"
#include "../../service/repair-todo/RepairToDoService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//查询维修代办
RepairToDoPageJsonVO::Wrapper RepairToDoController::execQueryAll(const RepairToDoQuery::Wrapper & query)
{
	auto jvo = RepairToDoPageJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!query->community_id && !query->staff_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RepairToDoService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	jvo->success(result);
	return jvo;
}

//查询所有维修类型
RepairToDoQueryAllRepairTypePageJsonVO::Wrapper RepairToDoController::execQueryAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& Query)
{
	auto jvo = RepairToDoQueryAllRepairTypePageJsonVO::createShared();
	if (!Query->community_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	RepairToDoService service;
	auto result = service.listAllRepairType(Query);
	jvo->success(result);
	return jvo;
}

//查询所有维修人员
RepairToDoQueryAllStaffPageJsonVO::Wrapper RepairToDoController::execQueryAllStaffByRepairType(const RepairToDoStaffNameQuery::Wrapper& Query)
{
	auto jvo = RepairToDoQueryAllStaffPageJsonVO::createShared();
	if (!Query->repair_type)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	RepairToDoService service;
	auto result = service.listAllStaffByStaffType(Query);
	jvo->success(result);
	return jvo;
	
}
// 转单处理
StringJsonVO::Wrapper RepairToDoController::execModify(const RepairToDoUpdateDTO::Wrapper& dto)
{
	 /*定义返回数据对象*/
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->repair_id &&!dto->staff_id && !dto->context)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RepairToDoService service;
	// 执行数据修改
	if (service.ModifyDataToTransferBill(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// 响应结果
	return jvo;
}

// 修改报修状态——》暂停
StringJsonVO::Wrapper RepairToDoController::executeModifyStateToSuspend(const RepairToDoUpdateToSuspendDTO::Wrapper& dto)
{
	/*定义返回数据对象*/
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->context && !dto->repair_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RepairToDoService service;
	// 执行数据修改
	if (service.ModifyDataToSuspend(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// 响应结果
	return jvo;

}

// 修改报修状态——》退单
StringJsonVO::Wrapper RepairToDoController::execRemove(const RepairToDoUpdateToRemoveDTO::Wrapper& dto)
{

	/*定义返回数据对象*/
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->context && !dto->repair_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RepairToDoService service;
	// 执行数据修改
	if (service.ModifyDataToRemove(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// 响应结果
	return jvo;


}

// 修改报修状态——》办结
StringJsonVO::Wrapper RepairToDoController::executeModifyStateToFinish(const RepairToDoUpdateToFinishDTO::Wrapper& dto)
{
	/*定义返回数据对象*/
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->repair_id && !dto->repair_before_photo_path && !dto->repair_after_photo_path  && !dto->is_material)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RepairToDoService service;
	// 执行数据修改
	if (service.ModifyDataToFinish(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// 响应结果
	return jvo;
}