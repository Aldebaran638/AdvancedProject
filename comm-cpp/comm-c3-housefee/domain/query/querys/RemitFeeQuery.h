#pragma once
#ifndef _REMITFEEQUERY_H_
#define  _REMITFEEQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class RemitFeeQuery :public PageQuery {
	DTO_INIT(RemitFeeQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("record.get.detail_id"));

	//  receipt_id: 费用项
	API_DTO_FIELD_DEFAULT(String, receipt_id, ZH_WORDS_GETTER("record.get.receipt_id"));
	//pay_obj: 收费对象
	API_DTO_FIELD_DEFAULT(String, pay_obj, ZH_WORDS_GETTER("record.get.pay_obj"));
	//cycle : 周期
	API_DTO_FIELD_DEFAULT(Float64, cycle, ZH_WORDS_GETTER("record.get.cycle"));
	//receivable_amount : 应收费用
	//API_DTO_FIELD_DEFAULT(Float64, receivable_amount, ZH_WORDS_GETTER("record.get.receivable_amount"));
	////amount : 实收费用
	//API_DTO_FIELD_DEFAULT(Float64, amount, ZH_WORDS_GETTER("record.get.amount"));
	//pay_path : 缴费方式
	API_DTO_FIELD_DEFAULT(String, receive_received, ZH_WORDS_GETTER("record.get.receive_received"));

	API_DTO_FIELD_DEFAULT(String, pay_path, ZH_WORDS_GETTER("record.get.pay_path"));
	//pay_period : 缴费阶段
	API_DTO_FIELD_DEFAULT(String, pay_period, ZH_WORDS_GETTER("record.get.pay_period"));

	/*API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("record.get.start_time"));
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("record.get.end_time"));*/

	//pay_time : 缴费时间
	API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("record.get.pay_time"));
	//receive_id : 收银员
	API_DTO_FIELD_DEFAULT(String, receive_id, ZH_WORDS_GETTER("record.get.receive_id"));
	//status_cd : 状态
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("record.get.status_cd"));
	//remark : 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("record.get.remark"));
	//opt : 操作
	API_DTO_FIELD_DEFAULT(String, opt, ZH_WORDS_GETTER("record.get.opt"));
};
#include OATPP_CODEGEN_END(DTO)
#endif