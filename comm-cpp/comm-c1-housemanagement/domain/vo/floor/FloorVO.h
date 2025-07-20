#pragma

#ifndef _FLOORVO_H_
#define _FLOORVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/floor/FloorDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个楼栋信息显示JsonVO对象，用于响应给客户端
 */
class FloorJsonVO : public JsonVO<FloorDTO::Wrapper>
{
	DTO_INIT(FloorJsonVO, JsonVO<FloorDTO::Wrapper>);
};

/*
 * 定义一个楼栋信息分页显示JsonVO对象，用于响应给客户端
 */
class FloorPageJsonVO :public JsonVO<FloorPageDTO::Wrapper>
{
	DTO_INIT(FloorPageJsonVO, JsonVO<FloorPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FLOORVO_H_