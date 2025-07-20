#pragma once
#ifndef _DEPOSIT_REPORT_VO_
#define _DEPOSIT_REPORT_VO_
#include "../../GlobalInclude.h"
#include "../../dto/deposit_report/DepositReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class DepositReportJsonVO : public JsonVO<DepositReportDTO::Wrapper> {
	DTO_INIT(DepositReportJsonVO, JsonVO<DepositReportDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class DepositReportPageJsonVO : public JsonVO<DepositReportPageDTO::Wrapper> {
	DTO_INIT(DepositReportPageJsonVO, JsonVO<DepositReportPageDTO::Wrapper>);
};

/**
 * 导出结果VO
 */
class DepositReportExportVO : public JsonVO<DepositReportExportDTO::Wrapper>
{
	DTO_INIT(DepositReportExportVO, JsonVO<DepositReportExportDTO::Wrapper>)
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DEPOSIT_REPORT_VO_