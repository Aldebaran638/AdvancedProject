#pragma once
#ifndef _ROOM_QUERY_
#define _ROOM_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class RoomQuery : public PageQuery
{
	DTO_INIT(RoomQuery, PageQuery);
	// 房屋编号
	DTO_FIELD(String, room_num);
	DTO_FIELD_INFO(room_num) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.room_num");
	}
	//楼层
	DTO_FIELD(String, layer);
	DTO_FIELD_INFO(layer) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.layer");
	}
	//室内面积
	DTO_FIELD(Float64, built_up_area);
	DTO_FIELD_INFO(built_up_area) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.build_up_area");
	}
	// 状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.state");
	}
	// 类型
	DTO_FIELD(String, room_type);
	DTO_FIELD_INFO(room_type) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.room_type");
	}
	// 租金
	DTO_FIELD(Float64, room_rent);
	DTO_FIELD_INFO(room_rent) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.room_rent");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ROOM_QUERY_