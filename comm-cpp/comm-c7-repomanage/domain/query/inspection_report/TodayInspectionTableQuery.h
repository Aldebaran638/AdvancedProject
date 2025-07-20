#pragma once
#ifndef _TODAY_INSPECTION_TALBE_QUERY_H_
#define _TODAY_INSPECTION_TALBE_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
//TodayInspectionTableQuery
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 今日巡检列表分页查询对象
 */
class TodayInspectionTableQuery : public PageQuery
{
	DTO_INIT(TodayInspectionTableQuery, PageQuery);
	//今天的日期
	API_DTO_FIELD_DEFAULT(String, todayDate, ZH_WORDS_GETTER("inspection-report.field.today"));
	//小区Id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("inspection-report.field.communityid"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_TODAY_INSPECTION_TALBE_QUERY_H_