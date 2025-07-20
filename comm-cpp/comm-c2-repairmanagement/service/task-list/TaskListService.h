#pragma once
#ifndef _TASKLISTSERVICE_
#define _TASKLISTSERVICE_
#include "domain/vo/task-list/TaskListVO.h"
#include "domain/query/task-list/TaskListQuery.h"
#include "domain/dto/task-list/TaskListDTO.h"

/**
 * 工单池工单列表服务实现
 */
class TaskListService
{
public:
	// 分页查询所有数据
	TaskListPageDTO::Wrapper listAll(const TaskListQuery::Wrapper& query);
	// 通过ID删除工单数据
	std::string removeData(const TaskListGetIdDTO::Wrapper& dto);
	// 修改数据
	std::string updateData(const TaskListUpdateDTO::Wrapper& dto);
};

#endif // !_TASKLISTSERVICE_



