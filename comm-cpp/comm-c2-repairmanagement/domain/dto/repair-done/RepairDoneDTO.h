#pragma once
#ifndef _REPAIRDONE_DTO_
#define _REPAIRDONE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 报修已办传输对象
class RepairDoneDTO : public oatpp::DTO
{
	DTO_INIT(RepairDoneDTO, DTO);
	// 工单编码
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairdone.repair-done.repair_id"));
	//位置
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairdone.repair-done.repair_obj_name"));
	// 报修类型 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairdone.repair-done.repair_type"));
	// 报修类型-中文映射 
	API_DTO_FIELD_DEFAULT(String, repair_type_detail, ZH_WORDS_GETTER("repairdone.repair-done.repair_type_detail"));
	// 维修类型 
	API_DTO_FIELD_DEFAULT(String, maintenance_type, ZH_WORDS_GETTER("repairdone.repair-done.maintenance_type"));
	// 维修类型-中文映射 
	API_DTO_FIELD_DEFAULT(String, maintenance_type_detail, ZH_WORDS_GETTER("repairdone.repair-done.maintenance_type_detail"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairdone.repair-done.repair_name"));
	//联系方式
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairdone.repair-done.tel"));
	//预约时间
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairdone.repair-done.appointment_time"));
	//报修状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairdone.repair-done.state"));

	//报修状态-中文映射
	API_DTO_FIELD_DEFAULT(String, state_detail, ZH_WORDS_GETTER("repairdone.repair-done.state_detail"));
	//位置-中文映射
	//API_DTO_FIELD_DEFAULT(String, repair_obj_name_detail, ZH_WORDS_GETTER("repairdone.repair-done.repair_obj_name_detail"));


};

// 报修已办分页传输对象
class RepairDonePageDTO : public PageDTO<RepairDoneDTO::Wrapper>
{
	DTO_INIT(RepairDonePageDTO, PageDTO<RepairDoneDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // ! _REPAIRDONE_DTO_