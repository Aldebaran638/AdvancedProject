#pragma once
#ifndef _HOUSE_DETAIL_QUERY_
#define _HOUSE_DETAIL_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseDetailQuery : public oatpp::DTO
{
    DTO_INIT(HouseDetailQuery, DTO);

    // 房屋ID
    DTO_FIELD(String, house_id);
    DTO_FIELD_INFO(house_id) {
        info->description = ZH_WORDS_GETTER("house.field.house_id");
        info->required = true;  // 设置为必填参数
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif