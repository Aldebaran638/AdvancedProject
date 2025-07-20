#pragma once
#ifndef _DEPOSIT_REPORT_DTO_
#define _DEPOSIT_REPORT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class DepositReportDTO : public oatpp::DTO
{
	DTO_INIT(DepositReportDTO, DTO);

	
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

	// 创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("depositReport.create_time");
	}

	// 付费对象类型
	DTO_FIELD(String, income_obj_id);
	DTO_FIELD_INFO(income_obj_id) {
		info->description = ZH_WORDS_GETTER("depositReport.income_obj_id");
	}
	// 付费方ID
	DTO_FIELD(String, payer_obj_id);
	DTO_FIELD_INFO(payer_obj_id) {
		info->description = ZH_WORDS_GETTER("depositReport.payer_obj_id");
	}
	// 付费状态
	DTO_FIELD(String, pay_state);
	DTO_FIELD_INFO(pay_state) {
		info->description = ZH_WORDS_GETTER("depositeReport.pay_state");
	}
	// 小区ID
	DTO_FIELD(String, community_id);
	DTO_FIELD_INFO(community_id) {
		info->description = ZH_WORDS_GETTER("depositReport.community_id");
	}
	// 房号
	DTO_FIELD(String, location_obj_name);
	DTO_FIELD_INFO(location_obj_name) {
		info->description = ZH_WORDS_GETTER("depositReport.location_obj_name");
	}
	// 业主
	DTO_FIELD(String, owner_name);
	DTO_FIELD_INFO(owner_name) {
		info->description = ZH_WORDS_GETTER("depositReport.owner_name");
	}
	// 费用项
	DTO_FIELD(String, config_name);
	DTO_FIELD_INFO(config_name) {
		info->description = ZH_WORDS_GETTER("depositReport.config_name");
	}
	// 应收金额
	DTO_FIELD(String, receivable_amount);
	DTO_FIELD_INFO(receivable_amount) {
		info->description = ZH_WORDS_GETTER("depositReport.receivable_amount");
	}
	// 退费状态
	DTO_FIELD(String, return_state);
	DTO_FIELD_INFO(return_state) {
		info->description = ZH_WORDS_GETTER("depositReport.return_state");
	}

};



class DepositReportPageDTO : public PageDTO<DepositReportDTO::Wrapper>
{
	DTO_INIT(DepositReportPageDTO, PageDTO<DepositReportDTO::Wrapper>);
};


class DepositReportExportDTO : public oatpp::DTO
{
	DTO_INIT(DepositReportExportDTO, DTO)

	// 文件下载URL
	API_DTO_FIELD_DEFAULT(String, fileUrl, ZH_WORDS_GETTER("export.field.fileUrl"));
	// 文件名
	API_DTO_FIELD_DEFAULT(String, fileName, ZH_WORDS_GETTER("export.field.fileName"));
	// 文件大小（可选）
	API_DTO_FIELD_DEFAULT(UInt64, fileSize, ZH_WORDS_GETTER("export.field.fileSize"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 