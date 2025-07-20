#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/12 21:11:44

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
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/owner/OwnerDTO.h" // 确保包含DTO头文件
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/owner/OwnerVo.h"
#include "domain/query/owner/OwnerListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class OwnerController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(OwnerController);
public: // 定义接口


	ENDPOINT_INFO(queryselectOwnerList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("owner.selectlist.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OwnerPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("owner.field.room_num"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("owner.field.name"), "li ming", false);

	}
	//  定义选择业主列表接口处理
	ENDPOINT(API_M_GET, "/owner/query", queryselectOwnerList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(ownerQuery, OwnerListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execSelectOwnerList(ownerQuery));
	}

	//  定义添加业主接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owner.post.summary"), addOwner, StringJsonVO::Wrapper);
	//  定义添加业主接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/owner/add", addOwner, BODY_DTO(OwnerAddDTO::Wrapper, dto), execAddOwner(dto, authObject->getPayload()));

	//  定义修改业主接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owner.put.summary"), modifyOwner, StringJsonVO::Wrapper);
	//  定义修改业主接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/owner/modify", modifyOwner, BODY_DTO(OwnerDTO::Wrapper, dto), execModifyOwner(dto, authObject->getPayload()));

	//  定义删除业主接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owner.delete.summary"), removeOwner, ListJsonVO<String>::Wrapper);
	//  定义删除业主接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/owner/remove", removeOwner, BODY_DTO(List<String>, ids), execRemoveOwner(ids));

private: // 定义接口执行函数

	// 选择业主列表
	//OwnerQueryJsonVO::Wrapper execSelectOwnerList(const OwnerQueryDTO::Wrapper& query);
	OwnerPageJsonVO::Wrapper execSelectOwnerList(const OwnerListQuery::Wrapper& query);
	// 添加业主
	StringJsonVO::Wrapper execAddOwner(const OwnerAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改业主
	StringJsonVO::Wrapper execModifyOwner(const OwnerDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除业主
	ListJsonVO<String>::Wrapper execRemoveOwner(const List<String>& ids);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_TESTCONTORLLER_H_#pragma once
