#pragma once
#ifndef _MEMBER_QUERY_
#define _MEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class MemberQuery : public PageQuery
{
	DTO_INIT(MemberQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("member.field.name");
	}
	// 电话号
	DTO_FIELD(String, link);
	DTO_FIELD_INFO(link) {
		info->description = ZH_WORDS_GETTER("member.field.link");
	}
	// 身份证
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("member.field.id_card");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("member.field.sex");
	}
	// 成员类型
	DTO_FIELD(String, owner_type_cd);
	DTO_FIELD_INFO(owner_type_cd) {
		info->description = ZH_WORDS_GETTER("member.field.owner_type_cd");
	}
	// 家庭地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("member.field.address");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("member.field.remark");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_Query : public PageQuery