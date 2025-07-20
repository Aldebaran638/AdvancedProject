#pragma once
#ifndef _MODIFYCONTROLLER_H_
#define _MODIFYCONTROLLER_H_
#include "domain/dto/dtos/modifyDTO.h"
#include "domain/query/querys/modifyQuery.h"
#include "domain/vo/vos/modifyVO.h"
#include "domain/vo/BaseJsonVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)


class modifyController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(modifyController);
public://定义接口

	ENDPOINT_INFO(querymodifyById)
	{
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("menu-catalog.modify.summary"), modifyPageJsonVO::Wrapper);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("modify.get.fee_id"), "902025052290680034", true);

	}
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/modify/get/fee_id", querymodifyById, QUERY(String, fee_id), execQueryById(fee_id));
	ENDPOINT(API_M_GET, "/c3-housefeemgr/query-modifyrecord-page", querymodifyById, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(query, modifyQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryById(query));
	}

private://定义接口执行函数
	// 3.3 演示分页查询数据
	//modifyJsonVO::Wrapper execQueryModify(const modifyQuery::Wrapper& query);
	modifyPageJsonVO::Wrapper execQueryById(const modifyQuery::Wrapper &query);

};

#include OATPP_CODEGEN_END(ApiController)


#endif