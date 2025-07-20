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
#ifndef _OWNERINFO_CONTROLLER_
#define _OWNERINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/OwnerInfo/OwnerInfoQuery.h"
#include "domain/dto/OwnerInfo/OwnerInfoDTO.h"
#include "domain/vo/OwnerInfo/OwnerInfoVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 入住/退出房屋控制器
 */
class OwnerInfoController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(OwnerInfoController);
public:
	ENDPOINT_INFO(queryIntoHouse) {
		// 定义入住房屋的标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("OwnerInfo.post.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义创建入住房屋接口处理
	ENDPOINT(API_M_POST, "/ownerinfo/add-intohouse", queryIntoHouse, BODY_DTO(OwnerInfoAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddIntoHouse(dto, authObject->getPayload()));
	}

	//// 定义退出房屋接口描述
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("OwnerInfo.modify.summary"), modifyOutHouse, StringJsonVO::Wrapper);
	//// 定义退出房屋处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ownerinfo/modify-outhouse", modifyOutHouse, BODY_DTO(OwnerInfoDTO::Wrapper, dto), execModifyOutHouse(dto, authObject->getPayload()));

	// 定义删除
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("OwnerInfo.delete.summary"), removeOutHouse, ListJsonVO<String>::Wrapper);
	 //定义删除处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ownerinfo/delete-outhouse", removeOutHouse, BODY_DTO(List<String>, ids), execRemoveOutHouse(ids));

private: // 定义执行函数
	// 执行入住房屋数据
	StringJsonVO::Wrapper execAddIntoHouse(const OwnerInfoAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 执行退出房屋数据
	//StringJsonVO::Wrapper execModifyOutHouse(const OwnerInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	// 删除数据
	ListJsonVO<String>::Wrapper execRemoveOutHouse(const List<String>& ids);

};

#include OATPP_CODEGEN_END(ApiController)
#endif