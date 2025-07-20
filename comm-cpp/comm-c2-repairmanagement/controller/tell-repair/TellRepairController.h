#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: maomao
 @Date: 2025/05/21 14:37:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

		https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _TELL_REPAIR_CONTROLLER_
#define _TELL_REPAIR_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/tell-repair/TellRepairQuery.h"
#include "domain/dto/tell-repair/TellRepairDTO.h"
#include "domain/vo/tell-repair/TellRepairVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class TellRepairController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(TellRepairController);

public:
	//	分页查询电话报修列表
	ENDPOINT_INFO(queryAll)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tell-repair.api.queryAll"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(TellRepairPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("tell-repair.field.community_id"), ZH_WORDS_GETTER("tell-repair.default.community_id"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_id", ZH_WORDS_GETTER("tell-repair.field.repair_id"), ZH_WORDS_GETTER("tell-repair.default.repair_id"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_name", ZH_WORDS_GETTER("tell-repair.field.repair_name"), ZH_WORDS_GETTER("tell-repair.default.repair_name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type", ZH_WORDS_GETTER("tell-repair.field.repair_type"), ZH_WORDS_GETTER("tell-repair.default.repair_type"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("tell-repair.field.tel"), ZH_WORDS_GETTER("tell-repair.default.tel"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("tell-repair.field.state"), ZH_WORDS_GETTER("tell-repair.default.state"), false);
	}
	ENDPOINT(API_M_GET, "/comm-c2-repairsetting/tell-repair/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(tellRepairQuery, TellRepairQuery, queryParams);
		API_HANDLER_RESP_VO(execQuery(tellRepairQuery));
	}

	// 添加电话报修
	ENDPOINT_INFO(add)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tell-repair.api.add"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/comm-c2-repairsetting/tell-repair/add", add, BODY_DTO(TellRepairAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execAdd(dto, authObject->getPayload()));
	}

	// 修改电话报修信息
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("tell-repair.api.modify"), modify, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/tell-repair/modify", modify, BODY_DTO(TellRepairUpdateDTO::Wrapper, dto), execModify(dto, authObject->getPayload()));

	// 删除电话报修
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("tell-repair.api.remove"), remove, ListJsonVO<String>::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/comm-c2-repairsetting/tell-repair/delete", remove, BODY_DTO(List<String>, ids), execRemove(ids));

private:
	TellRepairPageJsonVO::Wrapper execQuery(const TellRepairQuery::Wrapper &query);

	StringJsonVO::Wrapper execAdd(const TellRepairAddDTO::Wrapper &dto, const PayloadDTO &payload);

	StringJsonVO::Wrapper execModify(const TellRepairUpdateDTO::Wrapper &dto, const PayloadDTO &payload);

	ListJsonVO<String>::Wrapper execRemove(const List<String> &ids);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif																		// _TELL_REPAIR_CONTROLLER_