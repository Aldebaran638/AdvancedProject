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
#ifndef _FEEMGRDO_H_
#define _FEEMGRDO_H_
#include "DoInclude.h"

/**
 * 示例折扣数据库实体类
 */
class FeeMgrDO
{
	// 折扣id
	CC_SYNTHESIZE(string, discount_id, Discount_id);
	// 折扣名称
	CC_SYNTHESIZE(string, discount_name,Discount_name);
	// 折扣标识
	CC_SYNTHESIZE(string, fee_flag,Fee_flag);
	// 折扣类型
	CC_SYNTHESIZE(string, discount_type, Discount_type);
	// 折扣状态
	CC_SYNTHESIZE(string, status, Fee_status);
	// 折扣时间
	CC_SYNTHESIZE(string, createTime, CreateTime);

public:
	FeeMgrDO() 
	{
		discount_id = "";
		discount_name = "";
		fee_flag = "";
		discount_type = "";
		status = "";
	}
};

// 给FeeMgrDO智能指针设定一个别名方便使用
typedef std::shared_ptr<FeeMgrDO> PtrFeeMgrDO;
#endif 
