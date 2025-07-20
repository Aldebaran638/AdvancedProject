#pragma once
#ifndef _REPAIRWORKERNAMESERVICE_H_
#define _REPAIRWORKERNAMESERVICE_H_
#include "domain/vo/repair-worker/RepairWorkerVO.h"
#include "domain/query/repair-worker/RepairWorkerQuery.h"
#include "domain/dto/repair-worker/RepairWorkerDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RepairWorkerService
{
public:
	// 分页查询所有数据
	RepairWorkerPageDTO::Wrapper listAll(const RepairWorkerQuery::Wrapper& query);
	// 修改数据
	bool updateData(const RepairWorkerModifyDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String>& ids);
	// 保存数据
	std::string saveData(const RepairWorkerAddDTO::Wrapper& dto);
};

#endif 