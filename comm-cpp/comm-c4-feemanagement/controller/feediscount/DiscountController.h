#ifndef _DISCOUNT_CONTROLLER_H_
#define _DISCOUNT_CONTROLLER_H_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/feediscount/DiscountDo.h"
#include "domain/dto/feediscount/DiscountDto.h"
#include "domain/vo/feediscount/DiscountVo.h"
#include "domain/query/feediscount/DiscountQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class DiscountController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(DiscountController);

public:
	//ÃÌº”’€ø€
	ENDPOINT_INFO(addDiscount) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("discount.post.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT("POST", "/c4-discount/add-discount", addDiscount, BODY_DTO(DiscountAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddDiscount(dto,authObject->getPayload()));
	}

	//–ﬁ∏ƒ’€ø€
	ENDPOINT_INFO(modifyDiscount) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("discount.put.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT("PUT", "/c4-discount/modify-discount", modifyDiscount, BODY_DTO(DiscountChangeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModifyDiscount(dto, authObject->getPayload()));
	}

	//…æ≥˝’€ø€
	ENDPOINT_INFO(deleteDiscount) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("discount.delete.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT("DELETE", "/c4-discount/delete-discount", deleteDiscount, BODY_DTO(DiscountDeleteDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteDiscount(dto, authObject->getPayload()));
	}

	//≤È—Ø’€ø€
	ENDPOINT_INFO(getDiscount) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("discount.get.summary"));
		API_DEF_ADD_AUTH();

		//∑÷“≥≤È—Ø
		API_DEF_ADD_PAGE_PARAMS();
		//Ãıº˛≤È—Ø
		API_DEF_ADD_QUERY_PARAMS(String, "discount_id", ZH_WORDS_GETTER("discount.field.all.discount_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String,"discount_name",ZH_WORDS_GETTER("discount.field.fee_discount.discount_name"),"",false);
		API_DEF_ADD_QUERY_PARAMS(String, "discount_type", ZH_WORDS_GETTER("discount.field.fee_discount.discount_type"), "", false);

		API_DEF_ADD_RSP_JSON_WRAPPER(DiscountPageJsonVO);
	}
	ENDPOINT("GET", "/c4-discount/list-discount", getDiscount, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery,DiscountQuery,queryParams);
		API_HANDLER_RESP_VO(execQueryDiscount(userQuery));
	}

private:
	StringJsonVO::Wrapper execAddDiscount(const DiscountAddDTO::Wrapper& dto,const PayloadDTO& payload);
	StringJsonVO::Wrapper execModifyDiscount(const DiscountChangeDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDeleteDiscount(const DiscountDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	DiscountPageJsonVO::Wrapper execQueryDiscount(const DiscountQuery::Wrapper& query);
};



#include OATPP_CODEGEN_END(ApiController)

#endif