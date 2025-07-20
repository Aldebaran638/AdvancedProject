#pragma once

#ifndef _INSPECTION_POINT_STATISTIC_VO_H_
#define _INSPECTION_POINT_STATISTIC_VO_H_
//InspectionPointStatisticVO
#include "domain/GlobalInclude.h"
#include "domain/dto/inspection_report/InspectionPointStatisticDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 巡检点统计显示JsonVO，用于响应给客户端的Json对象
 */
class InspectionPointStatisticJsonVO : public JsonVO<InspectionPointStatisticDTO::Wrapper> {
	DTO_INIT(InspectionPointStatisticJsonVO, JsonVO<InspectionPointStatisticDTO::Wrapper>);
};
/**
 * 巡检点统计分页显示JsonVO
 */
class InspectionPointStatisticPageJsonVO : public JsonVO<InspectionPointStatisticPageDTO::Wrapper> { // 修改模板参数
	DTO_INIT(InspectionPointStatisticPageJsonVO, JsonVO<InspectionPointStatisticPageDTO::Wrapper>); // 匹配分页DTO
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_INSPECTION_POINT_STATISTIC_VO_H_