#pragma once
#ifndef _YYYCREVIEWSCONTROLLER_H_
#define _YYYCREVIEWSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/refund_reviews/YyycReviewsDTO.h"
#include "domain/query/refund_reviews/YyycReviewsQuery.h"
#include "domain/vo/refund_reviews/YyycReviewsVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
	审核退费模型
*/
class YyycReviewsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(YyycReviewsController);
public: // 定义接口
	// 1.1 定义审核退费接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("refund.put.summary"), AddRefundReview, StringJsonVO::Wrapper);
	// 1.2 定义审核退费接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c5-feemanage/refund/put-refund", AddRefundReview, BODY_DTO(ReviewsRefundDTO::Wrapper, dto), execAddRefundReview(dto, authObject->getPayload()));

private:// 定义接口执行函数
	StringJsonVO::Wrapper execAddRefundReview(const ReviewsRefundDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif