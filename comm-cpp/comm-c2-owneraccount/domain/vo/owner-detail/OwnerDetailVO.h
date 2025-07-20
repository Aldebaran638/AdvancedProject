#pragma once
#ifndef _OWNERDETAILVO_H_
#define _OWNERDETAILVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/owner-detail/OwnerDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加预存（账户明细）显示JsonVO对象，用于响应给客户端
 */
class OwnerDetailJsonVO : public JsonVO<OwnerDetailDTO::Wrapper>
{
	DTO_INIT(OwnerDetailJsonVO, JsonVO<OwnerDetailDTO::Wrapper>);
};

/**
 * 添加预存（账户明细）分页显示JsonVO对象，用于响应给客户端
 */
class OwnerDetailPageJsonVO : public JsonVO<OwnerDetailPageDTO::Wrapper>
{
	DTO_INIT(OwnerDetailPageJsonVO, JsonVO<OwnerDetailPageDTO::Wrapper>);
};

/**
 * 业主名称（预存）显示JsonVO对象，用于响应给客户端
 */
class OwnerDetailAccountNameJsonVO : public JsonVO<OwnerDetailAccountNameDTO::Wrapper>
{
	DTO_INIT(OwnerDetailAccountNameJsonVO, JsonVO<OwnerDetailAccountNameDTO::Wrapper>);
};

/**
 * 业主名称（预存）分页显示JsonVO对象，用于响应给客户端
 */
class OwnerDetailAccountNamePageJsonVO : public JsonVO<OwnerDetailAccountNamePageDTO::Wrapper>
{
	DTO_INIT(OwnerDetailAccountNamePageJsonVO, JsonVO<OwnerDetailAccountNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERDETAILVO_H_
