#pragma once
#ifndef _REPAIRWORKERNAMEVO_H_
#define _REPAIRWORKERNAMEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/repair-worker-name/RepairWorkerNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//师傅姓名列表VO
class RepairWorkerNameJsonVO : public JsonVO<RepairWorkerNameDTO::Wrapper> {
	DTO_INIT(RepairWorkerNameJsonVO, JsonVO<RepairWorkerNameDTO::Wrapper>);
};
class RepairWorkerNamePageJsonVO : public JsonVO<RepairWorkerNamePageDTO::Wrapper> {
	DTO_INIT(RepairWorkerNamePageJsonVO, JsonVO<RepairWorkerNamePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRWORKERNAMEVO_H_