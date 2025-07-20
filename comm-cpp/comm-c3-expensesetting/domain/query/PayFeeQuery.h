#pragma once

#ifndef _PAYFEEQUERY_H_
#define _PAYFEEQUERY_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PayFeeQuery : public PageQuery
{
	DTO_INIT(PayFeeQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("feeMgr.field.community_id"));

	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"));

	// 主键ID 
	API_DTO_FIELD_DEFAULT(String, feeId, ZH_WORDS_GETTER("feeMgr.field.config_id"));

	// 收费项目  
	API_DTO_FIELD_DEFAULT(String, chargeItem, ZH_WORDS_GETTER("feeMgr.field.fee_name"));

	// 费用标识 
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("feeMgr.field.fee_flag"));

	// 付费类型
	API_DTO_FIELD_DEFAULT(String, payment_cd, ZH_WORDS_GETTER("feeMgr.field.payment_cd"));

	// 是否支持账户抵扣
	API_DTO_FIELD_DEFAULT(String, deduct_from, ZH_WORDS_GETTER("feeMgr.field.deduct_from"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAYFEEQUERY_H_
