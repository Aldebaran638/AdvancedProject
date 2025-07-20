#pragma once

#include "domain/vo/CommunitySpaceMgrVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CommunitySpaceMgrQuery.h"
#include "domain/dto/CommunitySpaceMgrDTO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
using namespace oatpp;


#include OATPP_CODEGEN_BEGIN(ApiController)

class SpaceController : public oatpp::web::server::api::ApiController {
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SpaceController);
	// 定义接口
public:
	//接口描述
	ENDPOINT_INFO(queryList) {
		info->summary = ZH_WORDS_GETTER("CommunitySpaceMgr.get.summary");
		//接口参数
		API_DEF_ADD_PAGE_PARAMS();

		API_DEF_ADD_AUTH();
		//接口返回参数
		API_DEF_ADD_RSP_JSON_WRAPPER(CommunitySpaceMgrPageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "space_id", ZH_WORDS_GETTER("CommunitySpaceMgr.field.space_id"), "102025052134500010", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("CommunitySpaceMgr.field.name"), "shi tang", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("CommunitySpaceMgr.field.state"), "1001", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c3-pacemgr/query-space-page", queryList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, CommunitySpaceMgrPageQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryList(query));
	}


	//接口描述
	ENDPOINT_INFO(queryTime) {
		info->summary = ZH_WORDS_GETTER("CommunitySpaceMgr.get.time");
		//接口参数
		//API_DEF_ADD_PAGE_PARAMS();

		API_DEF_ADD_AUTH();
		//接口返回参数
		API_DEF_ADD_RSP_JSON_WRAPPER(CommunitySpaceTimeMgrPageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "space_id", ZH_WORDS_GETTER("CommunitySpaceMgr.field.space_id"), "102025052134500010", true);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c3-pacemgr/query-time", queryTime, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, CommunitySpaceTimeMgrPageQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTime(query));
	}



	 //3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("CommunitySpaceMgr.put.summary"), modifyTime, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c3-pacemgr/modify-time", modifyTime, BODY_DTO(CommunitySpaceTimeMgrDTO::Wrapper, dto),
		execModifyTime(dto, authObject->getPayload()));

private:
	CommunitySpaceMgrPageJsonVO::Wrapper execQueryList(const CommunitySpaceMgrPageQuery::Wrapper& query);

	CommunitySpaceTimeMgrPageJsonVO::Wrapper execQueryTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query);

	// 3.3 演示修改数据

	StringJsonVO::Wrapper execModifyTime(const CommunitySpaceTimeMgrDTO::Wrapper& dto, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController)