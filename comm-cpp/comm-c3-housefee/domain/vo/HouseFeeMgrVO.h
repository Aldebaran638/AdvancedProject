#pragma once
#ifndef _HOUSEFEEMGRVO_H_
#define _HOUSEFEEMGRVO_H_
#include "../GlobalInclude.h"
#include "../dto/HouseFeeMgrDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 房屋费用显示JsonVO，用于响应给客户端的Json对象
 */
class HouseFeeMgrJsonVO : public JsonVO<HouseFeeMgrDTO::Wrapper> {
	DTO_INIT(HouseFeeMgrJsonVO, JsonVO<HouseFeeMgrDTO::Wrapper>);
};

/**
 * 房屋费用分页显示JsonVO，用于响应给客户端的Json对象
 */
class HouseFeeMgrPageJsonVO : public JsonVO<HouseFeeMgrPageDTO::Wrapper> {
	DTO_INIT(HouseFeeMgrPageJsonVO, JsonVO<HouseFeeMgrPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_HOUSEFEEMGRVO_H_
