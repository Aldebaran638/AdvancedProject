#include "stdafx.h"
#include "TaskListController.h"
#include "../../service/task-list/TaskListService.h"

// 工单池->工单列表分页查询执行方法实现
TaskListPageJsonVO::Wrapper TaskListController::execQueryAll(const TaskListQuery::Wrapper& query)
{
	TaskListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = TaskListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 工单池->工单列表修改工单执行方法实现
TaskListUpdateJsonVO::Wrapper TaskListController::execModifyTask(const TaskListUpdateDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = TaskListUpdateJsonVO::createShared();
	// 参数校验
	if (dto->repair_id->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TaskListService service;
	// 执行数据修改
	std::string id = service.updateData(dto);
	if (id != "") {
		auto resultDto = TaskListGetIdDTO::createShared();
		resultDto->repair_id = id;
		jvo->success(resultDto);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// 响应结果
	return jvo;
}
// 定义删除工单数据函数
TaskListDeleteJsonVO::Wrapper TaskListController::execRemoveTask(const TaskListGetIdDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = TaskListDeleteJsonVO::createShared();
	// 参数校验
	if (dto->repair_id->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TaskListService service;
	// 执行数据删除
	std::string id = service.removeData(dto);
	if (id != ""){
		auto resultDto = TaskListGetIdDTO::createShared();
		resultDto->repair_id = id;
		jvo->success(resultDto);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// 响应结果
	return jvo;
}
