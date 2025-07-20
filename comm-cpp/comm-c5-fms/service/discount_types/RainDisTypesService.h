#pragma once
#ifndef _RAINDISTYPESSERVICE_H_
#define _RAINDISTYPESSERVICE_H_
#include "domain/vo/discount_types/RainDisTypesVO.h"
#include "domain/query/discount_types/RainDisTypesQuery.h"
#include "domain/dto/discount_types/RainDisTypesDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RainDisTypesService
{
public:
	// 分页查询所有数据
	RainDisTypesPageDTO::Wrapper listAll(const RainDisTypesQuery::Wrapper& query);
	// 通过ID查询单个数据
	//RainDisTypesDTO::Wrapper getByTypeId(std::string id);
	// 通过名称查询单个数据
	RainDisTypesPageDTO::Wrapper getByTypeName(std::string name);
	// 保存数据
	std::string saveData(const RainDisTypesAddDTO::Wrapper& dto);
};

#endif // !_RAINDISTYPESSERVICE_H_

