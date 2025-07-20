#pragma once
#ifndef _REPAIRRETURNCONTROLLER_H_
#define _REPAIRRETURNCONTROLLER_H_ 
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/repair-return/RepairReturnDTO.h"
#include "domain/vo/repair-return/RepairReturnVO.h"
#include "domain/query/repair-return/RepairReturnQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class RepairReturnController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(RepairReturnController);
public:
	// 分页查询报修回访接口描述
	ENDPOINT_INFO(queryRepairReturn) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairreturn.repair-return.summary-query-all"), RepairReturnPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairreturn.repair-return.community_id"), "2024022647620054", true);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_id", ZH_WORDS_GETTER("repairreturn.repair-return.repair_id"), "822024022794890018", false);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type", ZH_WORDS_GETTER("repairreturn.repair-return.repair_type"), ZH_WORDS_GETTER("repairreturn.repair-return.default-repair_type"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_name", ZH_WORDS_GETTER("repairreturn.repair-return.repair_name"), ZH_WORDS_GETTER("repairreturn.repair-return.default-repair_name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("repairreturn.repair-return.tel"), "18909711442", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("repairreturn.repair-return.state"), ZH_WORDS_GETTER("repairreturn.repair-return.default-state"), false);
	}

	// 分页查询报修回访接口处理
	ENDPOINT(API_M_GET, "/comm-c2-repairsetting/repair-return/repair-return/query-all", queryRepairReturn, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RepairReturnQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRepairReturn(query));
	}

	// 添加保修回访结果接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairreturn.repair-return.summary-add"), addRepairReturn, StringJsonVO::Wrapper);
	// 添加保修回访结果接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/comm-c2-repairsetting/repair-return/repair-return/add", addRepairReturn, BODY_DTO(RepairReturnAddDTO::Wrapper, dto), execAddRepairReturnDetail(dto, authObject->getPayload()));
private:
	//  分页查询报修回访数据
	RepairReturnPageJsonVO::Wrapper execQueryRepairReturn(const RepairReturnQuery::Wrapper& query);
	// 新增报修回访反馈数据
	StringJsonVO::Wrapper execAddRepairReturnDetail(const RepairReturnAddDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_REPAIRRETURNCONTROLLER_H_