#pragma once

#ifndef _COMMUNITYVENUEMODIFYDTO_H_
#define _COMMUNITYVENUEMODIFYDTO_H_

#include "domain/GlobalInclude.h"
#include "CommunityVenueAddDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改场馆数据传输对象
 */
class CommunityVenueModifyDTO : public CommunityVenueAddDTO {
public:

    DTO_INIT(CommunityVenueModifyDTO, CommunityVenueAddDTO);

    /* 场馆编号（venue_id）— 必填，用于定位要修改的记录 */
    DTO_FIELD(String, venueId);
    DTO_FIELD_INFO(venueId) {
        info->description = ZH_WORDS_GETTER("venue.field.venueId");
    }

    /* 场馆名称（varchar(30)）*/
    DTO_FIELD(String, name);
    DTO_FIELD_INFO(name) {
        info->description = ZH_WORDS_GETTER("venue.field.name");
    }
    /* 备注/描述（varchar(512)）*/
    DTO_FIELD(String, remark);
    DTO_FIELD_INFO(remark) {
        info->description = ZH_WORDS_GETTER("venue.field.remark");
    }
    /* 开场时间 start_time（varchar(30)）*/
    DTO_FIELD(String, startTime);
    DTO_FIELD_INFO(startTime) {
        info->description = ZH_WORDS_GETTER("venue.field.startTime");
    }

    /* 关场时间 end_time（varchar(30)）*/
    DTO_FIELD(String, endTime);
    DTO_FIELD_INFO(endTime) {
        info->description = ZH_WORDS_GETTER("venue.field.endTime");
    }


};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEMODIFYDTO_H_
