#pragma once
#ifndef _EXRMREMINDERSDTO_
#define _EXRMREMINDERSDTO_


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增数据传输对象
 */
class ExRmremindersDTO : public oatpp::DTO
{
	DTO_INIT(ExRmremindersDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, ofc_id, ZH_WORDS_GETTER("owe.ofc_id"));

	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owe.owner_name"));

	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("owe.payer_obj_name"));

	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("owe.fee_name"));

	API_DTO_FIELD_DEFAULT(String, amountd_owed, ZH_WORDS_GETTER("owe.amountd_owed"));

	API_DTO_FIELD_DEFAULT(String, callable_way, ZH_WORDS_GETTER("owe.callable_way"));

	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("owe.start_time"));

	//API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("owe.end_time"));

	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("owe.staff_name"));
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("owe.state"));
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owe.create_time"));
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("owe.remark"));
};

/**
 * 示例分页传输对象
 */
class ExRmremindersPageDTO : public PageDTO<ExRmremindersDTO::Wrapper>
{
	DTO_INIT(ExRmremindersPageDTO, PageDTO<ExRmremindersDTO::Wrapper>);
};
/**
 *传输对象
 */
class CombineExRmremindersDTO : public ExRmremindersDTO {
	DTO_INIT(CombineExRmremindersDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<ExRmremindersDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("owe.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("owe.total"));
public:
	CombineExRmremindersDTO() {
		this->DTOList = List<ExRmremindersDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(ExRmremindersDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EXRMREMINDERSDTO_