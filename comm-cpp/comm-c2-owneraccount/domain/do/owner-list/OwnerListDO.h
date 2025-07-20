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
#ifndef _OWNERLISTDO_H_
#define _OWNERLISTDO_H_
#include "../DoInclude.h"

/**
 * 用户列表数据库实体类
 */
class OwnerListDO
{
	// 账户编号
	CC_SYNTHESIZE(string, acct_id, AcctId);
	// 账户名称
	CC_SYNTHESIZE(string, name, Name);
	// 身份证号
	CC_SYNTHESIZE(string, id_card, IdCard);
	// 手机号
	CC_SYNTHESIZE(string, link, Link);
	// 账户类型
	CC_SYNTHESIZE(string, acct_type, AcctType);
	// 账户金额
	CC_SYNTHESIZE(double, amount, Amount);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 账户类型中文映射
	CC_SYNTHESIZE(string, acct_type_text, AcctTypeText);

public:
	OwnerListDO() {
		acct_id = "";
		name = "";
		id_card = "";
		link = "";
		acct_type = "";
		create_time = "";
		amount = -1.0;
	}
};

// 给OwnerListDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OwnerListDO> PtrOwnerListDO;
#endif // !_OWNERLISTDO_H_