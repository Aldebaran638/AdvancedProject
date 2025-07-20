#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

		https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _TASKDETAIL_DAO_
#define _TASKDETAIL_DAO_
#include "BaseDAO.h"
#include "../../domain/do/task-detail/TaskDetailDO.h"
#include "../../domain/query/task-detail/TaskDetailQuery.h"

/**
 * 工单表数据库操作实现
 */
class TaskDetailDAO : public BaseDAO
{
private:

public:

	// 通过ID查询数据
	PtrTaskDetailGetDO selectById(std::string id);
	// 插入数据
	int insert_r_repair_user(const TaskDetailDO& iObj);
	// 打印工单 工单详情查询
	PtrTaskDetailDO selectExportTaskDetail_r_repair_pool(const TaskDetailQuery::Wrapper& query);
	// 打印工单 工单流转查询
	std::list<TaskDetailDO> selectExportCirculate_r_repair_user(const TaskDetailQuery::Wrapper& query);
	// 统计工单流转数据条数
	uint64_t count_r_repair_user(const TaskDetailQuery::Wrapper& query);

};
#endif // !_TASKDETAIL_DAO_
