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
#ifndef _HOUSE_DO_
#define _HOUSE_DO_
#include "../DoInclude.h"

/**
 * 示例房屋数据库实体类
 */
class HouseDO
{
	// 房屋编号
	CC_SYNTHESIZE(string, id, Id);
	// 楼栋
	CC_SYNTHESIZE(string, building, Building);
	// 房屋类型
	CC_SYNTHESIZE(string, houseType, HouseType);
	// 单元
	CC_SYNTHESIZE(string, unit, Unit);
	// 房屋楼层
	CC_SYNTHESIZE(string, floor, Floor);
	// 建筑面积
	CC_SYNTHESIZE(string, buildArea, BuildArea);
	// 房屋面积
	CC_SYNTHESIZE(string, houseArea, HouseArea);
	// 房屋姓名
	CC_SYNTHESIZE(string, name, Name);
	// 房屋状态
	CC_SYNTHESIZE(string, state, State);
	// 购房时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 算费系数
	CC_SYNTHESIZE(string, coefficient, Coefficient);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 房屋门牌号
	CC_SYNTHESIZE(string, doorNumber, DoorNumber);

	//// 用户电话号
	//CC_SYNTHESIZE(string, phoneNumber, PhoneNumber);
	// 房屋位置
	//CC_SYNTHESIZE(string, address, Address);
	
	
	
public:
	HouseDO() {
		id = "";
		name = "01star";
		building = "";
		houseType = "";
		unit = "";
		floor = "";
		//doorNumber = "";
		buildArea = "";
		houseArea = "";
		state = "";
		coefficient = "";
		createTime = "";
		remark = "";
		doorNumber = "";
		//phoneNumber = "";
	}
};

// 给HouseDO智能指针设定一个别名方便使用
typedef std::shared_ptr<HouseDO> PtrHouseDO;
#endif // !_HOUSE_DO_
