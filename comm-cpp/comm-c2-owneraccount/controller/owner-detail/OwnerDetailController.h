#pragma once
#ifndef _OWNERDETAILCONTROLLER_H_
#define _OWNERDETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/owner-detail/OwnerDetailDTO.h"
#include "domain/vo/owner-detail/OwnerDetailVO.h"
#include "domain/query/owner-detail/OwnerDetailQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* 账户明细
*/
class OwnerDetailController : public oatpp::web::server::api::ApiController
{
	// 添加账户明细访问定义
	API_ACCESS_DECLARE(OwnerDetailController);
public:
	// 定义账户明细查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-query-all"), OwnerDetailPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 账户编号
		API_DEF_ADD_QUERY_PARAMS(String, "acct_id", ZH_WORDS_GETTER("owneraccount.owner-detail.acct-id"), ZH_WORDS_GETTER("owneraccount.owner-detail.default-acct-id"), true);
	}
	// 定义账户明细查询接口处理
	ENDPOINT(API_M_GET, "/comm-c2-owneraccount/owner-detail/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, OwnerDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(OwnerDetail_execQueryAll(query));
	}
	
	// 预存（新增）接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-add"), addOwnerDetail, StringJsonVO::Wrapper);
	// 预存（新增）接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/comm-c2-owneraccount/owner-detail/add", addOwnerDetail, BODY_DTO(OwnerDetailAddDTO::Wrapper, dto), execAddOwnerDetail(dto, authObject->getPayload()));

	// 定义获取所有符合手机号的业主名称接口端点描述
	ENDPOINT_INFO(queryAllAccountName) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-account-name-query-all"), OwnerDetailAccountNamePageJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("owneraccount.owner-detail.link"), ZH_WORDS_GETTER("owneraccount.owner-detail.default-link"), false);
	}
	// 定义查询所有符合手机号的业主名称信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-owneraccount/owner-detail/query-account-name", queryAllAccountName, OwnerDetailAccountNameQuery, execQueryAllAccountNameByLink(query));

	// 撤销（新增）接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-undo"), undoOwnerDetail, StringJsonVO::Wrapper);
	// 撤销（新增）接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/comm-c2-owneraccount/owner-detail/undo", undoOwnerDetail, BODY_DTO(OwnerDetailUndoDTO::Wrapper, dto), execUndoOwnerDetail(dto, authObject->getPayload()));

private:
	// 账户明细分页查询数据
	OwnerDetailPageJsonVO::Wrapper OwnerDetail_execQueryAll(const OwnerDetailQuery::Wrapper& query);

	// 预存（新增）数据
	StringJsonVO::Wrapper execAddOwnerDetail(const OwnerDetailAddDTO::Wrapper& dto, const PayloadDTO& payload);

	// 预存-账户名称分页查询数据
	OwnerDetailAccountNamePageJsonVO::Wrapper execQueryAllAccountNameByLink(const OwnerDetailAccountNameQuery::Wrapper& Query);

	// 撤销（新增）数据
	StringJsonVO::Wrapper execUndoOwnerDetail(const OwnerDetailUndoDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERDETAILCONTROLLER_H_
