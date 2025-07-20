#pragma

#ifndef _FLOORQUERY_H_
#define _FLOORQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FloorQuery :public PageQuery {
	//定义初始化
	DTO_INIT(FloorQuery, PageQuery);
	//楼ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("floor.field.floor_id"));
	//楼编号
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//小区楼名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("floor.field.name"));
	//用户ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("floor.field.user_id"));
	//小区ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("floor.field.community_id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif