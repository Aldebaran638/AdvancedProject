#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _TELL_REPAIR_VO_
#define _TELL_REPAIR_VO_

#include "../../GlobalInclude.h"
#include "../../dto/tell-repair/TellRepairDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单条数据JsonVO，返回给客户端的Json对象
 */
class TellRepairJsonVO : public JsonVO<TellRepairDTO::Wrapper>
{
	DTO_INIT(TellRepairJsonVO, JsonVO<TellRepairDTO::Wrapper>);
};

/**
 * 分页数据JsonVO，返回给客户端的Json对象
 */
class TellRepairPageJsonVO : public JsonVO<TellRepairPageDTO::Wrapper>
{
	DTO_INIT(TellRepairPageJsonVO, JsonVO<TellRepairPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TELL_REPAIR_VO_