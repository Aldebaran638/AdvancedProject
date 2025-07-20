#ifndef _REMITFEEDO_H_
#define _REMITFEEDO_H_
#include "./DoInclude.h"
class RemitFeeDO {
	CC_SYNTHESIZE(string, detail_id,DETAIL_ID);
	CC_SYNTHESIZE(string,receipt_id, RECEIPT_ID);
	CC_SYNTHESIZE(string, pay_obj, PAY_OBJ);
	CC_SYNTHESIZE(double, cycle, CYCLE);
// 	CC_SYNTHESIZE(double, receivable_amount, RECEIVABLE_AMOUNT);
// 	CC_SYNTHESIZE(double, amount, AMOUNT);
	CC_SYNTHESIZE(string, receive_received, RECEIVE_RECEIVED);
	CC_SYNTHESIZE(string, pay_path, PAY_PATH);
	//CC_SYNTHESIZE(string, start_time, START_TIME);
	//CC_SYNTHESIZE(string, end_time, END_TIME);
	CC_SYNTHESIZE(string, pay_period, PAY_PERIOD);
	CC_SYNTHESIZE(string, pay_time, PAY_TIME);
	CC_SYNTHESIZE(string, receive_id, RECEIVE_ID);
	CC_SYNTHESIZE(string, status_cd, STATUS_CD);
	CC_SYNTHESIZE(string, remark, REMARK);
	CC_SYNTHESIZE(string, opt, OPT);

public:
	RemitFeeDO()
	{
		detail_id = "";
		receipt_id = "";
		pay_obj = "";
		cycle = 0.0;
// 		receivable_amount = 0.0;
// 		amount = 0.0;
		receive_received = "";
		pay_path = "";
		//start_time = "";
		//end_time = "";
		pay_period = "";
		pay_time = "";
		receive_id = "";
		status_cd = "";
		remark = "";
		opt = "";
	}
};
typedef std::shared_ptr<RemitFeeDO> PtrRemitFeeDO;
#endif // !_HOUSEFEEMGRDO_H_
