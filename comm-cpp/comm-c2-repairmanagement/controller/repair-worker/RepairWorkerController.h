#pragma once

#ifndef _REPAIRWORKERCONTROLLER_H_
#define _REPAIRWORKERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/repair-worker/RepairWorkerDTO.h"
#include "domain/query/repair-worker/RepairWorkerQuery.h"
#include "domain/vo/repair-worker/RepairWorkerVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* 添加维修师傅控制器
*/
class RepairWorkerController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(RepairWorkerController);
public:
	// 定义查询维修师傅接口描述
	ENDPOINT_INFO(queryAllRepairWorker) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairsetting.repair-worker.summary-query-all"), RepairWorkerPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//报修工单号
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type_name",
			ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair_type_name"),
			ZH_WORDS_GETTER("repairsetting.repair-worker.default-repair-type-name"), true);
		// 小区分片名
		API_DEF_ADD_QUERY_PARAMS(String, "community_id",
			"repairsetting.repair-worker.community-id",
			"2024022154856948", true);
	}
	// 定义查询维修师傅接口处理
	ENDPOINT(API_M_GET, "/comm-c2-repairsetting/repair-setting/repair-worker/query-all", queryAllRepairWorker, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RepairWorkerQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 定义新增维修师傅接口描述
	ENDPOINT_INFO(addRepairWorker) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairsetting.repair-worker.summary-add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义新增维修师傅接口处理
	ENDPOINT(API_M_POST, "/comm-c2-repairsetting/repair-setting/repair-worker/add", addRepairWorker, BODY_DTO(RepairWorkerAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddRepairWorker(dto, authObject->getPayload()));
	}
	// 定义修改维修师傅状态接口描述
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairsetting.repair-worker.summary-modify"), modifyRepairWorker, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-setting/repair-worker/modify", modifyRepairWorker, BODY_DTO(RepairWorkerModifyDTO::Wrapper, dto),
		execModifyRepairWorker(dto, authObject->getPayload()));
	
	//定义维修师傅删除接口
	// 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairsetting.repair-worker.summary-remove"), removeRepairWorker, ListJsonVO<String>::Wrapper);
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/comm-c2-repairsetting/repair-setting/repair-worker/delete", removeRepairWorker, BODY_DTO(List<String>, ids), execRemoveRepairWorker(ids));

private:
	// 分页查询维修师傅数据
	RepairWorkerPageJsonVO::Wrapper execQueryAll(const RepairWorkerQuery::Wrapper& query);

	// 新增维修师傅数据
	StringJsonVO::Wrapper execAddRepairWorker(const RepairWorkerAddDTO::Wrapper& dto, const PayloadDTO& payload);

	// 修改维修师傅状态
	StringJsonVO::Wrapper execModifyRepairWorker(const RepairWorkerModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除维修师傅
	ListJsonVO<String>::Wrapper execRemoveRepairWorker(const List<String>& ids);

};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_OWNERDETAILCONTROLLER_H_
