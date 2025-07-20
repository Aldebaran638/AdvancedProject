#pragma once
#ifndef _HOUSESELECT_VO_
#define _HOUSESELECT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/HouseSelect/HouseSelectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseSelectJsonVO : public JsonVO<HouseSelectDTO::Wrapper>
{
    DTO_INIT(HouseSelectJsonVO, JsonVO<HouseSelectDTO::Wrapper>)
};

class HouseSelectPageJsonVO : public JsonVO<HouseSelectPageDTO::Wrapper>
{
    DTO_INIT(HouseSelectPageJsonVO, JsonVO<HouseSelectPageDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif