#pragma once
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
#ifndef _WATERMETER_DO_
#define _WATERMETER_DO_
#include "../DoInclude.h"

/**
 * 水电抄表数据库实体类
 */
class WaterMeterDO
{
	// 编号
	CC_SYNTHESIZE(string, water_id, Water_id);
	// 业务ID (默认-1)
	CC_SYNTHESIZE(string, b_id, B_id);
	// 对象ID，1001 是房屋 2002 是车位
	CC_SYNTHESIZE(string, obj_id, Obj_id);
	// 抄表类型
	CC_SYNTHESIZE(string, meter_type, Meter_type);
	// 类型 1001 房屋 2002 车位
	CC_SYNTHESIZE(string, obj_type, Obj_type);
	// 上期度数
	CC_SYNTHESIZE(float, pre_degrees, Pre_degrees);
	// 本期度数
	CC_SYNTHESIZE(float, cur_degrees, Cur_degrees);
	// 上期读表时间
	CC_SYNTHESIZE(string, pre_reading_time, Pre_reading_time);
	// 本期读表时间
	CC_SYNTHESIZE(string, cur_reading_time, Cur_reading_time);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 数据状态，详细参考c_status表，0, 在用 1失效
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// 度表署名
	CC_SYNTHESIZE(string, remark, Remark);
	// 费用ID
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// 对象名称
	CC_SYNTHESIZE(string, obj_name, Obj_name);
	// 抄表单价
	CC_SYNTHESIZE(float, price, Price);

public:
	WaterMeterDO() {
		water_id = "";
		b_id = "-1";
		meter_type = "";
		obj_type = "3333";
		obj_id = "";
		pre_degrees = 0;
		cur_degrees = 0;
		pre_reading_time = "";
		cur_reading_time = "";
		remark = "";
		status_cd = "0";
		obj_name = "";
		create_time = "2025-01-1 00:00:00";
		price = 0;
	}
};

// 给WaterMeterDO智能指针设定一个别名方便使用
typedef std::shared_ptr<WaterMeterDO> PtrWaterMeterDO;
#endif // !_WATERMETER_DO_
