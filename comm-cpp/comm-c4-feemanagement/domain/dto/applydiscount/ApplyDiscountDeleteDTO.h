#ifndef _ApplyDiscountDeleteDTO_H
#define _ApplyDiscountDeleteDTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 优惠申请状态查询对象
 */
class ApplyDiscountDeleteDTO : public oatpp::DTO
{
	DTO_INIT(ApplyDiscountDeleteDTO, DTO);

	//空置房申请id
	DTO_FIELD(String, ard_id);
	DTO_FIELD_INFO(ard_id) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.ard-id");
	}

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountDeleteDTO_H