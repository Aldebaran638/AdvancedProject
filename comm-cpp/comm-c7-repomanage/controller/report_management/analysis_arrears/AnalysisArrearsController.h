#pragma once
#ifndef _ANALYSISARREARS_CONTROLLER_H_
#define _ANALYSISARREARS_CONTROLLER_H_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/analysis_arrears/AnalysisArrearsVO.h"
#include "domain/dto/analysis_arrears/AnalysisArrearsDTO.h"
#include "domain/query/analysis_arrears/AnalysisArrearsQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* 欠费分析接口
*/
class AnalysisArrearsController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(AnalysisArrearsController);
public:
	// 获取收费类型列表
	ENDPOINT_INFO(queryAnalysisArrearsFeeType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-fee-type"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsFeeTypeListJsonVO);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-fee-type", queryAnalysisArrearsFeeType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsFeeType());
	}

	// 获取楼栋编号列表
	ENDPOINT_INFO(queryAnalysisArrearsBuildingNum) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-building-num"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsBuildingNumListJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-building-num", queryAnalysisArrearsBuildingNum, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuerySimple, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsBuildingNum(userQuery));
	}

	// 获取未收情况列表
	ENDPOINT_INFO(queryAnalysisArrearsBasic) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-basic"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsBasicPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// feeType中数字与store_fee_type表中的fee_type_cd对应
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("analysis-arrears.field.fee-type"), "8001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildingNum", ZH_WORDS_GETTER("analysis-arrears.field.building-num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-basic", queryAnalysisArrearsBasic, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsBasic(userQuery));
	}

	// 获取未收明细列表
	ENDPOINT_INFO(queryAnalysisArrearsDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-detail"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsDetailPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// feeType中数字与store_fee_type表中的fee_type_cd对应
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("analysis-arrears.field.fee-type"), "8001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildingNum", ZH_WORDS_GETTER("analysis-arrears.field.building-num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-detail", queryAnalysisArrearsDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsDetail(userQuery));
	}

	// 获取当月收费情况列表
	ENDPOINT_INFO(queryAnalysisArrearsMonth) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-month"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsMonthPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// feeType中数字与store_fee_type表中的fee_type_cd对应
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("analysis-arrears.field.fee-type"), "8001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildingNum", ZH_WORDS_GETTER("analysis-arrears.field.building-num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-month", queryAnalysisArrearsMonth, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsMonth(userQuery));
	}

private:
	// 执行文件导出处理
	AnalysisArrearsBasicPageJsonVO::Wrapper execQueryAnalysisArrearsBasic(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsDetailPageJsonVO::Wrapper execQueryAnalysisArrearsDetail(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsMonthPageJsonVO::Wrapper execQueryAnalysisArrearsMonth(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsFeeTypeListJsonVO::Wrapper execQueryAnalysisArrearsFeeType(void);
	AnalysisArrearsBuildingNumListJsonVO::Wrapper execQueryAnalysisArrearsBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ANALYSISARREARS_CONTROLLER_H_