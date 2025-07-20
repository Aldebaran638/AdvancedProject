#pragma once

#ifndef _PAYDET_DAO_
#define _PAYDET_DAO_

#include "BaseDAO.h"
#include "../../domain/do/paydet/PayDetDO.h"
#include "../../domain/query/paydet/PayDetQuery.h"

class PayDetDAO : public BaseDAO
{
public:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************

	inline std::string queryConditionBuilder(const GetPaydetQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const GetPaydetQuery::Wrapper& query);

	// 分页查询数据
	std::list<PayDetDO> selectWithPage(const GetPaydetQuery::Wrapper& query);
};

#endif // PAYDET_DAO_