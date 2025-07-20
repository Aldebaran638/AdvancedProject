#pragma once
#ifndef _REPAIRWORKERNAMEQUERY_H_
#define _REPAIRWORKERNAMEQUERY_H_

#include "../../GlobalInclude.h"
#include "../../dto/repair-worker/RepairWorkerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个显示维修师傅名称的数据传输模型
 */
class RepairWorkerNameQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(RepairWorkerNameQuery, DTO);
	// 小区id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-worker-name.community-id"));
	// 报修类型名称
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair-type-name"));
	//传入单号
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairsetting.repair-worker-name.repair-id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRWORKERNAMEQUERY_H_