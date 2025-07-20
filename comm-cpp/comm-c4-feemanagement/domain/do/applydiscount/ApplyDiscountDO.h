#ifndef APPLY_DISCOUNT_DO_H
#define APPLY_DISCOUNT_DO_H
#include"../DoInclude.h"

class ApplyDiscountDO
{
	//房屋id
	CC_SYNTHESIZE(string, room_id, RoomId);
	//房屋id
	CC_SYNTHESIZE(string, room_name, RoomName);
	//小区id
	CC_SYNTHESIZE(string, community_id, CommunityId);
	//主键id
	CC_SYNTHESIZE(string, ard_id, ArdId);
	//验房人
	CC_SYNTHESIZE(string, check_user_id, CheckUserId);
	//通过人
	CC_SYNTHESIZE(string, review_user_id, ReviewUserId);
	//申请信息
	CC_SYNTHESIZE(string, create_remark, CreateRemark);
	//验房备注信息
	CC_SYNTHESIZE(string, check_remark, CheckRemark);
	//检查信息
	CC_SYNTHESIZE(string, review_remark, ReviewRemark);
	//业务id
	CC_SYNTHESIZE(string, b_id, BId);
	//费用id
	CC_SYNTHESIZE(string, fee_id, FeeId);
	// 折扣id
	CC_SYNTHESIZE(string, discount_id, DiscountId);
	// 申请类型
	CC_SYNTHESIZE(string, apply_type, ApplyType);
	// 申请人
	CC_SYNTHESIZE(string, create_user_name, CreateUserName);
	// 申请电话
	CC_SYNTHESIZE(string, create_user_tel, CreateUserTel);
	// 开始时间
	CC_SYNTHESIZE(string, start_time, StartTime);
	// 结束时间
	CC_SYNTHESIZE(string, end_time, EndTime);
	// 状态
	CC_SYNTHESIZE(string, state, State);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//数据状态
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 使用状态
	CC_SYNTHESIZE(string, in_use, InUse);
	// 返回方式
	CC_SYNTHESIZE(string, return_way, ReturnWay);
	// 返回金额
	CC_SYNTHESIZE(string, return_amount, ReturnAmount);
public:
	ApplyDiscountDO() {
		ard_id = "";
		community_id = "";
		check_user_id = "";
		review_user_id = "";
		create_remark = "";
		check_remark = "";
		review_remark = "";
		room_id = ""; 
		discount_id = "";
		apply_type = "";
		create_user_name = "";
		create_user_tel = "";
		start_time = "";
		end_time = "";
		state = "0";//默认0
		create_time = "";
		status_cd = "";
		in_use = "";
		b_id = "";
		fee_id = "";
		return_way = "";
		return_amount = "";
	}
};

class DiscountNameDO
{
	// 折扣类型
	CC_SYNTHESIZE(string, discount_name, DiscountName);
	CC_SYNTHESIZE(string, discount_id, DiscountId);

public:
	DiscountNameDO() {
		discount_name = "";
		discount_id = "";
	}
};

// 给DO智能指针设定一个别名方便使用
typedef std::shared_ptr<ApplyDiscountDO> PtrApplyDiscountDO;
typedef std::shared_ptr<DiscountNameDO> PtrDiscountNameDO;

#endif