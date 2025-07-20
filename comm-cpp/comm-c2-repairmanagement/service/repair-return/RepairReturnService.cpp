#include "stdafx.h"
#include "RepairReturnService.h"
#include "../../dao/repair-return/RepairReturnDAO.h" 
#include "id/UuidFacade.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
//查询条件封装
RepairReturnPageDTO::Wrapper RepairReturnService::RepairReturn_listAll(const RepairReturnQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairReturnPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RepairReturnDAO dao;
	uint64_t count = dao.RepairReturn_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RepairReturnDO> result = dao.RepairReturn_selectWithPage(query);
	// 将DO转换成DTO
	for (RepairReturnDO sub : result)
	{
		auto dto = RepairReturnDTO::createShared();
		//查询结果字段
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id, RepairId, repair_obj_name, RepairObjName, repair_type, RepairType, repair_type_detail, RepairTypeDetail,
			repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime, state, State, state_detail, StateDetail);
		pages->addData(dto);
	}
	return pages;
}

//添加数据--持久化保存到数据库
std::string RepairReturnService::RepairReturn_saveData(const RepairReturnAddDTO::Wrapper& dto)
{
	//雪花算法
	SnowFlake snowFlake(1, 1);
	//PayloadDTO p;
	// 组装DO数据
	RepairReturnDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CommunityId, community_id, RepairId, repair_id, VisitType, visit_type, Context, context);
	// 生成工单编码ID
	//UuidFacade uf;
	//data.setRepairId(uf.genUuid());
	//SnowFlake sf(8,2);
	//data.setRepairId(std::to_string(sf.nextId()));
	//insert_data1.setBId(to_string(snowFlake.nextId()));
	data.setVisitId(to_string(snowFlake.nextId()));
	data.setVisitPersonId(to_string(snowFlake.nextId()));
	data.setVisitPersonName(dto->getPayload()->getUsername());
	data.setCreateTime(SimpleDateTimeFormat::format());
	data.setStatusCd("0");
	// 设置创建人
	//data.setRepairName(dto->getPayload()->getUsername());
	// 设置创建时间
	//data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	RepairReturnDAO dao;
	return dao.RepairReturn_insert(data) == 1 ? data.getRepairId() : "";
}
