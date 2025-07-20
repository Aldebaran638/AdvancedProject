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
#ifndef _BUILDING_OWNER_ROOM_REL_DO_H_
#define _BUILDING_OWNER_ROOM_REL_DO_H_
#include "../DoInclude.h"

class BuildingRoomDO
{
	// 房屋编号
	CC_SYNTHESIZE(string, room_num, Room_num);
	// 楼层
	CC_SYNTHESIZE(string, layer, Layer);
	// 房屋id （主键）
	CC_SYNTHESIZE(string, room_id, Room_id);
	// 建筑面积
	CC_SYNTHESIZE(double, built_up_area, Built_up_area);
	// 户型
	CC_SYNTHESIZE(string, apartment, Apartment);
	// 房间数
	CC_SYNTHESIZE(int, section, Section);

	CC_SYNTHESIZE(string, b_id, B_id);                   // 业务ID
	CC_SYNTHESIZE(string, unit_id, Unit_id);             // 单元ID
	CC_SYNTHESIZE(double, fee_coefficient, Fee_coefficient); // 算费系数
	CC_SYNTHESIZE(string, user_id, User_id);             // 用户ID
	CC_SYNTHESIZE(string, remark, Remark);               // 备注
	CC_SYNTHESIZE(string, create_time, Create_time);     // 创建时间
	CC_SYNTHESIZE(string, status_cd, Status_cd);         // 数据状态
	CC_SYNTHESIZE(string, state, State);                 // 房屋状态
	CC_SYNTHESIZE(string, community_id, Community_id);   // 小区ID
	CC_SYNTHESIZE(string, room_type, Room_type);         // 房屋类型
	CC_SYNTHESIZE(string, room_sub_type, Room_sub_type); // 房屋子类型
	CC_SYNTHESIZE(double, room_area, Room_area);         // 室内面积
	CC_SYNTHESIZE(double, room_rent, Room_rent);         // 租金
public:
	BuildingRoomDO() {
		room_num = "";
		layer = "";
		room_id = "";
		built_up_area = -1;
		apartment = "";
		section = -1;
		b_id = "1";
		unit_id = "1";
		fee_coefficient = 1;
		user_id = "LBL";
		remark = "";
		status_cd = "0";
		state = "0";
		community_id = "1";
		room_type = "";
		room_sub_type = "";
		room_area = 100;
		room_rent = 100;
	}
};

// 给BuildingOwnerRoomRelDO智能指针设定一个别名方便使用
typedef std::shared_ptr<BuildingRoomDO> PtrBuildingRoomDO;
#endif