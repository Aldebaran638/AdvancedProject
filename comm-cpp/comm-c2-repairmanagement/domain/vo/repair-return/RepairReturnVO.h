#pragma once
#ifndef _REPAIRRETURNVO_H_
#define _REPAIRRETURNVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/repair-return/RepairReturnDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个回访单列表显示JsonVO对象，用于响应给客户端
 */
class RepairReturnJsonVO : public JsonVO<RepairReturnDTO::Wrapper>
{
	DTO_INIT(RepairReturnJsonVO, JsonVO<RepairReturnDTO::Wrapper>);
};

/**
 * 定义一个回访单列表分页显示JsonVO对象，用于响应给客户端
 */
class RepairReturnPageJsonVO : public JsonVO<RepairReturnPageDTO::Wrapper>
{
	DTO_INIT(RepairReturnPageJsonVO, JsonVO<RepairReturnPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRRETURNVO_H_