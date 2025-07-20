#pragma once
#ifndef _REPAIR_REPORT_SUMMARY_DTO_
#define _REPAIR_REPORT_SUMMARY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修汇总表传输对象
 */
class RepairReportSummaryDTO : public oatpp::DTO
{
	DTO_INIT(RepairReportSummaryDTO, DTO);
	//报修编号
	DTO_FIELD(Int32, summaryId);
	DTO_FIELD_INFO(summaryId) {
		info->description = ZH_WORDS_GETTER("repair.summary.id");
	}
	//员工ID
	API_DTO_FIELD_DEFAULT(String, staffId, ZH_WORDS_GETTER("repair.staff.id"));
	//员工姓名
	API_DTO_FIELD_DEFAULT(String, staffName, ZH_WORDS_GETTER("repair.staff.name"));
	//处理中(条)
	API_DTO_FIELD_DEFAULT(Int32, deal, ZH_WORDS_GETTER("repair.list.deal"));
	//派单(条)
	API_DTO_FIELD_DEFAULT(Int32, sendList, ZH_WORDS_GETTER("repair.list.send"));
	//转单(条)
	API_DTO_FIELD_DEFAULT(Int32, transferList, ZH_WORDS_GETTER("repair.list.transfer"));
	//退单(条)
	API_DTO_FIELD_DEFAULT(Int32, chargeback, ZH_WORDS_GETTER("repair.list.back"));
	//已回访(条)
	API_DTO_FIELD_DEFAULT(Int32, returnVisit, ZH_WORDS_GETTER("repair.list.returnVisit"));
	//已完结(条)
	API_DTO_FIELD_DEFAULT(Int32, finish, ZH_WORDS_GETTER("repair.list.finish"));
	//员工评分
	API_DTO_FIELD_DEFAULT(String, examineValue, ZH_WORDS_GETTER("repair.staff.grade"));
	//数据状态
	//API_DTO_FIELD_DEFAULT(String, statusCd, ZH_WORDS_GETTER("repair.list.deal"));

};

/**
 * 报修汇总分页传输对象
 */
class RepairReportSummaryPageDTO : public PageDTO<RepairReportSummaryDTO::Wrapper>
{
	DTO_INIT(RepairReportSummaryPageDTO, PageDTO<RepairReportSummaryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIR_REPORT_SUMMARY_DTO_

