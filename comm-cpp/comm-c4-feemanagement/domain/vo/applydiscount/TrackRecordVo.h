#pragma once

#ifndef _TRACKRECORDVO_H_
#define _TRACKRECORDVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/applydiscount/TrackRecordDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 跟踪记录显示JsonVO，用于响应给客户端的Json对象
class TrackRecordJsonVO : public JsonVO<TrackRecordADDDTO::Wrapper> {
	DTO_INIT(TrackRecordJsonVO, JsonVO<TrackRecordADDDTO::Wrapper>);
};

// 跟踪记录分页显示JsonVO，用于响应给客户端的Json对象
class TrackRecordPageJsonVO : public JsonVO<TrackRecordPageDTO::Wrapper> {
	DTO_INIT(TrackRecordPageJsonVO, JsonVO<TrackRecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_TRACKRECORDVO_H_
