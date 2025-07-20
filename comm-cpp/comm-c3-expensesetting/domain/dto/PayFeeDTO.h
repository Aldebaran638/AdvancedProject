#pragma once

#ifndef _PAYFEEDTO_H_
#define _PAYFEEDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


// 费用项名称DTO
class ChargeItemDTO : public oatpp::DTO
{
	DTO_INIT(ChargeItemDTO, DTO);
	
	// ID
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("feeMgr.field.config_id"));

// 费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"));

	// 名称
	API_DTO_FIELD_DEFAULT(String, chargeItem, ZH_WORDS_GETTER("feeMgr.field.fee_name"));
};

class ChargeItemListDTO : public oatpp::DTO
{
	DTO_INIT(ChargeItemListDTO, oatpp::DTO);

	// 名称
	API_DTO_FIELD_DEFAULT(List<Object<ChargeItemDTO>>, chargeItemList, ZH_WORDS_GETTER("feeMgr.field.itemList"));
};


class PayFeeDTO : public oatpp::DTO
{
    DTO_INIT(PayFeeDTO, DTO);

	// 主键 ID
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("feeMgr.field.config_id"));

	// 费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"));

	// 收费项目
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("feeMgr.field.fee_name"));

	// 费用标识
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("feeMgr.field.fee_flag"));

	// 付费类型
	API_DTO_FIELD_DEFAULT(String, payment_cd, ZH_WORDS_GETTER("feeMgr.field.payment_cd"));

	// 缴费周期
	API_DTO_FIELD_DEFAULT(Int32, payment_cycle, ZH_WORDS_GETTER("feeMgr.field.payment_cycle"));

	//// 开始时间
	//API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("feeMgr.field.start_time"));

	//// 结束时间
	//API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("feeMgr.field.end_time"));

	//有效期
	API_DTO_FIELD_DEFAULT(String, validDate, ZH_WORDS_GETTER("feeMgr.field.validDate"));

	// 计算公式
	API_DTO_FIELD_DEFAULT(String, computing_formula, ZH_WORDS_GETTER("feeMgr.field.computing_formula"));

	// 计费单价
	API_DTO_FIELD_DEFAULT(String, square_price, ZH_WORDS_GETTER("feeMgr.field.square_price"));

	// 固定费用
	API_DTO_FIELD_DEFAULT(String, additional_amount, ZH_WORDS_GETTER("feeMgr.field.additional_amount"));
	
	// 是否支持账户抵扣
	API_DTO_FIELD_DEFAULT(String, deduct_from, ZH_WORDS_GETTER("feeMgr.field.deduct_from"));

};
/**
 * 分页费用项 DTO（用于分页查询结果）
 */
class  PayFeePageDTO : public PageDTO<PayFeeDTO::Wrapper>
{
	DTO_INIT(PayFeePageDTO, PageDTO<PayFeeDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !PAYFEEDTO_H_
