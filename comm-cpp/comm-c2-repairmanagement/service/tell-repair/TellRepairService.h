#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _TELLREPAIR_SERVICE_
#define _TELLREPAIR_SERVICE_
#include "domain/vo/tell-repair/TellRepairVO.h"
#include "domain/query/tell-repair/TellRepairQuery.h"
#include "domain/dto/tell-repair/TellRepairDTO.h"

/**
 * 电话报修服务实现
 */
class TellRepairService
{
public:
	// 分页查询所有数据
	TellRepairPageDTO::Wrapper listAll(const TellRepairQuery::Wrapper &query);
	// 保存数据
	std::string saveData(const TellRepairAddDTO::Wrapper &dto);
	// 修改数据
	bool updateData(const TellRepairUpdateDTO::Wrapper &dto);
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String> &ids);
};

#endif // !_TELLREPAIR_SERVICE_
