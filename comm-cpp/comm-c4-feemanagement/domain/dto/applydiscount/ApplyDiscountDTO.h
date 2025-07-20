#pragma once
#ifndef APPLY_DISCOUNTDTO_H
#define APPLY_DISCOUNTDTO_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//新增优惠申请传输对象

class ApplyDiscountAddDTO : public oatpp::DTO
{
	DTO_INIT(ApplyDiscountAddDTO, DTO);
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

	// 申请人
	DTO_FIELD(String, createUserName);
	DTO_FIELD_INFO(createUserName) {
		info->description = ZH_WORDS_GETTER("discount.field.createUserName");
	}
	// 申请电话
	DTO_FIELD(String, createUserTel);
	DTO_FIELD_INFO(createUserTel) {
		info->description = ZH_WORDS_GETTER("discount.field.createUserTel");
	}
	// 开始时间
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("discount.field.startTime");
	}
	// 结束时间
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("discount.field.endTime");
	}
	// 申请说明
	DTO_FIELD(String, createRemark);
	DTO_FIELD_INFO(createRemark) {
		info->description = ZH_WORDS_GETTER("discount.field.createRemark");
	}

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


//新增优化传输对象

class ApplyDiscountDTO : public ApplyDiscountAddDTO
{
	DTO_INIT(ApplyDiscountDTO, ApplyDiscountAddDTO);
	// 编号
	DTO_FIELD(String, ardId);
	DTO_FIELD_INFO(ardId) {
		info->description = ZH_WORDS_GETTER("discount.field.ardId");
	}
	// 小区编号
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("discount.field.communityId");
	}
	// 房屋编号
	DTO_FIELD(String, roomId);
	DTO_FIELD_INFO(roomId) {
		info->description = ZH_WORDS_GETTER("discount.field.roomId");
	}
	// 优惠编号
	DTO_FIELD(String, discountId);
	DTO_FIELD_INFO(discountId) {
		info->description = ZH_WORDS_GETTER("discount.field.discountId");
	}
	// 验房人
	DTO_FIELD(String, checkUserId);
	DTO_FIELD_INFO(checkUserId) {
		info->description = ZH_WORDS_GETTER("discount.field.checkUserId");
	}
	// 通过人
	DTO_FIELD(String, reviewUserId);
	DTO_FIELD_INFO(reviewUserId) {
		info->description = ZH_WORDS_GETTER("discount.field.reviewUserId");
	}
	// 审核状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("discount.field.state");
	}
	// 验房备注信息
	DTO_FIELD(String, checkRemark);
	DTO_FIELD_INFO(checkRemark) {
		info->description = ZH_WORDS_GETTER("discount.field.checkRemark");
	}
	// 通过备注信息
	DTO_FIELD(String, reviewRemark);
	DTO_FIELD_INFO(reviewRemark) {
		info->description = ZH_WORDS_GETTER("discount.field.reviewRemark");
	}
	// 创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("discount.field.createTime");
	}
	// 数据状态
	DTO_FIELD(String, statusCd);
	DTO_FIELD_INFO(statusCd) {
		info->description = ZH_WORDS_GETTER("discount.field.statusCd");
	}
	// 是否可用
	DTO_FIELD(String, inUse);
	DTO_FIELD_INFO(inUse) {
		info->description = ZH_WORDS_GETTER("discount.field.inUse");
	}
	// 业务id
	DTO_FIELD(String, bId);
	DTO_FIELD_INFO(bId) {
		info->description = ZH_WORDS_GETTER("discount.field.bId");
	}
	// 费用id
	DTO_FIELD(String, feeId);
	DTO_FIELD_INFO(feeId) {
		info->description = ZH_WORDS_GETTER("discount.field.feeId");
	}
	// 返还方式
	DTO_FIELD(String, returnWay);
	DTO_FIELD_INFO(returnWay) {
		info->description = ZH_WORDS_GETTER("discount.field.returnWay");
	}
	// 返还金额
	DTO_FIELD(String, returnAmount);
	DTO_FIELD_INFO(returnAmount) {
		info->description = ZH_WORDS_GETTER("discount.field.returnAmount");
	}
};


//优惠申请分页传输对象

class ApplyDiscountPageDTO : public PageDTO<ApplyDiscountDTO::Wrapper>
{
	DTO_INIT(ApplyDiscountPageDTO, PageDTO<ApplyDiscountDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* APPLY_DISCOUNT_H */