#ifndef _TASKDETAIL_SERVICE_
#define _TASKDETAIL_SERVICE_
#include "domain/vo/task-detail/TaskDetailVO.h"
#include "domain/query/task-detail/TaskDetailQuery.h"
#include "domain/dto/task-detail/TaskDetailDTO.h"

/**
 * 工单详情服务接口
 */
class TaskDetailService
{
public:
	// 通过ID查询单个工单详情
	TaskDetailGetDTO::Wrapper getById(std::string id);
	// 派单
	std::string saveData(const TaskDetailAddDTO::Wrapper& dto);
	//打印工单 工单详情数据查询
	TaskDetailExportDetailDTO::Wrapper getExportTaskDetail(const TaskDetailQuery::Wrapper& query);
	//打印工单 工单流转数据查询
	TaskDetailExportCirculationPageDTO::Wrapper getExportCirculate(const TaskDetailQuery::Wrapper& query);
};

#endif // !_TASKDETAIL_SERVICE_
