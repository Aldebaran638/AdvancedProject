#pragma once
#ifndef _FORCEBACKQUERY_H_
#define _FORCEBACKQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个强制回单的数据传输模型
 */
class ForceBackQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(ForceBackQuery, PageQuery);
	// 小区id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("forceback.force-back.community_id"));
	// 报修类型 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("forceback.force-back.repair_type"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("forceback.force-back.repair_name"));
	//报修电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("forceback.force-back.tel"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FORCEBACKQUERY_H_
