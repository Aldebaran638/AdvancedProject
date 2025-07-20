#pragma once
#ifndef _HOUSENAME_VO_
#define _HOUSENAME_VO_

#include "../../GlobalInclude.h"
#include "../../dto/HouseName/HouseNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseNameJsonVO : public JsonVO<oatpp::List<HouseNameDTO::Wrapper>>
{
    DTO_INIT(HouseNameJsonVO, JsonVO<oatpp::List<HouseNameDTO::Wrapper>>)
};


#include OATPP_CODEGEN_END(DTO)

#endif