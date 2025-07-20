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
#ifndef _PRESTORE_FEE_DO_H_
#define _PRESTORE_FEE_DO_H_
#include "../DoInclude.h"

class PreStoreFeeDO
{
	// 预存费用id (主键)
	CC_SYNTHESIZE(string, prestore_fee_id, Prestore_fee_id);
	// 预存费用类型 水费8003 电费8004
	CC_SYNTHESIZE(string, prestore_fee_type, Prestore_fee_type);
	// 预存对象id,预存至房屋
	CC_SYNTHESIZE(string, room_id, Room_id);
	// 预存对象类型
	CC_SYNTHESIZE(string, prestore_obj_type, Prestore_fee_obj_type);
	// 预存金额
	CC_SYNTHESIZE(string, prestore_fee_amount, Prestore_fee_amount);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);	
	// 备注
	CC_SYNTHESIZE(string, remark, Remark); // 
	// 小区id
	CC_SYNTHESIZE(string, community_id, Community_id);
	// 原因
	CC_SYNTHESIZE(string, reason, Reason);
	// 使用时间
	CC_SYNTHESIZE(string, use_time, Use_time);
	// 状态 1001未使用 2002已使用
	CC_SYNTHESIZE(string, state, State);
	// 数据状态
	CC_SYNTHESIZE(string, status_cd, Status_cd);

public:
	PreStoreFeeDO() {
		prestore_fee_id = "";
		prestore_fee_type = "";
		room_id = "";
		prestore_obj_type = "";
		prestore_fee_amount = "";
		create_time = "";
		remark = "";
		community_id = "";
		reason = "";
		use_time = "";
		state = "";
		status_cd = "";
	}
};

// 给PtrPreStoreFeeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<PreStoreFeeDO> PtrPreStoreFeeDO;
#endif