#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _TELL_REPAIR_QUERY_
#define _TELL_REPAIR_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 电话报修分页查询对象
 */
class TellRepairQuery : public PageQuery
{
    DTO_INIT(TellRepairQuery, PageQuery);

    // 小区id
    DTO_FIELD(String, community_id);
    DTO_FIELD_INFO(community_id)
    {
        info->description = ZH_WORDS_GETTER("tell-repair.field.community_id");
    }

    // 工单编号
    DTO_FIELD(String, repair_id);
    DTO_FIELD_INFO(repair_id)
    {
        info->description = ZH_WORDS_GETTER("tell-repair.field.repair_id");
    }

    // 报修人
    DTO_FIELD(String, repair_name);
    DTO_FIELD_INFO(repair_name)
    {
        info->description = ZH_WORDS_GETTER("tell-repair.field.repair_name");
    }

    // 联系方式
    DTO_FIELD(String, tel);
    DTO_FIELD_INFO(tel)
    {
        info->description = ZH_WORDS_GETTER("tell-repair.field.tel");
    }

    // 报修类型
    DTO_FIELD(String, repair_type);
    DTO_FIELD_INFO(repair_type)
    {
        info->description = ZH_WORDS_GETTER("tell-repair.field.repair_type");
    }
    //报修状态
    DTO_FIELD(UInt64, state);
    DTO_FIELD_INFO(state)
    {
        info->description = ZH_WORDS_GETTER("tell-repair.field.state");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TELL_REPAIR_QUERY_