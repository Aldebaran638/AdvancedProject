#pragma once

#ifndef _DISSATISFIEDREPAIR_CONTROLLER_H_
#define _DISSATISFIEDREPAIR_CONTROLLER_H_

#include "domain/vo/repair_report/DissatisfiedRepairVO.h"
#include "domain/dto/repair_report/DissatisfiedRepairDTO.h"
#include "domain/query/repair_report/DissatisfiedRepairQuery.h"
#include "domain/vo/BaseJsonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
* 报修不满意控制器
*/
class DissatisfiedRepairController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DissatisfiedRepairController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryAll) {

		//定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dissatisfied-repair.get.summary"), DissatisfiedRepairPageJsonVO::Wrapper);
		
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("dissatisfied-repair.community_id"), "community_id", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("dissatisfied-repair.field.start-date"), "yyyy-mm-dd", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("dissatisfied-repair.field.end-date"), "yyyy-mm-dd", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/dissatisfied-repair/query", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, DissatisfiedRepairQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportDissatisfied) {
		API_DEF_ADD_AUTH();
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dissatisfied-repair.export.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("dissatisfied-repair.export.filename"), "DissatisfiedRepair.xlsx", true);
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/dissatisfied-repair/export", exportDissatisfied, QUERY(String , filename), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		return execExport(filename);
	}
	
private:
	// 3.3 分页查询数据
	DissatisfiedRepairPageJsonVO::Wrapper execQueryAll(const DissatisfiedRepairQuery::Wrapper& query);
	// 3.3 演示导出数据
	std::shared_ptr<OutgoingResponse> execExport(const String& filename);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif //!_DISSATISFIEDREPAIR_CONTROLLER_H_