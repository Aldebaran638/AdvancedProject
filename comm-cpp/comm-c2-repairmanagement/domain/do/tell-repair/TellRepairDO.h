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
#ifndef _TELLREPAIR_DO_
#define _TELLREPAIR_DO_
#include "../DoInclude.h"

/**
 * 电话报修数据库实体类
 */
class TellRepairDO
{
	// 小区id
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// 编号
	CC_SYNTHESIZE(string, repairId, RepairId);
	// 报修对象id
	CC_SYNTHESIZE(string, repairObjId, RepairObjId);
	// 报修范围
	CC_SYNTHESIZE(string, repairObjType, RepairObjType);
	// 报修对象名称
	CC_SYNTHESIZE(string, repairObjName, RepairObjName);
	// 报修类型
	CC_SYNTHESIZE(string, repairType, RepairType);
	// 报修类型文本
	CC_SYNTHESIZE(string, repairTypeTxt, RepairTypeTxt);
	// 报修人
	CC_SYNTHESIZE(string, repairName, RepairName);
	// 联系方式
	CC_SYNTHESIZE(string, tel, Tel);
	// 预约时间
	CC_SYNTHESIZE(string, appointmentTime, AppointmentTime);
	// 报修内容
	CC_SYNTHESIZE(string, context, Context);
	// 提交时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 状态
	CC_SYNTHESIZE(string, state, State);
	// 状态文本
	CC_SYNTHESIZE(string, stateTxt, StateTxt);

public:
	TellRepairDO()
	{
		communityId = "";
		repairId = "";
		repairObjId = "";
		repairObjType = "";
		repairObjName = "";
		repairType = "";
		repairTypeTxt = "";
		repairName = "";
		tel = "";
		appointmentTime = "";
		context = "";
		createTime = "";
		state = "";
		stateTxt = "";
	}
};

// 给TellRepairDO智能指针设定一个别名方便使用
typedef std::shared_ptr<TellRepairDO> PtrTellRepairDO;
#endif // !_TELLREPAIR_DO_
