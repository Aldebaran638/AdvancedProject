#pragma once
#ifndef _YARREARS_REMINDERSDO_
#define _YARREARS_REMINDERSDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class YArrears_RemindersDO
{
	CC_SYNTHESIZE(int, ofc_id, Ofc_Id);
	CC_SYNTHESIZE(std::string, community_id, Community_Id);
	CC_SYNTHESIZE(std::string, owner_name, Owner_Name);
	CC_SYNTHESIZE(std::string, owner_id, Owner_Id);
	CC_SYNTHESIZE(std::string, payer_obj_name, Payer_Obj_Name);
	CC_SYNTHESIZE(std::string, payer_obj_id, Payer_Obj_Id);
	CC_SYNTHESIZE(std::string, config_id, Config_Id);
	CC_SYNTHESIZE(std::string, fee_id, Fee_Id);
	CC_SYNTHESIZE(std::string, fee_name, Fee_Name);
	CC_SYNTHESIZE(std::string, payer_obj_type, Payer_Obj_Type);
	CC_SYNTHESIZE(int, amountd_owed, Amountd_Owed);
	CC_SYNTHESIZE(std::string, start_time, Start_Time);
	CC_SYNTHESIZE(std::string, callable_way, Callable_Way);
	CC_SYNTHESIZE(std::string, staff_id, Staff_Id);
	CC_SYNTHESIZE(std::string, staff_name, Staff_Name);
	CC_SYNTHESIZE(std::string, state, State);
	CC_SYNTHESIZE(std::string, end_time, End_Time);
	CC_SYNTHESIZE(std::string, remark, Remark);
	CC_SYNTHESIZE(std::string, create_time, Create_Time);
	CC_SYNTHESIZE(std::string, status_cd, Status_Cd);

public:
	YArrears_RemindersDO()
		:ofc_id(0),
		owner_name(""),
		owner_id(""),
		payer_obj_id(""),
		payer_obj_name(""),
		config_id(""),
		fee_id(""),
		payer_obj_type(""),
		fee_name(""),
		amountd_owed(0),
		staff_id(""),
		start_time(""),
		callable_way(""),
		staff_name(""),
		end_time(""),
		state(""),
		remark(""),
		create_time(""),
		community_id(""),
		status_cd("")
	{}
};

#endif 
