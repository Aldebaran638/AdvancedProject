#pragma once
#ifndef _EXPEREM_CONTROLLER_
#define _EXPEREM_CONTROLLER_

#include "domain/vo/experem/ExpeRemVO.h"
#include "domain/dto/experem/ExpeRemDTO.h"
#include "domain/query/experem/ExpeRemQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExperemController : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ExperemController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.get.summary"), ExpeRemPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "objName", ZH_WORDS_GETTER("experem.field.pId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("experem.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("experem.field.tel"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeName", ZH_WORDS_GETTER("experem.field.logColumn"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/preExperemQuery", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ExpeRemQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportAll) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.export.summary"), oatpp::Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "objName", ZH_WORDS_GETTER("experem.field.pId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("experem.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("experem.field.tel"), "121323232", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeName", ZH_WORDS_GETTER("experem.field.logColumn"), "Water", false);
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/preExperemExport", exportAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpeRemQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportAll(userQuery);
	}
private: 
	// 3.3 演示分页查询数据
	ExpeRemPageJsonVO::Wrapper execQueryAll(const ExpeRemQuery::Wrapper& query);
	// 3.3 演示导出数据
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportAll(const ExpeRemQuery::Wrapper& query);

};


///////////////
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class overExperemController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(overExperemController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(query_experem) {
		/*
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("experem.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(overExpeRemPageJsonVO);
		*/
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.query.summary"), oatpp::Object<overExpeRemPageJsonVO>);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "BuildingNo", ZH_WORDS_GETTER("experem.field.BuildingNo"), "20130414039", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Name", ZH_WORDS_GETTER("experem.field.Name"), ZH_WORDS_GETTER("experem.query.Name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "Telephone", ZH_WORDS_GETTER("experem.field.Telephone"), "12345678900", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Expenses", ZH_WORDS_GETTER("experem.field.Expenses"), ZH_WORDS_GETTER("experem.query.Expenses"), false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/overExperemQuery", query_experem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, overExpeRemQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuery(userQuery));
	}

	// 3.1 定义导出接口描述
	ENDPOINT_INFO(export_experem) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.export.summary"), oatpp::Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "BuildingNo", ZH_WORDS_GETTER("experem.field.BuildingNo"), "20130414039", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Name", ZH_WORDS_GETTER("experem.field.Name"), ZH_WORDS_GETTER("experem.query.Name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "Telephone", ZH_WORDS_GETTER("experem.field.Telephone"), "12345678900", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Expenses", ZH_WORDS_GETTER("experem.field.Expenses"), ZH_WORDS_GETTER("experem.query.Expenses"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "FileName", ZH_WORDS_GETTER("experem.field.FileName"), ZH_WORDS_GETTER("experem.query.FileNameExample"), true);
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/overExperemExport", export_experem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, overExpeRemQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportExperem(userQuery);
	}
private:
	overExpeRemPageJsonVO::Wrapper execQuery(const overExpeRemQuery::Wrapper& query);

	std::shared_ptr<OutgoingResponse> execExportExperem(const overExpeRemQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_EXPEREMCONTROLLER_H_
