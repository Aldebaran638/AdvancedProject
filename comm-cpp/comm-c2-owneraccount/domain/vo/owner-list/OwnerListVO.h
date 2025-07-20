#pragma once
#ifndef _OWNERLISTVO_H_
#define _OWNERLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/owner-list/OwnerListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 账户列表显示JsonVO对象，用于响应给客户端
 */
class OwnerListJsonVO : public JsonVO<OwnerListDTO::Wrapper>
{
	DTO_INIT(OwnerListJsonVO, JsonVO<OwnerListDTO::Wrapper>);
};

/**
 * 账户列表分页显示JsonVO对象，用于响应给客户端
 */
class OwnerListPageJsonVO : public JsonVO<OwnerListPageDTO::Wrapper>
{
	DTO_INIT(OwnerListPageJsonVO, JsonVO<OwnerListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERLISTVO_H_
