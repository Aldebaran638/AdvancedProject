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
#ifndef _TABLEREADINDTYPESERVICE_H_
#define _TABLEREADINDTYPESERVICE_H_
#include "../../domain/vo/table-reading-type/TableReadingTypeVO.h"
#include "../../domain/query/table-reading-type/TableReadingTypeQuery.h"
#include "../../domain/dto/table-reading-type/TableReadingTypeDTO.h"

/**
 * 抄表类型服务实现，演示基础的示例服务实现
 */
class TableReadingTypeService
{
public:
	// 分页查询所有数据
	TableReadingTypePageDTO::Wrapper listAll(const TableReadingTypeQuery::Wrapper& query);
	// 保存数据
	std::string saveData(const TableReadingTypeAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const TableReadingTypeUpdateDTO::Wrapper& dto);
	// 删除数据（假删除）
	bool removeData(const TableReadingTypeRemoveDTO::Wrapper& dto);
};

#endif // !_TABLEREADINDTYPESERVICE_H_
