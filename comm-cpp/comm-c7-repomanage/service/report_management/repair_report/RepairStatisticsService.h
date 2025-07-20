#pragma once
#ifndef _REPAIRSTATISTICS_SERVICE_
#define _REPAIRSTATISTICS_SERVICE_
#include "../../../domain/query/repair_report/RepairStatisticsQuery.h"
#include "../../../domain/dto/repair_report/RepairStatisticsDTO.h"

class RepairStatisticsService {
public:
	QueryRepairStatisticsDTO::Wrapper countRepairStatistics(const QueryRepairStatisticsQuery::Wrapper& query);
};

#endif // !_REPAIRSTATISTICS_SERVICE_