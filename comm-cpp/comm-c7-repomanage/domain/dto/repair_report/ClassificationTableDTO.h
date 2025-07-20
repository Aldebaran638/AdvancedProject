#pragma once
#ifndef _CLASSIFICATIONTABlE_DTO_H_
#define _CLASSIFICATIONTABlE_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class ClassificationTableDTO : public oatpp::DTO
{
	DTO_INIT(ClassificationTableDTO, DTO);
	// 公共区域 public_area
	DTO_FIELD(String, public_area);
	DTO_FIELD_INFO(public_area) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.public_area");
	}
	// 类型 repair_type/repair_setting_type

	DTO_FIELD(String, repair_type_name);
	DTO_FIELD_INFO(repair_type_name) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.repair_type");
	}
	// 数量
	DTO_FIELD(Int32, type_count);
	DTO_FIELD_INFO(type_count) {
		info->description = ZH_WORDS_GETTER("repair_report.classificationtable.num");
	}
};

class ClassificationTableListPageDTO : public PageDTO<ClassificationTableDTO::Wrapper>
{
	DTO_INIT(ClassificationTableListPageDTO, PageDTO<ClassificationTableDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CLASSIFICATIONTABlE_DTO_