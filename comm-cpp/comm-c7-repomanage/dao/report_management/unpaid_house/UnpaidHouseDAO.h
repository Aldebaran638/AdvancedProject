#pragma once
#include "BaseDAO.h"
#include "domain/query/unpaid_house/UnpaidHouseQuery.h"
#include "domain/do/unpaid_house/UnpaidHouseDO.h"

#ifndef _UNPAIDHOUSEDAO_
#define _UNPAIDHOUSEDAO_

class UnpaidHouseDAO : public BaseDAO
{
private:
	// 查询条件构建器，根据UnpaidHouseQuery对象动态构建查询条件相关参数
	inline std::string queryConditionBuilder(const UnpaidHouseQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const UnpaidHouseQuery::Wrapper& query);
	// 分页查询数据
	std::list<UnpaidHouseDO> selectWithPage(const UnpaidHouseQuery::Wrapper& query);
	// 下载查询数据
	std::list<UnpaidHouseDO> selectAll(const UnpaidHouseQuery::Wrapper& query);

};

class FloorDAO : public BaseDAO
{
public:
	// 查询数据
	std::list<FloorDO> selectAll(const FloorQuery::Wrapper& query);

};

class UnitDAO : public BaseDAO
{
public:
	// 查询数据
	std::list<UnitDO> selectAll(const UnitQuery::Wrapper& query);

};

class RoomDAO : public BaseDAO
{
public:
	// 查询数据
	std::list<RoomDO> selectAll(const RoomQuery::Wrapper& query);

};

#endif // !_UNPAIDHOUSEDAO_