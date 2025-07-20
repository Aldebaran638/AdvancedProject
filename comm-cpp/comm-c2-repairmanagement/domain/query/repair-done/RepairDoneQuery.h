#pragma once
#ifndef _REPAIRDONE_QUERY_
#define _REPAIRDONE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 报修已办分页查询对象
 */
class RepairDoneQuery :public PageQuery
{
	DTO_INIT(RepairDoneQuery, PageQuery);
	//小区id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairdone.repair-done.community_id"));
	// 维修类型 
	API_DTO_FIELD_DEFAULT(String, maintenance_type, ZH_WORDS_GETTER("repairdone.repair-done.maintenance_type"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairdone.repair-done.repair_name"));
	//联系方式
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairdone.repair-done.tel"));
	// 报修类型 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairdone.repair-done.repair_type"));
	//报修状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairdone.repair-done.state"));
	//工单编码
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairdone.repair-done.repair_id"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRDONE_QUERY_
