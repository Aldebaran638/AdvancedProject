#ifndef _DISCOUNT_QUERY_H_
#define _DISCOUNT_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DiscountQuery : public PageQuery {
	DTO_INIT(DiscountQuery,PageQuery);

	//打折ID
	DTO_FIELD(String, discount_id);
	DTO_FIELD_INFO(discount_id) {
		info->description = ZH_WORDS_GETTER("discount.field.all.discount_id");
	}

	//折扣名称
	DTO_FIELD(String, discount_name);
	DTO_FIELD_INFO(discount_name) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.discount_name");
	}

	//折扣类型
	DTO_FIELD(String, discount_type);
	DTO_FIELD_INFO(discount_type) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.discount_type");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif