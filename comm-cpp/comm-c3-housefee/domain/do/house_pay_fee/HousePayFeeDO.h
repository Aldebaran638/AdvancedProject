#pragma once
#ifndef _HOUSE_PAY_FEE_DO_
#define _HOUSE_PAY_FEE_DO_
#include "../DoInclude.h"
class HouseInfoDO
{
public : 
	HouseInfoDO()
	{
		room_id = "";
		built_up_area = 0.0;
		room_area = 0.0;
	}
public : 
	CC_SYNTHESIZE(std::string, room_id,RoomId);
	CC_SYNTHESIZE(double, built_up_area,BuiltUpArea);
	CC_SYNTHESIZE(double, room_area,RoomArea);
};

class FindCommunityDO
{
public :
	CC_SYNTHESIZE(string, community,Community);
	CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);
	CC_SYNTHESIZE(string, fee_flag, FeeFlag);

};

class CalcHouseFeeDO
{
public : 
	CC_SYNTHESIZE(double, square_price, SquarePrice);
	CC_SYNTHESIZE(double, additional_amount, AdditionalAmount);
	CC_SYNTHESIZE(int, scale, Scale);
	CC_SYNTHESIZE(int, decimal_place, DecimalPlace);
	CC_SYNTHESIZE(std::string, units, Units);
	CC_SYNTHESIZE(std::string, computing_formula, ComputingFormula);
};

class FeeTypeIdDO
{
public : 
	CC_SYNTHESIZE(std::string, fee_type_cd, FeeTypeCd);
};

class DiscountDO
{
public :
	CC_SYNTHESIZE(int, discount_small_type, DiscountSmallType);
	CC_SYNTHESIZE(std::string, rule_name, RuleName);
	CC_SYNTHESIZE(double, spec_value, SpecValue);
};

class AddPayFeeDO
{
public :
	CC_SYNTHESIZE(std::string, fee_id,FeeId);
	CC_SYNTHESIZE(std::string, b_id,BId);
	CC_SYNTHESIZE(std::string, user_id, UserId);
	CC_SYNTHESIZE(std::string, community_id,CommunityCd);
	
	CC_SYNTHESIZE(std::string, income_obj_id,IncomeObjId);
	CC_SYNTHESIZE(std::string, start_time,StartTime);
	CC_SYNTHESIZE(std::string, end_time,EndTime);
	CC_SYNTHESIZE(std::string, create_time, CreateTime);
	CC_SYNTHESIZE(double, amount, Amount);
	CC_SYNTHESIZE(std::string, status_cd, StatusCd);
	CC_SYNTHESIZE(std::string, fee_flag, FeeFlag);
	CC_SYNTHESIZE(std::string, state, State);
	CC_SYNTHESIZE(std::string, config_id, ConfigId);
	CC_SYNTHESIZE(std::string, batch_id, BatchId);
	
	CC_SYNTHESIZE(std::string, fee_type_cd, FeeTypeCd);

	CC_SYNTHESIZE(std::string, payer_obj_id, PayerObjId);
	CC_SYNTHESIZE(std::string, payer_obj_cd, PayerObjCd);
};

class AddPayFeeConfigDO
{
public :
	CC_SYNTHESIZE(std::string, batch_id, BatchId);
	CC_SYNTHESIZE(std::string, community_id, CommunityId);
	CC_SYNTHESIZE(std::string, create_user_id, CreateUserId);
	CC_SYNTHESIZE(std::string, create_user_name,CreateUserName);
	CC_SYNTHESIZE(std::string, status_cd, StatusCd);
	CC_SYNTHESIZE(std::string, create_time, CreateTime);
	CC_SYNTHESIZE(std::string, state, State);
	CC_SYNTHESIZE(std::string, msg, Msg);
	CC_SYNTHESIZE(std::string, remark, Remark);
};

class ModifyFeeInfoDO
{
	CC_SYNTHESIZE(string, formula_value, FourmulaValue);
	CC_SYNTHESIZE(double , square_price,SquarePrice);
	CC_SYNTHESIZE(double, additional_price, AdditionalPrice);
	CC_SYNTHESIZE(double, build_up_area, BuildUpArea);
	CC_SYNTHESIZE(string, community_id, CommunityId);
	CC_SYNTHESIZE(string, fee_type, FeeType);
};

class PaymentInfoDO {
public:
	PaymentInfoDO() {
		detail_id = "";
		b_id = "";
		fee_id = "";
		community_id = "";
		cycles = 0;
		receivable_amount = 0.0;
		received_amount = 0.0;
		pay_order_id = "";
		cashier_id = "";
		cashier_name = "";
		open_invoice = false;
		acct_amount = 0.0;
		discount_amount = 0.0;
		deduction_amount = 0.0;
		late_amount = 0.0;
		gift_amount = 0.0;
		prime_rate = 0;
		remark = "";
		create_time = "";
		status_cd = "";
		state = "";
		start_time = "";
		end_time = "";
		payable_amount = 0.0;
	}

public:
	CC_SYNTHESIZE(std::string, detail_id, DetailId);
	CC_SYNTHESIZE(std::string, b_id, BId);
	CC_SYNTHESIZE(std::string, fee_id, FeeId);
	CC_SYNTHESIZE(std::string, community_id, CommunityId);
	CC_SYNTHESIZE(int, cycles, Cycles);
	CC_SYNTHESIZE(double, receivable_amount, ReceivableAmount);
	CC_SYNTHESIZE(double, received_amount, ReceivedAmount);
	CC_SYNTHESIZE(std::string, pay_order_id, PayOrderId);
	CC_SYNTHESIZE(std::string, cashier_id, CashierId);
	CC_SYNTHESIZE(std::string, cashier_name, CashierName);
	CC_SYNTHESIZE(bool, open_invoice, OpenInvoice);
	CC_SYNTHESIZE(double, acct_amount, AcctAmount);
	CC_SYNTHESIZE(double, discount_amount, DiscountAmount);
	CC_SYNTHESIZE(double, deduction_amount, DeductionAmount);
	CC_SYNTHESIZE(double, late_amount, LateAmount);
	CC_SYNTHESIZE(double, gift_amount, GiftAmount);
	CC_SYNTHESIZE(double, prime_rate, PrimeRate);
	CC_SYNTHESIZE(std::string, remark, Remark);
	CC_SYNTHESIZE(std::string, create_time, CreateTime);
	CC_SYNTHESIZE(std::string, status_cd, StatusCd);
	CC_SYNTHESIZE(std::string, state, State);
	CC_SYNTHESIZE(std::string, start_time, StartTime);
	CC_SYNTHESIZE(std::string, end_time, EndTime);
	CC_SYNTHESIZE(double, payable_amount, PayableAmount);
};

class StatusTimeDO {
public:
	StatusTimeDO() {
		status_cd = "";
		state = "";
		start_time = "";
		end_time = "";
		config_id = "";
	}

public:
	CC_SYNTHESIZE(std::string, status_cd, StatusCd);
	CC_SYNTHESIZE(std::string, state, State);
	CC_SYNTHESIZE(std::string, start_time, StartTime);
	CC_SYNTHESIZE(std::string, end_time, EndTime);
	CC_SYNTHESIZE(std::string, config_id, ConfigId);
};

class DiscountInfoDO {
public:
	DiscountInfoDO() {
		discount_type = "";
		spec_value =0;
	}

public:
	CC_SYNTHESIZE(std::string, discount_type, DiscountType);
	CC_SYNTHESIZE(double, spec_value, SpecValue);
};
#endif
