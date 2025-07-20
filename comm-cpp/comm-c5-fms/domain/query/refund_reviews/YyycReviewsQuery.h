#pragma once
#ifndef _YYYCREVIEWSQUERY_
#define _YYYCREVIEWSQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class YyycReviewsQuery : public PageQuery
{
	DTO_INIT(YyycReviewsQuery, PageQuery);
	// ÉóºË×´Ì¬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("refund.field.state");
	}
	// Ô­Òò
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("refund.field.reason");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // 