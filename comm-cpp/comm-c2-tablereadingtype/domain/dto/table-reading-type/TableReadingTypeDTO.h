#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _TABLEREADINGTYPEADD_H_
#define _TABLEREADINGTYPEADD_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 新增抄表类型数据传输模型
 */
class TableReadingTypeAddDTO : public oatpp::DTO
{
	DTO_INIT(TableReadingTypeAddDTO, DTO);
	// 名称
	API_DTO_FIELD(String, type_name, ZH_WORDS_GETTER("table-reading-type.field.type-name"), true, "abc");
	// 说明
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("table-reading-type.field.remark"), true, "def");
	// 社区id
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("table-reading-type.field.community-id"), true, "2024022647620054");
};

/**
 * 抄表类型完整数据传输模型
 */
class TableReadingTypeDTO : public TableReadingTypeAddDTO 
{
	
	DTO_INIT(TableReadingTypeDTO, TableReadingTypeAddDTO);

	// 抄表类型id
	API_DTO_FIELD_DEFAULT(String, type_id, ZH_WORDS_GETTER("table-reading-type.field.type-id"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("table-reading-type.field.create-time"));

};

/**
 * 修改抄表类型数据传输模型
 */
class TableReadingTypeUpdateDTO : public oatpp::DTO
{

	DTO_INIT(TableReadingTypeUpdateDTO, DTO);

	// 名称
	API_DTO_FIELD(String, type_name, ZH_WORDS_GETTER("table-reading-type.field.type-name"), true, "abc");
	// 说明
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("table-reading-type.field.remark"), true, "def");
	// 抄表类型id
	API_DTO_FIELD(String, type_id, ZH_WORDS_GETTER("table-reading-type.field.type-id"), true, "12241958387776098304");

};

/**
 * 删除抄表类型数据传输模型
 */
class TableReadingTypeRemoveDTO : public oatpp::DTO
{

	DTO_INIT(TableReadingTypeRemoveDTO, DTO);

	// 抄表类型id
	API_DTO_FIELD(String, type_id, ZH_WORDS_GETTER("table-reading-type.field.type-id"), true, "12241958387776098304");

};


/**
 * 抄表类型分页传输对象
 */
class TableReadingTypePageDTO : public PageDTO<TableReadingTypeDTO::Wrapper>
{
	DTO_INIT(TableReadingTypePageDTO, PageDTO<TableReadingTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TABLEREADINGTYPEADD_H_