/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "stdafx.h"
#include "TableReadingTypeDAO.h"
#include "TableReadingTypeMapper.h"
#include <sstream>
#include "../../../lib-common/include/id/SnowFlake.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"

std::string TableReadingTypeDAO::queryConditionBuilder(const TableReadingTypeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";

	if (query->community_id) {
		sqlCondition << " AND `community_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}

	// 添加 status_cd 不等于 1 的条件（参数化方式）
	sqlCondition << " AND `status_cd`!='1'";

	return sqlCondition.str();
}

uint64_t TableReadingTypeDAO::count(const TableReadingTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM meter_type ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<TableReadingTypeDO> TableReadingTypeDAO::selectWithPage(const TableReadingTypeQuery::Wrapper& query)
{
	SqlParams params;
	std::string sql = "SELECT type_id, type_name, remark, create_time FROM meter_type";

	// 添加 WHERE 条件（包含 community_id 和 status_cd 判断）
	sql += queryConditionBuilder(query, params);

	// 添加排序
	sql += " ORDER BY type_id DESC, create_time DESC";

	// 构建分页
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	TableReadingTypeMapper mapper;
	return sqlSession->executeQuery<TableReadingTypeDO>(sql, mapper, params);
}

int TableReadingTypeDAO::insert(const TableReadingTypeDO& iObj)
{
	string sql = "INSERT INTO meter_type (type_id, type_name, community_id, remark, create_time, status_cd) VALUES (?, ?, ?, ?, ?, ?)";
	string status_cd = "0";  // 默认状态为 0
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", iObj.getTypeId(), iObj.getTypeName(), iObj.getCommunityId(), iObj.getRemark(), iObj.getCreateTime(), status_cd);
}

int TableReadingTypeDAO::update(const TableReadingTypeDO& uObj)
{
	string sql = "UPDATE meter_type SET type_name=?, remark=? WHERE type_id=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getTypeName(), uObj.getRemark(), uObj.getTypeId());
}

int TableReadingTypeDAO::remove(const TableReadingTypeDO& uObj)
{
	string sql = "UPDATE meter_type SET status_cd=1 WHERE status_cd=0 AND type_id=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getTypeId());
}
