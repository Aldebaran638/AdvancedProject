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
#ifndef _WATERMETERMAPPER_H_
#define _WATERMETERMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/meterwater/WaterMeterDO.h"

/**
 * 表字段匹配映射
 */
class WaterMeterMapper : public Mapper<WaterMeterDO>
{
public:
	WaterMeterDO mapper(ResultSet* resultSet) const override
	{
		WaterMeterDO data;
		data.setWater_id(resultSet->getString(1));
		data.setB_id(resultSet->getString(2));
		data.setMeter_type(resultSet->getString(3));
		data.setObj_type(resultSet->getString(4));
		data.setPre_degrees(resultSet->getDouble(5));
		data.setCur_degrees(resultSet->getDouble(6));
		data.setPre_reading_time(resultSet->getString(7));
		data.setCur_reading_time(resultSet->getString(8));
		data.setRemark(resultSet->getString(9));
		data.setStatus_cd(resultSet->getString(10));
		data.setObj_name(resultSet->getString(11));
		data.setCreate_time(resultSet->getString(12));

		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrWaterMeterMapper : public Mapper<PtrWaterMeterDO>
{
public:
	PtrWaterMeterDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<WaterMeterDO>();
		data->setWater_id(resultSet->getString(1));
		data->setB_id(resultSet->getString(2));
		data->setMeter_type(resultSet->getString(3));
		data->setObj_type(resultSet->getString(4));
		data->setPre_degrees(resultSet->getDouble(5));
		data->setCur_degrees(resultSet->getDouble(6));
		data->setPre_reading_time(resultSet->getString(7));
		data->setCur_reading_time(resultSet->getString(8));
		data->setRemark(resultSet->getString(9));
		data->setStatus_cd(resultSet->getString(10));
		data->setObj_name(resultSet->getString(11));
		data->setCreate_time(resultSet->getString(12));
		return data;
	}
};

#endif // !_WATERMETERMAPPER_H_