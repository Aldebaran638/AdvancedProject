#pragma once

#ifndef _TRACKRECORDQUERY_H_
#define _TRACKRECORDQUERY_H_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 分页查询对象
class TrackRecordQuery : public PageQuery {
	DTO_INIT(TrackRecordQuery, PageQuery);
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
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_TRACKRECORDQUERY_H_
