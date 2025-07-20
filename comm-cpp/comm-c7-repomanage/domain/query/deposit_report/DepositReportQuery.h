#pragma once
#ifndef _DEPOSIT_REPORT_QUERY_
#define _DEPOSIT_REPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class DepositReportQuery : public PageQuery
{
	DTO_INIT(DepositReportQuery, PageQuery);
	// 房号
	DTO_FIELD(String, location_obj_name);
	DTO_FIELD_INFO(location_obj_name) {
		info->description = ZH_WORDS_GETTER("depositReport.location_obj_name");
	}
	// 费用ID
	DTO_FIELD(String, fee_id);
	DTO_FIELD_INFO(fee_id) {
		info->description = ZH_WORDS_GETTER("depositReport.fee_id");
	}
	// 费用类型
	DTO_FIELD(String, fee_type_cd);
	DTO_FIELD_INFO(fee_type_cd) {
		info->description = ZH_WORDS_GETTER("depositReport.fee_type_cd");
	}
	// 付款状态
	DTO_FIELD(String, pay_state);
	DTO_FIELD_INFO(pay_state) {
		info->description = ZH_WORDS_GETTER("depositReport.pay_state");
	}
	// 付费对象类型
	DTO_FIELD(String, income_obj_id);
	DTO_FIELD_INFO(income_obj_id) {
		info->description = ZH_WORDS_GETTER("depositReport.income_obj_id");
	}
	// 付费开始时间
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("depositReport.start_time");
	}
	// 付费结束时间
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("depositReport.end_time");
	}
	// 退费状态
	DTO_FIELD(String, return_state);
	DTO_FIELD_INFO(return_state) {
		info->description = ZH_WORDS_GETTER("depositReport.return_state");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_