#ifndef _ApplyDiscountRecordDTO_H
#define _ApplyDiscountRecordDTO_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 优惠申请跟踪记录分页查询对象
 */
class ApplyDiscountRecordDTO : public oatpp::DTO
{
	DTO_INIT(ApplyDiscountRecordDTO, DTO);

	// 验房跟踪记录ID
	DTO_FIELD(String, ardr_id);
	DTO_FIELD_INFO(ardr_id) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.ardr-id");
	}
	// 房屋名称
	DTO_FIELD(String, room_name);
	DTO_FIELD_INFO(room_name) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.room-name");
	}
	// 操作人员
	DTO_FIELD(String, create_user_name);
	DTO_FIELD_INFO(create_user_name) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.create-user-name");
	}
	// 创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.create-time");
	}
	// 审核状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.");
	}
	// 是否违规
	DTO_FIELD(String, is_true);
	DTO_FIELD_INFO(is_true) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.is-true");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.remark");
	}

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 优惠申请跟踪记录分页传输对象
 */
class ApplyDiscountRecordPageDTO : public PageDTO<ApplyDiscountRecordDTO::Wrapper>
{
	DTO_INIT(ApplyDiscountRecordPageDTO, PageDTO<ApplyDiscountRecordDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountRecordDTO_H