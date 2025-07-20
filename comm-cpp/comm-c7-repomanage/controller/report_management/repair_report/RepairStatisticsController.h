#pragma once

#ifndef _RepairStatistics_CONTROLLER_
#define _RepairStatistics_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/repair_report/RepairStatisticsVO.h"
#include "domain/query/repair_report/RepairStatisticsQuery.h"
#include "domain/dto/repair_report/RepairStatisticsDTO.h"
//#include <oatpp/core/Types.hpp> 

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


/**
 * 报修统计接口
 */
class RepairStatisticsController : public oatpp::web::server::api::ApiController {
		API_ACCESS_DECLARE(RepairStatisticsController);
public:

	//  1.0获取报修统计报表查询接口描述
	ENDPOINT_INFO(queryRepairStatistic) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("jiusui.repair.statistics"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(QueryRepairStatisticsJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("jiusui.community.id"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("jiusui.repair.start_time"), "2000-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("jiusui.repair.end_time"), "2099-12-31", false);

	}
	//  1.1获取报修统计报表查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/repair_report/query-repair-statistics", queryRepairStatistic, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(RepairStatisticQuery, QueryRepairStatisticsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRepairStatistics(RepairStatisticQuery));
	}


	//  导出报修统计报表查询接口描述
	ENDPOINT_INFO(exportRepairStatistic) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("jiusui.repair.export"), Void);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("jiusui.community.id"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("jiusui.repair.start_time"), "2000-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("jiusui.repair.end_time"), "2099-12-31", false);

	}
	//  导出报修统计报表查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/repair_report/export-repair-statistics", exportRepairStatistic, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(exportRepairStatisticQuery, QueryRepairStatisticsQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportRepairStatistic(exportRepairStatisticQuery);
	}



private:
	// 获取报修统计数据
	QueryRepairStatisticsJsonVO::Wrapper execQueryRepairStatistics(const QueryRepairStatisticsQuery::Wrapper& query);
	// 导出保修报表数据
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportRepairStatistic(const QueryRepairStatisticsQuery::Wrapper& query);

};



// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _RepairStatistics_CONTROLLER_