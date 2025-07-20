#pragma once

#ifndef _SELECTCAR_DAO_
#define _SELECTCAR_DAO_
#include "BaseDAO.h"

#include "../../domain/do/car/CarDO.h"
#include "../../domain/query/car/CarQuery.h"


class selectCarDAO : public BaseDAO
{
private:

	inline std::string queryConditionBuilder(const CarQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const CarQuery::Wrapper& query);
	// 分页查询数据
	std::list<CarDO> selectWithPage(const CarQuery::Wrapper& query);
};

#endif
