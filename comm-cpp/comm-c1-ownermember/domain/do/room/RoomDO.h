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
#ifndef _ROOM_DO_
#define _ROOM_DO_
#include "domain/do/DoInclude.h"

/**
 * 示例数据库实体类
 */
class RoomDO
{
	// 房屋编号
	CC_SYNTHESIZE(string, room_num, Room_num);
	// 楼层
	CC_SYNTHESIZE(string, layer, Layer);
	// 类型
	CC_SYNTHESIZE(string, room_type, Room_type);
	// 建筑/室内面积
	CC_SYNTHESIZE(double, built_up_area, Built_up_area);
	// 租金
	CC_SYNTHESIZE(double, room_rent, Room_rent);
	// 房屋状态
	CC_SYNTHESIZE(string, state, State);

public:
	RoomDO() {
		room_num = "";
		layer = "";
		room_type = "";
		built_up_area = 0;
		room_rent = 0;
		state = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RoomDO> PtrRoomDO;
#endif // !_ROOM_DO_
