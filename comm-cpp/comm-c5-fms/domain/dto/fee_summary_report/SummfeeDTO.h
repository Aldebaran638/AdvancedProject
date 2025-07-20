#pragma once


#ifndef _SUMMFEEDTO_H_
#define _SUMMFEEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	添加导出费用汇总模型
*/

class FeeSummaryDTO : public oatpp::DTO 
{

	DTO_INIT(FeeSummaryDTO, DTO);

	// 时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("axing.summ.create_time"));
	// 费用项id
	API_DTO_FIELD_DEFAULT(String, obj_id, ZH_WORDS_GETTER("axing.summ.obj_id"));
	// 费用项名称
	API_DTO_FIELD_DEFAULT(String, obj_name, ZH_WORDS_GETTER("axing.summ.obj_name"));
	// 应收金额（单位：元）
	API_DTO_FIELD_DEFAULT(Int64, receivable_amount, ZH_WORDS_GETTER("axing.summ.receivable_amount"));
	// 实收金额（单位：元）
	API_DTO_FIELD_DEFAULT(Int64, amount, ZH_WORDS_GETTER("axing.summ.amount"));


};


// 费用汇总分页
class FeeSummaryPageDTO : public PageDTO<FeeSummaryDTO::Wrapper> {
	
	DTO_INIT(FeeSummaryPageDTO, PageDTO<FeeSummaryDTO::Wrapper>);
};
/**
 *传输对象
 */
class CombineFeeSummaryDTO : public FeeSummaryDTO {
	DTO_INIT(CombineFeeSummaryDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<FeeSummaryDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("axing.summ.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("axing.summ.total"));
public:
	CombineFeeSummaryDTO() {
		this->DTOList = List<FeeSummaryDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(FeeSummaryDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_