#pragma once

#ifndef _PAYFEE_DAO_
#define _PAYFEE_DAO_


#include "BaseDAO.h"
#include "../domain/do/PayFeeDO.h"
#include "../domain/query/PayFeeQuery.h"

class PayFeeDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const PayFeeQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const PayFeeQuery::Wrapper& query);
	// 分页查询数据
	std::list<PayFeeDO> selectWithPage(const PayFeeQuery::Wrapper& query);

	// 通过费用类型查询费用项目
	std::list<ChargeItemDO> selectByType(std::string community_id, std::string feeType);

};



#endif // !_PAYFEE_DAO_H_
