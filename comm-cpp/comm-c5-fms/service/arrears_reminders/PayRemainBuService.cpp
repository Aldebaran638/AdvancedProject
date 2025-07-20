#include "PayRemainBuService.h"
#include "stdafx.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "../../dao/arrears_reminders/PayRemainBuDAO.h"
// 分页查询所有数据
PayRemainQuBuPageDTO::Wrapper PayRemainBuService::listALL(const PayRemainBuQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PayRemainQuBuPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PayRemainBuDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PayRemainBuDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PayRemainBuDO sub : result)
	{
		auto dto = PayRemainQuBuDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ofc_id, Ofc_Id);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owner_name, Owner_Name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, payer_obj_name, Payer_Obj_Name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_name, Fee_Name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, amountd_owed, Amountd_Owed);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, start_time, Start_Time);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, callable_way, Callable_Way);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, staff_name, Staff_Name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, state, State);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, remark, Remark);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, create_time, Create_Time);
		pages->addData(dto);
	}
	return pages;
}
// 增加数据
std::string PayRemainBuService::saveData(const PayRemainBuDTO::Wrapper& dto)
{
	// 组装DO数据
	PayRemainBuDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Owner_Name, owner_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Payer_Obj_Name, payer_obj_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Fee_Name, fee_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Amountd_Owed, amountd_owed);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Start_Time, start_time);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Callable_Way, callable_way);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Staff_Name, staff_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, State, state);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Remark, remark);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Create_Time, create_time);
	// 添加新字段的映射
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Community_Id, community_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Owner_Id, owner_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Payer_Obj_Id, payer_obj_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Config_Id, config_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Fee_Id, fee_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Payer_Obj_Type, payer_obj_type);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Staff_Id, staff_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, End_Time, end_time);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Status_Cd, status_cd);
	// 使用雪花算法生成UUId
	SnowFlake sf(1, 1);
	data.setOfc_Id(sf.nextId());
	// 设置创建人
	data.setOwner_Name(dto->getPayload()->getUsername());
	// 设置创建时间
	//data.setCreate_Time(SimpleDateTimeFormat::format());
	// 执行数据添加
	PayRemainBuDAO dao;
	return dao.insert(data) == 1 ? to_string(data.getOfc_Id()) : "";
}