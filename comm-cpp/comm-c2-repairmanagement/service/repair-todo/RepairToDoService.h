#pragma once
#ifndef _REPAIRTODO_SERVICE_
#define _REPAIRTODO_SERVICE_
#include "domain/vo/repair-todo/RepairToDoVO.h"
#include "domain/query/repair-todo/RepairToDoQuery.h"
#include "domain/dto/repair-todo/RepairToDoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RepairToDoService
{
public:
	// 分页查询所有数据
	RepairToDoPageDTO::Wrapper listAll(const RepairToDoQuery::Wrapper& query);
	// 分页查询维修类型所有数据
	RepairToDoQueryAllRepairTypePageDTO::Wrapper listAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& query);

	// 分页查询报修师傅所有数据
	RepairToDoQueryAllStaffPageDTO::Wrapper listAllStaffByStaffType(const RepairToDoStaffNameQuery::Wrapper& query);

	// 改单：修改数据
	bool ModifyDataToTransferBill(const RepairToDoUpdateDTO::Wrapper& dto);

	// 暂停：也是修改并新增数据
	bool ModifyDataToSuspend(const RepairToDoUpdateToSuspendDTO::Wrapper& dto);

	// 退单：修改数据并新增退单数据
	bool ModifyDataToRemove(const RepairToDoUpdateToRemoveDTO::Wrapper& dto);

	// 办结：修改数据并新增办结数据
	bool ModifyDataToFinish(const RepairToDoUpdateToFinishDTO::Wrapper& dto);

};

#endif // !_REPAIRTODO_SERVICE_

