#pragma once

#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "../dto/CommunitySpaceMgrDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class CommunitySpaceMgrJsonVO : public JsonVO<CommunitySpaceMgrDTO::Wrapper> {
	DTO_INIT(CommunitySpaceMgrJsonVO, JsonVO<CommunitySpaceMgrDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class CommunitySpaceMgrPageJsonVO : public JsonVO<CommunitySpaceMgrPageDTO::Wrapper> {
	DTO_INIT(CommunitySpaceMgrPageJsonVO, JsonVO<CommunitySpaceMgrPageDTO::Wrapper>);
};



/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class CommunitySpaceTimeMgrJsonVO : public JsonVO<CommunitySpaceTimeMgrDTO::Wrapper> {
	DTO_INIT(CommunitySpaceTimeMgrJsonVO, JsonVO<CommunitySpaceTimeMgrDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class CommunitySpaceTimeMgrPageJsonVO : public JsonVO<CommunitySpaceTimeMgrPageDTO::Wrapper> {
	
	DTO_INIT(CommunitySpaceTimeMgrPageJsonVO, JsonVO<CommunitySpaceTimeMgrPageDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

