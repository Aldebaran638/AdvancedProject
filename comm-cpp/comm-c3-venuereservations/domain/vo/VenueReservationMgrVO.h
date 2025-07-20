#pragma once
#ifndef _VENUERESERVATIONMGRVO_H_
#define _VENUERESERVATIONMGRVO_H_
#include "../GlobalInclude.h"
#include "../dto/VenueReservationMgrDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class VenueReservationMgrJsonVO : public JsonVO<VenueReservationMgrDTO::Wrapper> {
    DTO_INIT(VenueReservationMgrJsonVO, JsonVO<VenueReservationMgrDTO::Wrapper>);
};

class VenueReservationMgrPageJsonVO : public JsonVO<VenueReservationMgrPageDTO::Wrapper> {
    DTO_INIT(VenueReservationMgrPageJsonVO, JsonVO<VenueReservationMgrPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_VENUERESERVATIONMGRVO_H_