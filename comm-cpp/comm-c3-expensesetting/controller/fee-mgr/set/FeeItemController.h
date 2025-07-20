#pragma once
#ifndef _FEEITEMCONTROLLER_H_
#define _FEEITEMCONTROLLER_H_

#include "domain/vo/FeeItemlogVO.h"    
#include "domain/dto/FeeItemDTO.h"
#include "domain/query/FeeItemQuery.h"  
#include "domain/vo/BaseJsonVO.h"
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include OATPP_CODEGEN_BEGIN(ApiController)

class FeeItemController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(FeeItemController);

public:

// 3.1 定义接口描述
	ENDPOINT_INFO(queryFeeItemLog) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("/fee_itemlog/query.get.summary"));
		// 定义默认授权参数（如果接口需要认证，必须加）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式，包装 FeeItemPageJsonVO，类似你的 FeeItemPageDTO 封装的 JSON VO
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeItemPageJsonVO);
		// 分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 额外的查询参数描述，这里是 id，非必填可按需改 true/false
		API_DEF_ADD_QUERY_PARAMS(String, "config_id", ZH_WORDS_GETTER("fee_itemlog.query.field.id"), "d934050a8bb373e8f8eed0bf7507ec17", true);
	}

	// 3.2 定义接口处理逻辑
	ENDPOINT(API_M_GET, "/c3-expensesetting/query-feemodifyrecord-page", queryFeeItemLog, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数到领域模型 FeeItemQuery
		API_HANDLER_QUERY_PARAM(query, FeeItemQuery, queryParams);
		// 调用执行查询的函数并返回结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}


	// 3.1 定义新增接口描述
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/insert.post.summary"), additemlog, StringJsonVO::Wrapper);
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(additemlog) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("/fee_itemlog/insert.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/c3-expensesetting/insert-fee", additemlog, BODY_DTO(FeeItemAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAdditemlog(dto, authObject->getPayload()));
	}
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/modify.put.summary"), modifyitemlog, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c3-expensesetting/modify-fee", modifyitemlog, BODY_DTO(FeeItemModifyDTO::Wrapper, dto), execModifyitemlog(dto, authObject->getPayload()));
	//// 3.1 删除接口描述，返回 StringJsonVO
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/delete.delete.summary"), removeSample, StringJsonVO::Wrapper);
	//// 3.2 删除接口处理，仅接收 config_id 字段
	//ENDPOINT(API_M_DEL, "/fee_itemlog/delete", removeSample,
	//	BODY_DTO(FeeItemDeleteDTO::Wrapper, dto),
	//	execRemoveitemlog(dto, authObject->getPayload());
	// 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/delete.delete.summary"), removeSample, StringJsonVO::Wrapper);
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-expensesetting/delete-fee", removeSample, BODY_DTO(FeeItemDeleteDTO::Wrapper, dto), execRemoveitemlog(dto, authObject->getPayload()));


private:
	// 3.3 分页查询数据
	FeeItemPageJsonVO::Wrapper execQueryAll(const FeeItemQuery::Wrapper& query);
	// 3.3 新增数据
	StringJsonVO::Wrapper execAdditemlog(const FeeItemAddDTO::Wrapper& dto, const PayloadDTO& payload);
	//// 3.3 修改数据
	StringJsonVO::Wrapper execModifyitemlog(const FeeItemModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	//// 3.3 演示删除数据
	StringJsonVO::Wrapper execRemoveitemlog(const FeeItemDeleteDTO::Wrapper& dto, const PayloadDTO& payload);


};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FEEITEMCONTROLLER_H_