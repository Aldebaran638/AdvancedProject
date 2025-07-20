#ifndef _EXRMREMINDERSVO_H_
#define _EXRMREMINDERSVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/arrears_reminders/ExRmremindersDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ExRmremindersJsonVO : public JsonVO<ExRmremindersDTO::Wrapper> {
	DTO_INIT(ExRmremindersJsonVO, JsonVO<ExRmremindersDTO::Wrapper>);
};

class CombineExRmremindersJsonVO : public JsonVO<CombineExRmremindersDTO::Wrapper> {
	DTO_INIT(CombineExRmremindersJsonVO, JsonVO<CombineExRmremindersDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXRMREMINDERSVO_H_