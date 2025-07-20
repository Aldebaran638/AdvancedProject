#pragma once
#ifndef _HOUSE_DETAIL_VO_
#define _HOUSE_DETAIL_VO_

#include "../../GlobalInclude.h"
#include "../../dto/HouseDetail/HouseDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseDetailJsonVO : public JsonVO<HouseDetailDTO::Wrapper>
{
    DTO_INIT(HouseDetailJsonVO, JsonVO<HouseDetailDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif