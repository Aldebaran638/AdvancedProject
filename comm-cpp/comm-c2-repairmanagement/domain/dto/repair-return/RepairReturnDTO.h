#pragma once
#ifndef _REPAIRRETURNDTO_H_
#define _REPAIRRETURNDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

// 定义一个添加报修回访反馈的数据模型
class RepairReturnAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairReturnAddDTO, DTO);
	// 小区id
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("repairreturn.repair-return.community_id"), true, "2024022647620054");

	// 工单编码
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairreturn.repair-return.repair_id"), true, "822025060191700286");

	// 满意度
	API_DTO_FIELD(String, visit_type, ZH_WORDS_GETTER("repairreturn.repair-return.visit_type"), true, "1001");
	// 回访内容
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairreturn.repair-return.context"), true, "good");

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};
//定义一个报修回访的数据传输模型
class RepairReturnDTO : public oatpp::DTO
{
	DTO_INIT(RepairReturnDTO, DTO);
	// 工单编码
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairreturn.repair-return.repair_id"));
	//位置
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairreturn.repair-return.repair_obj_name"));
	// 报修类型 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairreturn.repair-return.repair_type"));
	// 报修类型-中文映射 
	API_DTO_FIELD_DEFAULT(String, repair_type_detail, ZH_WORDS_GETTER("repairreturn.repair-return.repair_type_detail"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairreturn.repair-return.repair_name"));
	// 联系方式
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairreturn.repair-return.tel"));
	// 预约时间
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairreturn.repair-return.appointment_time"));
	// 回访状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairreturn.repair-return.state"));
	//报修状态-中文映射
	API_DTO_FIELD_DEFAULT(String, state_detail, ZH_WORDS_GETTER("repairreturn.repair-return.state_detail"));
	// 满意度
	//API_DTO_FIELD_DEFAULT(String, visit_type, ZH_WORDS_GETTER("repairreturn.repair-return.visit_type"));
	// 回访内容
	//API_DTO_FIELD_DEFAULT(String, context, ZH_WORDS_GETTER("repairreturn.repair-return.context"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 定义一个报修回访单分页传输对象
 */
class RepairReturnPageDTO : public PageDTO<RepairReturnDTO::Wrapper>
{
	DTO_INIT(RepairReturnPageDTO, PageDTO<RepairReturnDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRRETURNDTO_H_