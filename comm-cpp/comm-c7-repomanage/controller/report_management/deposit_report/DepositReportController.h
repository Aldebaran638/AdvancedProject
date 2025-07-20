#pragma once
#ifndef _DEPOSIT_REPORT_CONTROLLER_
#define _DEPOSIT_REPORT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/deposit_report/DepositReportQuery.h"
#include "domain/dto/deposit_report/DepositReportDTO.h"
#include "domain/vo/deposit_report/DepositReportVO.h"
#include "service/report_management/deposit_report/DepositReportService.h"
#include "FastDfsClient.h" 
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 继承控制器
class DepositReportController : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DepositReportController);

// 3 定义接口
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryDepositReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("depositReport.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DepositReportPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "location_obj_name", ZH_WORDS_GETTER("depositReport.location_obj_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("depositReport.fee_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_type_cd", ZH_WORDS_GETTER("depositReportfee_type_cd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pay_state", ZH_WORDS_GETTER("depositReport.pay_state"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "income_obj_id", ZH_WORDS_GETTER("depositReport.income_obj_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("depositReport.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("depositReport.end_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "return_state", ZH_WORDS_GETTER("depositReport.return_state"), "", false);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/report-management/deposit-report/query", queryDepositReport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, DepositReportQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDepositReport(userQuery));
	}


	// 定义导出接口描述
	ENDPOINT_INFO(exportDepositReport) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("depositReport.export.summary"), Void);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("depositReport.community.id"), "", true);
	}
	// 定义导出接口处理
	ENDPOINT(API_M_GET, "c7-repomanage/deposit-report/export", exportDepositReport, QUERY(String, community_id), API_HANDLER_AUTH_PARAME) {

		// 呼叫执行函数响应结果
		return execExportDepositReport(community_id);
	}
private:
	DepositReportPageJsonVO::Wrapper execQueryDepositReport(const DepositReportQuery::Wrapper& query);
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportDepositReport(const String &community_id);
};

#include OATPP_CODEGEN_END(ApiController) 
#endif // _DEPOSIT_REPORT_CONTROLLER_