#pragma once
#ifndef _FEEMGRQUERY_H_
#define _FEEMGRQUERY_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class FeeMgrQuery :public PageQuery
{
	DTO_INIT(FeeMgrQuery, PageQuery);

	//费用Id
	API_DTO_FIELD_DEFAULT(String, discount_id, ZH_WORDS_GETTER("FeeMgr.field.discount_id"));
	//费用名称
	API_DTO_FIELD_DEFAULT(String, discount_name, ZH_WORDS_GETTER("FeeMgr.field.discount_name"));
	//费用类型
	API_DTO_FIELD_DEFAULT(String, discount_type, ZH_WORDS_GETTER("FeeMgr.field.discount_type"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_FEEMGRQUERY_H_
