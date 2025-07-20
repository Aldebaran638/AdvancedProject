#ifndef _ApplyDiscountStateDTO_H
#define _ApplyDiscountStateDTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 优惠申请状态查询对象
 */
class ApplyDiscountStateDTO : public oatpp::DTO
{
	DTO_INIT(ApplyDiscountStateDTO, DTO);

	//空置房申请id
	DTO_FIELD(String, ard_id);
	DTO_FIELD_INFO(ard_id) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.ard-id");
	}
	// 审核状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.state");
	}

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountStateDTO_H