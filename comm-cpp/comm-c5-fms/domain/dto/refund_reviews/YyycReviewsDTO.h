#pragma once
#ifndef _YYCREVIEWSDTO_H_
#define _YYCREVIEWSDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	审核退费模型
*/
class ReviewsRefundDTO : public oatpp::DTO
{
	DTO_INIT(ReviewsRefundDTO, DTO);

	// 审核状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("refund.field.state"));
	// 原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("refund.field.reason"));
	// 退费id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("refund.field.id"));

	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_BEGIN(DTO)

#endif  //!_YYYCDISTYPESDTO_H