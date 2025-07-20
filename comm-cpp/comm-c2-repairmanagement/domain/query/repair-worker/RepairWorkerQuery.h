#pragma once
#ifndef _REPAIRWORKERQUERY_H_
#define _REPAIRWORKERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询维修师傅信息的数据传输模型
 */
class RepairWorkerQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(RepairWorkerQuery, PageQuery);
	// 小区id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-worker-name.community-id"));
	// 传入修改类型
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-worker-name.default-repair-type-name"));
};

/**
 * 定义一个变更报修师傅状态的Query
 */
class RepairWorkerModifyQuery : public oatpp::DTO
{
	DTO_INIT(RepairWorkerModifyQuery, DTO);
	//维修师傅id
	API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("repairsetting.repair-worker.staff_id"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRWORKERQUERY_H_