#pragma once
#ifndef _HOUSELIST_DO_
#define _HOUSELIST_DO_

#include "../DoInclude.h"

class HouseListDO
{
    //房屋ID
    CC_SYNTHESIZE(string, house_id, House_id);
    //房屋号
    CC_SYNTHESIZE(string, room_num, Room_num);
    //楼栋号
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    //单元号
    CC_SYNTHESIZE(string, unit_num, Unit_num);
    //房屋状态
    CC_SYNTHESIZE(string, status_cd, Status_cd);
    //业主成员数
    CC_SYNTHESIZE(int, owner_count, Owner_count);
    //业主车辆数
    CC_SYNTHESIZE(int, car_count, Car_count);
    //投诉数
    CC_SYNTHESIZE(int, complaint_count, Complaint_count);

public:
    HouseListDO()
    {
        owner_count = 0;
        car_count = 0;
        complaint_count = 0;
    }
};

typedef shared_ptr<HouseListDO> PtrHouseListDO;
#endif