#pragma once
#ifndef _YYYCDISTYPESQUERY_
#define _YYYCDISTYPESQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改优惠类型
 */
class YyycDisTypesUpdateQuery : public PageQuery
{
	DTO_INIT(YyycDisTypesUpdateQuery, PageQuery);
	// 类型名称
	API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("type.field.type_name"));
	// 类型描述
	API_DTO_FIELD_DEFAULT(String, type_desc, ZH_WORDS_GETTER("type.field.type_desc"));
};


/**
 * 删除优惠类型
 */
class YyycDisTypesDeleteQuery : public PageQuery
{
	DTO_INIT(YyycDisTypesDeleteQuery, PageQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 

