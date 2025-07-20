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
#ifndef _OWNERDETAILDAO_H_
#define _OWNERDETAILDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/owner-detail/OwnerDetailDO.h"
#include "../../domain/query/owner-detail/OwnerDetailQuery.h"

/**
 * 账户明细数据库操作实现
 */
class OwnerDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    OwnerDetailDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const OwnerDetailQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string OwnerDetail_queryConditionBuilder_count(const OwnerDetailQuery::Wrapper& query, SqlParams& params);
	inline std::string OwnerDetail_queryConditionBuilder_select(const OwnerDetailQuery::Wrapper& query, SqlParams& params);
	inline std::string OwnerDetail_queryConditionBuilder_AccountName(const OwnerDetailAccountNameQuery::Wrapper& query, SqlParams& params);

public:
	// 统计数据条数
	uint64_t OwnerDetail_count(const OwnerDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<OwnerDetailDO> OwnerDetail_selectWithPage(const OwnerDetailQuery::Wrapper& query);
	// 预存操作-向account_detail表中插入数据
	int OwnerDetail_add_insert_account_detail(const OwnerDetailDO& iObj);
	// 预存操作-向account_receipt插入数据
	int OwnerDetail_add_insert_account_receipt(const OwnerDetailDO& iObj);
	// 预存操作-在account表中修改数据
	int OwnerDetail_add_update_account(const OwnerDetailDO& uObj);
	// 预存操作-查询符合手机号的账户名称
	std::list<OwnerDetailAccountNameDO> OwnerDetail_add_get_account(const OwnerDetailAccountNameQuery::Wrapper& query);
	// 撤销操作-在account表中修改数据
	int OwnerDetail_undo_update_account(const OwnerDetailDO& uObj);
	// 撤销操作-在account_detail表中修改原预存的数据（3003）
	int OwnerDetail_undo_update_account_detail(const OwnerDetailDO& uObj);
	// 撤销操作-向account_detail表中插入数据
	int OwnerDetail_undo_insert_account_detail(const OwnerDetailDO& iObj);
};
#endif // !_OWNERDETAILDAO_H_
