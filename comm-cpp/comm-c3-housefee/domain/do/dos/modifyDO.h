#pragma once

#ifndef _MODIFYDO_H_
#define  _MODIFYDO_H_
#include "DoInclude.h"
class modifyDO {
	CC_SYNTHESIZE(string, fee_id, FEE_ID);
	/*CC_SYNTHESIZE(string, fee_name, FEE_NAME);
	CC_SYNTHESIZE(string, obj_name, Obj_name);*/
	CC_SYNTHESIZE(string, fee_pro, FEE_PRO);
	//CC_SYNTHESIZE(string, pay_time, PAY_TIME);
	CC_SYNTHESIZE(string, pay_start, PAY_START);
	CC_SYNTHESIZE(string, pay_end, PAY_END);

	CC_SYNTHESIZE(string, actions, ACTIONS);
	CC_SYNTHESIZE(string, oporator, OPORATOR);
	CC_SYNTHESIZE(string, opt_time, OPT_TIME);
public:
	modifyDO() {
		fee_id = "";
		//fee_name = "";
		//obj_name = "";
		fee_pro = "";
		//pay_time = "";
		pay_start = "";
		pay_end = "";
		actions = "";
		oporator = "";
		opt_time = "";
	}

};
typedef std::shared_ptr<modifyDO> PtrmodifyDO;
#endif