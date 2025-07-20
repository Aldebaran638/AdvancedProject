
// 文件：domain/dto/communityvenue/CommunityVenueDTO.h
#pragma once
#ifndef _COMMUNITYVENUEDTO_H_
#define _COMMUNITYVENUEDTO_H_

#include "domain/GlobalInclude.h"
#include "CommunityVenueAddDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 场馆目录传输模型
 * 用于列表展示、详情查看、表单回填
 */
class CommunityVenueDTO : public CommunityVenueAddDTO {
public:
    DTO_INIT(CommunityVenueDTO, CommunityVenueAddDTO);


    /* 场馆编号（varchar(30)）*/
    DTO_FIELD(String, venueId);
    DTO_FIELD_INFO(venueId) {
        info->description = ZH_WORDS_GETTER("venue.field.venueId");
    }


    /* 状态 status_cd（varchar(2)），可预约/不可预约 */
    DTO_FIELD(String, statusCd);
    DTO_FIELD_INFO(statusCd) {
        info->description = ZH_WORDS_GETTER("venue.field.statusCd");
    }
    /* 小区ID community_id（varchar(30)）*/
    DTO_FIELD(String, communityId);
    DTO_FIELD_INFO(communityId) {
        info->description = ZH_WORDS_GETTER("venue.field.communityId");
    }
    /* 关联业务ID b_id（varchar(30)）*/
    DTO_FIELD(String, bId);
    DTO_FIELD_INFO(bId) {
        info->description = ZH_WORDS_GETTER("venue.field.bId");
    }

    // create_time 由数据库自动生成，不放到 AddDTO 中
};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEDTO_H_
