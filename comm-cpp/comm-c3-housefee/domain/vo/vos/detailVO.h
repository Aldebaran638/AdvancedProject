#pragma once
#ifndef  _DETAILVO_H_
#define  _DETAILVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/dtos/detailDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class detailJsonVO :public JsonVO<detailDTO::Wrapper> {
	DTO_INIT(detailJsonVO, JsonVO<detailDTO::Wrapper>);
};
class detailPageJsonVO : public JsonVO<detailPageDTO::Wrapper> {
	DTO_INIT(detailPageJsonVO, JsonVO<detailPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif