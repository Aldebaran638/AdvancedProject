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
#ifndef _OWNERDETAILDO_H_
#define _OWNERDETAILDO_H_
#include "../DoInclude.h"

/**
 * 账户明细数据库实体类
 */
class OwnerDetailDO
{
	// 明细编号
	CC_SYNTHESIZE(string, detail_id, DetailId);
	// 交易编号
	CC_SYNTHESIZE(string, order_id, OrderId);
	// 账户名称
	CC_SYNTHESIZE(string, owner_name, OwnerName);
	// 明细类型
	CC_SYNTHESIZE(string, detail_type, DetailType);
	// 金额/积分
	CC_SYNTHESIZE(double, amount, Amount);
	// 交易时间（创建时间）
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 说明
	CC_SYNTHESIZE(string, remark, Remark);
	// 收据ID
	CC_SYNTHESIZE(string, ar_id, ArId);
	// 账户ID
	CC_SYNTHESIZE(string, acct_id, AcctId);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 业主ID（对象ID）
	CC_SYNTHESIZE(string, owner_id, OwnerId);
	// 业主手机号
	CC_SYNTHESIZE(string, link, Link);
	// 支付方式
	CC_SYNTHESIZE(string, prime_rate, PrimeRate);
	// 应收金额
	CC_SYNTHESIZE(double, receivable_amount, ReceivableAmount);
	// 实收金额
	CC_SYNTHESIZE(double, received_amount, ReceivedAmount);
	// 数据状态
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 关联账户
	CC_SYNTHESIZE(string, rel_acct_id, RelAcctId);
	// 对象类型
	CC_SYNTHESIZE(string, obj_type, ObjType);
	// 对象ID
	CC_SYNTHESIZE(string, obj_id, ObjId);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, BId);
	// 原明细ID
	CC_SYNTHESIZE(string, pre_detail_id, PreDetailId);
	// 明细类型中文映射
	CC_SYNTHESIZE(string, detail_type_text, DetailTypeText);

public:
	OwnerDetailDO() {
		detail_id = "";
		order_id = "";
		owner_name = "";
		detail_type = "";
		amount = -1.0;
		create_time = "";
		remark = "";
		ar_id = "";
		acct_id = "";
		community_id = "";
		owner_id = "";
		link = "";
		prime_rate = "";
		receivable_amount = -1.0;
		received_amount = -1.0;
		status_cd = "";
		rel_acct_id = "";
		obj_type = "";
		obj_id = "";
		b_id = "";
	}
};

// 给OwnerDetailDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OwnerDetailDO> PtrOwnerDetailDO;

/**
 * 业主名称数据库实体类
 */
class OwnerDetailAccountNameDO
{
	// 账户名称
	CC_SYNTHESIZE(string, owner_name, OwnerName);

public:
	OwnerDetailAccountNameDO() {
		owner_name = "";
	}
};

// 给OwnerDetailAccountNameDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OwnerDetailAccountNameDO> PtrOwnerDetailAccountNameDO;
#endif // !_OWNERDETAILDO_H_
