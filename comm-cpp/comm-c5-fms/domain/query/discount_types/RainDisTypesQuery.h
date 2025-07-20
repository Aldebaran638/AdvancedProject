#pragma once
#ifndef _RAINDISTYPESQUERY_H_
#define _RAINDISTYPESQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取优惠类型分页
 */
class RainDisTypesQuery : public PageQuery
{
	DTO_INIT(RainDisTypesQuery, PageQuery);
	// 类型编码
	API_DTO_FIELD_DEFAULT(String, apply_type, ZH_WORDS_GETTER("discount-type.field.apply_type"));
	// 类型名称
	API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("discount-type.field.type_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // _RAINDISTYPESQUERY_H_
