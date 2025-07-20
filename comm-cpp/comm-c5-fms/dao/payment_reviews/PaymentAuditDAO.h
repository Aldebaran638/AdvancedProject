#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/23 17:51:17

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
#ifndef _PAYMENTAUDIT_DAO_
#define _PAYMENTAUDIT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/payment_reviews/PaymentAuditDO.h"
#include "../../domain/query/payment_reviews/PaymentAduitQuery.h"

/**
 * 缴费审核部分数据库操作实现
 */
class PaymentAuditDAO : public BaseDAO
{
private:
	//查询条件构建器,根据PaymentAudit*Query对象动态构建查询条件相关参数
	inline std::string buildListConditions(const PaymentAuditListQuery::Wrapper& query, SqlParams& params);
	inline std::string buildHistoryConditions(const PaymentAuditHistoryQuery::Wrapper& query, SqlParams& params);
public:
	// 缴费审核列表
	std::list<PaymentAuditListDO> selectPaymentAuditList(const PaymentAuditListQuery::Wrapper& query);
	uint64_t countAuditList(const PaymentAuditListQuery::Wrapper& query);
	// 缴费审核详情
	PtrPaymentAuditDetailDO selectAuditDetail(const std::string& feeId);
	// 缴费历史列表
	 std::list<PaymentAuditHistoryDO> selectPaymentAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query);
    uint64_t countAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query);
};

#endif // !_PAYMENTAUDIT_DAO_