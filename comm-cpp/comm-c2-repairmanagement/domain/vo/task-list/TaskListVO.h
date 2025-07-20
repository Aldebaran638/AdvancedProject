#pragma once
#ifndef _TASKLISTVO_H_
#define _TASKLISTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/task-list/TaskListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *工单池->删除工单响应VO
 */
class TaskListDeleteJsonVO : public JsonVO<TaskListGetIdDTO::Wrapper>
{
	DTO_INIT(TaskListDeleteJsonVO, JsonVO<TaskListGetIdDTO::Wrapper>);
};

/**
 *工单池->修改工单响应VO
 */
class TaskListUpdateJsonVO : public JsonVO<TaskListGetIdDTO::Wrapper>
{
	DTO_INIT(TaskListUpdateJsonVO, JsonVO<TaskListGetIdDTO::Wrapper>);
};
/**
 *工单池->工单列表分页查询响应VO
 */
class TaskListPageJsonVO : public JsonVO<TaskListPageDTO::Wrapper>
{
	DTO_INIT(TaskListPageJsonVO, JsonVO<TaskListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKLISTVO_H_