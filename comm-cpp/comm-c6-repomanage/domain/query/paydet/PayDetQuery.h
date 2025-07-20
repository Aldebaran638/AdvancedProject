#pragma once
#ifndef _PAYDET_QUERY_
#define _PAYDET_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h" 
#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 导出缴费明细查询对象（VO）
 * 继承自PageQuery，用于封装导出缴费明细的查询条件
 */
class GetPaydetQuery : public PageQuery {
	DTO_INIT(GetPaydetQuery, PageQuery);

	// 选择缴费开始时间
	API_DTO_FIELD_DEFAULT(String, paymentStartTime, ZH_WORDS_GETTER("paydet.paymentStartTime"));

	// 选择缴费结束时间
	API_DTO_FIELD_DEFAULT(String, paymentEndTime, ZH_WORDS_GETTER("paydet.paymentEndTime"));

	// 选择支付方式
	API_DTO_FIELD_DEFAULT(String, paymentMethod, ZH_WORDS_GETTER("paydet.payMethod.paymentMethod"));

	// 选择费用状态
	API_DTO_FIELD_DEFAULT(String, expenseStatus, ZH_WORDS_GETTER("paydet.feeSituation.expenseStatus"));

	// 房屋编号或者车牌号
	API_DTO_FIELD_DEFAULT(String, houseOrPlateNumber, ZH_WORDS_GETTER("paydet.houseOrPlateNumber"));

	// 选择费用类型
	API_DTO_FIELD_DEFAULT(String, expenseType, ZH_WORDS_GETTER("paydet.expenseType.type"));

	// 选择收费项
	API_DTO_FIELD_DEFAULT(String, chargeItem, ZH_WORDS_GETTER("paydet.chargeItem"));

	// 收费开始时间
	API_DTO_FIELD_DEFAULT(String, chargeStartTime, ZH_WORDS_GETTER("paydet.chargeStartTime"));

	// 收费结束时间
	API_DTO_FIELD_DEFAULT(String, chargeEndTime, ZH_WORDS_GETTER("paydet.chargeEndTime"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYDET_QUERY_