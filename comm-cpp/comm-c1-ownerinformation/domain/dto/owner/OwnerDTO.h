#pragma once

#ifndef _OWNER_DTO_H_
#define _OWNER_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class OwnerAddDTO : public oatpp::DTO {
    DTO_INIT(OwnerAddDTO, DTO);

    API_DTO_FIELD_DEFAULT(String, member_id, ZH_WORDS_GETTER("owner.field.member_id"));
    API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("owner.field.owner_id"));
    API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("owner.field.b_id"));
    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owner.field.name"));
    API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("owner.field.sex"));
    API_DTO_FIELD_DEFAULT(String, age, ZH_WORDS_GETTER("owner.field.age"));
    API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owner.field.link"));
    API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("owner.field.user_id"));
    API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("owner.field.remark"));
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owner.field.create_time"));
    API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("owner.field.status_cd"));
    API_DTO_FIELD_DEFAULT(String, owner_type_cd, ZH_WORDS_GETTER("owner.field.owner_type_cd"));
    API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("owner.field.community_id"));
    API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owner.field.id_card"));
    API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("owner.field.state"));
    API_DTO_FIELD_DEFAULT(String, owner_flag, ZH_WORDS_GETTER("owner.field.owner_flag"));
    API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("owner.field.address"));
    API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("owner.field.create_by"));
    API_DTO_FIELD_DEFAULT(String, room_num, ZH_WORDS_GETTER("owner.field.room_num"));


    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class OwnerDTO : public OwnerAddDTO {
    DTO_INIT(OwnerDTO, DTO);

    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owner.field.name"));
    API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("owner.field.sex"));
    API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owner.field.link"));
    API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("owner.field.remark"));
    API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owner.field.id_card"));
    API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("owner.field.address"));
    API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("owner.field.owner_id"));
    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


/**
 * 选择业主列表传输对象(分页)
 */
class OwnerPageDTO : public PageDTO<OwnerDTO::Wrapper>
{
    DTO_INIT(OwnerPageDTO,PageDTO<OwnerDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNER_DTO_