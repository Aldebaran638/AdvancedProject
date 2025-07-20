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
#ifndef _TABLEREADINGTYPE_DAO_
#define _TABLEREADINGTYPE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/table-reading-type/TableReadingTypeDO.h"
#include "../../domain/query/table-reading-type/TableReadingTypeQuery.h"

/**
 * 示例表数据库操作实现
 */
class TableReadingTypeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    TableReadingTypeDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const TableReadingTypeQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据TableReadingTypeQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const TableReadingTypeQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const TableReadingTypeQuery::Wrapper& query);
	// 分页查询数据
	std::list<TableReadingTypeDO> selectWithPage(const TableReadingTypeQuery::Wrapper& query);
	// 插入数据
	int insert(const TableReadingTypeDO& iObj);
	// 修改数据
	int update(const TableReadingTypeDO& uObj);
	// 删除数据
	int remove(const TableReadingTypeDO& uObj);
};
#endif // !_SAMPLE_DAO_
