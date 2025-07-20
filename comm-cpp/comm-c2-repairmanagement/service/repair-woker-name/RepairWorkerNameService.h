#pragma once
#ifndef _REPAIRWORKERNAMESERVICE_
#define _REPAIRWORKERNAMESERVICE_
#include "domain/vo/repair-worker-name/RepairWorkerNameVO.h"
#include "domain/query/repair-worker-name/RepairWorkerNameQuery.h"
#include "domain/dto/repair-worker-name/RepairWorkerNameDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RepairWorkerNameService
{
public:
	// 查询所有维修师傅姓名
	RepairWorkerNamePageDTO::Wrapper listAll(const RepairWorkerNameQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_