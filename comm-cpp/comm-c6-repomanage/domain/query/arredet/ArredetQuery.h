#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/17 19:56:09

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
#ifndef _MENUCATALOGQUERY_H_
#define _MENUCATALOGQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
//class PageQuery : public oatpp::DTO
//{
//	// 初始化定义
//	DTO_INIT(PageQuery, DTO);
//	// 查询页码
//	DTO_FIELD(UInt64, pageIndex) = 1;
//	DTO_FIELD_INFO(pageIndex) {
//#ifndef LINUX
//		info->description = u8"当前页码";
//#else
//		info->description = "curr page index";
//#endif
//	}
//	// 查询条数
//	DTO_FIELD(UInt64, pageSize) = 5;
//	DTO_FIELD_INFO(pageSize) {
//#ifndef LINUX
//		info->description = u8"每页数据条数";
//#else
//		info->description = "curr page size";
//#endif
//	}
//};
class ArredetQuery : public PageQuery
{
	DTO_INIT(ArredetQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("arredet.id"));
	API_DTO_FIELD_DEFAULT(String, room, ZH_WORDS_GETTER("arredet.room"));
	API_DTO_FIELD_DEFAULT(String, ow, ZH_WORDS_GETTER("arredet.owner"));
	API_DTO_FIELD_DEFAULT(String, owt, ZH_WORDS_GETTER("arredet.owt"));
	API_DTO_FIELD_DEFAULT(String, area, ZH_WORDS_GETTER("arredet.area"));
	API_DTO_FIELD_DEFAULT(String, ei, ZH_WORDS_GETTER("arredet.ei"));
	API_DTO_FIELD_DEFAULT(String, st, ZH_WORDS_GETTER("arredet.st"));
	API_DTO_FIELD_DEFAULT(String, et, ZH_WORDS_GETTER("arredet.et"));
	API_DTO_FIELD_DEFAULT(String, ad, ZH_WORDS_GETTER("arredet.ad"));
	API_DTO_FIELD_DEFAULT(String, aa, ZH_WORDS_GETTER("arredet.aa"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUCATALOGQUERY_H_