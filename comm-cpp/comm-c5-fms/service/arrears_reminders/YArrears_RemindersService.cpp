#include "stdafx.h"
#include "YArrears_RemindersService.h"
#include "../../dao/arrears_reminders/YArrears_RemindersDAO.h"
#include "id/UuidFacade.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "../../../arch-demo/Macros.h"

// 催缴登录
std::string YArrears_RemindersService::addData(const YArrears_RemindersAddDTO::Wrapper& dto)
{
	// 组装DO数据
	YArrears_RemindersDO data;
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
	// 执行数据添加
	YArrears_RemindersDAO dao;
	return dao.add(data) == 1 ? to_string(data.getOfc_Id()) : "";
}