#pragma once
#ifndef _REFUNDREVIEW_H_
#define _REFUNDREVIEW_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
class RefundReviewController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(RefundReviewController);
public:
	//1.导出欠费信息
	ENDPOINT_INFO(downloadInRefund) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("refund.download.summary1"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("refund.download.summary2"), "refund_review.xlsx", true);
		API_DEF_ADD_AUTH();
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/c5-feemanage/refund/download-refund", downloadInRefund, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return downloadRefundReview(filename);
	}
private:
	//1.导出欠费信息excle文件
	std::shared_ptr<OutgoingResponse> downloadRefundReview(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_REFUNDREVIEW_H_