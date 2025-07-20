#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/23 17:52:21

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
#ifndef _PAYMENTAUDIT_SERVICE_
#define _PAYMENTAUDIT_SERVICE_
#include "domain/vo/payment_reviews/PaymentAduitVO.h"
#include "domain/query/payment_reviews/PaymentAduitQuery.h"
#include "domain/dto/payment_reviews/PaymentAuditDTO.h"

class PaymentAuditService {
public:
    // 分页查询审核列表
    PaymentAuditListPageDTO::Wrapper getList(const PaymentAuditListQuery::Wrapper& query);
    // 查询审核详情
    PaymentAuditDetailDTO::Wrapper getDetail(const std::string& id);
    // 分页查询缴费历史
    PaymentAuditHistoryPageDTO::Wrapper getHistory(const PaymentAuditHistoryQuery::Wrapper& query);

};

#endif // !_PAYMENTAUDIT_SERVICE_

