#pragma once
#ifndef _REPAIRRETURNQUERY_H_
#define _REPAIRRETURNQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个报修回访的数据传输模型
 */
class RepairReturnQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(RepairReturnQuery, PageQuery);
	// 小区id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairreturn.repair-return.community_id"));
	// 工单编码
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairreturn.repair-return.repair_id"));
	// 报修类型 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairreturn.repair-return.repair_type"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairreturn.repair-return.repair_name"));
	// 联系方式
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairreturn.repair-return.tel"));
	// 回访状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairreturn.repair-return.state"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRRETURNQUERY_H_
