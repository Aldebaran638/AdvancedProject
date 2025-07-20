#pragma once
#ifndef _BUREFUNDDO_H_
#define _BUREFUNDDO_H_
#include "../DoInclude.h"
#include "../../../Macros.h"
/**
 * 欠费数据表
 */
class BuRefundDO
{
	//退款单号
	CC_SYNTHESIZE(std::string, return_fee_id, Return_Fee_Id);
	CC_SYNTHESIZE(std::string, community_id,Community_Id);
	//缴费单号
	CC_SYNTHESIZE(std::string, b_id, B_Id);
	CC_SYNTHESIZE(std::string, config_id, Config_Id);
	//费用类型
	CC_SYNTHESIZE(std::string, fee_type_cd, Fee_Type_Cd);
	CC_SYNTHESIZE(std::string, detail_id, Detail_Id);
	//付费对象
	CC_SYNTHESIZE(std::string, fee_id, Fee_Id);
	//付费周期
	CC_SYNTHESIZE(std::string, cycles, Cycles);
	//应付金额/实付金额
	CC_SYNTHESIZE(int, received_amount, Received_Amount);
	CC_SYNTHESIZE(int, receivable_amount, Receivable_Amount);
	CC_SYNTHESIZE(std::string, prime_rate, Prime_Rate);
	CC_SYNTHESIZE(std::string, remark, Remark);
	//申请时间
	CC_SYNTHESIZE(std::string, create_time, Create_Time);
	CC_SYNTHESIZE(std::string, pay_time, Pay_Time);
	//退费原因
	CC_SYNTHESIZE(std::string, reason, Reason);
	//申请人
	CC_SYNTHESIZE(std::string, apply_person_name, Apply_Person_Name);
	CC_SYNTHESIZE(std::string, apply_person_id, Apply_Person_Id);
	//审核状态
	CC_SYNTHESIZE(std::string, state, State);
	//审核人
	CC_SYNTHESIZE(std::string, audit_person_name, Audit_Person_Name);
	CC_SYNTHESIZE(std::string, audit_person_id, Audit_Person_Id);
	//退款情况
	CC_SYNTHESIZE(std::string, status_cd, Status_Cd);
public:
	BuRefundDO()
		: return_fee_id(""),
		community_id(""),
		config_id(""),
		detail_id(""),
		b_id(""),
		fee_type_cd(""),
		fee_id(""),
		cycles(""),
		received_amount(0),
		receivable_amount(0),
		apply_person_id(""),
		pay_time(""),
		prime_rate(""),
		remark(""),
		create_time(""),
		reason(""),
		apply_person_name(""),
		state(""),
		audit_person_name(""),
		audit_person_id(""),
		status_cd("")
	{
	}
};
#endif // !_BUREFUNDDO_H_