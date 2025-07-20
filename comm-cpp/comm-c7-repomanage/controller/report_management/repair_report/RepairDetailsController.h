#pragma once

#ifndef _RepairDetails_CONTROLLER_
#define _RepairDetails_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/repair_report/RepairDetailsVO.h"
#include "domain/query/repair_report/RepairDetailsQuery.h"
#include "domain/dto/repair_report/RepairDetailsDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 报修明细接口
 */
class RepairDetailsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	API_ACCESS_DECLARE(RepairDetailsController);
	//  定义接口
public:
	// 1 获取报修明细报表査询接口描述
	ENDPOINT_INFO(queryRepairDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("alex.repair.details"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RepairDetailsPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("alex.community.id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("alex.repair.start_time"), "2020-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("alex.repair.end_time"), "2025-05-21", false);
	}
	// 3.2获取报修明细报表查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/query-repair-details", queryRepairDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, RepairDetailsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRepairDetails(userQuery));
	}


	// 2 导出报修明细报表接口描述
	ENDPOINT_INFO(exportRepairDetails) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("alex.repair.export"), Void);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("alex.community.id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("alex.repair.start_time"), "2020-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("alex.repair.end_time"), "2025-05-21", false);
	}
	//  导出报修明细报表接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/export-repair-details", exportRepairDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Export领域模型
		API_HANDLER_QUERY_PARAM(exportRepairDetailsQuery, RepairDetailsQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportRepairDetails(exportRepairDetailsQuery);
	}

private:
	// 3.3 获取报修明细分页查询数据
	RepairDetailsPageJsonVO::Wrapper execQueryRepairDetails(const RepairDetailsQuery::Wrapper& query);
	// 3.3 导出报修明细导出数据
	std::shared_ptr<OutgoingResponse> execExportRepairDetails(const RepairDetailsQuery::Wrapper& query);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _RepairDetails_CONTROLLER_