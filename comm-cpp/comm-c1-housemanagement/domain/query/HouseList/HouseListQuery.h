#pragma once
#ifndef _HOUSELIST_QUERY_
#define _HOUSELIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseListQuery : public PageQuery
{
    DTO_INIT(HouseListQuery, PageQuery);

    //Â¥¶°ºÅ(±ØÌî)
    DTO_FIELD(String, floor_num);
    DTO_FIELD_INFO(floor_num) {
        info->description = ZH_WORDS_GETTER("houselist.field.floor_num");
        info->required = true;
    }
    //µ¥ÔªºÅ
    DTO_FIELD(String, unit_num);
    DTO_FIELD_INFO(unit_num) {
        info->description = ZH_WORDS_GETTER("houselist.field.unit_num");
    }
    //·¿ÎÝID
    DTO_FIELD(String, house_id);
    DTO_FIELD_INFO(house_id) {
        info->description = ZH_WORDS_GETTER("houselist.field.house_id");
    }
    //·¿ÎÝ×´Ì¬
    DTO_FIELD(String, status_cd);
    DTO_FIELD_INFO(status_cd) {
        info->description = ZH_WORDS_GETTER("houselist.field.status_cd");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif