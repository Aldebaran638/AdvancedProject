#pragma once
#ifndef _DETAILDO_H_
#define  _DETAILDO_H_
#include "DoInclude.h"
class detailDO {
	CC_SYNTHESIZE(string, fee_id, FEE_ID);
	CC_SYNTHESIZE(string, cycle, CYCLE);
	CC_SYNTHESIZE(string, pay_path, PAY_PATH);
	CC_SYNTHESIZE(string, receivable_amount, RECEIVABLE_AMOUNT);
	CC_SYNTHESIZE(string, amount, AMOUNT);
	CC_SYNTHESIZE(string, pay_time, PAY_TIME);
	CC_SYNTHESIZE(string, start_time, START_TIME);
	CC_SYNTHESIZE(string, end_time, END_TIME);
	CC_SYNTHESIZE(string, receive_id, RECEIVE_ID);
	CC_SYNTHESIZE(string, status_cd, STATUS_CD);
	CC_SYNTHESIZE(string, remark, REMARK);
	CC_SYNTHESIZE(string, opt, OPT);
public:
	detailDO()
	{
		fee_id = "";
		cycle = "";
		pay_path = "";
		receivable_amount = "";
		amount = "";
		pay_time = "";
		start_time = "";
		end_time = "";
		receive_id = "";
		status_cd = "";
		remark = "";
		opt = "";
	}
};
typedef std::shared_ptr<detailDO> PtrdetailDO;
#endif // !_DETAILDTO_H_
