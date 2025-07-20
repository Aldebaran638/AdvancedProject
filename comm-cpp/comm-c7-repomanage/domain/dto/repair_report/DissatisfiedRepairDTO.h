#pragma once
#ifndef _DISSATISFIEDREPAIRDTO_H_
#define _DISSATISFIEDREPAIRDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 报修不满意数据传输对象
*/
class DissatisfiedRepairDTO : public oatpp::DTO
{
	DTO_INIT(DissatisfiedRepairDTO, DTO);
	// 报修时间 repair-time
	API_DTO_FIELD_DEFAULT(String, repair_time, ZH_WORDS_GETTER("dissatisfied-repair.field.repair-time"));
	
	// 报修位置 repair-location
	API_DTO_FIELD_DEFAULT(String, repair_location, ZH_WORDS_GETTER("dissatisfied-repair.field.repair-location"));

	// 报修单号 repair-id
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("dissatisfied-repair.field.repair-id"));

	// 状态 status
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("dissatisfied-repair.field.status"));

	// 不满意原因 reason
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("dissatisfied-repair.field.reason"));
};

/**
* 报修不满意分页数据传输对象
*/
class DissatisfiedRepairPageDTO : public PageDTO<DissatisfiedRepairDTO::Wrapper>
{
	DTO_INIT(DissatisfiedRepairPageDTO, PageDTO<DissatisfiedRepairDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DISSATISFIEDREPAIRDTO_H_