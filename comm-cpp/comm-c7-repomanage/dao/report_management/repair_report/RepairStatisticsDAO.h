#pragma once
#ifndef _REPAIRSTATISTICS_DAO_
#define _REPAIRSTATISTICS_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/repair_report/RepairStatisticsDO.h"
#include "../../../domain/query/repair_report/RepairStatisticsQuery.h"

class RepairStatisticsDAO : public BaseDAO {
public:
	std::list<RepairStatisticsDO> getRepairStatistics(const QueryRepairStatisticsQuery::Wrapper& query);
};

#endif // !_REPAIRSTATISTICS_DAO_
