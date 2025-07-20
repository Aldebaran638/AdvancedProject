#ifndef _OWEINFORMATIONVO_H_
#define _OWEINFORMATIONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/arrears_information/OweInformationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class OweInformationJsonVO : public JsonVO<OweInformationDTO::Wrapper> {
	DTO_INIT(OweInformationJsonVO, JsonVO<OweInformationDTO::Wrapper>);
};

class CombineOweInformationJsonVO : public JsonVO<OweInformationPageDTO::Wrapper> {
	DTO_INIT(CombineOweInformationJsonVO, JsonVO<OweInformationPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_OWEINFORMATIONVO_H_