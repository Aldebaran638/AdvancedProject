#pragma once
#ifndef _OWEINFORMATIONDTO_H_
#define _OWEINFORMATIONDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增数据传输对象
 */
class OweInformationDTO : public oatpp::DTO
{
	DTO_INIT(OweInformationDTO, DTO);
	// 欠费id
	API_DTO_FIELD_DEFAULT(Int64, owe_id, ZH_WORDS_GETTER("owe.owe_id"));
	// 收费对象
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("owe.payer_obj_name"));
	// 业主id
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owe.owner_name"));
	// 手机号
	API_DTO_FIELD_DEFAULT(String, owner_tel, ZH_WORDS_GETTER("owe.owner_tel"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owe.create_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, deadline_time, ZH_WORDS_GETTER("owe.deadline_time"));
	//合计(单位:元)
	API_DTO_FIELD_DEFAULT(Int64, bill_amount_owed, ZH_WORDS_GETTER("owe.bill_amount_owed"));
	//跟新时间
	API_DTO_FIELD_DEFAULT(String, fee_end_time, ZH_WORDS_GETTER("owe.fee_end_time"));
};

/**
 * 示例分页传输对象
 */
class OweInformationPageDTO : public PageDTO<OweInformationDTO::Wrapper>
{
	DTO_INIT(OweInformationPageDTO, PageDTO<OweInformationDTO::Wrapper>);
};

/**
 *传输对象
 */
class CombineOweInformationDTO : public OweInformationDTO {
	DTO_INIT(CombineOweInformationDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<OweInformationDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("owe.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("owe.total"));
public:
	CombineOweInformationDTO() {
		this->DTOList = List<OweInformationDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(OweInformationDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_OWEINFORMATIONDTO_H_