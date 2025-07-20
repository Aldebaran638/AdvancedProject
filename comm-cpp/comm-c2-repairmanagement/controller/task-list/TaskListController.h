#pragma once
#ifndef _TASKLISTCONTROLLER_H_
#define _TASKLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/task-list/TaskListQuery.h"
#include "domain/dto/task-list/TaskListDTO.h"
#include "domain/vo/task-list/TaskListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TaskListController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(TaskListController);
public:
    /**
     * 工单池->工单列表分页查询接口
     */
    ENDPOINT_INFO(queryTaskList) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("taskpool.task-list.summary-query-all"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(TaskListPageJsonVO);
        API_DEF_ADD_PAGE_PARAMS();

        // 小区编号（前端传入）
        API_DEF_ADD_QUERY_PARAMS(String, "community_id",
            ZH_WORDS_GETTER("taskpool.task-list.community-id"),
            "2023052267100146", true);
        // 工单编号
        API_DEF_ADD_QUERY_PARAMS(String, "repair_id",
            ZH_WORDS_GETTER("taskpool.task-list.repair-id"),
            "822025053099990009", false);
        // 报修人
        API_DEF_ADD_QUERY_PARAMS(String, "repair_name",
            ZH_WORDS_GETTER("taskpool.task-list.repair-name"),
            ZH_WORDS_GETTER("taskpool.task-list.default-repair-name"), false);
        //报修电话
        API_DEF_ADD_QUERY_PARAMS(String, "tel",
            ZH_WORDS_GETTER("taskpool.task-list.tel"),
            "15262352623", false);
        // 报修类型
        API_DEF_ADD_QUERY_PARAMS(String, "repair_type",
            ZH_WORDS_GETTER("taskpool.task-list.repair-type"),
            ZH_WORDS_GETTER("taskpool.task-list.default-repair-type"), false);
        // 报修设置类型
        API_DEF_ADD_QUERY_PARAMS(String, "repair_setting_type",
            ZH_WORDS_GETTER("taskpool.task-list.repair-setting-type"),
            ZH_WORDS_GETTER("taskpool.task-list.default-repair-setting-type"), false);
        // 报修位置
        API_DEF_ADD_QUERY_PARAMS(String, "repair_obj_name",
            ZH_WORDS_GETTER("taskpool.task-list.repair-obj-name"),
            ZH_WORDS_GETTER("taskpool.task-list.default-repair-obj-name"), false);
        // 维修类型
        API_DEF_ADD_QUERY_PARAMS(String, "maintenance_type",
            ZH_WORDS_GETTER("taskpool.task-list.maintenance-type"),
            ZH_WORDS_GETTER("taskpool.task-list.default-maintenance-type"), false);
        // 开始时间
        API_DEF_ADD_QUERY_PARAMS(String, "start_time",
            ZH_WORDS_GETTER("taskpool.task-list.start-time"),
            "2025-05-30 15:10:52", false);
        // 结束时间
        API_DEF_ADD_QUERY_PARAMS(String, "end_time",
            ZH_WORDS_GETTER("taskpool.task-list.end-time"),
            "2025-05-30 15:11:20", false);
    }

    ENDPOINT(API_M_GET, "/comm-c2-repairsetting/taskpool/task-list/query-all", queryTaskList,
        QUERIES(QueryParams, queryParams),
        API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, TaskListQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryAll(query));
    }

    /**
    * 工单池->工单列表修改接口
    */
    // 定义修改接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("taskpool.task-list.summary-modify"), modifyTask, TaskListUpdateJsonVO::Wrapper);
    // 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/taskpool/task-list/modify", modifyTask, BODY_DTO(TaskListUpdateDTO::Wrapper, dto), execModifyTask(dto));

    /**
    * 工单池->工单列表删除接口
    */
	// 定义删除工单接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("taskpool.task-list.summary-delete"), removeTask, TaskListDeleteJsonVO::Wrapper);
	// 定义删除工单接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/comm-c2-repairsetting/taskpool/task-list/remove", removeTask, BODY_DTO(TaskListGetIdDTO::Wrapper, dto), execRemoveTask(dto));

private:
    // 声明查询工单函数
    TaskListPageJsonVO::Wrapper execQueryAll(const TaskListQuery::Wrapper& query);
    // 声明修改工单数据函数
    TaskListUpdateJsonVO::Wrapper execModifyTask(const TaskListUpdateDTO::Wrapper& dto);
	// 声明删除工单数据函数
    TaskListDeleteJsonVO::Wrapper execRemoveTask(const TaskListGetIdDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // _TASKLISTCONTROLLER_H_