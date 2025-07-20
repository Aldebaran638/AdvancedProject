#pragma once
#ifndef _REPAIRDONESERVICE_H_
#define _REPAIRDONESERVICE_H_
#include "domain/dto/repair-done/RepairDoneDTO.h"
#include "domain/query/repair-done/RepairDoneQuery.h"
#include "domain/vo/repair-done/RepairDoneVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RepairDoneService
{
public:
	// 分页查询所有数据 
	RepairDonePageDTO::Wrapper RepairDone_listAll(const RepairDoneQuery::Wrapper& query);
};

#endif // !_REPAIRDONESERVICE_H_