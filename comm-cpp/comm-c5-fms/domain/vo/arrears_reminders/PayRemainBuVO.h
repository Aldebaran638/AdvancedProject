#ifndef _PAYREMAINBUJSONVO_H_
#define _PAYREMAINBUJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/arrears_reminders/PayRemainBuDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class PayRemainBuJsonVO : public JsonVO<PayRemainBuDTO::Wrapper> {
	DTO_INIT(PayRemainBuJsonVO, JsonVO<PayRemainBuDTO::Wrapper>);
};
//·ÖÒ³
class CombinePayRemainBuJsonVO : public JsonVO<PayRemainBuPageDTO::Wrapper> {
	DTO_INIT(CombinePayRemainBuJsonVO, JsonVO<PayRemainBuPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PAYREMAINBUJSONVO_H_