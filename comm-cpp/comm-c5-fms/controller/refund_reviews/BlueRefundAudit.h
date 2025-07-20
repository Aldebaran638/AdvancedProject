#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 12:16:04

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
#ifndef BLUEREFUNDADUITCONTROLLER_
#define BLUEREFUNDADUITCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/refund_reviews/BlueRefundAduitQuery.h"
#include "domain/vo/refund_reviews/BlueRefundAduitVO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class BlueRefundAduitController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(BlueRefundAduitController);
	// 3 定义接口
public:
	//定义获取退费审核列表接口描述
	ENDPOINT_INFO(FeeReview) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("blue.refundauditlist.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("blue.refundauditlist.id"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "range", ZH_WORDS_GETTER("blue.refundauditlist.range"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("blue.refundauditlist.status"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "applicant", ZH_WORDS_GETTER("blue.refundauditlist.applicant"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Reviewers", ZH_WORDS_GETTER("blue.refundauditlist.Reviewers"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Housenumber", ZH_WORDS_GETTER("blue.refundauditlist.Housenumber"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Applicationstarttime", ZH_WORDS_GETTER("blue.refundauditlist.Applicationstarttime"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Applicatioendtime", ZH_WORDS_GETTER("blue.refundauditlist.Applicatioendtime"), "0", false);
	}
	//定义获取退费审核列表接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/refund/get-list", FeeReview, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, FeeReviewQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFeeReview(userQuery));
	}


	//定义获取退费审核详情接口描述
	ENDPOINT_INFO(FeeDetails) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("blue.refundauditlist.detail"), FeeDetailJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("blue.refundauditlist.id"), "0", true);
	}
	//定义获取退费审核详情接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c5-feemanage/refund/get-detail", FeeDetails, QUERY(String, id), execQueryFeeDetail(id));


	//定义获取缴费历史列表接口描述
	ENDPOINT_INFO(FeeHistory) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("blue.refundauditlist.history"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeHistoryJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("blue.refundauditlist.begin"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("blue.refundauditlist.end"), "0", false);
	}
	// 3.2 定义获取缴费历史列表接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/refund/get-history", FeeHistory, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, FeeHistoryQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFeeHistory(userQuery));
	}
private:
	// 获取退费审核列表
	ReviewPageJsonVO::Wrapper execQueryFeeReview(const FeeReviewQuery::Wrapper& query);
	// 获取退费审核详情
	FeeDetailJsonVO::Wrapper execQueryFeeDetail(const String& id);
	//获取缴费历史列表
	FeeHistoryJsonVO::Wrapper execQueryFeeHistory(const FeeHistoryQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 