#pragma once
#ifndef _OWEINFORMATIONDO_H_
#define _OWEINFORMATIONDO_H_
#include "../DoInclude.h"
#include "../../../Macros.h"
/**
 * 欠费数据表
 */
class OweInformationDo
{
	CC_SYNTHESIZE(int, owe_id, Owe_Id);
	CC_SYNTHESIZE(int, bill_id, Bill_Id);
	CC_SYNTHESIZE(int, fee_id, Fee_Id);
	CC_SYNTHESIZE(int, bill_amount_owed, Bill_Amount_Owed);
	CC_SYNTHESIZE(int, amount_owed, Amount_Owed);
	CC_SYNTHESIZE(std::string, fee_end_time, Fee_End_Time);
	CC_SYNTHESIZE(int, owner_id, Owner_Id);
	CC_SYNTHESIZE(std::string, owner_name, Owner_Name);
	CC_SYNTHESIZE(std::string, owner_tel, Owner_Tel);
	CC_SYNTHESIZE(std::string, payer_obj_name, Payer_Obj_Name);
	CC_SYNTHESIZE(std::string, payer_obj_type, Payer_Obj_Type);
	CC_SYNTHESIZE(int, community_id, Community_Id);
	CC_SYNTHESIZE(std::string, state, State);
	CC_SYNTHESIZE(std::string, create_time, Create_Time);
	CC_SYNTHESIZE(std::string, deadline_time, Deadline_Time);
public:
	OweInformationDo()
		: owe_id(0),
		bill_id(0),
		fee_id(0),
		bill_amount_owed(0),
		amount_owed(0),
		fee_end_time(""),
		owner_id(0),
		owner_name(""),
		owner_tel(""),
		payer_obj_name(""),
		payer_obj_type(""),
		community_id(0),
		state(""),
		create_time(""),
		deadline_time("")
	{
	}
};
#endif // !_OWEINFORMATIONDO_H_
