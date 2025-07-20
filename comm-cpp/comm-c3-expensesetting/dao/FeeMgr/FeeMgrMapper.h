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
#ifndef _FEEMGRMAPPER_H_
#define _FEEMGRMAPPER_H_

#include "FeeMgrMapper.h"
#include "../../domain/do/FeeMgrDO.h"

/**
 * 示例表字段匹配映射
 */
class FeeMgrMapper : public Mapper<FeeMgrDO>
{
public:
	FeeMgrDO mapper(ResultSet* resultSet) const override
	{
		FeeMgrDO data;
		data.setDiscount_id(resultSet->getString("discount_id"));
		data.setDiscount_name(resultSet->getString("discount_name"));
		
		data.setFee_flag(resultSet->getString("fee_flag"));
		data.setDiscount_type(resultSet->getString("discount_type"));
		data.setFee_status(resultSet->getString("status"));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */

class PtrFeeMgrMapper : public Mapper<PtrFeeMgrDO>
{
public:
	PtrFeeMgrDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<FeeMgrDO>();
		data->setDiscount_id(resultSet->getString("discount_id"));
		data->setDiscount_name(resultSet->getString("discount_name"));

		data->setFee_flag(resultSet->getString("fee_flag"));
		data->setDiscount_type(resultSet->getString("discount_type"));
		data->setFee_status(resultSet->getString("status"));
		return data;
	}
};

#endif 