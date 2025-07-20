#pragma once
#ifndef _HOUSESELECT_DTO_
#define _HOUSESELECT_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseSelectDTO : public oatpp::DTO
{
    DTO_INIT(HouseSelectDTO, DTO);

    //·¿ÎÝID
    DTO_FIELD(String, house_id);
    DTO_FIELD_INFO(house_id) {
        info->description = ZH_WORDS_GETTER("houseselect.field.house_id");
    }
    //·¿ÎÝºÅ
    DTO_FIELD(String, room_num);
    DTO_FIELD_INFO(room_num) {
        info->description = ZH_WORDS_GETTER("houseselect.field.room_num");
    }
    //Â¥¶°ºÅ
    DTO_FIELD(String, floor_num);
    DTO_FIELD_INFO(floor_num) {
        info->description = ZH_WORDS_GETTER("houseselect.field.floor_num");
    }
    //µ¥ÔªºÅ
    DTO_FIELD(String, unit_num);
    DTO_FIELD_INFO(unit_num) {
        info->description = ZH_WORDS_GETTER("houseselect.field.unit_num");
    }
    //Â¥²ã
    DTO_FIELD(String, layer_num);
    DTO_FIELD_INFO(layer_num) {
        info->description = ZH_WORDS_GETTER("houseselect.field.layer_num");
    }
};

class HouseSelectPageDTO : public PageDTO<HouseSelectDTO::Wrapper>
{
    DTO_INIT(HouseSelectPageDTO, PageDTO<HouseSelectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif