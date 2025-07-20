#pragma once
#ifndef _OWNER_QUERY_
#define _OWNER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OwnerQuery : public PageQuery
{
	DTO_INIT(OwnerQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("owner.field.id"));
	//业主姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owner.field.name"));
	//房屋编号
	API_DTO_FIELD_DEFAULT(String, room_num, ZH_WORDS_GETTER("owner.field.room_num"));
	//业主身份证
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owner.field.id_card"));
	//联系方式
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owner.field.link"));
	//业主成员姓名
	API_DTO_FIELD_DEFAULT(String, member_name, ZH_WORDS_GETTER("owner.field.member_name"));
	//业主成员联系方式
	API_DTO_FIELD_DEFAULT(String, member_link, ZH_WORDS_GETTER("owner.field.member_link"));
};


#include OATPP_CODEGEN_END(DTO)
#endif