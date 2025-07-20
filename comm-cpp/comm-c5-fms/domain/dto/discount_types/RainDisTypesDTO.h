#pragma once
#ifndef _RAINDISTYPESDTO_H_
#define _RAINDISTYPESDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
    获取优惠类型名称列表
*/
class RainDisTypesGetDTO : public oatpp::DTO
{
    DTO_INIT(RainDisTypesGetDTO, DTO);

    // 类型编码
    API_DTO_FIELD_DEFAULT(String, apply_type, ZH_WORDS_GETTER("discount-type.field.apply_type"));
    // 类型名称
    API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("discount-type.field.type_name"));

    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
    添加优惠类型数据传输模型
*/
class RainDisTypesAddDTO : public oatpp::DTO
{
    DTO_INIT(RainDisTypesAddDTO, DTO);

    // 类型名称
    API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("discount-type.field.type_name"));
    // 类型描述
    API_DTO_FIELD_DEFAULT(String, type_desc, ZH_WORDS_GETTER("discount-type.field.type_desc"));
    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
 * 比较完整, 用于列表数据
 */
class RainDisTypesDTO : public RainDisTypesAddDTO
{
    DTO_INIT(RainDisTypesDTO, RainDisTypesAddDTO);

    // 类型编码
    API_DTO_FIELD_DEFAULT(String, apply_type, ZH_WORDS_GETTER("discount-type.field.apply_type"));
};

/*
    获取优惠类型分页
*/
class RainDisTypesPageDTO : public PageDTO<RainDisTypesDTO::Wrapper>
{
    DTO_INIT(RainDisTypesPageDTO, PageDTO<RainDisTypesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_RAINDISTYPESDTO_H_
