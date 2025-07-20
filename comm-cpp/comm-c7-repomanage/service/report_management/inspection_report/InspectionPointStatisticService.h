#pragma once
#ifndef _INSPECTION_POINT_STATISTIC_SERVICE_H_
#define _INSPECTION_POINT_STATISTIC_SERVICE_H_
//InspectionPointStatisticService
#include "domain/vo/inspection_report/InspectionPointStatisticVO.h"
#include "domain/query/inspection_report/InspectionPointStatisticQuery.h"
#include "domain/dto/inspection_report/InspectionPointStatisticDTO.h"
#include "domain/do/inspection_report/InspectionPointStatisticDO.h"
/**
 * 获取巡检点统计列表服务实现
 */
class InspectionPointStatisticService
{
public:
	// 分页查询所有数据
	InspectionPointStatisticPageDTO::Wrapper listAll(const InspectionPointStatisticQuery::Wrapper& query);
	
	//oatpp::List<InspectionPointStatisticDTO::Wrapper>
	//	InspectionPointStatisticService::listAllExport(const InspectionPointStatisticQuery::Wrapper& query);
	oatpp::List<InspectionPointStatisticDTO::Wrapper>
		listAllExport(const InspectionPointStatisticQuery::Wrapper& query);
};

#endif // !_INSPECTION_POINT_STATISTIC_SERVICE_H_

