#pragma once
#ifndef _OERPAYDETVO_H_
#define _OERPAYDETVO_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/oerpaydet/OerPayDetDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//业主缴费明细显示JsonVO，用于响应给客户端的Json对象

class OerPayDetJsonVO : public JsonVO<OerPayDetDetailDTO::Wrapper> {
	DTO_INIT(OerPayDetJsonVO, JsonVO<OerPayDetDetailDTO::Wrapper>);
};

//业主缴费明细分页显示JsonVO，用于响应给客户端的Json对象

class OerPayDetPageJsonVO : public JsonVO<OerPayDetPageDTO::Wrapper> {
	DTO_INIT(OerPayDetPageJsonVO, JsonVO<OerPayDetPageDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif