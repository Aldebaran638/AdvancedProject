#pragma once
#ifndef _COMMUNITYVENUEADDTO_H_
#define _COMMUNITYVENUEADDTO_H_

#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加场馆数据传输对象
 */
class CommunityVenueAddDTO : public oatpp::DTO {
    DTO_INIT(CommunityVenueAddDTO, DTO);



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


    /* 关联一个 PayloadDTO 负载数据对象（如有鉴权需求） */
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEADDTO_H_
