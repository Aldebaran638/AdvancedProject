#ifndef _REPAIR_STATISTICS_MAPPER_
#define _REPAIR_STATISTICS_MAPPER_

#include "../../../domain/do/repair_report/RepairStatisticsDO.h"
#include "Mapper.h"

class RepairStatisticsMapper : public Mapper<RepairStatisticsDO> {
public:
	RepairStatisticsDO mapper(sql::ResultSet* resultSet) const override {
		RepairStatisticsDO stats;
		stats.setPublicAreaTotal(resultSet->getInt("public_area_total"));
		stats.setNonPublicAreaTotal(resultSet->getInt("non_public_area_total"));
		stats.setDispatchedOrders(resultSet->getInt("dispatched_orders"));
		stats.setReturnVisitCount(resultSet->getInt("return_visits"));
		stats.setUnreturnedVisitCount(resultSet->getInt("unreturned_visits"));
		stats.setPublicAreaUnfinished(resultSet->getInt("public_area_unfinished"));
		stats.setNonPublicAreaUnfinished(resultSet->getInt("non_public_area_unfinished"));
		stats.setRepairReceivable(resultSet->getDouble("repair_receivable"));
		stats.setRepairReceived(resultSet->getDouble("repair_received"));
		stats.setNonPublicAreaCompletionRate(resultSet->getDouble("non_public_completion_rate"));
		stats.setPublicAreaCompletionRate(resultSet->getDouble("public_completion_rate"));

		return stats;
	}
};

#endif // _REPAIR_STATISTICS_MAPPER_