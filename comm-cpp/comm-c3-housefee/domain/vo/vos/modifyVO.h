#pragma once
#ifndef  _MODIFYVO_H_
#define  _MODIFYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/dtos/modifyDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
	

class modifyJsonVO :public JsonVO<modifyDTO::Wrapper> {
	DTO_INIT(modifyJsonVO, JsonVO<modifyDTO::Wrapper>);
};
class modifyPageJsonVO : public JsonVO<modifyPageDTO::Wrapper> {
	DTO_INIT(modifyPageJsonVO, JsonVO<modifyPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif