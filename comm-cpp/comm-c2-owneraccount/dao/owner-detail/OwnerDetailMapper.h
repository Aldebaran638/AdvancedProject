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
#ifndef _OWNERDETAILMAPPER_H_
#define _OWNERDETAILMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/owner-detail/OwnerDetailDO.h"

/**
 * 账户明细表字段匹配映射
 */
class OwnerDetailMapper : public Mapper<OwnerDetailDO>
{
public:
	OwnerDetailDO mapper(ResultSet* resultSet) const override
	{
		OwnerDetailDO data;
		data.setDetailId(resultSet->getString(1));
		data.setOrderId(resultSet->getString(2));
		data.setOwnerName(resultSet->getString(3));
		data.setDetailType(resultSet->getString(4));
		data.setAmount(resultSet->getDouble(5));
		data.setCreateTime(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));
		data.setDetailTypeText(resultSet->getString(8));
		return data;
	}
};

/**
 * 账户明细表字段匹配映射-创建智能指针对象
 */
class PtrOwnerDetailMapper : public Mapper<PtrOwnerDetailDO>
{
public:
	PtrOwnerDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerDetailDO>();
		data->setDetailId(resultSet->getString(1));
		data->setOrderId(resultSet->getString(2));
		data->setOwnerName(resultSet->getString(3));
		data->setDetailType(resultSet->getString(4));
		data->setAmount(resultSet->getDouble(5));
		data->setCreateTime(resultSet->getString(6));
		data->setRemark(resultSet->getString(7));
		data->setDetailTypeText(resultSet->getString(8));
		return data;
	}
};

/**
 * 业主名称表字段匹配映射
 */
class OwnerDetailAccountNameMapper : public Mapper<OwnerDetailAccountNameDO>
{
public:
	OwnerDetailAccountNameDO mapper(ResultSet* resultSet) const override
	{
		OwnerDetailAccountNameDO data;
		data.setOwnerName(resultSet->getString(1));
		return data;
	}
};

/**
 * 业主名称表字段匹配映射-创建智能指针对象
 */
class PtrOwnerDetailAccountNameMapper : public Mapper<PtrOwnerDetailAccountNameDO>
{
public:
	PtrOwnerDetailAccountNameDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerDetailAccountNameDO>();
		data->setOwnerName(resultSet->getString(1));
		return data;
	}
};

#endif // !_OWNERDETAILMAPPER_H_