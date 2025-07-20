#pragma once
#ifndef _APPLY_ROOM_DISCOUNT_DO_
#define _APPLY_ROOM_DISCOUNT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ApplyRoomDiscountDO
{
	// 主键ID
	CC_SYNTHESIZE(string, ard_id, Ard_id);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// 房屋ID
	CC_SYNTHESIZE(string, room_id, Room_id);
	// 房屋名称
	CC_SYNTHESIZE(string, room_name, Room_name);
	// 折扣ID
	CC_SYNTHESIZE(string, discount_id, Discount_id);
	// 申请类型
	CC_SYNTHESIZE(string, apply_type, Apply_type);
	// 开始时间
	CC_SYNTHESIZE(string, start_time, Start_time);
	// 结束时间
	CC_SYNTHESIZE(string, end_time, End_time);
	// 创建人
	CC_SYNTHESIZE(string, create_user_name, Create_user_name);
	// 创建手机号
	CC_SYNTHESIZE(string, create_user_tel, Create_user_tel);
	// 验房人
	CC_SYNTHESIZE(string, check_user_id, Check_user_id);
	// 通过人
	CC_SYNTHESIZE(string, review_user_id, Review_user_id);
	// 审核状态
	CC_SYNTHESIZE(string, state, State);
	// 申请信息
	CC_SYNTHESIZE(string, create_remark, Create_remark);
	// 验房备注信息
	CC_SYNTHESIZE(string, check_remark, Check_remark);
	// 通过备注信息
	CC_SYNTHESIZE(string, review_remark, Review_remark);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 数据状态
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// 是否可用
	CC_SYNTHESIZE(string, in_use, In_use);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, B_id);
	// 费用ID
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	// 返还方式
	CC_SYNTHESIZE(string, return_way, Return_way);
	// 返还金额
	CC_SYNTHESIZE(string, return_amount, Return_amount);
public:
	ApplyRoomDiscountDO() {
		ard_id = "";
		community_id = "";
		room_id = "";
		room_name = "";
		discount_id = "";
		apply_type = "";
		start_time = "";
		end_time = "";
		create_user_name = "";
		create_user_tel = "";
		check_user_id = "";
		review_user_id = "";
		state = "0";
		create_remark = "";
		check_remark = "";
		review_remark = "";
		create_time = "";
		status_cd = "0";
		in_use = "";
		b_id = "";
		fee_id = "";
		return_way = "";
		return_amount = "";
		
	}
};

// 给ApplyRoomDiscountDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ApplyRoomDiscountDO> PtrApplyRoomDiscountDO;
#endif // !_APPLY_ROOM_DISCOUNT_DO_
