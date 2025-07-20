#pragma once
#ifndef _MEMBER_VO_
#define _MEMBER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/member/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MemberPageJsonVO : public JsonVO<MemberPageDTO::Wrapper> {
	DTO_INIT(MemberPageJsonVO, JsonVO<MemberPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_