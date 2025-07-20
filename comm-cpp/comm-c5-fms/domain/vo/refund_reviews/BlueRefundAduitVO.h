#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 11:34:14

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
#ifndef _BLUEREFUNDADUITVO_
#define _BLUEREFUNDADUITVO_

#include "../../GlobalInclude.h"
#include "../../dto/refund_reviews/BlueRefundAduitDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//获取退费审核列表json对象
class ReviewPageJsonVO : public JsonVO<ReviewPageDTO::Wrapper> {
	DTO_INIT(ReviewPageJsonVO, JsonVO<ReviewPageDTO::Wrapper>);
};
//获取退费审核详细信息json对象
class FeeDetailJsonVO : public JsonVO<FeeDetailDTO::Wrapper> {
	DTO_INIT(FeeDetailJsonVO, JsonVO<FeeDetailDTO::Wrapper>);
};
//获取缴费历史列表json对象
class FeeHistoryJsonVO : public JsonVO<FeeHistoryDTO::Wrapper> {
	DTO_INIT(FeeHistoryJsonVO, JsonVO<FeeHistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 