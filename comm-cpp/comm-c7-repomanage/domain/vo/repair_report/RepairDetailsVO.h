#pragma once

#ifndef _RepairDetails_VO_
#define _RepairDetails_VO_

#include "../../GlobalInclude.h"
#include "../../dto/repair_report/RepairDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示保修明细的JsonVO，用于响应给客户端的Json对象
 */
class RepairDetailsJsonVO : public JsonVO<RepairDetailsDTO::Wrapper> {
	DTO_INIT(RepairDetailsJsonVO, JsonVO<RepairDetailsDTO::Wrapper>);
};

/**
 * 报修明细分页显示JsonVO，用于响应给客户端的Json对象
 */
class RepairDetailsPageJsonVO : public JsonVO<RepairDetailsListPageDTO::Wrapper> {
	DTO_INIT(RepairDetailsPageJsonVO, JsonVO<RepairDetailsListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RepairDetails_VO_