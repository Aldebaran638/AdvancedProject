#pragma once
#ifndef _RAINDISTYPESVO_H_
#define _RAINDISTYPESVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/discount_types/RainDisTypesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取优惠类型名称列表Json对象
 */
class RainDisTypesJsonVO : public JsonVO<RainDisTypesGetDTO::Wrapper>
{
	DTO_INIT(RainDisTypesJsonVO, JsonVO<RainDisTypesGetDTO::Wrapper>);
};

/**
 * 获取优惠类型列表（分页）Json对象
 */
class RainDisTypesPageJsonVO : public JsonVO<RainDisTypesPageDTO::Wrapper>
{
	DTO_INIT(RainDisTypesPageJsonVO, JsonVO<RainDisTypesPageDTO::Wrapper>);
};

/**
 * 优惠类型名称列表响应（用于下拉框）
 */
class RainDisTypesListJsonVO : public JsonVO<oatpp::List<RainDisTypesGetDTO::Wrapper>>
{
	DTO_INIT(RainDisTypesListJsonVO, JsonVO<oatpp::List<RainDisTypesGetDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _RAINDISTYPESVO_H_