#pragma once
#ifndef _HOUSELIST_VO_
#define _HOUSELIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/HouseList/HouseListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseListJsonVO : public JsonVO<HouseListDTO::Wrapper>
{
    DTO_INIT(HouseListJsonVO, JsonVO<HouseListDTO::Wrapper>)
};

class HouseListPageJsonVO : public JsonVO<HouseListPageDTO::Wrapper>
{
    DTO_INIT(HouseListPageJsonVO, JsonVO<HouseListPageDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif