#pragma once
#ifndef _OWNERDETAILQUERY_H_
#define _OWNERDETAILQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询账户明细数据传输模型
 */
class OwnerDetailQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(OwnerDetailQuery, PageQuery);

	// 账户id
	API_DTO_FIELD_DEFAULT(String, acct_id, ZH_WORDS_GETTER("owneraccount.owner-detail.acct-id"));
};

/**
 * 查询业主名称数据传输模型
 */
class OwnerDetailAccountNameQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(OwnerDetailAccountNameQuery, PageQuery);

	// 账户名称
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"));
	// 手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owneraccount.owner-detail.link"));
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERDETAILQUERY_H_

