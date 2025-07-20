#pragma once
#ifndef _REPAIRWORKERVO_H_
#define _REPAIRWORKERVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/repair-worker/RepairWorkerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个维修师傅信息显示JsonVO对象，用于响应给客户端
 */
class RepairWorkerQueryJsonVO : public JsonVO<RepairWorkerQueryDTO::Wrapper>
{
	DTO_INIT(RepairWorkerQueryJsonVO, JsonVO<RepairWorkerQueryDTO::Wrapper>);
};

/**
 * 定义一个维修师傅信息分页显示JsonVO对象，用于响应给客户端
 */
class RepairWorkerPageJsonVO : public JsonVO<RepairWorkerPageDTO::Wrapper>
{
	DTO_INIT(RepairWorkerPageJsonVO, JsonVO<RepairWorkerPageDTO::Wrapper>);
};

//修改师傅状态VO
class RepairWorkerModifyJsonVO : public JsonVO<RepairWorkerModifyDTO::Wrapper> {
	DTO_INIT(RepairWorkerModifyJsonVO, JsonVO<RepairWorkerModifyDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRWORKERVO_H_