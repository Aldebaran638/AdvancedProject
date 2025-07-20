#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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

#ifndef _TABLEREADINGTYPEMAPPER_H_
#define _TABLEREADINGTYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/table-reading-type/TableReadingTypeDO.h"

/**
 * 示例表字段匹配映射
 */
class TableReadingTypeMapper : public Mapper<TableReadingTypeDO>
{
public:
    TableReadingTypeDO mapper(ResultSet* resultSet) const override
    {
        TableReadingTypeDO data;
        data.setTypeId(resultSet->getString(1));      // type_id
        data.setTypeName(resultSet->getString(2));    // typename
        data.setRemark(resultSet->getString(3));       // remark
		data.setCreateTime(resultSet->getString(4)); // create_time
        return data;
    }
};
/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrTableReadingTypeMapper : public Mapper<PtrTableReadingTypeDO>
{
public:
	PtrTableReadingTypeDO mapper(ResultSet* resultSet) const override
	{
		
        auto data = std::make_shared<TableReadingTypeDO>();
        data->setTypeId(resultSet->getString(1));      // type_id
        data->setTypeName(resultSet->getString(2));    // typename
        data->setRemark(resultSet->getString(3));       // remark
        data->setCreateTime(resultSet->getString(4)); // create_time

		return data;
	}
};

#endif // !_TABLEREADINGTYPEMAPPER_H_