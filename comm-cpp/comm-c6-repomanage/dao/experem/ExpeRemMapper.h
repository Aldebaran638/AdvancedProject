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
#ifndef _EXPEREM_MAPPER_
#define _EXPEREM_MAPPER_

#include "Mapper.h"
#include "../../domain/do/experem/ExpeRemDO.h"

/**
 * 费用提醒表字段匹配映射
 */
class ExpeRemMapper : public Mapper<ExpeRemDO>
{
public:
    ExpeRemDO mapper(ResultSet* resultSet) const override
    {
        ExpeRemDO data;
        data.setObjName(resultSet->getString("objName"));
        data.setLink(resultSet->getString("link"));
        data.setOwnerName(resultSet->getString("ownerName"));
        data.setFeeName(resultSet->getString("feename"));
        return data;
    }
};

/**
 * 费用提醒表字段匹配映射-创建智能指针对象
 */
class PtrExpeRemMapper : public Mapper<PtrExpeRemDO>
{
public:
    PtrExpeRemDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<ExpeRemDO>();
        data->setObjName(resultSet->getString("objName"));
        data->setLink(resultSet->getString("link"));
        data->setOwnerName(resultSet->getString("ownerName"));
        data->setFeeName(resultSet->getString("feename"));
        return data;
    }
};


/////////////
/**
 * 示例表字段匹配映射
 */
class overExpeRemMapper : public Mapper<overExpeRemDO>
{
public:
	overExpeRemDO mapper(ResultSet* resultSet) const override
	{
		overExpeRemDO data;
		data.setFeeid(resultSet->getString(1));
		data.setBuildno(resultSet->getString(2));
		data.setExpense(resultSet->getString(3));
		data.setEndtime(resultSet->getString(4));
		data.setRemainingtime(resultSet->getString(5));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrOverExpeRemMapper : public Mapper<PtroverExpeRemDO>
{
public:
	PtroverExpeRemDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<overExpeRemDO>();
		data->setFeeid(resultSet->getString(1));
		data->setBuildno(resultSet->getString(2));
		data->setExpense(resultSet->getString(3));
		data->setEndtime(resultSet->getString(4));
		data->setRemainingtime(resultSet->getString(5));
		return data;
	}
};



#endif // !_PAY_FEE_MAPPER_