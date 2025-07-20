#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/18 10:15:12

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
#ifndef _PAYMENTAUDITVO_
#define _PAYMENTAUDITVO_

#include "../../GlobalInclude.h"
#include "../../dto/payment_reviews/PaymentAuditDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//获取缴费审核列表json对象
class PaymentAuditListJsonVO : public JsonVO<PaymentAuditListPageDTO::Wrapper> {
	DTO_INIT(PaymentAuditListJsonVO, JsonVO<PaymentAuditListPageDTO::Wrapper>);
};
//获取缴费审核详情json对象
class PaymentAuditDetailJsonVO : public JsonVO<PaymentAuditDetailDTO::Wrapper> {
	DTO_INIT(PaymentAuditDetailJsonVO, JsonVO<PaymentAuditDetailDTO::Wrapper>);
};
//获取缴费历史列表json对象
class PaymentAuditHistoryJsonVO : public JsonVO<PaymentAuditHistoryPageDTO::Wrapper> {
	DTO_INIT(PaymentAuditHistoryJsonVO, JsonVO<PaymentAuditHistoryPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif  // !_PAYMENTAUDIT_VO_