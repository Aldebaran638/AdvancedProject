#pragma once
#ifndef _UNIT_CONTROLLER_
#define _UNIT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/UnitDTO/UnitDTO.h"
#include "domain/vo/UnitVO/UnitVO.h"
#include "domain/query/UnitQuery/UnitQuery.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 单元信息控制器，实现增加、修改、删除单元信息的接口
 */
class UnitController : public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(UnitController);
public:	//定义接口

	//添加单元信息接口描述
	ENDPOINT_INFO(addUnit)
	{
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//添加单元信息接口
	ENDPOINT(API_M_POST, "/c1-unit/add-unit", addUnit, BODY_DTO(UnitDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) 
	{
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddUnit(dto, authObject->getPayload()));
	}

	//定义修改单元信息接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.put.summary"), modifyUnit, StringJsonVO::Wrapper);
	//定义修改单元信息接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-unit/modify-unit", modifyUnit, BODY_DTO(UnitDTO::Wrapper, dto), execModifyUnit(dto, authObject->getPayload()));

	//定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.delete.summary"), removeUnit, ListJsonVO<String>::Wrapper);
	//定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c1-unit/delete-unit", removeUnit, BODY_DTO(List<String>, ids), execRemoveUnit(ids));

	ENDPOINT_INFO(queryUnit)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.get.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "floor_id", ZH_WORDS_GETTER("unit.field.floor_id"), "732023120568080332", true);
		API_DEF_ADD_QUERY_PARAMS(String, "unit_num", ZH_WORDS_GETTER("unit.field.unit_num"), "1", false);
	}
	ENDPOINT(API_M_GET, "/unit/query", queryUnit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(query, UnitQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryUnit(query));
	}

	ENDPOINT_INFO(queryCommunityUnit)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.query-community-unit.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("floor.field.community_id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "floor_num", ZH_WORDS_GETTER("floor.field.floor_num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "unit_num", ZH_WORDS_GETTER("unit.field.unit_num"), "1", false);
	}
	ENDPOINT(API_M_GET, "/unit/query-community-unit", queryCommunityUnit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(query, UnitQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryCommunityUnit(query));
	}

private:	//定义执行函数
	//添加单元信息
	StringJsonVO::Wrapper execAddUnit(const UnitDTO::Wrapper& dto ,const PayloadDTO& payload);
	//修改单元信息
	StringJsonVO::Wrapper execModifyUnit(const UnitDTO::Wrapper& dto, const PayloadDTO& payload);
	//删除单元信息
	ListJsonVO<String>::Wrapper execRemoveUnit(const List<String>& ids);

	UnitPageJsonVO::Wrapper execQueryUnit(const UnitQuery::Wrapper& query);
	UnitPageJsonVO::Wrapper execQueryCommunityUnit(const UnitQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif