#pragma once
#ifndef _HOUSENAME_QUERY_
#define _HOUSENAME_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseNameQuery : public oatpp::DTO
{
    DTO_INIT(HouseNameQuery, DTO);

    //Â¥¶°ºÅ
    DTO_FIELD(String, floor_num);
    DTO_FIELD_INFO(floor_num) {
        info->description = ZH_WORDS_GETTER("housename.field.floor_num");
    }
    //µ¥ÔªºÅ
    DTO_FIELD(String, unit_num);
    DTO_FIELD_INFO(unit_num) {
        info->description = ZH_WORDS_GETTER("housename.field.unit_num");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif