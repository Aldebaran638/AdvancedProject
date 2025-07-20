#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/17 19:38:42

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
#ifndef _ARREDETDTO_H_
#define _ARREDETDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加菜单目录数据传输模型
 */
class ArredetDTO : public oatpp::DTO
{
	DTO_INIT(ArredetDTO, DTO);
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


/**
 * 菜单目录数据传输模型(比较完整，由于列表数据)
 */
class MenuCatalogDTO : public ArredetDTO {
	DTO_INIT(MenuCatalogDTO, ArredetDTO);

	// id
	API_DTO_FIELD_DEFAULT(String, caId, ZH_WORDS_GETTER("menu-catalog.field.caId"));
};

/**
 * 示例分页传输对象
 */
class  ArredetPageDTO : public PageDTO<MenuCatalogDTO::Wrapper>
{
	DTO_INIT(ArredetPageDTO, PageDTO<MenuCatalogDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 