#pragma once
#ifndef  _REMITFEEVO_H_
#define  _REMITFEEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/dtos/RemitFeeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class RemitFeeJsonVO :public JsonVO<RemitFeeDTO::Wrapper> {
	DTO_INIT(RemitFeeJsonVO, JsonVO<RemitFeeDTO::Wrapper>);
};
class RemitFeePageJsonVO : public JsonVO<RemitFeePageDTO::Wrapper> {
	DTO_INIT(RemitFeePageJsonVO, JsonVO<RemitFeePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif