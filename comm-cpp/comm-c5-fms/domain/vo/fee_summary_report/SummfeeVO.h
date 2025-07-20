#pragma once

#ifndef _SUMMFEEVO_H_
#define _SUMMFEEVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/fee_summary_report/SummfeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用汇总显示JsonVO，用于响应给客户端的Json对象
 */
class FeeSummaryJsonVO : public JsonVO<FeeSummaryDTO::Wrapper> {
	DTO_INIT(FeeSummaryJsonVO, JsonVO<FeeSummaryDTO::Wrapper>);
};

/**
 *费用汇总分页显示JsonVO，用于响应给客户端的Json对象
 */
class FeeSummaryPageJsonVO : public JsonVO<FeeSummaryPageDTO::Wrapper> {
	DTO_INIT(FeeSummaryPageJsonVO, JsonVO<FeeSummaryPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_