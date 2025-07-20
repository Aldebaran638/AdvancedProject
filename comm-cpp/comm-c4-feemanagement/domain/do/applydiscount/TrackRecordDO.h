#pragma once

#ifndef TRACKRECORDDO_H_
#define TRACKRECORDDO_H_


#include "../DoInclude.h"

class TrackRecordDO {
	// apply_room_discount_record
	// 空置房验房跟踪记录id
	CC_SYNTHESIZE(string, ardr_id, ArdrId);
	// 空置房申请id
	CC_SYNTHESIZE(string, ard_id, ArdId);
	// 业务id
	CC_SYNTHESIZE(string, b_id, BId);
	// 小区id
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 数据状态，0, 在用 1失效
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 创建用户的id
	CC_SYNTHESIZE(string, create_user_id, CreateUserId);
	// 创建人
	CC_SYNTHESIZE(string, create_user_name, CreateUserName);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否违规  true 是   false 否
	CC_SYNTHESIZE(string, is_true, IsTrue);
	// 审核状态: 1申请验房2验房通过3验房不通过 4审批通过5审批不通过
	CC_SYNTHESIZE(string, state, State);

	// apply_room_discount
	// 房屋
	CC_SYNTHESIZE(string, room_name, RoomName);

public:
	TrackRecordDO() {
		ardr_id = "";
		ard_id = "";
		b_id = "-1";
		community_id = "";
		status_cd = "0"; // 默认在用
		create_user_id = "";
		create_user_name = "";
		create_time = "";
		remark = "";
		is_true = "false"; // 默认不是违规
		state = "1"; // 默认申请验房
		room_name = "";
	}

};


// 给TrackRecordDO智能指针设定一个别名方便使用
typedef std::shared_ptr<TrackRecordDO> PtrTrackRecordDO;


#endif // !TRACKRECORDDO_H_
