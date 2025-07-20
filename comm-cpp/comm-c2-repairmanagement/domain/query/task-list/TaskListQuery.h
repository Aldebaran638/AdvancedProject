#pragma once
#ifndef _TASKLISTQUERY_H_
#define _TASKLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工单池->工单列表分页查询对象
 */
class TaskListQuery : public PageQuery {
    DTO_INIT(TaskListQuery, PageQuery);
    //小区编号
    API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("taskpool.task-list.community-id"));
    // 工单编号
    API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"));
    // 报修人
    API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("taskpool.task-list.repair-name"));
    // 报修电话
    API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("taskpool.task-list.tel"));
    // 报修类型
    API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("taskpool.task-list.repair-type"));
    // 报修设置类型
    API_DTO_FIELD_DEFAULT(String, repair_setting_type, ZH_WORDS_GETTER("taskpool.task-list.repair-setting-type"));
    // 报修位置
    API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("taskpool.task-list.repair-obj-name"));
    // 维修类型
    API_DTO_FIELD_DEFAULT(String, maintenance_type, ZH_WORDS_GETTER("taskpool.task-list.maintenance-type"));
    // 开始时间
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("taskpool.task-list.start-time"));
    // 结束时间
    API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("taskpool.task-list.end-time"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKLISTQUERY_H_