#pragma once

#ifndef _DISSATISFIEDREPAIR_QUERY_H_
#define _DISSATISFIEDREPAIR_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/repair_report/DissatisfiedRepairDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修不满意分页查询对象
 */
class DissatisfiedRepairQuery : public PageQuery
{
	DTO_INIT(DissatisfiedRepairQuery, PageQuery);
	// 小区名称 community_id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("dissatisfied-repair.community-id"));
	// 起始日期 start_date
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("dissatisfied-repair.field.start-date"));
	// 终止日期 end_date
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("dissatisfied-repair.field.end-date"));
	// 文件名 filename
	API_DTO_FIELD_DEFAULT(String, filename, ZH_WORDS_GETTER("dissatisfied-repair.export.filename"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DISSATISFIEDREPAIR_QUERY_H_