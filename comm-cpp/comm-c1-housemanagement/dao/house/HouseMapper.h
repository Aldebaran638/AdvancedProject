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
#ifndef _HOUSE_MAPPER_
#define _HOUSE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/house/HouseDO.h"

/**
 * 示例表字段匹配映射
 */
class HouseMapper : public Mapper<HouseDO>
{
public:
	HouseDO mapper(ResultSet* resultSet) const override
	{
		HouseDO data;
		data.setId(resultSet->getString("house_id"));
		data.setName(resultSet->getString("house_name"));
		//data.setAddress(resultSet->getString("address"));
		data.setHouseArea(resultSet->getString("house_area"));
		data.setDoorNumber(resultSet->getString("house_num"));
		
		//data.setPhoneNumber(resultSet->getString("house_phone"));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrHouseMapper : public Mapper<PtrHouseDO>
{
public:
	PtrHouseDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<HouseDO>();
		data->setId(resultSet->getString("house_id"));
		data->setName(resultSet->getString("house_name"));
		//data.setAddress(resultSet->getString("address"));
		data->setHouseArea(resultSet->getString("house_area"));
		data->setDoorNumber(resultSet->getString("house_num"));
		//data->setPhoneNumber(resultSet->getString("house_phone"));
		return data;
	}
};

#endif // !_HOUSE_MAPPER_