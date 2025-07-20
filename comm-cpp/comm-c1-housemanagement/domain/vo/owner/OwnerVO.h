#pragma once

#ifndef _OWNER_VO_
#define _OWNER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/owner/OwnerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 业主显示JsonVO，用于响应给客户端的Json对象
 */
class OwnerJsonVO :public JsonVO<OwnerDTO::Wrapper> {
	DTO_INIT(OwnerJsonVO, JsonVO<OwnerDTO::Wrapper>);
};
/**
 * 业主信息分页显示JsonVO，用于响应给客户端的Json对象
 */
class OwnerPageJsonVO :public JsonVO<OwnerPageDTO::Wrapper> {
	DTO_INIT(OwnerPageJsonVO, JsonVO<OwnerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif
