#pragma once
#ifndef _REPAIRWORKERNAMEDTO_H_
#define _REPAIRWORKERNAMEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个显示报修师傅名称列表请求的数据传输模型
 */
class RepairWorkerNameDTO : public oatpp::DTO
{
	DTO_INIT(RepairWorkerNameDTO, DTO);
	//// 维修类型id
	//API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair-type"));
	
	// 维修类型名称
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair-type-name"));
	// 维修师傅名称
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairsetting.repair-worker-name.staff-name"));
	//// 小区id
	//API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-worker-name.community-id"));
	
	//传入单号
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair-id"));
	//添加一个payload变量
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
//用于返回的DTO
class RepairWorkerNameResponDTO : public oatpp::DTO
{
	DTO_INIT(RepairWorkerNameResponDTO, DTO);
	// 维修师傅名称
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairsetting.repair-worker-name.staff-name"));
};

class RepairWorkerNamePageDTO : public PageDTO<RepairWorkerNameDTO::Wrapper>
{
	DTO_INIT(RepairWorkerNamePageDTO, PageDTO<RepairWorkerNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRWORKERDTO_H_