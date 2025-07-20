#ifndef _CANCELLATIONFEECONTROLLER_H_
#define _CANCELLATIONFEECONTROLLER_H_
#include"domain/vo/fee_cancellations/CancellationFeeVO.h"
#include"domain/dto/fee_cancellations/CancellationFeeDTO.h"
#include"domain/query/fee_cancellations/CancellationFeeQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class CancellationFeeController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(CancellationFeeController);
public://定义接口

	// 定义查询接口描述和相应格式
	ENDPOINT_INFO(queryAll) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cancellationfee.get.summary"), CancellationFeePageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "batchId", ZH_WORDS_GETTER("cancellationfee.field.batchId"), "122025051547630128", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("cancellationfee.field.state"), ZH_WORDS_GETTER("cancellationfee.state.2006001"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "createUserName", ZH_WORDS_GETTER("cancellationfee.field.createUserName"), "wuwx", false);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/cancellationfee/query-cancellationfee", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, CancellationFeeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	//定义申请取消接口描述和相应格式
	ENDPOINT_INFO(addApplyCancel) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cancellationfee.post.apply"), StringJsonVO::Wrapper);
	}
	//  定义申请取消接口处理
	ENDPOINT(API_M_POST, "/c5-feemanage/cancellationfee/apply-cancellationfee", addApplyCancel, BODY_DTO(CancellationFeeApplyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execApplyCancel(dto, authObject->getPayload()));
	}

	//定义审核取消接口描述和相应格式
	ENDPOINT_INFO(addAuditCancel) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cancellationfee.post.audit"), StringJsonVO::Wrapper);
	}
	//  定义审核取消接口处理
	ENDPOINT(API_M_POST, "/c5-feemanage/cancellationfee/audit-cancellationfee", addAuditCancel, BODY_DTO(CancellationFeeAuditDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAuditCancel(dto, authObject->getPayload()));
	}


private://定义接口执行函数
	CancellationFeePageJsonVO::Wrapper execQueryAll(const CancellationFeeQuery::Wrapper& query);
	StringJsonVO::Wrapper execApplyCancel(const CancellationFeeApplyDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execAuditCancel(const CancellationFeeAuditDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_ROUTER_