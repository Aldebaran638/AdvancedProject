#pragma once
#ifndef _YYYCREVIEWSVO_
#define _YYYCREVIEWSVO_

#include "../../GlobalInclude.h"
#include "../../dto/refund_reviews/YyycReviewsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * …Û∫ÀÕÀ∑—Json∂‘œÛ
 */
class ReviewsRefundJsonVO : public JsonVO<ReviewsRefundDTO::Wrapper> {
	DTO_INIT(ReviewsRefundJsonVO, JsonVO<ReviewsRefundDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif 