#ifndef PAYDETDTO_H
#define PAYDETDTO_H

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 缴费明细数据传输对象（DTO）
 */class PayDetDTO : public oatpp::DTO {
	 DTO_INIT(PayDetDTO, DTO);

	 // 订单号
	 API_DTO_FIELD_DEFAULT(String, on, ZH_WORDS_GETTER("paydet.orderNumber"));
	 // 房号/业主
	 API_DTO_FIELD_DEFAULT(String, hnpo, ZH_WORDS_GETTER("paydet.houseNumberPropertyOwner"));
	 // 费用类型->费用项
	 API_DTO_FIELD_DEFAULT(String, eti, ZH_WORDS_GETTER("paydet.expenseTypeItem"));
	 // 费用状态
	 API_DTO_FIELD_DEFAULT(String, etatus, ZH_WORDS_GETTER("paydet.expenseType.expenseStatus"));
	 // 支付方式
	 API_DTO_FIELD_DEFAULT(String, pm, ZH_WORDS_GETTER("paydet.payMethod.method"));
	 // 缴费时间段
	 API_DTO_FIELD_DEFAULT(String, pps, ZH_WORDS_GETTER("paydet.paymentPeriod"));
	 // 缴费时间
	 API_DTO_FIELD_DEFAULT(String, payt, ZH_WORDS_GETTER("paydet.paymentTime"));
	 // 收银员
	 API_DTO_FIELD_DEFAULT(String, chier, ZH_WORDS_GETTER("paydet.cashier"));
	 // 应缴/应收金额 (元)
	 API_DTO_FIELD_DEFAULT(Float64, dra, ZH_WORDS_GETTER("paydet.dueReceiveAmount"));
	 // 实收金额 (元)
	 API_DTO_FIELD_DEFAULT(Float64, ard, ZH_WORDS_GETTER("paydet.amountReceived"));
	 // 账户抵扣 (元)
	 API_DTO_FIELD_DEFAULT(Float64, ad, ZH_WORDS_GETTER("paydet.accountDeduction"));
	 // 优惠/减免金额 (元)
	 API_DTO_FIELD_DEFAULT(Float64, dwa, ZH_WORDS_GETTER("paydet.discountWaiverAmount"));
	 // 赠送金额 (元)
	 API_DTO_FIELD_DEFAULT(Float64, ga, ZH_WORDS_GETTER("paydet.giftAmount"));
	 // 滞纳金 (元)
	 API_DTO_FIELD_DEFAULT(Float64, lpf, ZH_WORDS_GETTER("paydet.latePaymentFee"));
	 // 面积 (平方米)
	 API_DTO_FIELD_DEFAULT(Float64, ar, ZH_WORDS_GETTER("paydet.area"));
	 // 车位
	 API_DTO_FIELD_DEFAULT(String, ps, ZH_WORDS_GETTER("paydet.parkingSpace"));
	 // 说明
	 API_DTO_FIELD_DEFAULT(String, rem, ZH_WORDS_GETTER("paydet.remarks"));
 };

 /*
  * 缴费明细分页数据传输对象（DTO）
  */
 class PayDetPageDTO : public PageDTO<PayDetDTO::Wrapper> {
	 DTO_INIT(PayDetPageDTO, PageDTO<PayDetDTO::Wrapper>);
 };

#include OATPP_CODEGEN_END(DTO)

#endif // PAYDETDTO_H