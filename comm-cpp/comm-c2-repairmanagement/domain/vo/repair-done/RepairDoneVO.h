#pragma once
#ifndef _REPAIRDONE_VO_
#define _REPAIRDONE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/repair-done/RepairDoneDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修已办显示JsonVO，用于响应给客户端的Json对象
 */
class RepairDoneJsonVO : public JsonVO<RepairDoneDTO::Wrapper> {
	DTO_INIT(RepairDoneJsonVO, JsonVO<RepairDoneDTO::Wrapper>);
};

/**
 * 报修已办分页显示JsonVO，用于响应给客户端的Json对象
 */
class RepairDonePageJsonVO : public JsonVO<RepairDonePageDTO::Wrapper> {
	DTO_INIT(RepairDonePageJsonVO, JsonVO<RepairDonePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REPAIRDONE_VO_