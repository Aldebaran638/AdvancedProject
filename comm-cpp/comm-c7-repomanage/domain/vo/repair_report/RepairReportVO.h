#pragma once

#ifndef _REPAIRREPORTVO_H_
#define _REPAIRREPORTVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/repair_report/RepairReportDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修收费显示JsonVO，用于响应给客户端的Json对象
 */
class RepairReportFeeJsonVO : public JsonVO<RepairReportFeeDTO::Wrapper> {
	DTO_INIT(RepairReportFeeJsonVO, JsonVO<RepairReportFeeDTO::Wrapper>);
};

/**
 * 报修分页显示JsonVO，用于响应给客户端的Json对象
 */
class RepairReportFeePageJsonVO : public JsonVO<RepairReportFeePageDTO::Wrapper> {
	DTO_INIT(RepairReportFeePageJsonVO, JsonVO<RepairReportFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 