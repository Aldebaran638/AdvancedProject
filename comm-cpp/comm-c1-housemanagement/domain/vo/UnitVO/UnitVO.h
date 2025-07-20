#pragma once
#ifndef _UNIT_VO_
#define _UNIT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/UnitDTO/UnitDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnitJsonVO : public JsonVO<UnitDTO::Wrapper>
{
	DTO_INIT(UnitJsonVO, JsonVO<UnitDTO::Wrapper>)
};

class UnitPageJsonVO : public JsonVO<UnitPageDTO::Wrapper>
{
	DTO_INIT(UnitPageJsonVO, JsonVO<UnitPageDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif