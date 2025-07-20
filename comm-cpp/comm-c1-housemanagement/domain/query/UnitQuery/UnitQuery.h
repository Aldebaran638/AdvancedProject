#pragma once
#ifndef _UNIT_QUERY_
#define _UNIT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnitQuery : public PageQuery
{
	DTO_INIT(UnitQuery, PageQuery);

	//单元编号
	DTO_FIELD(String, unit_num);
	DTO_FIELD_INFO(unit_num) {
		info->description = ZH_WORDS_GETTER("unit.field.unit_num");
	}
	//楼ID
	DTO_FIELD(String, floor_id);
	DTO_FIELD_INFO(floor_id) {
		info->description = ZH_WORDS_GETTER("unit.field.floor_id");
	}
	//楼编号(连接查询用)
	DTO_FIELD(String, floor_num);
	DTO_FIELD_INFO(floor_num) {
		info->description = ZH_WORDS_GETTER("floor.field.floor_num");
	}
	//小区ID(连接查询用)
	DTO_FIELD(String, community_id);
	DTO_FIELD_INFO(community_id) {
		info->description = ZH_WORDS_GETTER("floor.field.community_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif