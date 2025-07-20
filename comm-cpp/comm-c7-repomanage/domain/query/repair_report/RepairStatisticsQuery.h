#pragma once
#ifndef _RepairStatistics_QUERY_
#define _RepairStatistics_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
//#include <oatpp/core/Types.hpp> 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修统计查询对象
 */
class QueryRepairStatisticsQuery : public PageQuery
{
	DTO_INIT(QueryRepairStatisticsQuery, PageQuery);
	// 公共区总数量
	DTO_FIELD(String, public_count);
	DTO_FIELD_INFO(public_count) {
		info->description = ZH_WORDS_GETTER("jiusui.repair.public_count");
	}
	//上用原方式，下用宏
	// 小区ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("jiusui.community.id"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("jiusui.repair.start_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("jiusui.repair.end_time"));
	//非公共区总数量
	API_DTO_FIELD_DEFAULT(String, private_count, ZH_WORDS_GETTER("jiusui.repair.private_count"));
	//已派单数
	API_DTO_FIELD_DEFAULT(String, assigned_count, ZH_WORDS_GETTER("jiusui.repair.assigned_count"));
	//回访数
	API_DTO_FIELD_DEFAULT(String, revisit_count, ZH_WORDS_GETTER("jiusui.repair.revisit_count"));
	//未回访数
	API_DTO_FIELD_DEFAULT(String, unrevisit_count, ZH_WORDS_GETTER("jiusui.repair.unrevisit_count"));
	//公共区未完成
	API_DTO_FIELD_DEFAULT(String, public_incomplete, ZH_WORDS_GETTER("jiusui.repair.public_incomplete"));
	//非公共区未完成
	API_DTO_FIELD_DEFAULT(String, private_incomplete, ZH_WORDS_GETTER("jiusui.repair.private_incomplete"));
	//维修应收
	API_DTO_FIELD_DEFAULT(String, repair_pay, ZH_WORDS_GETTER("jiusui.repair.repair_pay"));
	//维修实收
	API_DTO_FIELD_DEFAULT(String, repair_payed, ZH_WORDS_GETTER("jiusui.repair.repair_payed"));
	//非公区完成平均值
	API_DTO_FIELD_DEFAULT(String, private_incomplete_average, ZH_WORDS_GETTER("jiusui.repair.private_incomplete_average"));
	//公区完成平均值
	API_DTO_FIELD_DEFAULT(String, public_incomplete_average, ZH_WORDS_GETTER("jiusui.repair.public_incomplete_average"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RepairStatistics_QUERY_