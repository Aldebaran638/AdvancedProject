#pragma once
#ifndef _EXPEDETVO_H_
#define _EXPEDETVO_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../GlobalInclude.h"
#include "../../dto/expedet/ExpeDetDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO) 

/**
 * 房屋费用明细VO对象
 */
class BuildingExpedetJsonVO : public JsonVO<BuildingExpedetDTO::Wrapper>
{
    DTO_INIT(BuildingExpedetJsonVO, JsonVO<BuildingExpedetDTO::Wrapper>);
};

/**
 * 房屋费用明细分页显示JsonVO对象，用于响应给客户端
 */
class BuildingExpedetPageJsonVO : public JsonVO<BuildingExpedetPageDTO::Wrapper>
{
    DTO_INIT(BuildingExpedetPageJsonVO, JsonVO<BuildingExpedetPageDTO::Wrapper>);
};

/**
 * 业主费用明细VO对象
 */
class OwnerExpedetJsonVO : public JsonVO<OwnerExpedetDTO::Wrapper>
{
    DTO_INIT(OwnerExpedetJsonVO, JsonVO<OwnerExpedetDTO::Wrapper>);
};

/**
 * 业主费用明细分页显示JsonVO对象，用于响应给客户端
 */
class OwnerExpedetPageJsonVO : public JsonVO<OwnerExpedetPageDTO::Wrapper>
{
    DTO_INIT(OwnerExpedetPageJsonVO, JsonVO<OwnerExpedetPageDTO::Wrapper>);
};

/**
 * 合同费用明细VO对象
 */
class ContractExpedetJsonVO : public JsonVO<ContractExpedetDTO::Wrapper>
{
    DTO_INIT(ContractExpedetJsonVO, JsonVO<ContractExpedetDTO::Wrapper>);
};

/**
 * 合同费用明细分页显示JsonVO对象，用于响应给客户端
 */
class ContractExpedetPageJsonVO : public JsonVO<ContractExpedetPageDTO::Wrapper>
{
    DTO_INIT(ContractExpedetPageJsonVO, JsonVO<ContractExpedetPageDTO::Wrapper>);
};

/**
 * 车辆费用明细VO对象
 */
class CarExpedetJsonVO : public JsonVO<CarExpedetDTO::Wrapper>
{
    DTO_INIT(CarExpedetJsonVO, JsonVO<CarExpedetDTO::Wrapper>);
};

/**
 * 车辆费用明细分页显示JsonVO对象，用于响应给客户端
 */
class CarExpedetPageJsonVO : public JsonVO<CarExpedetPageDTO::Wrapper>
{
    DTO_INIT(CarExpedetPageJsonVO, JsonVO<CarExpedetPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif