#pragma once
#ifndef _REPAIRWORKERNAMECONTROLLER_H_
#define _REPAIRWORKERNAMECONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repair-worker-name/RepairWorkerNameQuery.h"
#include "domain/dto/repair-worker-name/RepairWorkerNameDTO.h"
#include "domain/vo/repair-worker-name/RepairWorkerNameVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * 维修师傅名称控制器
 */
class RepairWorkerNameController : public oatpp::web::server::api::ApiController 
{
	API_ACCESS_DECLARE(RepairWorkerNameController);
public:
	//查询获取师傅名称列表
	ENDPOINT_INFO(queryAll) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairsetting.repair-worker-name.summary-query-all"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(RepairWorkerNameJsonVO);
		// 维修类型名称
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type_name",
			ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair-type-name"),
			ZH_WORDS_GETTER("repairsetting.repair-worker-name.default-repair-type-name"), false);
		//报修工单号
		API_DEF_ADD_QUERY_PARAMS(String, "repair_id",
			ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair-id"),
			"822024022794890018", true);
		// 小区分片名
		API_DEF_ADD_QUERY_PARAMS(String, "community_id",
			ZH_WORDS_GETTER("repairsetting.repair-worker-name.community-id"), 
			"2024022154856948", true);
	}
	ENDPOINT(API_M_GET, "/comm-c2-repairsetting/repair-setting/repair-worker-name/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RepairWorkerNameQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryByRepairTypeName(query));
	}

	
private:
	//根据维修类型名称查询师傅名称列表
	RepairWorkerNamePageJsonVO::Wrapper execQueryByRepairTypeName(const RepairWorkerNameQuery::Wrapper& query);
};


#include OATPP_CODEGEN_END(ApiController)
#endif // _REPAIRWORKERNAMECONTROLLER_H_