#include "stdafx.h"
#include "RepairStatisticsService.h"
#include "../../../domain/do/repair_report/RepairStatisticsDO.h"
#include "../../../dao/report_management/repair_report/RepairStatisticsDAO.h"
#include "../../../domain/dto/repair_report/RepairStatisticsDTO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"



QueryRepairStatisticsDTO::Wrapper RepairStatisticsService::countRepairStatistics(const QueryRepairStatisticsQuery::Wrapper& query) {
	RepairStatisticsDAO dao;
	auto res = dao.getRepairStatistics(query);
	//查询到的数据dao转换为dto
	auto dto = QueryRepairStatisticsDTO::createShared();
	//dao->dto
	for (RepairStatisticsDO sub : res) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, public_count, PublicAreaTotal,
			private_count, NonPublicAreaTotal, assigned_count, DispatchedOrders,
			revisit_count, ReturnVisitCount, unrevisit_count, UnreturnedVisitCount,
			public_incomplete, PublicAreaUnfinished, private_incomplete, NonPublicAreaUnfinished);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_pay, RepairReceivable, repair_payed, RepairReceived,
			private_incomplete_average, NonPublicAreaCompletionRate,
			public_incomplete_average, PublicAreaCompletionRate);
	}
	return dto;

}

