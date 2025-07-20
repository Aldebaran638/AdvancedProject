#pragma once
#ifndef _REPAIRREPORTDTO_H_
#define _REPAIRREPORTDTO_H_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)
/*
报修收费数据传输类型（比较完整，用于列表数据）
*/
class RepairReportFeeDTO : public oatpp::DTO
{
	DTO_INIT(RepairReportFeeDTO, DTO);

	//报修id
	API_DTO_FIELD_DEFAULT(String, repairId, ZH_WORDS_GETTER("repair-report-fee.field.repairId"));
	//报修日期
	API_DTO_FIELD_DEFAULT(String, date, ZH_WORDS_GETTER("repair-report-fee.field.date"));
	//报修人
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("repair-report-fee.field.name"));
	//报修电话
	API_DTO_FIELD_DEFAULT(String, telephone, ZH_WORDS_GETTER("repair-report-fee.field.telephone"));
	//报修位置
	API_DTO_FIELD_DEFAULT(String, location, ZH_WORDS_GETTER("repair-report-fee.field.location"));
	//维修应收
	API_DTO_FIELD_DEFAULT(String, expectfee, ZH_WORDS_GETTER("repair-report-fee.field.expectfee"));
	//维修实收
	API_DTO_FIELD_DEFAULT(String, actualfee, ZH_WORDS_GETTER("repair-report-fee.field.actualfee"));


};
/*
报修数据分页传输类型（比较完整，用于列表数据）
*/
class RepairReportFeePageDTO : public PageDTO<RepairReportFeeDTO::Wrapper>
{
	DTO_INIT(RepairReportFeePageDTO, PageDTO<RepairReportFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
