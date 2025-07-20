#pragma once

#ifndef _OWNER_QUERY_
#define _OWNER_QUERY_

#include "domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 通过业主ID查询业主详细信息
 */
class OwnerQuery : public oatpp::DTO
{
	DTO_INIT(OwnerQuery, DTO);
	// 业主ID
	DTO_FIELD(String, owner_id);
	DTO_FIELD_INFO(owner_id) {
		info->description = ZH_WORDS_GETTER("owner.field.ownerId");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("owner.field.name");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("owner.field.sex");
	}
	// 年龄
	DTO_FIELD(String, age);//这里是UInt32还是Int32？(待修改)
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("owner.field.age");
	}
	// 身份证
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("owner.field.idCard");
	}
	// 联系方式
	DTO_FIELD(String, link);//这里是UInt32还是Int32？(待修改)
	DTO_FIELD_INFO(link) {
		info->description = ZH_WORDS_GETTER("owner.field.phone");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_OWNER_QUERY_#pragma once
