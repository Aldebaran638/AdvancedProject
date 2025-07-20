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
#ifndef _OWNER_DO_
#define _OWNER_DO_
#include "../DoInclude.h"

/**
 * 业主数据库实体类
 */
class OwnerDO
{
	// 业主成员ID
	CC_SYNTHESIZE(std::string, member_id, MemberId);
	// 业主ID
	CC_SYNTHESIZE(std::string, owner_id, OwnerId);
	// 业务ID
	CC_SYNTHESIZE(std::string, b_id, BId);
	// 业主名称
	CC_SYNTHESIZE(std::string, name, Name);
	// 性别
	CC_SYNTHESIZE(std::string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(std::string, age, Age);
	// 联系人手机号
	CC_SYNTHESIZE(std::string, link, Link);
	// 用户ID
	CC_SYNTHESIZE(std::string, user_id, UserId);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 创建时间
	CC_SYNTHESIZE(std::string, create_time, CreateTime);
	// 数据状态
	CC_SYNTHESIZE(std::string, status_cd, StatusCd);
	// 业主类型
	CC_SYNTHESIZE(std::string, owner_type_cd, OwnerTypeCd);
	// 小区ID
	CC_SYNTHESIZE(std::string, community_id, CommunityId);
	// 身份证号码
	CC_SYNTHESIZE(std::string, id_card, IdCard);
	// 业主成员状态
	CC_SYNTHESIZE(std::string, state, State);
	// 业主标识
	CC_SYNTHESIZE(std::string, owner_flag, OwnerFlag);
	// 家庭住址
	CC_SYNTHESIZE(std::string, address, Address);
	//创建员工
	CC_SYNTHESIZE(std::string, create_by, CreateBy);
	// 房屋编号
	CC_SYNTHESIZE(std::string, room_num, RoomNum);

public:
	OwnerDO() {
		member_id = "";
		owner_id = "";
		b_id = "";
		name = "";
		sex = "";
		age = "";
		link = "";
		user_id = "";
		remark = "";
		create_time = "";
		status_cd = "0";
		owner_type_cd = "1001";
		community_id = "";
		id_card = "-1";
		state = "2000";
		owner_flag = "T";
		address = "";
		create_by = "";
		room_num = "";
	}
};

// 给OwnerDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OwnerDO> PtrOwnerDO;
#endif // !_OWNER_DO_