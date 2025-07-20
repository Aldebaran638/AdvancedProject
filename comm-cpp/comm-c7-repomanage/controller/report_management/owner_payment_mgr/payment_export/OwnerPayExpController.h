#pragma once
#ifndef _OWNERPAYEXPCONTROLLER_H_
#define _OWNERPAYEXPCONTROLLER_H_

#include "domain/vo/owner_payment/OwnerPaymentVO.h"
#include "domain/dto/owner_payment/OwnerPaymentDTO.h"
#include "domain/query/owner_payment/OwnerPaymentQuery.h"
#include "domain/vo/BaseJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class OwnerPaymentExpController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(OwnerPaymentExpController);
public: // 定义接口
	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportALL) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-export.export.summary"), Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-export", exportALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, OwnerPaymentQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExport(userQuery);
	}

private: // 定义接口执行函数
	// 3.3 分页导出数据
	std::shared_ptr<OutgoingResponse> execExport(const OwnerPaymentQuery::Wrapper& userQuery);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERPAYEXPCONTROLLER_H_