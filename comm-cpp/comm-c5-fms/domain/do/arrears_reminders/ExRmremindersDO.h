#pragma once

#ifndef _EXRMREMINDERS_DO_
#define _EXRMREMINDERS_DO_
#include "../DoInclude.h"


class ExRmremindersDO
{
	// 编号
	CC_SYNTHESIZE(string, ofc_id, Ofc_id);
	// 业主名称
	CC_SYNTHESIZE(string, owner_name, Owner_name);
	// 付费对象名称
	CC_SYNTHESIZE(string, payer_obj_name, Payer_obj_name);
	// 费用名称
	CC_SYNTHESIZE(string, fee_name, Fee_name);
	// 催缴金额
	CC_SYNTHESIZE(string, amountd_owed, Amountd_owed);
	// 开始时间
	CC_SYNTHESIZE(string, start_time, Start_time);
	//// 截止时间
	//CC_SYNTHESIZE(string, end_time, End_time);
	// 催缴方式
	CC_SYNTHESIZE(string, callable_way, Callable_way);
	// 催缴人
	CC_SYNTHESIZE(string, staff_name, Staff_name);
	// 催缴状态
	CC_SYNTHESIZE(string, state, State);
	// 说明
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	ExRmremindersDO() {
		ofc_id = "";
		owner_name = "";
		payer_obj_name = "";
		fee_name = "";
		amountd_owed = "";
		start_time = "";
		/*end_time = "";*/
		callable_way = "";
		staff_name = "";
		state = "";
		remark = "";
		create_time = "";
				
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ExRmremindersDO> PtrExRmremindersDO;
#endif // !_EXRMREMINDERS_DO_
