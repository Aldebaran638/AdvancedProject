#pragma once
#ifndef _CLASSIFICATIONTABlE_QUERY_H_
#define _CLASSIFICATIONTABlE_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class ClassificationTableQuery : public PageQuery
{
	DTO_INIT(ClassificationTableQuery, PageQuery);
	DTO_FIELD(String, public_area);
	DTO_FIELD_INFO(public_area) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.public_area");
	}
	DTO_FIELD(String, repair_type_name);
	DTO_FIELD_INFO(repair_type_name) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.repair_type");
	}
	DTO_FIELD(Int32, type_count);
	DTO_FIELD_INFO(type_count) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.num");
	}
	DTO_FIELD(String, community_id);
	DTO_FIELD_INFO(community_id) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.community_id");
	}
	DTO_FIELD(String,start_date);
	DTO_FIELD_INFO(start_date) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.start_date");
	}
	DTO_FIELD(String, end_date);
	DTO_FIELD_INFO(end_date) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.end_date");
	}
	DTO_FIELD(String, filename);
	DTO_FIELD_INFO(filename) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.filename");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CLASSIFICATIONTABlE_QUERY_