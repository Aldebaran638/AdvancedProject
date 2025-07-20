#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:19:05

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
#ifndef _HOUSECONTROLLER_H_H
#define _HOUSECONTROLLER_H_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/house/HouseDTO.h"
#include "domain/vo/house/HouseVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"


#include OATPP_CODEGEN_BEGIN(ApiController)


class HouseController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(HouseController);
public:
	//// 定义一个房产文件上传接口
	//// 房产文件上传接口描述
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("house.file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	//// 定义端点
	//API_HANDLER_ENDPOINT(API_M_POST, "/house/file/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));

	//// 定义一个房产文件下载接口
	//// 定义描述
	//ENDPOINT_INFO(downloadFile) {
	//	API_DEF_ADD_COMMON(ZH_WORDS_GETTER("house.file.download.summary"), Void);
	//	API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/test.jpg", true);
	//}
	//// 定义端点
	//ENDPOINT(API_M_GET, "house/file/download", downloadFile, QUERY(String, filename)) {
	//	return execDownloadFile(filename);
	//}

	// 新增交房（添加）接口描述
	ENDPOINT_INFO(addHouse) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house.home.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 新增交房（添加）接口处理
	ENDPOINT(API_M_POST, "/house/add-house", addHouse, BODY_DTO(HouseAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddHouse(dto, authObject->getPayload()));
	}

	// 定义退房（删除）接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("house.home.delete.summary"), removeHouse, ListJsonVO<String>::Wrapper);
	// 定义退房（删除）接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/house/delete-house-by-id", removeHouse, BODY_DTO(List<String>, ids), execRemoveHouse(ids));


	//// 定义退房（删除）接口描述
	//ENDPOINT_INFO(removeHouse) {
	//	// 定义接口标题
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house.home.delete.summary"));
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//}
	//// 定义退房（删除）接口处理
	//ENDPOINT(API_M_DEL, "/house/home/delete", removeHouse, BODY_DTO(HouseAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	//	// 呼叫执行函数响应结果
	//	API_HANDLER_RESP_VO(execRemoveHouse(ids);
	//}


	

private: // 定义接口执行函数
	// 执行单文件上传处理
	//StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
	//// 执行文件下载处理
	//std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
	// 退房删除房产信息
	ListJsonVO<String>::Wrapper execRemoveHouse(const List<String>& ids);
	// 新增房产信息
	StringJsonVO::Wrapper execAddHouse(const HouseAddDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_HOUSECONTROLLER_H_H