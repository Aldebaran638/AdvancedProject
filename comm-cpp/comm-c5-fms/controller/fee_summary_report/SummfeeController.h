#pragma once

#ifndef _SUMMFEECONTROLLER_H_
#define _SUMMFEECONTROLLER_H_


#include "domain/vo/fee_summary_report/SummfeeVO.h"
#include "domain/dto/fee_summary_report/SummfeeDTO.h"
#include "domain/query/fee_summary_report/SummfeeQuery.h"

#include "domain/vo/BaseJsonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SummfeeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	API_ACCESS_DECLARE(SummfeeController);

public:  // 定义接口
	// 3.1 定义分页查询接口描述
	ENDPOINT_INFO(queryAll) {

		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("axing.summary"), FeeSummaryPageJsonVO::Wrapper);
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 时间
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("axing.summ.create_time"), "2025-3-20", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/feesum/get-feesum", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, SummfeeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
private:  // 定义接口执行函数

	// 3.3 演示分页查询数据
	FeeSummaryPageJsonVO::Wrapper execQueryAll(const SummfeeQuery::Wrapper& query);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_