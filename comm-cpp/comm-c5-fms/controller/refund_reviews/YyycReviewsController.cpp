#include"stdafx.h"
#include"YyycReviewsController.h"
#include "../../service/refund_reviews/YyycReviewsService.h"

StringJsonVO::Wrapper YyycReviewsController::execAddRefundReview(const ReviewsRefundDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	YyycReviewsService service;
	// 执行退费审核数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}
