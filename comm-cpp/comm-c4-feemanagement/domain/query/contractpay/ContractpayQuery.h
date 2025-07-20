#pragma once

#ifndef _CONTRACTPAYQUERY_H_
#define _CONTRACTPAYQUERY_H_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 合同收费分页查询对象
class ContractpayQuery : public PageQuery {
	DTO_INIT(ContractpayQuery, PageQuery);
	// 付款方id，即合同id
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"));
	// 费用项目
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("contractpay.newfield.fee_name"));
	// 费用标志
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("contractpay.newfield.fee_flag"));
	// 费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("contractpay.newfield.fee_type_cd"));
	// 应收金额（固定费用）
	API_DTO_FIELD_DEFAULT(Float64, additional_amount, ZH_WORDS_GETTER("contractpay.newfield.additional_amount"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("contractpay.newfield.create_time"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("contractpay.newfield.start_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("contractpay.newfield.end_time"));
	// 每平单价
	API_DTO_FIELD_DEFAULT(Float64, square_price, ZH_WORDS_GETTER("contractpay.newfield.square_price"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("contractpay.newfield.state"));
};

// 获取合同缴费记录分页查询对象
class ContractpayRecordQuery : public PageQuery {
	DTO_INIT(ContractpayRecordQuery, PageQuery);
	//费用id
	API_DTO_FIELD_DEFAULT(String, feeid, ZH_WORDS_GETTER("contractcost.charge.feeid"));
	// 费用项目
	API_DTO_FIELD_DEFAULT(String, feeobj, ZH_WORDS_GETTER("contractcost.charge.costobj"));
	// 收费对象
	API_DTO_FIELD_DEFAULT(String, chargeobj, ZH_WORDS_GETTER("contractcost.charge.chargeobj"));
	// 缴费周期
	API_DTO_FIELD_DEFAULT(String, chargecycle, ZH_WORDS_GETTER("contractcost.charge.chargecycle"));
	//应收款
	API_DTO_FIELD_DEFAULT(String, receivable, ZH_WORDS_GETTER("contractcost.charge.receivable"));
	//实收款
	API_DTO_FIELD_DEFAULT(String, received, ZH_WORDS_GETTER("contractcost.charge.received"));
	//支付方式
	API_DTO_FIELD_DEFAULT(String, chargeway, ZH_WORDS_GETTER("contractcost.charge.chargeway"));
	// 计费起始时间
	API_DTO_FIELD_DEFAULT(String, coststarttime, ZH_WORDS_GETTER("contractcost.charge.coststarttime"));
	// 计费起始时间
	API_DTO_FIELD_DEFAULT(String, costendtime, ZH_WORDS_GETTER("contractcost.charge.costendtime"));
	// 缴费时间
	API_DTO_FIELD_DEFAULT(String, chargetime, ZH_WORDS_GETTER("contractcost.charge.chargetime"));
	//收银员名字
	API_DTO_FIELD_DEFAULT(String, cashier, ZH_WORDS_GETTER("contractcost.charge.received"));
	//状态
	API_DTO_FIELD_DEFAULT(String, statu, ZH_WORDS_GETTER("contractcost.charge.statu"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("contractcost.charge.remark"));
	// 付款方id，即合同id
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"));
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_CONTRACTPAYQUERY_H_
