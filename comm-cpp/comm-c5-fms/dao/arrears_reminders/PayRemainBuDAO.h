#pragma once
#ifndef _PAYREMAINBUDAO_H_
#define _PAYREMAINBUDAO_H_
#include "../../domain/do/arrears_reminders/PayRemainBuDO.h"
#include "../../domain/query/arrears_reminders/PayRemainBuQuery.h"
#include "BaseDAO.h"
#include <list>
class PayRemainBuDAO : BaseDAO
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
	inline std::string queryConditionBuilder(const PayRemainBuQuery::Wrapper& query, SqlParams& params);
public:
	// 插入数据
	int insert(const PayRemainBuDO& iObj);
	// 统计数据条数
	uint64_t count(const PayRemainBuQuery::Wrapper& query);
	//条件和分页查询
	std::list<PayRemainBuDO> selectWithPage(const PayRemainBuQuery::Wrapper& query);
};
#endif // !_PAYREMAINBUDAO_H_
