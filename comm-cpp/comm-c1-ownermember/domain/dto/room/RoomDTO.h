#pragma once

#ifndef _ROOM_DTO_
#define _ROOM_DTO_
#include "domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增数据传输对象
 */
//class OhouseAddDTO : 
//{
//	DTO_INIT(OhouseAddDTO, DTO);
//	// 姓名
//	DTO_FIELD(String, name);
//	DTO_FIELD_INFO(name) {
//		info->description = ZH_WORDS_GETTER("ohouse.query-all.field.name");
//	}
//	// 年龄
//	DTO_FIELD(Int32, age);
//	DTO_FIELD_INFO(age) {
//		info->description = ZH_WORDS_GETTER("sample.field.age");
//	}
//	// 性别
//	DTO_FIELD(String, sex);
//	DTO_FIELD_INFO(sex) {
//		info->description = ZH_WORDS_GETTER("sample.field.sex");
//	}
//
//	// 关联一个PayloadDTO负载数据对象
//	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
//};

/**
 * 示例传输对象
 */
class RoomDTO : public oatpp::DTO
{
	DTO_INIT(RoomDTO, DTO);
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

/**
 * 示例分页传输对象
 */
class RoomPageDTO : public PageDTO<RoomDTO::Wrapper>
{
	DTO_INIT(RoomPageDTO, PageDTO<RoomDTO::Wrapper>);
	//DTO_FIELD(String, room_num);
	//DTO_FIELD_INFO(room_num) {
	//	info->description = ZH_WORDS_GETTER("room.query-all.field.room_num");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ROOM_DTO_
