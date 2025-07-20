#pragma once

#ifndef _SPACEVO_H_
#define _SPACEVO_H_

#include "../GlobalInclude.h"
#include "../dto/SpaceDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  场地显示JsonVO，用于响应给客户端的Json对象
 */
class SpaceJsonVO : public JsonVO<SpaceDTO::Wrapper> {
	DTO_INIT(SpaceJsonVO, JsonVO<SpaceDTO::Wrapper>);
};

/**
 * 场地分页显示JsonVO，用于响应给客户端的Json对象
 */
class SpacePageJsonVO : public JsonVO<SpacePageDTO::Wrapper> {
	DTO_INIT(SpacePageJsonVO, JsonVO<SpacePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_