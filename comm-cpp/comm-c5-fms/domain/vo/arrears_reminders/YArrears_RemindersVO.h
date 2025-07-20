#pragma once
#ifndef _ARREARS_REMINDERSVO_H_
#define _ARREARS_REMINDERSVO_H_
#include "../../GlobalInclude.h"
#include "domain/dto/arrears_reminders/YArrears_RemindersDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ´ß½ÉµÇ¼Ç
 */
class YArrears_RemindersJsonVO : public JsonVO<YArrears_RemindersAddDTO::Wrapper> {
	DTO_INIT(YArrears_RemindersJsonVO, JsonVO<YArrears_RemindersAddDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)

#endif 