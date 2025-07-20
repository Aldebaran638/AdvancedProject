#pragma once
#ifndef _REPAIRRETURNSERVICE_H_
#define _REPAIRRETURNSERVICE_H_
#include "domain/dto/repair-return/RepairReturnDTO.h"
#include "domain/query/repair-return/RepairReturnQuery.h"
#include "domain/vo/repair-return/RepairReturnVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RepairReturnService
{
public:
	// 分页查询所有数据 
	RepairReturnPageDTO::Wrapper RepairReturn_listAll(const RepairReturnQuery::Wrapper& query);
	// 保存数据
	std::string RepairReturn_saveData(const RepairReturnAddDTO::Wrapper& dto);
	// 修改数据
	bool RepairReturn_updateData(const RepairReturnDTO::Wrapper& dto);
};

#endif // !_REPAIRRETURNSERVICE_H_