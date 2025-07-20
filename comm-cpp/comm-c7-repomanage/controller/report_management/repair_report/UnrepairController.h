#ifndef _UNREPAIRCONTROLLER_H_
#define _UNREPAIRCONTROLLER_H_

#include "domain/dto/repair_report/Unrepair/UnrepairDTO.h"
#include "domain/vo/repair_report/UnrepairVO/UnrepairVO.h"
#include "domain/query/repair_report/UnrepairQuery/UnrepairQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) 

class UnrepairController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(UnrepairController);
public:
	// 3.1 定义分页查询接口描述
	ENDPOINT_INFO(queryAll) {
		//定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Unrepair.get.query"), UnrepairPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("Unrepair.communityId"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("Unrepair.createTime"), "2021-2-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("Unrepair.endTime"), "2025-2-1", false);
	}
	// 3.2 定义分页查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report/unrepair-query", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, UnrepairQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportUnrepair) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Unrepair.get.export"), Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("Unrepair.communityId"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("Unrepair.createTime"), "2021-2-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("Unrepair.endTime"), "2025-2-1", false);
	}

	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report/unrepair-export", exportUnrepair, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(UserQuery, UnrepairQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportAll(UserQuery);
	}
private:
	// 3.3 演示分页查询数据
	UnrepairPageJsonVO::Wrapper execQueryAll(const UnrepairQuery::Wrapper& query);
	// 导出报修未完成数据
	std::shared_ptr<OutgoingResponse> execExportAll(const UnrepairQuery::Wrapper& query);


};

#include OATPP_CODEGEN_END(ApiController) 
#endif
