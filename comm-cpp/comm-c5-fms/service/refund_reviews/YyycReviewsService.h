#pragma once
#ifndef _YYYCREVIEWSSERVICE_
#define _YYYCREVIEWSSERVICE_
#include "domain/vo/refund_reviews/YyycReviewsVO.h"
#include "domain/query/refund_reviews/YyycReviewsQuery.h"
#include "domain/dto/refund_reviews/YyycReviewsDTO.h"

class YyycReviewsService
{
public:
	// ÐÞ¸ÄÊý¾Ý
	bool updateData(const ReviewsRefundDTO::Wrapper& dto);
};

#endif
