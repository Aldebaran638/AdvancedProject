#pragma once
#ifndef _APPLYDISCOUNTVO_H
#define _APPLYDISCOUNTVO_H

#include "../../GlobalInclude.h"
#include "../../dto//applydiscount/ApplyDiscountDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 优惠申请显示JsonVO，用于响应给客户端的Json对象
 */
class ApplyDiscountJsonVO : public JsonVO<ApplyDiscountDTO::Wrapper> {
	DTO_INIT(ApplyDiscountJsonVO, JsonVO<ApplyDiscountDTO::Wrapper>);
};

/**
 * 优惠申请分页显示JsonVO，用于响应给客户端的Json对象
 */
class ApplyDiscountPageJsonVO : public JsonVO<ApplyDiscountPageDTO::Wrapper> {
	DTO_INIT(ApplyDiscountPageJsonVO, JsonVO<ApplyDiscountPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_ApplyDiscountRecordVO_H