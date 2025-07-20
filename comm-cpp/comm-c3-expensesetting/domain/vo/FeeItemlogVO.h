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
#ifndef _FEEITEMVO_H_
#define _FEEITEMVO_H_

#include "../GlobalInclude.h"
#include "../dto/FeeItemDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用项详情 JsonVO，用于响应给客户端的单条费用项数据
 */
class FeeItemJsonVO : public JsonVO<FeeItemDTO::Wrapper> {
	DTO_INIT(FeeItemJsonVO, JsonVO<FeeItemDTO::Wrapper>);
};

/**
 * 费用项分页 JsonVO，用于响应给客户端的分页费用项数据
 */
class FeeItemPageJsonVO : public JsonVO<FeeItemPageDTO::Wrapper> {
	DTO_INIT(FeeItemPageJsonVO, JsonVO<FeeItemPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FEEITEMVO_H_
