#pragma once
#ifndef _APPLYDISCOUNTRECORDVO_H
#define _APPLYDISCOUNTRECORDVO_H

#include "../../GlobalInclude.h"
#include "../../dto//applydiscount/ApplyDiscountRecordDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 优惠申请显示JsonVO，用于响应给客户端的Json对象
 */
class ApplyDiscountRecordJsonVO : public JsonVO<ApplyDiscountRecordDTO::Wrapper> {
	DTO_INIT(ApplyDiscountRecordJsonVO, JsonVO<ApplyDiscountRecordDTO::Wrapper>);
};

/**
 * 优惠申请分页显示JsonVO，用于响应给客户端的Json对象
 */
class ApplyDiscountRecordPageJsonVO : public JsonVO<ApplyDiscountRecordPageDTO::Wrapper> {
	DTO_INIT(ApplyDiscountRecordPageJsonVO, JsonVO<ApplyDiscountRecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_ApplyDiscountRecordVO_H