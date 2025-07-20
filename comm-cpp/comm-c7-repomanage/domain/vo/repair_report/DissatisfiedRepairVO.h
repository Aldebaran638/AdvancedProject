#pragma once

#ifndef _DISSATISFIEDREPAIRVO_H_
#define _DISSATISFIEDREPAIRVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/repair_report/DissatisfiedRepairDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修不满意显示JsonVO，用于响应给客户端的Json对象
 */
class DissatisfiedRepairJsonVO : public JsonVO<DissatisfiedRepairDTO::Wrapper> {
	DTO_INIT(DissatisfiedRepairJsonVO, JsonVO<DissatisfiedRepairDTO::Wrapper>);
};

/**
 * 报修不满意分页显示JsonVO，用于响应给客户端的Json对象
 */
class DissatisfiedRepairPageJsonVO : public JsonVO<DissatisfiedRepairPageDTO::Wrapper> {
	DTO_INIT(DissatisfiedRepairPageJsonVO, JsonVO<DissatisfiedRepairPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DISSATISFIEDREPAIRVO_H_