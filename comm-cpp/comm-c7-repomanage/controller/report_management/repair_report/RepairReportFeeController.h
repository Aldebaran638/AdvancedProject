#pragma once
#ifndef _REPAIRREPORTCONTROLLER_H_
#define _REPAIRREPORTCONTROLLER_H_

#include "domain/vo/repair_report/RepairReportFeeVO.h"
#include "domain/dto/repair_report/RepairReportFeeDTO.h"
#include "domain/query/repair_report/RepairReportFeeQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) 


class RepairReportFeeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	
	API_ACCESS_DECLARE(RepairReportFeeController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repair-report-fee.get.summary") , RepairReportFeeJsonVO::Wrapper);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "repairId", ZH_WORDS_GETTER("repair-report-fee.field.repairId"), "id", false);
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("repair-report-fee.field.startDate"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("repair-report-fee.field.endDate"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report-fee", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RepairReportFeeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryByDate(query));
	}

	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportRepairReport) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repair-report-fee.export.summary"), Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "repairId", ZH_WORDS_GETTER("repair-report.field.repairId"), "id", false);
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("repair-report.field.startDate"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("repair-report.field.endDate"), "N", false);
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report-fee/export", exportRepairReport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型s
		API_HANDLER_QUERY_PARAM(RepairaReportExport, RepairReportFeeQuery, queryParams);
		// 呼叫执行函数响应结果
		return execRepairReportExport(RepairaReportExport);
	}



private:
	// 3.3 演示分页查询数据
	RepairReportFeePageJsonVO::Wrapper execQueryByDate(const RepairReportFeeQuery::Wrapper& query);
	// 3.3 演示导出数据
	std::shared_ptr<OutgoingResponse> execRepairReportExport(const RepairReportFeeQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
