#pragma once
#ifndef _OWNERDETAILDTO_H_
#define _OWNERDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 添加预存（账户明细）传输模型
*/
class OwnerDetailAddDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailAddDTO, DTO);
	
	// 业主手机号
	API_DTO_FIELD(String, link, ZH_WORDS_GETTER("owneraccount.owner-detail.link"), true, "13111011002");
	// 业主名称
	API_DTO_FIELD(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"), true, "abc");
	// 预存金额
	API_DTO_FIELD(Float32, receivable_amount, ZH_WORDS_GETTER("owneraccount.owner-detail.receivable-amount"), true, 114514.00);
	// 支付方式
	API_DTO_FIELD(String, prime_rate, ZH_WORDS_GETTER("owneraccount.owner-detail.prime-rate"), true, "1");
	// 账户类型（对象类型）
	API_DTO_FIELD(String, obj_type, ZH_WORDS_GETTER("owneraccount.owner-detail.obj-type"), true, "6006");
	// 备注（说明）
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("owneraccount.owner-detail.remark"), false, "defaultdetail");
	// 小区ID
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("owneraccount.owner-detail.community-id"), true, "2024022647620054");

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
	
};

/**
* 撤销预存（账户明细）传输模型
*/
class OwnerDetailUndoDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailUndoDTO, DTO);

	// 账户编号
	API_DTO_FIELD(String, pre_detail_id, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-id"), true, "12240897944722739200");
	// 撤销原因
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("owneraccount.owner-detail.remark"), true, "defaultreason");

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
* 账户明细传输模型(比较完整）
*/
class OwnerDetailDTO : public OwnerDetailAddDTO
{
	DTO_INIT(OwnerDetailDTO, OwnerDetailAddDTO);

	// 明细编号
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-id"));
	// 交易编号
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("owneraccount.owner-detail.order-id"));
	// 明细类型
	API_DTO_FIELD_DEFAULT(String, detail_type, ZH_WORDS_GETTER("owneraccount.owner-detail.detial-type"));
	// 交易时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owneraccount.owner-detail.create-time"));
	// 账户金额
	API_DTO_FIELD_DEFAULT(Float32, amount, ZH_WORDS_GETTER("owneraccount.owner-detail.amount"));
	// 收据ID
	API_DTO_FIELD_DEFAULT(String, ar_id, ZH_WORDS_GETTER("owneraccount.owner-detail.ar-id"));
	// 实收金额
	API_DTO_FIELD_DEFAULT(Float32, received_amount, ZH_WORDS_GETTER("owneraccount.owner-detail.received_amount"));
	// 数据状态
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("owneraccount.owner-detail.status-cd"));
	// 关联账户
	API_DTO_FIELD_DEFAULT(String, rel_acct_id, ZH_WORDS_GETTER("owneraccount.owner-detail.rel-acct-id"));
	// 业务ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("owneraccount.owner-detail.b-id"));
	
};


/**
* 账户明细获取（条件+分页）传输模型
*/
class OwnerDetailGetDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailGetDTO, DTO);

	// 明细编号
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-id"));
	// 交易编号
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("owneraccount.owner-detail.order-id"));
	// 账户名称
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"));
	// 明细类型
	API_DTO_FIELD_DEFAULT(String, detail_type, ZH_WORDS_GETTER("owneraccount.owner-detail.detial-type"));
	// 金额/积分
	API_DTO_FIELD_DEFAULT(Float32, amount, ZH_WORDS_GETTER("owneraccount.owner-detail.amount"));
	// 交易时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owneraccount.owner-detail.create-time"));
	// 说明
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("owneraccount.owner-detail.remark"));
	// 明细类型
	API_DTO_FIELD_DEFAULT(String, detail_type_text, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-type-txt"));
};


/**
 * 账户明细分页传输对象
 */
class OwnerDetailPageDTO : public PageDTO<OwnerDetailGetDTO::Wrapper>
{
	DTO_INIT(OwnerDetailPageDTO, PageDTO<OwnerDetailGetDTO::Wrapper>);
};


/**
* 业主名称获取（条件+分页）传输模型
*/
class OwnerDetailAccountNameDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailAccountNameDTO, DTO);

	// 账户名称
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"));

};


/**
 * 业主名称分页传输对象
 */
class OwnerDetailAccountNamePageDTO : public PageDTO<OwnerDetailAccountNameDTO::Wrapper>
{
	DTO_INIT(OwnerDetailAccountNamePageDTO, PageDTO<OwnerDetailAccountNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERDETAILDTO_H_
