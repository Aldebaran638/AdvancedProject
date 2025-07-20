#pragma once
#ifndef _BUREFUNDDTO_H_
#define _BUREFUNDDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  欠费数据表
 */
class BuRefundDTO : public oatpp::DTO
{
	DTO_INIT(BuRefundDTO, DTO);
	//退款单号
	API_DTO_FIELD_DEFAULT(String, return_fee_id, ZH_WORDS_GETTER("refund.return_fee_id"));
	//缴费单号
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("refund.b_id"));
	//费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("refund.fee_type_cd"));
	//付费对象
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("refund.fee_id"));
	//付费周期
	API_DTO_FIELD_DEFAULT(String, cycles, ZH_WORDS_GETTER("refund.cycles"));
	//应付金额/实付金额
	API_DTO_FIELD_DEFAULT(Int64, received_amount, ZH_WORDS_GETTER("refund.received_amount"));
	//申请时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("refund.create_time"));
	//退费原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("refund.reason"));
	//申请人
	API_DTO_FIELD_DEFAULT(String, apply_person_name, ZH_WORDS_GETTER("refund.apply_person_name"));
	//审核状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("refund.state"));
	//审核人
	API_DTO_FIELD_DEFAULT(String, audit_person_name, ZH_WORDS_GETTER("refund.audit_person_name"));
	//退款情况
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("refund.status_cd"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_BUREFUNDDTO_H_