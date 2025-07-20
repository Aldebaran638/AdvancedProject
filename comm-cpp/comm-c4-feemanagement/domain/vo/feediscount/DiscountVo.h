#ifndef _DISCOUNT_VO_H_
#define _DISCOUNT_VO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/feediscount/DiscountDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DiscountPageJsonVO : public JsonVO<DiscountPageDTO::Wrapper> {
	DTO_INIT(DiscountPageJsonVO, JsonVO<DiscountPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif