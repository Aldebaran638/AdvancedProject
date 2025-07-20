#pragma once

#ifndef _TODAY_INSPECTION_TABLE_CONTROLLER_H_
#define _TODAY_INSPECTION_TABLE_CONTROLLER_H_
//TodayInspectionTableController
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/inspection_report/TodayInspectionTableQuery.h"
#include "domain/vo/inspection_report/InspectionPointStatisticVO.h"
#include "domain/query/inspection_report/InspectionPointStatisticQuery.h"
#include "domain/dto/inspection_report/InspectionPointStatisticDTO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取今日巡检列表控制器
 */
class TodayInspectionTableController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//  定义控制器访问入口
	API_ACCESS_DECLARE(TodayInspectionTableController);
	//  定义接口
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryAll) {
		//定义接口描述和响应格式                                      TodayInspectionTableJsonVO
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("today-inspection-table.get.summary"), InspectionPointStatisticPageJsonVO::Wrapper);

		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "todayDate", ZH_WORDS_GETTER("inspection-report.field.today"), "2025-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("inspection-report.field.communityid"), "2023052267100146", false);

	}
	//  定义查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/today-inspection-table", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, TodayInspectionTableQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	/**
	 * 导出今日巡检表接口
	 */
	ENDPOINT_INFO(exportTodayInspectionTable) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("today-inspection-table.export.summary"), Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "todayDate", ZH_WORDS_GETTER("inspection-report.field.today"), "2025-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("inspection-report.field.communityid"), "2023052267100146", false);

	}
	//  定义导出接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/today-inspection-table/export", exportTodayInspectionTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, TodayInspectionTableQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportTodayInspectionTable(query);
	}

private:
	// 分页查询数据
	InspectionPointStatisticPageJsonVO::Wrapper execQueryAll(const TodayInspectionTableQuery::Wrapper& query);
	// 演示导出数据
	std::shared_ptr<OutgoingResponse> execExportTodayInspectionTable(const TodayInspectionTableQuery::Wrapper& query);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TODAY_INSPECTION_TABLE_CONTROLLER_H_