#pragma once

#ifndef _DISSATISFIEDREPAIR_DAO_H_
#define _DISSATISFIEDREPAIR_DAO_H_

#include "BaseDAO.h"
#include "../../../domain/do/repair_report/DissatisfiedRepairDO.h"
#include "../../../domain/query/repair_report/DissatisfiedRepairQuery.h"

class DissatisfiedRepairDAO :public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const DissatisfiedRepairQuery::Wrapper& query, SqlParams& params);
public:
	std::list<DissatisfiedRepairDO> selectWithPage(const DissatisfiedRepairQuery::Wrapper& query);
	std::list<DissatisfiedRepairDO> listAllDO();
	uint64_t count(const DissatisfiedRepairQuery::Wrapper& query);
};
#endif //!_DISSATISFIEDREPAIR_DAO_H_