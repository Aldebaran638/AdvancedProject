#pragma once
#ifndef _COMMUNITYVENUEDELETEDTO_H_
#define _COMMUNITYVENUEDELETEDTO_H_

#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 删除场馆数据传输对象
 * 支持批量删除，通过传入场馆编号列表
 */
class CommunityVenueDeleteDTO : public oatpp::DTO {
    DTO_INIT(CommunityVenueDeleteDTO, DTO);

    /* 场馆编号列表 */
    DTO_FIELD(String, venueIds);
    DTO_FIELD_INFO(venueIds) {
        info->description = ZH_WORDS_GETTER("venue.field.venueIds");
    }

    /* 可选：鉴权负载 */
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEDELETEDTO_H_
