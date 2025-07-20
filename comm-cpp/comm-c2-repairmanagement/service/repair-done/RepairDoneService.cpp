#include "stdafx.h"
#include "RepairDoneService.h"
#include "../../dao/repair-done/RepairDoneDAO.h" 
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
//多表联查 r_repair_pool表、r_repair_setting表、t_dict表 
RepairDonePageDTO::Wrapper RepairDoneService::RepairDone_listAll(const RepairDoneQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairDonePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RepairDoneDAO dao;
	uint64_t count = dao.RepairDone_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RepairDoneDO> result = dao.RepairDone_selectWithPage(query);
	// 将DO转换成DTO
	for (RepairDoneDO sub : result)
	{
		auto dto = RepairDoneDTO::createShared();
		//查询结果字段
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id, RepairId, repair_obj_name, RepairObjName, repair_type, RepairType, repair_type_detail, RepairTypeDetail,
			maintenance_type, MaintenanceType, maintenance_type_detail, MaintenanceTypeDetail, repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime, state, State, state_detail, StateDetail);
		pages->addData(dto);
	}
	return pages;
}
