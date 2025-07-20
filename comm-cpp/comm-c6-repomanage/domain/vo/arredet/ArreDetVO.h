#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/17 19:51:58

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
#ifndef _ARREDETVO_H_
#define _ARREDETVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/arredet/ArreDetDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 菜单目录显示JsonVO，用于响应给客户端的Json对象
 */
class ArredetJsonVO : public JsonVO<ArredetDTO::Wrapper> {
	DTO_INIT(ArredetJsonVO, JsonVO<ArredetDTO::Wrapper>);
};

/**
 * 菜单目录分页显示JsonVO，用于响应给客户端的Json对象
 */
class ArredetPageJsonVO : public JsonVO<ArredetPageDTO::Wrapper> {
	DTO_INIT(ArredetPageJsonVO, JsonVO<ArredetPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif 