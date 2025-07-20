#pragma once
#ifndef _HOUSE_DETAIL_DO_
#define _HOUSE_DETAIL_DO_

#include "../DoInclude.h"

class HouseDetailDO
{
    // 房屋ID
    CC_SYNTHESIZE(string, house_id, House_id);
    // 房屋号
    CC_SYNTHESIZE(string, house_num, House_num);
    // 单元ID
    CC_SYNTHESIZE(string, unit_id, Unit_id);
    // 楼层
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    // 业主ID
    CC_SYNTHESIZE(string, owner_id, Owner_id);
    // 业主姓名
    CC_SYNTHESIZE(string, owner_name, Owner_name);
    // 业主电话
    CC_SYNTHESIZE(string, owner_phone, Owner_phone);
    // 房屋类型
    CC_SYNTHESIZE(string, house_type, House_type);
    // 建筑面积
    CC_SYNTHESIZE(double, built_area, Built_area);
    // 室内面积
    CC_SYNTHESIZE(double, inner_area, Inner_area);
    // 租金
    CC_SYNTHESIZE(double, rent_amount, Rent_amount);
    // 房屋状态
    CC_SYNTHESIZE(string, house_status, House_status);
    // 入住时间
    CC_SYNTHESIZE(string, check_in_date, Check_in_date);
    // 创建时间
    CC_SYNTHESIZE(string, create_time, Create_time);
    // 状态码
    CC_SYNTHESIZE(string, status_cd, Status_cd);

public:
    HouseDetailDO()
    {
        status_cd = "0";
    }
};

typedef shared_ptr<HouseDetailDO> PtrHouseDetailDO;
#endif