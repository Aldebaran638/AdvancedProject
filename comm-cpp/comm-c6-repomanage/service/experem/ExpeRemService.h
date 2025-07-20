#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mlg
 @Date: 2025-05-28

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
#ifndef _EXPEREM_SERVICE_
#define _EXPEREM_SERVICE_
#include "domain/vo/experem/ExpeRemVO.h"
#include "domain/query/experem/ExpeRemQuery.h"
#include "domain/dto/experem/ExpeRemDTO.h"


class ExpeRemService
{
public:
    // 分页查询经验移除相关数据
    ExpeRemPageDTO::Wrapper listAll(const ExpeRemQuery::Wrapper& query);

};


/**
 * 示例服务实现，演示基础的示例服务实现
 */
class overExpeRemService
{
public:
    // 分页查询所有数据
    overExpeRemPageDTO::Wrapper listAll(const overExpeRemQuery::Wrapper& query);
};

#endif // !_EXPEREM_SERVICE_