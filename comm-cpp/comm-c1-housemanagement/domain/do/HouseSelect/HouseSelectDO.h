#pragma once
#ifndef _HOUSESELECT_DO_
#define _HOUSESELECT_DO_

#include "../DoInclude.h"

class HouseSelectDO
{
    //·¿ÎÝID
    CC_SYNTHESIZE(string, house_id, House_id);
    //·¿ÎÝºÅ
    CC_SYNTHESIZE(string, room_num, Room_num);
    //Â¥¶°ºÅ
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    //µ¥ÔªºÅ
    CC_SYNTHESIZE(string, unit_num, Unit_num);
    //Â¥²ã
    CC_SYNTHESIZE(string, layer_num, Layer_num);

public:
    HouseSelectDO() = default;
};

typedef shared_ptr<HouseSelectDO> PtrHouseSelectDO;
#endif