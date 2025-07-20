#include "stdafx.h"
#include "YyycReviewsService.h"
#include "../../dao/refund_reviews/YyycReviewsDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../../arch-demo/Macros.h"

bool YyycReviewsService::updateData(const ReviewsRefundDTO::Wrapper& dto)
{
	// 组装DO数据
	YyycReviewsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, State, state, Reason, reason, Id, id);
	////  设置审核状态
	//data.setState(dto->state.getValue({}));
	//// 设置审核原因
	//data.setReason(dto->reason.getValue({}));
	// 执行数据修改
	YyycRevewsDAO dao;
	return dao.update(data) == 1;
}
