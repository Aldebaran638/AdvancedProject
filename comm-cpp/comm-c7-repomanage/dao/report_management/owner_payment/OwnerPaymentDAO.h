#pragma once

#ifndef _OWNERPAYMENT_DAO_
#define _OWNERPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/owner_payment/OwnerPaymentDO.h"
#include "../../../domain/query/owner_payment/OwnerPaymentQuery.h"

/**
 * 示例表数据库操作实现
 */
class OwnerPaymentDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    OwnerPaymentDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const OwnerPaymentQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const OwnerPaymentQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const OwnerPaymentQuery::Wrapper& query);
	// 分页查询数据
	std::list<OwnerPaymentDO> selectWithPage(const OwnerPaymentQuery::Wrapper& query);
	std::list<OwnerPaymentDO> listAllDO();
	std::list<OwnerPaymentDO> selectFeeTypeList(const OwnerPaymentListQuery::Wrapper& query);
	std::list<OwnerPaymentDO> selectConfigNametList(const OwnerPaymentListQuery::Wrapper& query);

};
#endif // !_OWNERPAYMENT_DAO_