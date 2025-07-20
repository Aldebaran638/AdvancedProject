#pragma once

#ifndef _CAR_VO_
#define _CAR_VO_

#include "../../GlobalInclude.h"
#include "../../dto/car/CarDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 车辆信息显示JsonVO，用于响应给客户端的Json对象
 */
class CarJsonVO :public JsonVO<CarDTO::Wrapper> {
	DTO_INIT(CarJsonVO, JsonVO<CarDTO::Wrapper>);
};
/**
 * 车辆信息分页显示JsonVO，用于响应给客户端的Json对象
 */
class CarPageJsonVO :public JsonVO<CarPageDTO::Wrapper> {
	DTO_INIT(CarPageJsonVO, JsonVO<CarPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif