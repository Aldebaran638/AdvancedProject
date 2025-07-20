#pragma once
#ifndef _HOUSEFEEMGRDO_H_
#define _HOUSEFEEMGRDO_H_
#include "DoInclude.h"
class HouseFeeMgrDO
{
private:
	//费用id
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	//费用标识
	CC_SYNTHESIZE(string, fee_flag, Fee_flag);
	//费用类型
	CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
	//付费对象
	CC_SYNTHESIZE(string, payer_obj_name, Payer_obj_name);
	//费用项
	CC_SYNTHESIZE(string, config_name, Config_name);
	//费用状态
	CC_SYNTHESIZE(string, state, State);
	//建帐时间&应收开始时间
	CC_SYNTHESIZE(string, end_time, End_time);
	//批次
	CC_SYNTHESIZE(string, batch_id, Batch_id);
	//应收结束时间&收费截止时间
	CC_SYNTHESIZE(string, deadline_time, Deadline_time);
	//欠费金额
	CC_SYNTHESIZE(double, fee_pay, Fee_pay);
	//业主联系方式
	CC_SYNTHESIZE(string, owner_tel , Owner_tel);
	//业主名称
	CC_SYNTHESIZE(string, owner_name, Owner_name);
	//业主id
	CC_SYNTHESIZE(string, owner_id, Owner_id);

public:
	HouseFeeMgrDO()
	{
		fee_id = "";
		fee_flag = "";
		fee_type_cd = "";
		payer_obj_name = "";
		config_name = "";
		state = "";
		end_time = "";
		batch_id = "";
		deadline_time = "";
		fee_pay = 0.0;
		owner_tel = "";
		owner_name = "";
		owner_id = "";
	}
};

typedef std::shared_ptr<HouseFeeMgrDO> PtrHouseFeeMgrDO;
#endif // !_HOUSEFEEMGRDO_H_
