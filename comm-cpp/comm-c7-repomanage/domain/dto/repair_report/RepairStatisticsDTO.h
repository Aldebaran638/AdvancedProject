#pragma once

#ifndef _RepairStatistics_DTO_
#define _RepairStatistics_DTO_
#include "../../GlobalInclude.h"
//#include <oatpp/core/Types.hpp> 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取报修统计列表
 */
class RepairStatisticsBaseDTO : public oatpp::DTO
{
	DTO_INIT(RepairStatisticsBaseDTO, DTO);
	//API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("jiusui.community.id"));
	API_DTO_FIELD_DEFAULT(Int64, public_count, ZH_WORDS_GETTER("jiusui.repair.public_count"));
	API_DTO_FIELD_DEFAULT(Int64, private_count, ZH_WORDS_GETTER("jiusui.repair.private_count"));
	API_DTO_FIELD_DEFAULT(Int64, assigned_count, ZH_WORDS_GETTER("jiusui.repair.assigned_count"));
	API_DTO_FIELD_DEFAULT(Int64, revisit_count, ZH_WORDS_GETTER("jiusui.repair.revisit_count"));
	API_DTO_FIELD_DEFAULT(Int64, unrevisit_count, ZH_WORDS_GETTER("jiusui.repair.unrevisit_count"));
	API_DTO_FIELD_DEFAULT(Int64, public_incomplete, ZH_WORDS_GETTER("jiusui.repair.public_incomplete"));
	API_DTO_FIELD_DEFAULT(Int64, private_incomplete, ZH_WORDS_GETTER("jiusui.repair.private_incomplete"));
	API_DTO_FIELD_DEFAULT(Float64, repair_pay, ZH_WORDS_GETTER("jiusui.repair.repair_pay"));
	API_DTO_FIELD_DEFAULT(Float64, repair_payed, ZH_WORDS_GETTER("jiusui.repair.repair_payed"));
	API_DTO_FIELD_DEFAULT(Float64, private_incomplete_average, ZH_WORDS_GETTER("jiusui.repair.private_incomplete_average"));
	API_DTO_FIELD_DEFAULT(Float64, public_incomplete_average, ZH_WORDS_GETTER("jiusui.repair.public_incomplete_average"));
};


/**
 *	   获取报修统计列表
 */
class QueryRepairStatisticsDTO : public RepairStatisticsBaseDTO
{
	DTO_INIT(QueryRepairStatisticsDTO, RepairStatisticsBaseDTO);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_RepairStatistics_DTO_