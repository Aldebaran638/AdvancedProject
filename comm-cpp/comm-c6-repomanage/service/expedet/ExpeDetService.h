#pragma once



#ifndef _EXPEDET_SERVICE
#define _EXPEDET_SERVICE


#include "../../domain/dto/expedet/ExpeDetDTO.h"
#include "../../domain/vo/expedet/ExpeDetVO.h"
#include "../../domain/query/expedet/ExpeDetQuery.h"

/**
 * 房屋费用明细服务实现
 */
class ExpedetBuildingFeeDetailService
{
public:
	// 分页查询所有数据
	BuildingExpedetPageDTO::Wrapper listAll(const ExpedetBuildingFeeDetailQuery::Wrapper& query);
};

/**
 * 业主费用明细服务实现
 */
class ExpedetOwnerFeeDetailService
{
public:
	// 分页查询所有数据
	OwnerExpedetPageDTO::Wrapper listAll(const ExpedetOwnerFeeDetailQuery::Wrapper& query);
};

/**
 * 合同费用明细服务实现
 */
class ExpedetContractFeeDetailService
{
public:
	// 分页查询所有数据
	ContractExpedetPageDTO::Wrapper listAll(const ExpedetContractFeeDetailQuery::Wrapper& query);
};

/**
 * 车辆费用明细服务实现
 */
class ExpedetCarFeeDetailService
{
public:
	// 分页查询所有数据
	CarExpedetPageDTO::Wrapper listAll(const ExpedetCarFeeDetailQuery::Wrapper& query);
};



#endif