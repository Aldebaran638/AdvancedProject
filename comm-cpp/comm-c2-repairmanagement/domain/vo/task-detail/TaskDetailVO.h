#pragma once
#ifndef _TASKDETAILVO_H_
#define _TASKDETAILVO_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/task-detail/TaskDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个获取工单详情显示JsonVO对象，用于响应给前端
 */
class TaskDetailGetJsonVO : public JsonVO<TaskDetailGetDTO::Wrapper> {
	DTO_INIT(TaskDetailGetJsonVO, JsonVO<TaskDetailGetDTO::Wrapper>);
};

/**
 * 定义一个派单显示JsonVO对象，用于响应给前端
 */
class TaskDetailAddJsonVO : public JsonVO<TaskDetailGetIdDTO::Wrapper> {
	DTO_INIT(TaskDetailAddJsonVO, JsonVO<TaskDetailGetIdDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif