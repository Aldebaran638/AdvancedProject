#pragma once
#ifndef _CLASSIFICATIONTABLECONTROLLER_H_
#define _CLASSIFICATIONTABLECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/repair_report/ClassificationTableVO.h"
#include "domain/dto/repair_report/ClassificationTableDTO.h"
#include "domain/query/repair_report/ClassificationTableQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ClassificationTableController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ClassificationTableController);
public:
	ENDPOINT_INFO(queryClassificationTable) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repair_report.classificationtable.query"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ClassificationTablePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repair_report.classificationtable.community_id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("repair_report.classificationtable.start_date"), "2024-2-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("repair_report.classificationtable.end_date"), "2025-5-26", false);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/classification-table/query", queryClassificationTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ClassificationTableQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryClassificationTable(userQuery));
	}

	/**
	 * 导出报修分项报表接口
	 */
	ENDPOINT_INFO(exportExcelClassificationTable) {
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("repair_report.classificationtable.export"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("repair_report.classificationtable.filename"), "ClassificationTable.xlsx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/c7-repomanage/classification-table/export", exportExcelClassificationTable, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execExportExcel(filename);
	};

private:
	
	ClassificationTablePageJsonVO::Wrapper execQueryClassificationTable(const ClassificationTableQuery::Wrapper& query);
	// 执行文件导出处理
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportExcel(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //