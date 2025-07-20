#pragma once
#ifndef _TASKLISTDAO_
#define _TASKLISTDAO_
#include "BaseDAO.h"
#include "../../domain/do/task-list/TaskListDO.h"
#include "../../domain/query/task-list/TaskListQuery.h"

/**
 * 工单池工单列表数据库操作实现
 */
class TaskListDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const TaskListQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count_r_repair_pool(const TaskListQuery::Wrapper& query);
	// 分页查询数据
	std::list<TaskListDO> selectWithPage_r_repair_pool(const TaskListQuery::Wrapper& query);
	// 通过ID删除数据
	int deleteById_r_repair_pool(const TaskListDO& dObj);
	// 修改数据
	int update_r_repair_pool(const TaskListDO& uObj);
};
#endif // !_TASKLISTDAO_
