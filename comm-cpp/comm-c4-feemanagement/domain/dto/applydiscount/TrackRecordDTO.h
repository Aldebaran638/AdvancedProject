#pragma once

#ifndef _TRACKRECORDDTO_H_
#define _TRACKRECORDDTO_H_


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 添加跟踪记录传输对象
class TrackRecordADDDTO : public oatpp::DTO {
	DTO_INIT(TrackRecordADDDTO, DTO);
	// 跟踪记录ID 
	API_DTO_FIELD_DEFAULT(String, ardr_id, ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id"));
	// 房屋 
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("apply_room_discount.field.room_name"));
	// 创建人（操作人员） 
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("apply_room_discount_record.field.create_user_name"));
	// 创建时间 
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("apply_room_discount_record.field.create_time"));
	// 状态 
	 API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("apply_room_discount_record.field.state"));
	// 是否违规
	API_DTO_FIELD_DEFAULT(String, is_true, ZH_WORDS_GETTER("apply_room_discount_record.field.is_true"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("apply_room_discount_record.field.remark"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// 传输对象
class TrackRecordDTO : public TrackRecordADDDTO {
	DTO_INIT(TrackRecordDTO, TrackRecordADDDTO);
	// 跟踪记录id
	DTO_FIELD(String, ardr_id);
	DTO_FIELD_INFO(ardr_id) {
		info->description = ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id");
	}
};

// 分页数据传输对象
class TrackRecordPageDTO : public PageDTO<TrackRecordDTO::Wrapper>
{
	DTO_INIT(TrackRecordPageDTO, PageDTO<TrackRecordDTO::Wrapper>);
};

// 删除跟踪记录传输对象
class TrackRecordDeleteDTO : public oatpp::DTO {
	DTO_INIT(TrackRecordDeleteDTO, DTO);
	// 跟踪记录id
	DTO_FIELD(String, ardr_id);
	DTO_FIELD_INFO(ardr_id) {
		info->description = ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id");
	}
};


#include OATPP_CODEGEN_END(DTO)


#endif // !_TRACKRECORDDTO_H_
