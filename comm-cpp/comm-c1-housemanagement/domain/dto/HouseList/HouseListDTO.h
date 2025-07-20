#pragma once
#ifndef _HOUSELIST_DTO_
#define _HOUSELIST_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseListDTO : public oatpp::DTO
{
    DTO_INIT(HouseListDTO, DTO);

    //房屋ID
    DTO_FIELD(String, house_id);
    DTO_FIELD_INFO(house_id) {
        info->description = ZH_WORDS_GETTER("houselist.field.house_id");
    }
    //房屋号
    DTO_FIELD(String, room_num);
    DTO_FIELD_INFO(room_num) {
        info->description = ZH_WORDS_GETTER("houselist.field.room_num");
    }
    //楼栋号
    DTO_FIELD(String, floor_num);
    DTO_FIELD_INFO(floor_num) {
        info->description = ZH_WORDS_GETTER("houselist.field.floor_num");
    }
    //单元号
    DTO_FIELD(String, unit_num);
    DTO_FIELD_INFO(unit_num) {
        info->description = ZH_WORDS_GETTER("houselist.field.unit_num");
    }
    //房屋状态
    DTO_FIELD(String, status_cd);
    DTO_FIELD_INFO(status_cd) {
        info->description = ZH_WORDS_GETTER("houselits.field.status_cd");
    }
    //业主成员数
    DTO_FIELD(Int32, owner_count);
    DTO_FIELD_INFO(owner_count) {
        info->description = ZH_WORDS_GETTER("houselist.field.owner_count");
    }
    //业主车辆数
    DTO_FIELD(Int32, car_count);
    DTO_FIELD_INFO(car_count) {
        info->description = ZH_WORDS_GETTER("houselist.field.car_count");
    }
    //投诉数
    DTO_FIELD(Int32, complaint_count);
    DTO_FIELD_INFO(complaint_count) {
        info->description = ZH_WORDS_GETTER("houselist.field.complaint_count");
    }
};

class HouseListPageDTO : public PageDTO<HouseListDTO::Wrapper>
{
    DTO_INIT(HouseListPageDTO, PageDTO<HouseListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif