#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/05/18 11:11:44

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PAYMENTAUDITCONNTROLLER_H_
#define _PAYMENTAUDITCONNTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/payment_reviews/PaymentAduitQuery.h"
#include "domain/dto/payment_reviews/PaymentAuditDTO.h"
#include "domain/vo/payment_reviews/PaymentAduitVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class PaymentAuditController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PaymentAuditController);
public: // 定义接口
	//获取缴费审核列表接口端点描述
	ENDPOINT_INFO(queryPaymentAuditList) {
		// 接口描述
		info->summary = ZH_WORDS_GETTER("paymentaudit.list.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PaymentAuditListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_type", ZH_WORDS_GETTER("paymentaudit.field.payer_obj_type"), "fangwu", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("paymentaudit.field.state"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "value", ZH_WORDS_GETTER("paymentaudit.field.value"), "1-1-1", false);

	}
	// 获取缴费审核列表接口端点
	ENDPOINT(API_M_GET, "/c5-feemanage/paymentaudit/get-paymentaudit", queryPaymentAuditList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(listQuery, PaymentAuditListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPaymentAuditList(listQuery));
	}

	// 获取缴费审核详情接口端点描述
	ENDPOINT_INFO(queryPaymentAuditDetail) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("paymentaudit.detail.summary"), PaymentAuditDetailJsonVO::Wrapper);
		// 费用id（非用户输入）
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("paymentaudit.field.fee_id_a"), "902025051894710014", true);
	}
	// 获取缴费审核详情接口端点
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c5-feemanage/paymentaudit/get-detail", queryPaymentAuditDetail, QUERY(String, fee_id), execQueryPaymentAuditDetail(fee_id));


	// 获取缴费历史列表接口端点描述
	ENDPOINT_INFO(queryPaymentAuditHistory) {
		// 接口描述
		info->summary = ZH_WORDS_GETTER("paymentaudit.lhistory.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PaymentAuditHistoryJsonVO);
		// 接口参数
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("paymentaudit.field.start_time"), "2025-03-06", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("paymentaudit.field.end_time"), "2025-03-06", false);
		// 费用id（非用户输入）
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("paymentaudit.field.fee_id_a"), "902025051894710014", true);
	}
	// 获取缴费历史列表接口端点
	ENDPOINT(API_M_GET, "/c5-feemanage/paymentaudit/get-history", queryPaymentAuditHistory, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(historyQuery, PaymentAuditHistoryQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPaymentAuditHistory(historyQuery));
	}



private: // 定义接口执行函数
	// 声执行函数
	PaymentAuditListJsonVO::Wrapper execQueryPaymentAuditList(const PaymentAuditListQuery::Wrapper& listquery);

	PaymentAuditDetailJsonVO::Wrapper execQueryPaymentAuditDetail(const String& fee_id);

	PaymentAuditHistoryJsonVO::Wrapper execQueryPaymentAuditHistory(const PaymentAuditHistoryQuery::Wrapper& historyquery);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PAYMENTAUDITCONNTROLLER_H_