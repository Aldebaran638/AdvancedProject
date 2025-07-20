#pragma once

#ifndef _UNIT_DAO_
#define _UNIT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/UnitDO/UnitDO.h"
#include "../../domain/query/UnitQuery/UnitQuery.h"

class UnitDAO : public BaseDAO {
private:
	inline std::string queryConditionBuilder(const UnitQuery::Wrapper& query, SqlParams& params);
public:
	// 插入数据
	int insert(const UnitDO& iObj);
	// 修改数据
	int update(const UnitDO& uObj);
	// 修改全部数据
	int update_all(const UnitDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string id);

	uint64_t count(const UnitQuery::Wrapper& query);
	uint64_t countCommunityUnit(const UnitQuery::Wrapper& query);
	std::list<UnitDO> selectUnit(const UnitQuery::Wrapper& query);
	std::list<UnitDO> selectCommunityUnit(const UnitQuery::Wrapper& query);
};

#endif