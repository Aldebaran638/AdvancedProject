#pragma once
#ifndef _REPAIRWORKERDTO_H_
#define _REPAIRWORKERDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询维修师傅数据传输对象
 */
class RepairWorkerQueryDTO : public oatpp::DTO
{
	DTO_INIT(RepairWorkerQueryDTO, DTO);
	// 维修师傅id
	//API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("repairsetting.repair-worker.staff_id"));
	API_DTO_FIELD(String, staff_id, ZH_WORDS_GETTER("repairsetting.repair-worker.staff-id"), true, "302025052791430008");
	// 维修师傅名称
	//API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairsetting.repair-worker.staff-name"));
	API_DTO_FIELD(String, staff_name, ZH_WORDS_GETTER("repairsetting.repair-worker.staff-name"), true, "cjy");
	// 维修类型名称
	//API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-worker.repair_type_name"));
	API_DTO_FIELD(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-worker.repair-type-name"), 
		true, ZH_WORDS_GETTER("repairsetting.repair-worker.default-repair-type-name"));
	// 状态编码
	//API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairsetting.repair-worker.state"));
	API_DTO_FIELD(String, state, ZH_WORDS_GETTER("repairsetting.repair-worker.state"), true, "9999");
	// 状态编码
	//API_DTO_FIELD_DEFAULT(String, state_txt, ZH_WORDS_GETTER("repairsetting.repair-worker.state_txt"));
	API_DTO_FIELD(String, state_txt, ZH_WORDS_GETTER("repairsetting.repair-worker.state-txt"), true, 
		ZH_WORDS_GETTER("repairsetting.repair-worker.default-state-txt"));
	// 说明
	//API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("repairsetting.repair-worker.remark"));
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairsetting.repair-worker.remark"), true, 
		ZH_WORDS_GETTER("repairsetting.repair-worker.default-remark"));
	// 创建时间
	//API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("repairsetting.repair-worker.create-time"));
	API_DTO_FIELD(String, create_time, ZH_WORDS_GETTER("repairsetting.repair-worker.create-time"), true,"2025-05-31 16:40:11");
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
/**
 * 定义一个维修师傅分页传输对象
 */
class RepairWorkerPageDTO : public PageDTO<RepairWorkerQueryDTO::Wrapper>
{
	DTO_INIT(RepairWorkerPageDTO, PageDTO<RepairWorkerQueryDTO::Wrapper>);
};

/**
 * 定义一个维修师傅信息的数据传输模型
 */
class RepairWorkerAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairWorkerAddDTO, DTO);
	// 组织名
	//API_DTO_FIELD_DEFAULT(String, org_name, ZH_WORDS_GETTER("repairsetting.repair-worker.org-name"));
	API_DTO_FIELD(String, org_name, ZH_WORDS_GETTER("repairsetting.repair-worker.org-name"), true, 
		ZH_WORDS_GETTER("repairsetting.repair-worker.default-org-name"));
	// 员工名称
	//API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairsetting.repair-worker.staff-name"));
	API_DTO_FIELD(String, staff_name, ZH_WORDS_GETTER("repairsetting.repair-worker.staff-name"), true,"cjy");
	// 维修类型名称
	API_DTO_FIELD(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-worker.repair-type-name"),
		true, ZH_WORDS_GETTER("repairsetting.repair-worker.default-repair-type-name"));
	// 小区分片ID
	//API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-worker.community-id"));
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-worker.community-id"),
		true, "2023052267100146");
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 定义一个变更报修师傅状态的数据传输模型
 */
class RepairWorkerModifyDTO : public oatpp::DTO
{
	DTO_INIT(RepairWorkerModifyDTO, DTO);
	//维修师傅状态
	API_DTO_FIELD(String, state, ZH_WORDS_GETTER("repairsetting.repair-worker.state"), true, "9999");
	//维修师傅id
	API_DTO_FIELD(String, staff_id, ZH_WORDS_GETTER("repairsetting.repair-worker.staff-id"), true, "302025052791430008");
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairsetting.repair-worker.remark"), true,
		ZH_WORDS_GETTER("repairsetting.repair-worker.default-remark"));
	//小区分片id
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-worker.community-id"),
		true, "2023052267100146");
	// 维修类型名称
	API_DTO_FIELD(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-worker.repair-type-name"),
		true, ZH_WORDS_GETTER("repairsetting.repair-worker.default-repair-type-name"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRWORKERDTO_H_