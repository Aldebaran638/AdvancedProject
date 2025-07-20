#pragma once

#ifndef _QueryRepairStatistics_VO_
#define _QueryRepairStatistics_VO_

#include "../../GlobalInclude.h"
#include "../../dto/repair_report/RepairStatisticsDTO.h"
//#include <oatpp/core/Types.hpp> 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示报修统计JsonVO，用于响应给客户端的Json对象
 */
class QueryRepairStatisticsJsonVO : public JsonVO<QueryRepairStatisticsDTO::Wrapper> {
	DTO_INIT(QueryRepairStatisticsJsonVO, JsonVO<QueryRepairStatisticsDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_QueryRepairStatistics_VO_