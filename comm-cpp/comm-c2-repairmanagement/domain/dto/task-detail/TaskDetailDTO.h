#pragma once
#ifndef _TASKDETAILDTO_H_
#define _TASKDETAILDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *	任务详情获取信息数据传输模型
 */
class TaskDetailGetDTO : public oatpp::DTO
{
    DTO_INIT(TaskDetailGetDTO, DTO);
    // 报修单号
    API_DTO_FIELD_DEFAULT(String, repairId, ZH_WORDS_GETTER("task-detail.field2.repair-id"));
    // 报修类型
    API_DTO_FIELD_DEFAULT(String, repairType, ZH_WORDS_GETTER("task-detail.field2.repair-type"));
    // 报修类型文本
    API_DTO_FIELD_DEFAULT(String, repairTypeTxt, ZH_WORDS_GETTER("task-detail.field2.repair-type-txt"));
    // 报修人
    API_DTO_FIELD_DEFAULT(String, repairName, ZH_WORDS_GETTER("task-detail.field2.repair-name"));
    // 联系方式
    API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("task-detail.field2.tel"));
    // 报修对象名称
    API_DTO_FIELD_DEFAULT(String, repairObjName, ZH_WORDS_GETTER("task-detail.field2.repair-obj-name"));
    // 预约时间
    API_DTO_FIELD_DEFAULT(String, appointmentTime, ZH_WORDS_GETTER("task-detail.field2.appointment-time"));
    // 超时时间
    API_DTO_FIELD_DEFAULT(String, timeoutTime, ZH_WORDS_GETTER("task-detail.field2.timeout-time"));
    // 提单时长
    API_DTO_FIELD_DEFAULT(String, time, ZH_WORDS_GETTER("task-detail.field2.time"));
    // 完成时间
    API_DTO_FIELD_DEFAULT(String, completeTime, ZH_WORDS_GETTER("task-detail.field2.complete-time"));
    // 创建时间
    API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("task-detail.field2.create-time"));
    // 状态
    API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("task-detail.field2.state"));
    // 状态文本
    API_DTO_FIELD_DEFAULT(String, stateTxt, ZH_WORDS_GETTER("task-detail.field2.state-txt"));
    // 报修内容
    API_DTO_FIELD_DEFAULT(String, context, ZH_WORDS_GETTER("task-detail.field2.context"));
};

/**
* 工单打印的工单详情数据传输模型
*/
class TaskDetailExportDetailDTO : public oatpp::DTO {
    DTO_INIT(TaskDetailExportDetailDTO, DTO);
    // 报修信息
    // 工单编号
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"), true, "822025053099990009");
    // 报修人
    API_DTO_FIELD(String, repair_name, ZH_WORDS_GETTER("taskpool.task-list.repair-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-name"));
    // 联系方式
    API_DTO_FIELD(String, tel, ZH_WORDS_GETTER("taskpool.task-list.tel"), true, "15262352623");
    // 报修位置
    API_DTO_FIELD(String, repair_obj_name, ZH_WORDS_GETTER("taskpool.task-list.repair-obj-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-obj-name"));
    // 报修内容
    API_DTO_FIELD(String, task_context, ZH_WORDS_GETTER("taskpool.task-list.task-context"), true, ZH_WORDS_GETTER("taskpool.task-list.default-task-context"));
    // 报修类型
    API_DTO_FIELD(String, repair_type, ZH_WORDS_GETTER("taskpool.task-list.repair-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-type"));
    // 维修类型
    API_DTO_FIELD(String, maintenance_type, ZH_WORDS_GETTER("taskpool.task-list.maintenance-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-maintenance-type"));
};

/**
 * 工单打印的工单流转数据传输模型
 */
class TaskDetailExportCirculationDTO : public oatpp::DTO {
    DTO_INIT(TaskDetailExportCirculationDTO, DTO);
    // 工单流转
    // 处理人
    API_DTO_FIELD(String, staff_name, ZH_WORDS_GETTER("taskpool.task-detail.staff-name"), true, ZH_WORDS_GETTER("taskpool.task-detail.default-staff-name"));
    // 状态
    API_DTO_FIELD(String, state, ZH_WORDS_GETTER("taskpool.task-detail.state"), true, ZH_WORDS_GETTER("taskpool.task-detail.default-state"));
    // 处理时间
    API_DTO_FIELD(String, start_time, ZH_WORDS_GETTER("taskpool.task-detail.start-time"), true, "2025-05-30 15:13:41");
    // 耗时
    API_DTO_FIELD(String, cost, ZH_WORDS_GETTER("taskpool.task-detail.cost"), true, "0:00");
    // 意见
    API_DTO_FIELD(String, user_context, ZH_WORDS_GETTER("taskpool.task-detail.user-context"), true, ZH_WORDS_GETTER("taskpool.task-detail.default-user-context"));
};
/**
 * 工单打印的工单流转分页传输对象
 */
class TaskDetailExportCirculationPageDTO : public PageDTO<TaskDetailExportCirculationDTO::Wrapper>
{
    DTO_INIT(TaskDetailExportCirculationPageDTO, PageDTO<TaskDetailExportCirculationDTO::Wrapper>);

};

/**
 * 派单数据响应传输模型
 */
class TaskDetailGetIdDTO : public oatpp::DTO {
    DTO_INIT(TaskDetailGetIdDTO, DTO);
    // 工单编码
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"), true, "822025053099990009");
};
/**
 * 派单数据传输模型
 */
class TaskDetailAddDTO : public oatpp::DTO
{
    DTO_INIT(TaskDetailAddDTO, DTO);
    // 工单编号(前端传入)
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.front-repair-id"), true, "822025053099990009");
    // 报修师傅
    API_DTO_FIELD(String, staff_name, ZH_WORDS_GETTER("taskpool.task-detail.staff-name"), true, ZH_WORDS_GETTER("taskpool.task-detail.default-staff-name"));
    // 处理意见
    API_DTO_FIELD(String, context, ZH_WORDS_GETTER("taskpool.task-detail.user-context"), true, ZH_WORDS_GETTER("taskpool.task-detail.default-user-context"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKDETAILDTO_H_