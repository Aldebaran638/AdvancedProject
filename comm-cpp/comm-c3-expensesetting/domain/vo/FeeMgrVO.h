#pragma once
#ifndef _FEEMGRVO_H_
#define _FEEMGRVO_H_
#include "../GlobalInclude.h"
#include "../dto/FeeMgrDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 房屋费用显示JsonVO，用于响应给客户端的Json对象
 */
class FeeMgrJsonVO : public JsonVO<FeeMgrDTO::Wrapper> {
	DTO_INIT(FeeMgrJsonVO, JsonVO<FeeMgrDTO::Wrapper>);
};

/**
 * 房屋费用分页显示JsonVO，用于响应给客户端的Json对象
 */
class FeeMgrPageJsonVO : public JsonVO<FeeMgrPageDTO::Wrapper> {
	DTO_INIT(FeeMgrPageJsonVO, JsonVO<FeeMgrPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_FEEMGRVO_H_
