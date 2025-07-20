#pragma once
#ifndef _ORDER_DAO_
#define _ORDER_DAO_

#include "BaseDAO.h"
#include "domain/do/venue-reservation/OrderDO.h"
#include "domain/query/venue-reservation/OrderQuery.h"

class OrderDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const OrderQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const OrderQuery::Wrapper& query);
	// 分页查询数据
	std::list<OrderDO> selectWithPage(const OrderQuery::Wrapper& query);
	// 修改数据
	int update(const std::string id);
};

#endif // !_ORDER_DAO_
