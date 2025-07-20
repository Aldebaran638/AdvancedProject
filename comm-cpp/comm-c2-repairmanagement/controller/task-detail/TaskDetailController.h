#pragma once
#ifndef _TASKDETAILCONTROLLER_H_
#define _TASKDETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/task-detail/TaskDetailQuery.h"
#include "domain/dto/task-detail/TaskDetailDTO.h"
#include "domain/vo/task-detail/TaskDetailVO.h"
#include <chrono>

#include OATPP_CODEGEN_BEGIN(ApiController)

class TaskDetailController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(TaskDetailController);

public:
    // 定义获取工单详情描述
    ENDPOINT_INFO(queryTaskDetailById)
    {
        // 定义通用描述
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("taskpool.task-detail.summary-query-by-id"), TaskDetailGetJsonVO::Wrapper);
        // 定义参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "repair_id", ZH_WORDS_GETTER("taskpool.task-detail.repair-id"), ZH_WORDS_GETTER("taskpool.task-detail.default-repair-id"), true);
    }
    // 定义工单编号查询接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/comm-c2-repairsetting/task-detail/query-by-id", queryTaskDetailById, QUERY(String, repair_id), execQueryTaskDetailById(repair_id));

        /**
     * 工单详情->打印接口
     */
    ENDPOINT_INFO(exportTaskDetail) {
        // 定义通用描述
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("taskpool.task-detail.summary-export"), Void);
        // 定义查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "repair_id", ZH_WORDS_GETTER("taskpool.task-list.front-repair-id"), "822025053099540019", true);
    }

    ENDPOINT(API_M_GET, "/comm-c2-repairsetting/taskpool/task-detail/export", exportTaskDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, TaskDetailQuery, queryParams);
        return execExportTaskDetail(query);
    }
  
    /**
    * 派单
    */
	// 定义派单接口描述
	ENDPOINT_INFO(addTaskDetail) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("taskpool.task-detail.summary-add"), TaskDetailAddJsonVO::Wrapper);
	}
	// 定义派单接口处理
	ENDPOINT(API_M_POST, "/comm-c2-repairsetting/taskpool/task-detail/add", addTaskDetail, BODY_DTO(TaskDetailAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddTaskDetail(dto));
	}

private:
    Float64 calculateDuration(const String& startTime, const String& endTime)
    {
        return 2.5;
    }

    // 声明获取工单详情数据函数
    TaskDetailGetJsonVO::Wrapper execQueryTaskDetailById(const String& repair_id);
    // 声明打印工单数据函数
    std::shared_ptr<OutgoingResponse> execExportTaskDetail(const TaskDetailQuery::Wrapper& query);
    // 声明派单数据函数
    TaskDetailAddJsonVO::Wrapper execAddTaskDetail(const TaskDetailAddDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // _TASKDETAILCONTROLLER_H_