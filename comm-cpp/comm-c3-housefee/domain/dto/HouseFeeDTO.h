#pragma once
#ifndef _HOUSE_FEE_DTO_H_
#define _HOUSE_FEE_DTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class AddHouseFeeDTO : public oatpp::DTO
{
	DTO_INIT(AddHouseFeeDTO, DTO);
	
	//房屋ID house_id
	DTO_FIELD(String, house_id);
	DTO_FIELD_INFO(house_id) {
		info->description = ZH_WORDS_GETTER("house_fee.add.house_id");
	}
	
	//费用类型 fee_type
	DTO_FIELD(String, fee_type);
	DTO_FIELD_INFO(fee_type)
	{
		info->description = ZH_WORDS_GETTER("house_fee.add.fee_type");
	}
	
	//收费项目 charge_project
	DTO_FIELD(String, charge_project);
	DTO_FIELD_INFO(charge_project)
	{
		info->description = ZH_WORDS_GETTER("house_fee.add.charge_project");
	}
	//计费起始时间 start_time
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time)
	{
		info->description = ZH_WORDS_GETTER("house_fee.add.start_time");
	}
	//计费结束时间 end_time
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time)
	{
		info->description = ZH_WORDS_GETTER("house_fee.add.end_time");
	}

	//计费结束时间 end_time
	DTO_FIELD(Float64, amount);
	DTO_FIELD_INFO(amount)
	{
		info->description = ZH_WORDS_GETTER("house_fee.add.amount");
	}

	//配置id
	DTO_FIELD(String, config_id);
	DTO_FIELD_INFO(config_id) {
		info->description = ZH_WORDS_GETTER("house_fee.add.config_id");
	}

};

class ModifyHouseFeeDTO : public  oatpp::DTO 
{
	DTO_INIT(ModifyHouseFeeDTO, DTO);

	DTO_FIELD(String, fee_id);
	DTO_FIELD_INFO(fee_id)
	{
		info->description = ZH_WORDS_GETTER("house_fee.modify.fee_id");
	}

	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time)
	{
		info->description = ZH_WORDS_GETTER("house_fee.modify.create_time");
	}

	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time)
	{
		info->description = ZH_WORDS_GETTER("hosue_fee.modify.start_time");
	}

	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time)
	{
		info->description = ZH_WORDS_GETTER("house_fee.modify.end_time");
	}
};

class HouseFeeIdDTO : public oatpp::DTO
{
	DTO_INIT(HouseFeeIdDTO, DTO);

	DTO_FIELD(String, fee_id);
	DTO_FIELD_INFO(fee_id)
	{
		info->description = ZH_WORDS_GETTER("house_fee.modify.fee_id");
		//info->description = "house_fee.modify.fee_id";
	}
};


//业主账户DTO
class AccountDTO :public oatpp::DTO
{
	DTO_INIT(AccountDTO, DTO);

	DTO_FIELD(Boolean, flag);


	DTO_FIELD(String, account_type);
	DTO_FIELD_INFO(account_type)
	{
		info->description = ZH_WORDS_GETTER("account.info.type");
	}

	DTO_FIELD(String, account_name);
	DTO_FIELD_INFO(account_name)
	{
		info->description = ZH_WORDS_GETTER("account.info.name");
	}
	
	DTO_FIELD(Float32, account_amount);

	DTO_FIELD_INFO(account_amount)
	{
		info->description = ZH_WORDS_GETTER("account.info.amount");
	}
};

class PayFeeDTO : AccountDTO
{
	DTO_INIT(PayFeeDTO, AccountDTO);

	DTO_FIELD(String, fee_id);
	DTO_FIELD_INFO(fee_id)
	{
		info->description = ZH_WORDS_GETTER("house_fee.modify.fee_id");
		//info->description = "house_fee.modify.fee_id";
	}

	//缴费时间
	DTO_FIELD(String, pay_fee_time);
	DTO_FIELD_INFO(pay_fee_time)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.cycle");
	}


	DTO_FIELD(Int32, cycle);
	DTO_FIELD_INFO(cycle)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.ycle");
	}

	DTO_FIELD(Int32, real_cycle);
	DTO_FIELD_INFO(real_cycle)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.real_cycle");
	}
	
	DTO_FIELD(String, pay_fee_start_time);
	DTO_FIELD_INFO(pay_fee_start_time)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.pay_fee_start_time");
	}

	DTO_FIELD(String, pay_fee_end_time);
	DTO_FIELD_INFO(pay_fee_end_time)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.pay_fee_end_time");
	}

	DTO_FIELD(String, pay_fee_way);
	DTO_FIELD_INFO(pay_fee_way)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.pay_fee_way");
	}

	DTO_FIELD(Float32, amount);
	DTO_FIELD_INFO(amount)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.amount");
	}

	DTO_FIELD(Float32, amount_due); //应缴金额
	DTO_FIELD_INFO(amount_due)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.amount_due");
	}

	DTO_FIELD(Float32, pay_amount);
	DTO_FIELD_INFO(pay_amount)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.pay_amount");
	}

	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark)
	{
		info->description = ZH_WORDS_GETTER("house_fee.pay.remark");
	}

	DTO_FIELD(String, community_id);
	DTO_FIELD_INFO(community_id)
	{
		info->description = ZH_WORDS_GETTER("house_fee.add.community_id");
	}
};

class CalcHousePayDTO : public oatpp::DTO
{
	DTO_INIT(CalcHousePayDTO, oatpp::DTO);

	DTO_FIELD(String, community_id);
	DTO_FIELD(String, config_id);
	DTO_FIELD(String, charge_project);
	DTO_FIELD(String, start_time);
	DTO_FIELD(String, end_time);
	DTO_FIELD(String, fee_type);
	DTO_FIELD_INFO(fee_type)
	{
		info->description = ZH_WORDS_GETTER("house_fee.add.fee_type");
	}

	DTO_FIELD(Float64, built_up_area);
	DTO_FIELD(Float64, room_area);
};

class CalcDiscountDTO :public oatpp::DTO
{
	DTO_INIT(CalcDiscountDTO, oatpp::DTO);

	DTO_FIELD(String, community_id);
	DTO_FIELD(String, fee_type);
	DTO_FIELD(Float64, amount);
;
};


#include OATPP_CODEGEN_END(DTO)
#endif
