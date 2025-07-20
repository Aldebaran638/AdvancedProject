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
#ifndef _TELLREPAIR_MAPPER_
#define _TELLREPAIR_MAPPER_

#include "Mapper.h"
#include "../../domain/do/tell-repair/TellRepairDO.h"

/**
 * 字段匹配映射
 */
class TellRepairMapper : public Mapper<TellRepairDO>
{
public:
	TellRepairDO mapper(ResultSet* resultSet) const override
	{
		TellRepairDO data;
		data.setRepairId(resultSet->getString(1));
		data.setRepairType(resultSet->getString(2));
		data.setRepairTypeTxt(resultSet->getString(3)); // 报修类型文本，紧跟在报修类型后
		data.setRepairName(resultSet->getString(4));
		data.setTel(resultSet->getString(5));
		data.setAppointmentTime(resultSet->getString(6));
		data.setCreateTime(resultSet->getString(7));
		data.setState(resultSet->getString(8));
		data.setStateTxt(resultSet->getString(9));     // 状态文本，紧跟在状态后
		return data;
	}
};

/**
 * 字段匹配映射-智能指针版本
 */
class PtrTellRepairMapper : public Mapper<PtrTellRepairDO>
{
public:
	PtrTellRepairDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TellRepairDO>();
		data->setRepairId(resultSet->getString(1));
		data->setRepairType(resultSet->getString(2));
		data->setRepairTypeTxt(resultSet->getString(3)); // 报修类型文本，紧跟在报修类型后
		data->setRepairName(resultSet->getString(4));
		data->setTel(resultSet->getString(5));
		data->setAppointmentTime(resultSet->getString(6));
		data->setCreateTime(resultSet->getString(7));
		data->setState(resultSet->getString(8));
		data->setStateTxt(resultSet->getString(9));     // 状态文本，紧跟在状态后
		return data;
	}
};



#endif // !_TELLREPAIR_MAPPER_