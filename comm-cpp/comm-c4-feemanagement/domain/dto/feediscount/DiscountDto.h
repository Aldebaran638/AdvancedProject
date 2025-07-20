#ifndef _FEE_DISCOUNT_DTO_H_
#define _FEE_DISCOUNT_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DiscountAddDTO : public oatpp::DTO {
	DTO_INIT(DiscountAddDTO,DTO);

	//折扣id discount_id
	//小区id commutity_id
	//创建时间 create_time
	//vector<discount_spec_id> vector<spec_id> 
	//等在Service层通过uuid生成

	//折扣名称
	DTO_FIELD(String,discount_name);
	DTO_FIELD_INFO(discount_name) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.discount_name");
	}

	//折扣类型
	DTO_FIELD(String,discount_type);
	DTO_FIELD_INFO(discount_type) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.discount_type");
	}

	//规则ID
	DTO_FIELD(String, rule_id);
	DTO_FIELD_INFO(rule_id) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.rule_id");
	}

	//折扣说明 只有一个
	DTO_FIELD(String, discount_desc);
	DTO_FIELD_INFO(discount_desc) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.discount_desc");
	}

	//规格名称1
	DTO_FIELD(Vector<String>, spec_name);
	DTO_FIELD_INFO(spec_name) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount_spec.spec_name");
	}

	//规格值1
	DTO_FIELD(Vector<String>, spec_value);
	DTO_FIELD_INFO(spec_value) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount_spec.spec_value");
	}

};

class DiscountChangeDTO : public oatpp::DTO {
	DTO_INIT(DiscountChangeDTO, DTO);

	//打折ID
	DTO_FIELD(String, discount_id);
	DTO_FIELD_INFO(discount_id) {
		info->description = ZH_WORDS_GETTER("discount.field.all.discount_id");
	}

	//规则ID
	DTO_FIELD(String, rule_id);
	DTO_FIELD_INFO(rule_id) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.rule_id");
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

	//折扣说明 只有一个
	DTO_FIELD(String, discount_desc);
	DTO_FIELD_INFO(discount_desc) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.discount_desc");
	}

	//规格名称1
	DTO_FIELD(Vector<String>, spec_name);
	DTO_FIELD_INFO(spec_name) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount_spec.spec_name");
	}

	//规格值1
	DTO_FIELD(Vector<String>, spec_value);
	DTO_FIELD_INFO(spec_value) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount_spec.spec_value");
	}
};

class DiscountDeleteDTO : public oatpp::DTO {
	DTO_INIT(DiscountDeleteDTO, DTO);

	//打折ID
	DTO_FIELD(String, discount_id);
	DTO_FIELD_INFO(discount_id) {
		info->description = ZH_WORDS_GETTER("discount.field.all.discount_id");
	}
};

class DiscountPageShowDTO : public oatpp::DTO {
	DTO_INIT(DiscountPageShowDTO, DTO);

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

	//规则ID
	DTO_FIELD(String, rule_id);
	DTO_FIELD_INFO(rule_id) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.rule_id");
	}

	//规则名称
	DTO_FIELD(String, rule_name);
	DTO_FIELD_INFO(rule_name) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount.rule_name");
	}

	//规格名称1
	DTO_FIELD(Vector<String>, spec_name);
	DTO_FIELD_INFO(spec_name) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount_spec.spec_name");
	}

	//规格值1
	DTO_FIELD(Vector<String>, spec_value);
	DTO_FIELD_INFO(spec_value) {
		info->description = ZH_WORDS_GETTER("discount.field.fee_discount_spec.spec_value");
	}

	//创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("discount.field.all.create_time");
	}
};

class DiscountPageDTO : public PageDTO<DiscountPageShowDTO::Wrapper>{
	DTO_INIT(DiscountPageDTO, PageDTO<DiscountPageShowDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif