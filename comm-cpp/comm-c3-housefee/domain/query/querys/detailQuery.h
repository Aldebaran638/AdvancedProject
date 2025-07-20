#pragma once
#ifndef _DETAILQUERY_H_
#define  _DETAILQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class detailQuery :public PageQuery {
	DTO_INIT(detailQuery, PageQuery);
	//fee_id: 缴费ID
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("detail.get.fee_id"));
	//cycle : 周期(单位 : 月)
	API_DTO_FIELD_DEFAULT(String, cycle, ZH_WORDS_GETTER("detail.get.cycle"));
	//pay_path : 缴费方式
	API_DTO_FIELD_DEFAULT(String, pay_path, ZH_WORDS_GETTER("detail.get.pay_path"));
	//receiveable_amount : 应收金额
	API_DTO_FIELD_DEFAULT(String, receivable_amount, ZH_WORDS_GETTER("detail.get.receivable_amount"));
	//amount : 实收金额
	API_DTO_FIELD_DEFAULT(String, amount, ZH_WORDS_GETTER("detail.get.amount"));
	//pay_time : 缴费时间
	API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("detail.get.pay_time"));
	//start_time : 缴费开始
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("detail.get.start_time"));
	//end_time : 缴费结束
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("detail.get.end_time"));
	//end_time : 收银员
	API_DTO_FIELD_DEFAULT(String, receive_id, ZH_WORDS_GETTER("detail.get.receive_id"));
	//status_cd : 状态
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("detail.get.status_cd"));
	//remark : 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("detail.get.remark"));
	//opt : 操作
	API_DTO_FIELD_DEFAULT(String, opt, ZH_WORDS_GETTER("detail.get.opt"));
};
#include OATPP_CODEGEN_END(DTO)
#endif