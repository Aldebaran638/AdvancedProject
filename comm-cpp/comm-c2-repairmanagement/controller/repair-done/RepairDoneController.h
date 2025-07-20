#pragma once
#ifndef _REPAIRDONE_CONTROLLER_
#define _REPAIRDONE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repair-done/RepairDoneQuery.h"
#include "domain/dto/repair-done/RepairDoneDTO.h"
#include "domain/vo/repair-done/RepairDoneVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// 报修已办控制器
class RepairDoneController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RepairDoneController);
	// 3 定义接口
public:
	// 3.1 定义报修已办分页查询接口的描述
	ENDPOINT_INFO(queryAll) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairdone.repair-done.query-all"), RepairDonePageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 小区id
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairdone.repair-done.community_id"), "2024022647620054", true);
		// 维修类型
		API_DEF_ADD_QUERY_PARAMS(String, "maintenance_type", ZH_WORDS_GETTER("repairdone.repair-done.maintenance_type"), ZH_WORDS_GETTER("repairdone.repair-done.default-maintenance_type"), false);
		// 报修人
		API_DEF_ADD_QUERY_PARAMS(String, "repair_name", ZH_WORDS_GETTER("repairdone.repair-done.repair_name"), ZH_WORDS_GETTER("repairdone.repair-done.default-repair_name"), false);
		// 联系方式
		API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("repairdone.repair-done.tel"), "18909711442", false);
		// 报修类型
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type", ZH_WORDS_GETTER("repairdone.repair-done.repair_type"), ZH_WORDS_GETTER("repairdone.repair-done.default-repair_type"), false);
		// 报修状态
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("repairdone.repair-done.state"), ZH_WORDS_GETTER("repairdone.repair-done.default-state"), false);
		// 报修状态
		API_DEF_ADD_QUERY_PARAMS(String, "repair_id", ZH_WORDS_GETTER("repairdone.repair-done.repair_id"), "822024022794890018", false);
	}
	// 3.2 定义报修已办分页查询接口处理
	ENDPOINT(API_M_GET, "/comm-c2-repairsetting/repair-done/repair-done/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RepairDoneQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
private:
	RepairDonePageJsonVO::Wrapper execQueryAll(const RepairDoneQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_REPAIRDONE_CONTROLLER_
