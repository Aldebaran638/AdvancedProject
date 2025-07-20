#ifndef _PAYREMAINQUBUVO_H_
#define _PAYREMAINQUBUVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/arrears_reminders/PayRemainQuBuDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class PayRemainQuBuJsonVO : public JsonVO<PayRemainQuBuDTO::Wrapper> {
	DTO_INIT(PayRemainQuBuJsonVO, JsonVO<PayRemainQuBuDTO::Wrapper>);
};
//·ÖÒ³
class CombinePayRemainQuBuJsonVO : public JsonVO<PayRemainQuBuPageDTO::Wrapper> {
	DTO_INIT(CombinePayRemainQuBuJsonVO, JsonVO<PayRemainQuBuPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PAYREMAINQUBUVO_H_