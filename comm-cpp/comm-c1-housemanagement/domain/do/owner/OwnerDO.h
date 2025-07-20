#pragma once

#ifndef _OWNER_DO_
#define _OWNER_DO_
#include "../DoInclude.h"


/**
 * 业主实体类
 */
class OwnerDO
{
	CC_SYNTHESIZE(string, owner_id, Owner_id); // 业主id
	CC_SYNTHESIZE(string, name, Name); // 业主姓名
	CC_SYNTHESIZE(string, file_real_name, File_real_name); // 业主人脸
	CC_SYNTHESIZE(string, sex, Sex); // 业主性别
	CC_SYNTHESIZE(string, id_card, Id_card); // 业主身份证
	CC_SYNTHESIZE(string, link, Link); // 联系方式
	CC_SYNTHESIZE(string, address, Address); // 家庭住址
	CC_SYNTHESIZE(int, house_num, House_num); // 房屋数
	CC_SYNTHESIZE(int, member_num, Member_num); // 业主成员数量
	CC_SYNTHESIZE(int, car_number, Car_number); // 车辆数
	CC_SYNTHESIZE(int, complaint_num, Complaint_num); // 投诉数
	CC_SYNTHESIZE(int, repair_num, Repair_num); // 报修数
	CC_SYNTHESIZE(string, amount_owed, Amount_owed); // 欠费金额
	CC_SYNTHESIZE(int, contract_num, Contract_num); // 合同数
	CC_SYNTHESIZE(string, access_control_key, Access_control_key);// 门禁钥匙
};

typedef std::shared_ptr<OwnerDO> PtrOwnerDO;

#endif
