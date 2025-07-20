#pragma once
#ifndef _HOUSESELECT_QUERY_
#define _HOUSESELECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseSelectQuery : public PageQuery
{
    DTO_INIT(HouseSelectQuery, PageQuery);

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
    //·¿ÎÝºÅ
    DTO_FIELD(String, room_num);
    DTO_FIELD_INFO(room_num) {
        info->description = ZH_WORDS_GETTER("houseselect.field.room_num");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif