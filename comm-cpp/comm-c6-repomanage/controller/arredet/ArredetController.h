#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author:
 @Date: 2025/05/17 20:01:27

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
#ifndef _ARREDETCONTROLLER_H_
#define _ARREDETCONTROLLER_H_

#include "domain/vo/arredet/ArreDetVO.h"
#include "domain/dto/arredet/ArreDetDTO.h"
#include "domain/query/arredet/ArredetQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ArredetController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ArredetController);
public: // 定义接口
	// 3.1 定义分页查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("arredet.query"), ArredetPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "objname", ZH_WORDS_GETTER("arredet.objname"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feename", ZH_WORDS_GETTER("arredet.feename"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feecreatetime", ZH_WORDS_GETTER("arredet.feecreatetime"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "createtime", ZH_WORDS_GETTER("arredet.createtime"), "4", false);
		API_DEF_ADD_QUERY_PARAMS(String, "oweamount", ZH_WORDS_GETTER("arredet.oweamount"), "5", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deadlinetime", ZH_WORDS_GETTER("arredet.deadlinetime"), "5", false);

	}
	// 3.2 定义分页查询接口处理
	ENDPOINT(API_M_GET, "/c6-repomanage/arredetQuery", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ArredetQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	ENDPOINT_INFO(downloadFile) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("arredet.export"), ArredetPageJsonVO::Wrapper);

		// 定义授权参数
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "objname", ZH_WORDS_GETTER("arredet.objname"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feename", ZH_WORDS_GETTER("arredet.feename"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feecreatetime", ZH_WORDS_GETTER("arredet.feecreatetime"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "createtime", ZH_WORDS_GETTER("arredet.createtime"), "4", false);
		API_DEF_ADD_QUERY_PARAMS(String, "oweamount", ZH_WORDS_GETTER("arredet.oweamount"), "5", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deadlinetime", ZH_WORDS_GETTER("arredet.deadlinetime"), "5", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/c6-repomanage/arredetExport", downloadFile, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execDownloadFile(filename);
	}

private: // 定义接口执行函数
	// 3.3 分页查询数据
	ArredetPageJsonVO::Wrapper execQueryAll(const ArredetQuery::Wrapper& query);


	// 3.3导出数据
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif 
