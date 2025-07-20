#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49
*/
#ifndef _FEE_ITEM_DAO_
#define _FEE_ITEM_DAO_

#include "BaseDAO.h"
#include "../domain/do/FeeItem/FeeItemDo.h"
#include "../domain/query/FeeItemQuery.h"

/**
 * 费用项数据库操作实现
 */
class FeeItemDAO : public BaseDAO
{
private:
	// 构建查询条件的 SQL 语句
	inline std::string queryConditionBuilder(const FeeItemQuery::Wrapper& query, SqlParams& params);

public:
	// 统计符合条件的数据条数
	uint64_t count(const FeeItemQuery::Wrapper& query);

	// 分页查询费用项数据
	std::list<FeeItemDO> selectWithPage(const FeeItemQuery::Wrapper& query);


	//插入新的费用项数据
	int insert(const FeeItemDO& iObj);

	//// 更新已有费用项数据
	int update(const FeeItemDO& uObj);
	int modifyBusiness(const FeeItemDO& newObj);

	//// 根据 ID 删除费用项
	int deleteById(const FeeItemDO& uObj);
	int deleteBusiness(const FeeItemDO& newObj);
};

#endif // !_FEE_ITEM_DAO_
