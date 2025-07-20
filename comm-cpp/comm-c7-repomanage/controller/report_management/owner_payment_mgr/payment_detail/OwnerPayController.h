#pragma once
#ifndef _OWNERPAYCONTROLLER_H_
#define _OWNERPAYCONTROLLER_H_

#include "domain/vo/owner_payment/OwnerPaymentVO.h"
#include "domain/dto/owner_payment/OwnerPaymentDTO.h"
#include "domain/query/owner_payment/OwnerPaymentQuery.h"
#include "domain/vo/BaseJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class OwnerPaymentController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(OwnerPaymentController);
public: // 定义接口
	// 3.1 定义分页查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-detail.get.summary"), OwnerPaymentPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeCd", ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "configName", ZH_WORDS_GETTER("owner-payment-detail.field.configName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "roomName", ZH_WORDS_GETTER("owner-payment-detail.field.roomName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("owner-payment-detail.field.ownerName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pfYear", ZH_WORDS_GETTER("owner-payment-detail.field.pfYear"), "", false);
	}
	// 3.2 定义分页查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-detail", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, OwnerPaymentQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 获取收费大类列表
	ENDPOINT_INFO(queryOwnerPaymentFeeType) {
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-detail.get.feeTypeList"), OwnerPaymentFeeTypeJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("owner-payment-detail.field.communityId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeCd", ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"), "", false);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-detail/fee-type-list",queryOwnerPaymentFeeType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, OwnerPaymentListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOwnerPaymentFeeType(query));
	}

	// 获取收费类型列表
	ENDPOINT_INFO(queryOwnerPaymentConfigName) {
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-detail.get.configNameList"), OwnerPaymentConfigNameJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("owner-payment-detail.field.communityId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeCd", ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"), "", false);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-detail/config-name-list", queryOwnerPaymentConfigName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, OwnerPaymentListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOwnerPaymentConfigName(query));
	}

private: // 定义接口执行函数
	// 3.3 分页查询数据
	OwnerPaymentPageJsonVO::Wrapper execQueryAll(const OwnerPaymentQuery::Wrapper& query);
	OwnerPaymentFeeTypeJsonVO::Wrapper execQueryOwnerPaymentFeeType(const OwnerPaymentListQuery::Wrapper& query);
	OwnerPaymentConfigNameJsonVO::Wrapper execQueryOwnerPaymentConfigName(const OwnerPaymentListQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERPAYCONTROLLER_H_