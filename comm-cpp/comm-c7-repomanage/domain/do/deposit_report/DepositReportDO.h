#pragma once
#ifndef _DEPOSIT_REPORT_DO_
#define _DEPOSIT_REPORT_DO_
#include "../DoInclude.h"

/**
 * 押金报表数据库实体类
 */
class DepositReportDO
{
	// 费用ID
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	// 费用类型
	CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
	// 付费开始时间
	CC_SYNTHESIZE(string, start_time, Start_time);
	// 付费结束时间
	CC_SYNTHESIZE(string, end_time, End_time);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 付费对象类型
	CC_SYNTHESIZE(string, income_obj_id, Income_obj_id);
	// 付费方ID
	CC_SYNTHESIZE(string, payer_obj_id, Payer_obj_id);
	// 付费状态
	CC_SYNTHESIZE(string, pay_state, Pay_state);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// 房号
	CC_SYNTHESIZE(string, location_obj_name, Location_obj_name);
	// 业主
	CC_SYNTHESIZE(string, owner_name, Owner_name);
	// 费用项
	CC_SYNTHESIZE(string, config_name, Config_name);
	// 应收金额
	CC_SYNTHESIZE(string, receivable_amount, Receivable_amount);
	// 退费状态
	CC_SYNTHESIZE(string, return_state, Return_state);
public:
	DepositReportDO() {
		fee_id = "";
		fee_type_cd = "";
		start_time = "";
		end_time = "";
		create_time = "";
		income_obj_id = "";
		payer_obj_id = "";
		pay_state = "";
		community_id = "";
		location_obj_name = "";
		owner_name = "";
		config_name = "";
		receivable_amount = "";
		return_state = "";
	}
};
#endif // !_DEPOSIT_REPORT_DO_
