
#pragma once
#ifndef _COMMUNITYVENUE_VO_
#define _COMMUNITYVENUE_VO_

#include "domain/GlobalInclude.h"
#include "../../dto/communityvenue/CommunityVenueDTO.h"
#include "../../dto/communityvenue/CommunityVenuePageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 场馆显示 JsonVO，用于响应给客户端的 Json 对象
 */
class CommunityVenueJsonVO : public JsonVO<CommunityVenueDTO::Wrapper> {
	DTO_INIT(CommunityVenueJsonVO, JsonVO<CommunityVenueDTO::Wrapper>);
};

/**
 * 场馆分页显示 JsonVO，用于响应给客户端的 Json 对象
 */
class CommunityVenuePageJsonVO : public JsonVO<CommunityVenuePageDTO::Wrapper> {
	DTO_INIT(CommunityVenuePageJsonVO, JsonVO<CommunityVenuePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _COMMUNITYVENUE_VO_
