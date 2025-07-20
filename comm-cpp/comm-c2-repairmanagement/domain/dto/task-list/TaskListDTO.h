#pragma once
#ifndef _TASKLISTDTO_H_
#define _TASKLISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 工单池->工单列表删除和修改信息的数据传输模型
*/
class TaskListGetIdDTO : public oatpp::DTO {
    DTO_INIT(TaskListGetIdDTO, DTO);
    // 工单编号
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"), true, "822025053099990009");
};

/**
* 工单池->工单列表修改信息的数据传输模型
*/
class TaskListUpdateDTO : public oatpp::DTO {
    DTO_INIT(TaskListUpdateDTO, DTO);
    //小区编号(前端传入)
    API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("taskpool.task-list.front-community-id"), true, "2023052267100146");
    // 工单编码（前端传入）
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.front-repair-id"), true, "822025053099990009");
    // 报修类型
    API_DTO_FIELD(String, repair_type, ZH_WORDS_GETTER("taskpool.task-list.repair-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-type"));
    // 报修人
    API_DTO_FIELD(String, repair_name, ZH_WORDS_GETTER("taskpool.task-list.repair-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-name"));
    // 联系方式
    API_DTO_FIELD(String, tel, ZH_WORDS_GETTER("taskpool.task-list.tel"), true, "15262352623");
    // 预约时间
    API_DTO_FIELD(String, appointment_time, ZH_WORDS_GETTER("taskpool.task-list.appointment-time"), true, "2025-05-30 15:10:52");
    // 报修内容
    API_DTO_FIELD(String, context, ZH_WORDS_GETTER("taskpool.task-list.task-context"), true, ZH_WORDS_GETTER("taskpool.task-list.default-task-context"));
};

/**
 * 工单池->工单列表详细数据模型
 */
class TaskListDTO : public oatpp::DTO {
    DTO_INIT(TaskListDTO, DTO);
    // 工单编号（唯一标识）
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"), true, "822025053099990009");
    // 报修位置
    API_DTO_FIELD(String, repair_obj_name, ZH_WORDS_GETTER("taskpool.task-list.repair-obj-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-obj-name"));
    // 报修类型
    API_DTO_FIELD(String, repair_type, ZH_WORDS_GETTER("taskpool.task-list.repair-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-type"));
    // 维修类型
    API_DTO_FIELD(String, maintenance_type, ZH_WORDS_GETTER("taskpool.task-list.maintenance-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-maintenance-type"));
    // 维修类型中文映射
    API_DTO_FIELD(String, maintenance_type_txt, ZH_WORDS_GETTER("taskpool.task-list.maintenance-type-txt"), true, ZH_WORDS_GETTER("taskpool.task-list.default-maintenance-type-txt"));
    // 报修人
    API_DTO_FIELD(String, repair_name, ZH_WORDS_GETTER("taskpool.task-list.repair-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-name"));
    // 联系方式
    API_DTO_FIELD(String, tel, ZH_WORDS_GETTER("taskpool.task-list.tel"), true, "15262352623");
    // 预约时间
    API_DTO_FIELD(String, appointment_time, ZH_WORDS_GETTER("taskpool.task-list.appointment-time"), true, "2025-05-30 15:10:52");
    // 提交时间
    API_DTO_FIELD(String, create_time, ZH_WORDS_GETTER("taskpool.task-list.create-time"), true, "2025-05-30 15:11:20");
    // 状态
    API_DTO_FIELD(String, state, ZH_WORDS_GETTER("taskpool.task-list.state"), true, ZH_WORDS_GETTER("taskpool.task-list.default-state"));
    // 状态中文映射
    API_DTO_FIELD(String, state_txt, ZH_WORDS_GETTER("taskpool.task-list.state-txt"), true, ZH_WORDS_GETTER("taskpool.task-list.default-state-txt"));
};

/**
 * 工单池->工单列表分页传输对象
 */
class TaskListPageDTO : public PageDTO<TaskListDTO::Wrapper> {
    DTO_INIT(TaskListPageDTO, PageDTO<TaskListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKLISTDTO_H_