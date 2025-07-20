#ifndef _ApplyDiscountQUERY_H
#define _ApplyDiscountQUERY_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 优惠申请分页查询对象
 */
class ApplyDiscountQuery : public PageQuery
{
	DTO_INIT(ApplyDiscountQuery, PageQuery);
	// 房屋名称
	DTO_FIELD(String, roomName);
	DTO_FIELD_INFO(roomName) {
		info->description = ZH_WORDS_GETTER("discount.field.roomName");
	}
	// 申请类型
	DTO_FIELD(String, applyType);
	DTO_FIELD_INFO(applyType) {
		info->description = ZH_WORDS_GETTER("discount.field.applyType");
	}
	// 审核状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("discount.field.state");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountQUERY_H