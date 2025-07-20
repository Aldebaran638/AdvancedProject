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
#ifndef _EXPEREM_DAO_
#define _EXPEREM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/experem/ExpeRemDO.h"
#include "../../domain/query/experem/ExpeRemQuery.h"
#include "../../domain/dto/experem/ExpeRemDTO.h"
/**
 * 示例表数据库操作实现
 */
class ExpeRemDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const ExpeRemQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ExpeRemQuery::Wrapper& query);
	// 分页查询费用提醒记录
	std::list<ExpeRemDO> selectWithPage(const ExpeRemQuery::Wrapper& query);
};



/*
费用提醒DAO
*/
class overExpeRemDAO :public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const overExpeRemQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const overExpeRemQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const overExpeRemQuery::Wrapper& query);
	// 分页查询数据
	std::list<overExpeRemDO> selectWithPage(const overExpeRemQuery::Wrapper& query);
};
#endif // !_ExpeRem_DAO_
