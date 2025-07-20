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
#ifndef _ACCOUNT_DO_H_
#define _ACCOUNT_DO_H_
#include "../DoInclude.h"

class AccountDO
{
	// 账户ID (主键)
	CC_SYNTHESIZE(string, acct_id, Acct_id);
	// 账户名称
	CC_SYNTHESIZE(string, acct_name, Acct_name);
	// 账户类型
	CC_SYNTHESIZE(string, acct_type, Acct_type);		// 账户名称、账户类型
	// 金额
	CC_SYNTHESIZE(string, amount, Amount);
	// 对象类型
	CC_SYNTHESIZE(string, obj_type, Obj_type);
	// 对象ID
	CC_SYNTHESIZE(string, obj_id, Obj_id);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, B_id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 数据状态
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// 局部ID
	CC_SYNTHESIZE(string, part_id, Part_id);
	// 账户手机号
	CC_SYNTHESIZE(string, link, Link);
public:
	AccountDO() {
		acct_id = "";
		acct_name = "";
		acct_type = "";
		amount = "";
		obj_type = "";
		obj_id = "";
		b_id = "";
		create_time = "";
		status_cd = "";
		part_id = "";
		link = "";
	}
};

// 给AccountDO智能指针设定一个别名方便使用
typedef std::shared_ptr<AccountDO> PtrAccountDO;
#endif