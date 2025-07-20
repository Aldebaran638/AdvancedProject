#pragma once
#ifndef _HOUSE_PAY_FEE_JSON_VO_
#define _HOUSE_PAY_FEE_JSON_VO_
#include "../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)
using namespace oatpp;
class AddHouseFeeJsonVO : public JsonVO<Int32>
{
	DTO_INIT(AddHouseFeeJsonVO, JsonVO <Int32>);
};
#include OATPP_CODEGEN_END(DTO)
#endif
