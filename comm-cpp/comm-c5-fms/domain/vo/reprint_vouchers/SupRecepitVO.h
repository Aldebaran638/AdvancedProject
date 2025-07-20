#pragma once
#ifndef _SUP_RECEPIT_VO_
#define _SUP_RECEPIT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/reprint_vouchers/SupRecepitDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SupRecepitJsonVO : public JsonVO<SupRecepitDTO::Wrapper> {
	DTO_INIT(SupRecepitJsonVO, JsonVO<SupRecepitDTO::Wrapper>);
};

class SupRecepitPageJsonVO : public JsonVO<SupRecepitPageDTO::Wrapper> {
	DTO_INIT(SupRecepitPageJsonVO, JsonVO<SupRecepitPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
