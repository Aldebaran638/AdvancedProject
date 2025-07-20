#pragma once
#ifndef _OWNERLISTCONTROLLER_H_
#define _OWNERLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/owner-list/OwnerListDTO.h"
#include "domain/vo/owner-list/OwnerListVO.h"
#include "domain/query/owner-list/OwnerListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* 账户列表
*/
class OwnerListController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(OwnerListController);
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owneraccount.owner-list.summary-query-all"), OwnerListPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("owneraccount.owner-list.name"), ZH_WORDS_GETTER("owneraccount.owner-list.default-name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("owneraccount.owner-list.id-card"), ZH_WORDS_GETTER("owneraccount.owner-list.default-idcard"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("owneraccount.owner-list.link"), ZH_WORDS_GETTER("owneraccount.owner-list.default-link"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("owneraccount.owner-list.community-id"), ZH_WORDS_GETTER("owneraccount.owner-list.default-community-id"), true);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/comm-c2-owneraccount/owner-list-queryAll", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, OwnerListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

private:
	// 分页查询数据
	OwnerListPageJsonVO::Wrapper execQueryAll(const OwnerListQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERLISTCONTROLLER_H_
