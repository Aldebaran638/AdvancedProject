#pragma once

#ifndef _PAYFEECONTROLLER_H_
#define _PAYFEECONTROLLER_H_

#include "domain/vo/PayFeeVO.h"
#include "domain/dto/PayFeeDTO.h"
#include "domain/query/PayFeeQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PayFeeController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PayFeeController);
public: // 定义接口

	ENDPOINT_INFO(queryChargeItem) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("feeMgr.get.getItem"), ChargeItemListJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("feeMgr.field.community_id"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"), "", false);
	}

	ENDPOINT(API_M_GET, "/c3-expensesetting/query-feeitemname", queryChargeItem, QUERY(String, community_id), QUERY(String, feeType, "feeType", "default"), API_HANDLER_AUTH_PARAME) {

		API_HANDLER_RESP_VO(execQueryChargeItem(community_id, feeType));
	}


	// 3.1 定义分页查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("feeMgr.get.summary"), PayFeePageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("feeMgr.field.community_id"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_type_cd", ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeId", ZH_WORDS_GETTER("feeMgr.field.config_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "chargeItem", ZH_WORDS_GETTER("feeMgr.field.fee_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_flag", ZH_WORDS_GETTER("feeMgr.field.fee_flag"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "payment_cd", ZH_WORDS_GETTER("feeMgr.field.payment_cd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deduct_from", ZH_WORDS_GETTER("feeMgr.field.deduct_from"), "", false);
	}
	// 3.2 定义分页查询接口处理
	ENDPOINT(API_M_GET, "/c3-expensesetting/query-feeitem-page", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, PayFeeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}


private: // 定义接口执行函数
	// 3.3 分页查询数据
	PayFeePageJsonVO::Wrapper execQueryAll(const PayFeeQuery::Wrapper& query);

	ChargeItemListJsonVO::Wrapper execQueryChargeItem(const String& community_id, const String& feeType);
};
#include OATPP_CODEGEN_END(ApiController)

#endif
