#pragma once
#ifndef _PAYREMAINBUCONTROLLER_H_
#define _PAYREMAINBUCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/arrears_reminders/PayRemainBuQuery.h"
#include "domain/dto/arrears_reminders/PayRemainQuBuDTO.h"
#include "domain/dto/arrears_reminders/PayRemainBuDTO.h"
#include "domain/vo/arrears_reminders/PayRemainQuBuVO.h"
#include "domain/vo/arrears_reminders/PayRemainBuVO.h"

//  定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

class PayRemainBuController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(PayRemainBuController);
public:
	//1.分页/条件查询
	ENDPOINT_INFO(queryAll) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Bupayremind.get.summary"), CombinePayRemainQuBuJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义分页查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "owner_name", ZH_WORDS_GETTER("Bupayremind.field.owner_name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("Bupayremind.field.fee_name"), "water", false);
		API_DEF_ADD_QUERY_PARAMS(String, "callable_way", ZH_WORDS_GETTER("Bupayremind.field.callable_way"), "PRINT", false);
		API_DEF_ADD_QUERY_PARAMS(String, "staff_name", ZH_WORDS_GETTER("Bupayremind.field.staff_name"), "wuye", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("Bupayremind.field.state"), "C", false);
	}

	// 3.2 定义分页查询欠缴费用接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/payremind/query-arrears", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, PayRemainBuQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addPayRemain) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Bupayremind.post2.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/c5-feemanage/payremind/add-payremind", addPayRemain, BODY_DTO(PayRemainBuDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddReamin(dto, authObject->getPayload()));
	}
private:
	CombinePayRemainQuBuJsonVO::Wrapper execQueryAll(const PayRemainBuQuery::Wrapper& query);
	// 3.3 演示新增数据
	StringJsonVO::Wrapper execAddReamin(const PayRemainBuDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PAYREMAINBUCONTROLLER_H_
