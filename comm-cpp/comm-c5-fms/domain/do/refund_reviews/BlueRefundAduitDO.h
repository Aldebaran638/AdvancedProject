#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/25 14:54:32

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
#ifndef _BLUEREFUNDADUITDO_
#define _BLUEREFUNDADUITDO_
#include "../DoInclude.h"

//获取退费审核列表
class ReviewPageDO
{
	// 退款单号
	CC_SYNTHESIZE(string, return_fee_id, Return_fee_id);
	// 缴费单号
	CC_SYNTHESIZE(string, detail_id, Detail_id);
	// 费用类型
	CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
	// 付费周期
	CC_SYNTHESIZE(int, cycles, Cycles);
	// 申请时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 退费原因
	CC_SYNTHESIZE(string, reason, Reason);
	// 审核状态
	CC_SYNTHESIZE(string, state, State);
public:
	ReviewPageDO() {
		return_fee_id = "";
		detail_id = "";
		fee_type_cd = "";
		cycles = -1;
		create_time = "";
		reason = "";
		state = "";
	}
};

//获取退费详情
class FeeDetailDO
{
	// 缴费单号
	CC_SYNTHESIZE(string, detail_id, Detail_id);
	// 费用标识
	CC_SYNTHESIZE(string, fee_label, Fee_label);
	// 费用类型
	CC_SYNTHESIZE(string, fee_type, Fee_type);
	// 付费对象
	CC_SYNTHESIZE(string, fee_object, Fee_object);
	// 费用项
	CC_SYNTHESIZE(string, fee_item, Fee_item);
	// 费用状态
	CC_SYNTHESIZE(string, fee_state, Fee_state);
public:
	FeeDetailDO() {
		detail_id = "";
		fee_label = "";
		fee_type = "";
		fee_object = "";
		fee_item = "";
		fee_state = "";
	}
};

//获取缴费历史列表
class FeeHistoryDO
{
	// 缴费单号
	CC_SYNTHESIZE(string, detail_id, Detail_id);
	// 缴费方式
	CC_SYNTHESIZE(string, prime_rate, Prime_rate);
	//缴费时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//缴费起始时间
	CC_SYNTHESIZE(string, pay_time, Pay_time);
public:
	FeeHistoryDO() {
		detail_id = "";
		prime_rate = "";
		create_time = "";
		pay_time = "";
	}
};

#endif 
