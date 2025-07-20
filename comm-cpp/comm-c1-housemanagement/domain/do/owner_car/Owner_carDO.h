#pragma once

#ifndef _OWNER_CAR_DO_
#define _OWNER_CAR_DO_
#include "../DoInclude.h"

class Owner_carDO
{
	//汽车id
	CC_SYNTHESIZE(string, car_id, Car_id);
	//业主
	CC_SYNTHESIZE(string, owner_id, Owner_id);
	//业务id
	CC_SYNTHESIZE(string, b_id, B_id);
	//车牌号
	CC_SYNTHESIZE(string, car_num, Car_num);
	//汽车品牌
	CC_SYNTHESIZE(string, car_brand, Car_brand);
	//车牌类型 9901 家用小汽车，9902 客车，9903 货车
	CC_SYNTHESIZE(string, car_type, Car_type);
	//颜色
	CC_SYNTHESIZE(string, car_color, Car_color);
	//车位id
	CC_SYNTHESIZE(string, ps_id, Ps_id);
	//用户ID
	CC_SYNTHESIZE(string, user_id, User_id);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//数据状态
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	//小区id
	CC_SYNTHESIZE(string, community_id, Community_id);
	//起租时间
	CC_SYNTHESIZE(string, start_time, Start_time);
	//结租时间
	CC_SYNTHESIZE(string, end_time, End_time);
	//状态
	CC_SYNTHESIZE(string, state,State);
	//1001
	CC_SYNTHESIZE(string, car_type_id, Car_type_id);
	//成员id
	CC_SYNTHESIZE(string, member_id, Member_id);
	//车辆类型 H 月租车 S 出售车 I 内部车 NM 免费车
	CC_SYNTHESIZE(string, lease_type, Lease_type);
	
public:
	Owner_carDO() {}
};
typedef std::shared_ptr<Owner_carDO> PtrCarDO;
#endif