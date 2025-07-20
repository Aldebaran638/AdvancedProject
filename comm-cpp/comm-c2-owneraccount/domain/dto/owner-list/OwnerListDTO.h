#pragma once
#ifndef _OWNERLISTDTO_H_
#define _OWNERLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 账户列表传输模型
*/
class OwnerListDTO : public oatpp::DTO
{
	DTO_INIT(OwnerListDTO, DTO);

	// 账户编号
	API_DTO_FIELD_DEFAULT(String, acct_id, ZH_WORDS_GETTER("owneraccount.owner-list.acct-id"));
	// 账户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owneraccount.owner-list.name"));
	// 身份证号
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owneraccount.owner-list.id-card"));
	// 手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owneraccount.owner-list.list"));
	// 账户类型
	API_DTO_FIELD_DEFAULT(String, acct_type, ZH_WORDS_GETTER("owneraccount.owner-list.acct-type"));
	// 账户金额
	API_DTO_FIELD_DEFAULT(Float32, amount, ZH_WORDS_GETTER("owneraccount.owner-list.amount"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owneraccount.owner-list.create-time"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, acct_type_text, ZH_WORDS_GETTER("owneraccount.owner-list.acct-type-text"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
 * 账户列表分页传输对象
 */
class OwnerListPageDTO : public PageDTO<OwnerListDTO::Wrapper>
{
	DTO_INIT(OwnerListPageDTO, PageDTO<OwnerListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERLISTDTO_H_
