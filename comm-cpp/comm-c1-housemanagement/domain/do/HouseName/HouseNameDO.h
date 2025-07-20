#pragma once
#ifndef _HOUSENAME_DO_
#define _HOUSENAME_DO_

#include "../DoInclude.h"

class HouseNameDO
{
    //房屋ID
    CC_SYNTHESIZE(string, house_id, House_id);
    //业务ID
    CC_SYNTHESIZE(string, b_id, B_id);
    //房屋编号
    CC_SYNTHESIZE(string, house_num, House_num);
    //单元ID
    CC_SYNTHESIZE(string, unit_id, Unit_id);
    //业主姓名
    CC_SYNTHESIZE(string, owner_name, Owner_name);
    //楼栋号
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    //单元号
    CC_SYNTHESIZE(string, unit_num, Unit_num);
    //创建时间
    CC_SYNTHESIZE(string, create_time, Create_time);
    //数据状态
    CC_SYNTHESIZE(string, status_cd, Status_cd);

public:
    HouseNameDO()
    {
        b_id = "";
        status_cd = "0";
    }
};

typedef shared_ptr<HouseNameDO> PtrHouseNameDO;
#endif