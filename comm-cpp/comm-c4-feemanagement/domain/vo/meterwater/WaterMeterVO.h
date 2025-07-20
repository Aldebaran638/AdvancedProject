#pragma once
#ifndef _WATERMETERVO_H_
#define _WATERMETERVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/meterwater/WaterMeterDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个水电抄表信息显示JsonVO对象，用于响应给客户端
 */
class WaterMeterJsonVO : public JsonVO<WaterMeterDTO::Wrapper>
{
	DTO_INIT(WaterMeterJsonVO, JsonVO<WaterMeterDTO::Wrapper>);
};

/**
 * 定义一个水电抄表信息分页显示JsonVO对象，用于响应给客户端
 */
class WaterMeterPageJsonVO : public JsonVO<WaterMeterPageDTO::Wrapper>
{
	DTO_INIT(WaterMeterPageJsonVO, JsonVO<WaterMeterPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _WATERMETERVO_H_