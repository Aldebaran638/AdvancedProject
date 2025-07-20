#pragma once
#ifndef _APPLY_ROOM_DISCOUNT_RECORD_DO_
#define _APPLY_ROOM_DISCOUNT_RECORD_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ApplyRoomDiscountRecordDO
{
	// 空置房验房跟踪记录ID
	CC_SYNTHESIZE(string, ardr_id, Ardr_id);
	// 空置房申请ID
	CC_SYNTHESIZE(string, ard_id, Ard_id);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, B_id);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// 数据状态
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// 创建用户的ID
	CC_SYNTHESIZE(string, create_user_id, Create_user_id);
	// 创建人
	CC_SYNTHESIZE(string, create_user_name, Create_user_name);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否违规
	CC_SYNTHESIZE(string, is_true, Is_true);
	// 审核状态
	CC_SYNTHESIZE(string, state, State);
public:
	ApplyRoomDiscountRecordDO() {
		ardr_id = "";
		ard_id = "";
		b_id = "";
		community_id = "";
		status_cd = "";
		create_user_id = "";
		create_user_name = "";
		create_time = "";
		remark = "";
		is_true = "";
		state = "0";
	}
};

// 给ApplyRoomDiscountRecordDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ApplyRoomDiscountRecordDO> PtrApplyRoomDiscountRecordDO;
#endif // !_APPLY_ROOM_DISCOUNT_RECORD_DO_
