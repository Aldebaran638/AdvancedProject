#pragma once

#ifndef _CAR_DO_
#define _CAR_DO_

#include "../DoInclude.h"

/**
 * 车辆实体类
 */
class CarDO
{
	//车牌号
	CC_SYNTHESIZE(string, car_num, Car_num);
	//成员车辆数
	//CC_SYNTHESIZE(int, member_car_num, Member_car_num);
	//房屋号 楼栋-单元-房屋
	//CC_SYNTHESIZE(string,room_num,Room_num);
	//车牌类型
	CC_SYNTHESIZE(string, lease_type, Lease_type);
	//车辆类型
	CC_SYNTHESIZE(string, car_type, Car_type);
	//颜色
	CC_SYNTHESIZE(string, car_color, Car_color);
	//业主
	CC_SYNTHESIZE(string,name,Name);
	//车位
	CC_SYNTHESIZE(string, num,Num);
	//有效期
	CC_SYNTHESIZE(string,valid_time,Valid_time);
	//状态
	//CC_SYNTHESIZE(string, state, State);
	//备注
	//CC_SYNTHESIZE(string, remark, Remark);
};

typedef std::shared_ptr<CarDO> PtrCarDO;
#endif