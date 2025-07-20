#include "stdafx.h"
#include "TaskListService.h"
#include "../../dao/task-list/TaskListDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

TaskListPageDTO::Wrapper TaskListService::listAll(const TaskListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TaskListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	TaskListDAO dao;
	uint64_t count = dao.count_r_repair_pool(query);

	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();

	list<TaskListDO> result = dao.selectWithPage_r_repair_pool(query);

	// 将DO转换成DTO
	for (TaskListDO sub : result)
	{
		auto dto = TaskListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id, RepairId, repair_obj_name, RepairObjName, repair_type, RepairTypeName,
			maintenance_type, MaintenanceTypeName, repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime,
			create_time, CreateTime, state, StateName, maintenance_type_txt, MaintenanceTypeTxt, state_txt, StateTxt);

		pages->addData(dto);
	}
	return pages;
}

std::string TaskListService::removeData(const TaskListGetIdDTO::Wrapper& dto)
{
	// 组装DO数据
	TaskListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairId, repair_id);
	// 执行数据删除
	TaskListDAO dao;
	return dao.deleteById_r_repair_pool(data) == 1 ? data.getRepairId() : "";
}

std::string TaskListService::updateData(const TaskListUpdateDTO::Wrapper& dto)
{
	// 组装DO数据
	TaskListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairTypeName, repair_type, CommunityId, community_id,RepairName, repair_name,
		Tel, tel, AppointmentTime, appointment_time, Context,context, RepairId, repair_id);
	// 执行数据修改
	TaskListDAO dao;
	return dao.update_r_repair_pool(data) == 1 ? data.getRepairId() : "";
}




