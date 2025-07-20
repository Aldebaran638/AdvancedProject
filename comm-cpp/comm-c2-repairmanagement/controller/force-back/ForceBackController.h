#pragma once
#ifndef _FORCEBACKCONTROLLER_H_
#define _FORCEBACKCONTROLLER_H_ 
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/force-back/ForceBackDTO.h"
#include "domain/vo/force-back/ForceBackVO.h"
#include "domain/query/force-back/ForceBackQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class ForceBackController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(ForceBackController);
public:
	// 分页查询强制回单接口描述
	ENDPOINT_INFO(queryForceBack) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("forceback.force-back.summary-query-all"), ForceBackPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("forceback.force-back.community_id"), "2024022647620054", true);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type", ZH_WORDS_GETTER("forceback.force-back.repair_type"), ZH_WORDS_GETTER("forceback.force-back.default-repair_type"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_name", ZH_WORDS_GETTER("forceback.force-back.repair_name"), ZH_WORDS_GETTER("forceback.force-back.default-repair_name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("forceback.force-back.tel"), "18909711442", false);
	}
	// 分页查询强制回单接口处理
	ENDPOINT(API_M_GET, "/comm-c2-repairsetting/force-back/force-back/query-all", queryForceBack, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ForceBackQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryForceBack(query));
	}

	// 修改强制回单状态接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("forceback.force-back.summary-modify"), modifyForceBack, StringJsonVO::Wrapper);
	// 修改强制回单状态接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/force-back/force-back/modify", modifyForceBack, BODY_DTO(ForceBackModifyDTO::Wrapper, dto), execModifyForceBack(dto, authObject->getPayload()));

private:
	//  分页查询强制回单数据
	ForceBackPageJsonVO::Wrapper execQueryForceBack(const ForceBackQuery::Wrapper& query);
	//  修改强制回单状态
	StringJsonVO::Wrapper execModifyForceBack(const ForceBackModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_FORCEBACKCONTROLLER_H_
