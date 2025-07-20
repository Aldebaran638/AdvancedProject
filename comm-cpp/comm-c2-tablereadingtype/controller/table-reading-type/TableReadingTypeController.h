#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _TABLEREADINGTYPECONTROLLER_H_
#define _TABLEREADINGTYPECONTROLLER_H_

//#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/table-reading-type/TableReadingTypeQuery.h"
#include "domain/dto/table-reading-type/TableReadingTypeDTO.h"
#include "domain/vo/table-reading-type/TableReadingTypeVO.h"

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 抄表类型控制器
 */
class TableReadingTypeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义抄表类型控制器访问入口
	API_ACCESS_DECLARE(TableReadingTypeController);
	// 定义接口
public:
	// 定义抄表类型查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("table-reading-type.query-all.summary"), TableReadingTypePageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("table-reading-type.field.community-id"), "2024022647620054", true);
	}
	// 定义抄表类型查询接口处理
	ENDPOINT(API_M_GET, "/comm-c2-tablereadingtype/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, TableReadingTypeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTableReadingType(query));
	}

	// 定义抄表类型新增接口描述
	ENDPOINT_INFO(addTableReadingType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("table-reading-type.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义抄表类型新增接口处理
	ENDPOINT(API_M_POST, "/comm-c2-tablereadingtype/add", addTableReadingType, BODY_DTO(TableReadingTypeAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddTableReadingType(dto));
	}

	// 定义抄表类型修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("table-reading-type.update.summary"), modifyTableReadingType, StringJsonVO::Wrapper);
	// 定义抄表类型修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-tablereadingtype/upadte", modifyTableReadingType, BODY_DTO(TableReadingTypeUpdateDTO::Wrapper, dto), execModifyTableReadingType(dto));

	// 定义抄表类型删除接口描述
	// API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("table-reading-type.delete.summary"), removeTableReadingType, ListJsonVO<String>::Wrapper);
	// 定义抄表类型删除接口处理
	// API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/table-reading-type/delete", removeTableReadingType, BODY_DTO(List<String>, ids), execRemoveTableReadingType(ids));

	// 定义抄表类型删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("table-reading-type.delete.summary"), removeTableReadingType, StringJsonVO::Wrapper);
	// 定义抄表类型删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-tablereadingtype/delete", removeTableReadingType, BODY_DTO(TableReadingTypeRemoveDTO::Wrapper, dto), execRemoveTableReadingType(dto));

private:
	// 分页查询抄表类型数据
	TableReadingTypePageJsonVO::Wrapper execQueryTableReadingType(const TableReadingTypeQuery::Wrapper& query);
	// 修改抄表类型数据
	StringJsonVO::Wrapper execModifyTableReadingType(const TableReadingTypeUpdateDTO::Wrapper& dto);
	// 新增抄表类型数据
	StringJsonVO::Wrapper execAddTableReadingType(const TableReadingTypeAddDTO::Wrapper& dto);
	// 删除抄表类型数据
	StringJsonVO::Wrapper execRemoveTableReadingType(const TableReadingTypeRemoveDTO::Wrapper& dto);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_TABLEREADINGTYPECONTROLLER_H_