#pragma once
#ifndef _OWNERLISTQUERY_H_
#define _OWNERLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 账户列表数据传输模型
 */
class OwnerListQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(OwnerListQuery, PageQuery);


	// 账户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owneraccount.owner-list.name"));
	// 身份证号
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owneraccount.owner-list.id-card"));
	// 手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owneraccount.owner-list.list"));
	// 小区ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("owneraccount.owner-list.community-id"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERLISTQUERY_H_

