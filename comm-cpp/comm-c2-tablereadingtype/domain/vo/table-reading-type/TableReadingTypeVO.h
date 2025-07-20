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
#ifndef _TABLEREADINGTYPEVO_H_
#define _TABLEREADINGTYPEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/table-reading-type/TableReadingTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 抄表类型显示JsonVO对象，用于响应给客户端
 */
class TableReadingTypeJsonVO : public JsonVO<TableReadingTypeDTO::Wrapper>
{
	DTO_INIT(TableReadingTypeJsonVO, JsonVO<TableReadingTypeDTO::Wrapper>);
};

/**
 * 抄表类型分页显示JsonVO对象，用于响应给客户端
 */
class TableReadingTypePageJsonVO : public JsonVO<TableReadingTypePageDTO::Wrapper>
{
	DTO_INIT(TableReadingTypePageJsonVO, JsonVO<TableReadingTypePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _TABLEREADINGTYPEVO_H_