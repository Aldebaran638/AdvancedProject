#pragma once
#ifndef _RAINDISTYPESCONTROLLER_H_
#define _RAINDISTYPESCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/discount_types/RainDisTypesDTO.h"
#include "domain/vo/discount_types/RainDisTypesVO.h"
#include "domain/query/discount_types/RainDisTypesQuery.h"
#include "../../lib-oatpp/include/ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RainDisTypesController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(RainDisTypesController);

public: // 定义接口
	//// 1.1 定义接口描述和响应格式
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("discount-type.get.summary"), getTypes, RainDisTypesJsonVO::Wrapper);
	//// 1.2 定义获取优惠类型接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/discount-type/get-typelist", getTypes, BODY_DTO(RainDisTypesGetDTO::Wrapper, dto), execGetTypes(dto, authObject->getPayload()));

	// 3.1 定义ID查询接口描述
	ENDPOINT_INFO(queryList) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("discount-type.get.summary"), RainDisTypesPageJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "type_name", ZH_WORDS_GETTER("discount-type.field.type_name"), "d934050a8bb373e8f8eed0bf7507ec17", true);
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c5-feemanage/discounttype/get-typelist", queryList, QUERY(String, type_name), execQueryList(type_name));

	// 2.1 定义获取优惠类型分页接口描述
	ENDPOINT_INFO(queryAll)
	{
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("discount-type.get.page"), RainDisTypesPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "apply_type", ZH_WORDS_GETTER("discount-type.field.type_id"), "12345678901", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type_name", ZH_WORDS_GETTER("discount-type.field.type_name"), "big discount", false);
	}
	// 2.2 定义获取优惠类型分页接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/discounttype/get-typelistpage", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RainDisTypesQuery, queryParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execQueryAll(query, authObject->getPayload()));
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 定义添加优惠类型接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("discount-type.post.summary"), addTypes, StringJsonVO::Wrapper);
	// 3.2 定义添加优惠类型接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/c5-feemanage/discounttype/post-type", addTypes, BODY_DTO(RainDisTypesAddDTO::Wrapper, dto), execAddTypes(dto, authObject->getPayload()));


private: // 定义接口执行函数
	// 1.1 获取优惠类型列表
	//RainDisTypesJsonVO::Wrapper RainDisTypesController::execGetTypes(const RainDisTypesQuery::Wrapper& query, const PayloadDTO& payload);
	RainDisTypesPageJsonVO::Wrapper execQueryList(const String& type_name);
	// 1.2 获取优惠类型分页
	//RainDisTypesPageJsonVO::Wrapper execQueryAll(const RainDisTypesQuery::Wrapper &query, const PayloadDTO& payload);
	RainDisTypesPageJsonVO::Wrapper execQueryAll(const RainDisTypesQuery::Wrapper& query);

	// 1.2 添加优惠类型数据
	StringJsonVO::Wrapper execAddTypes(const RainDisTypesAddDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // _RAINDISTYPESCONTROLLER_H_