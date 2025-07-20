#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _ACCOUNT_RECEIPT_DO_H_
#define _ACCOUNT_RECEIPT_DO_H_
#include "../DoInclude.h"

class AccountReceiptDO  
{
	// 收据id （主键）
	CC_SYNTHESIZE(string, ar_id, Ar_id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 账户名称
	CC_SYNTHESIZE(string, acct_name, Acct_name);
	// 账户类型
	CC_SYNTHESIZE(string, acct_type, Acct_type);
	// 业主名称
	CC_SYNTHESIZE(string, owner_name, Owner_name);
	// 应收金额
	CC_SYNTHESIZE(string, receivable_amount, Receivable_amount);
	// 支付方式
	CC_SYNTHESIZE(string, prime_rate, Prime_rate);  
	// 实收金额
	CC_SYNTHESIZE(string, received_amount, Received_amount);
	// 说明
	CC_SYNTHESIZE(string, remark, Remark);
	// 当前余额（总余额）
	CC_SYNTHESIZE(string, amount, Amount);
	// 物业的名称
	CC_SYNTHESIZE(string, page_name, Page_name);
	// 小区名称
	CC_SYNTHESIZE(string, name, Name);

public:
	AccountReceiptDO() {
		ar_id = "";
		owner_name = "";
		prime_rate = "";
		receivable_amount = "";
		received_amount = "";
		create_time = "";
		remark = "";
		name = "";
	}
};

// 给AccountReceiptDO智能指针设定一个别名方便使用
typedef std::shared_ptr<AccountReceiptDO> PtrAccountReceiptDO;
#endif