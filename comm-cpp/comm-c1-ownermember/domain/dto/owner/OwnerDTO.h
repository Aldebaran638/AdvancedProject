#pragma once

#ifndef _OWNER_DTO_
#define _OWNER_DTO_

#include "domain/GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

    /**
 * 业主数据传输对象，用于在不同层之间传输业主信息
 */
    class OwnerDTO : public oatpp::DTO
    {
        DTO_INIT(OwnerDTO, DTO)

        // 业主ID
        DTO_FIELD(String, owner_id, "owner_id");
        // 业主姓名
        DTO_FIELD(String, name, "name");
        // 业主性别
        DTO_FIELD(String, sex, "sex");
        // 业主年龄
        DTO_FIELD(String, age, "age");
        // 业主身份证号
        DTO_FIELD(String, id_card, "id_card");
        // 业主联系方式
        DTO_FIELD(String, link, "link");
    };




#include OATPP_CODEGEN_END(DTO)
#endif