#pragma once
#ifndef _FORCEBACKVO_H_
#define _FORCEBACKVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/force-back/ForceBackDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个强制回单显示JsonVO对象，用于响应给客户端
 */
class ForceBackJsonVO : public JsonVO<ForceBackDTO::Wrapper>
{
	DTO_INIT(ForceBackJsonVO, JsonVO<ForceBackDTO::Wrapper>);
};
/**
 * 定义一个强制回单分页显示JsonVO对象，用于响应给客户端
 */
class ForceBackPageJsonVO : public JsonVO<ForceBackPageDTO::Wrapper>
{
	DTO_INIT(ForceBackPageJsonVO, JsonVO<ForceBackPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_FORCEBACKVO_H_
