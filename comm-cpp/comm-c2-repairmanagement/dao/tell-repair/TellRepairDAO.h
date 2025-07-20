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
#ifndef _TELLREPAIR_DAO_
#define _TELLREPAIR_DAO_
#include "BaseDAO.h"
#include "../../domain/do/tell-repair/TellRepairDO.h"
#include "../../domain/query/tell-repair/TellRepairQuery.h"

/**
 * 示例：报修数据库访问实现
 */
class TellRepairDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    TellRepairDAO::queryConditionBuilder
	// Access:      private
	// Returns:     std::string 返回拼接SQL语句的WHERE条件字符串
	// Parameter:   const TellRepairQuery::Wrapper& query 查询参数对象
	// Parameter:   SqlParams& params 用于存放查询参数的容器
	// Description: 查询条件构建，根据TellRepairQuery动态拼接查询条件并设置参数
	//************************************
	inline std::string queryConditionBuilder(const TellRepairQuery::Wrapper &query, SqlParams &params);

public:
	// 统计数据总数
	uint64_t count(const TellRepairQuery::Wrapper &query);
	// 分页查询数据
	std::list<TellRepairDO> selectWithPage(const TellRepairQuery::Wrapper &query);
	// 新增数据
	int insert(const TellRepairDO &iObj);
	// 修改数据
	int update(const TellRepairDO &uObj);
	// 通过ID删除数据
	int deleteById(std::string id);
};
#endif // !_TELLREPAIR_DAO_
