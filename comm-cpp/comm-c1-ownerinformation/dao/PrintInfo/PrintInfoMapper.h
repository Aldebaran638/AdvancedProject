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
#ifndef _PRINTINFO_MAPPER_
#define _PRINTINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/account_receipt/account_receiptDO.h"

/**
 * 示例表字段匹配映射
 */
class PrintInfoMapper : public Mapper<AccountReceiptDO>
{
public:
	AccountReceiptDO mapper(ResultSet* resultSet) const override
	{
		AccountReceiptDO data;
		data.setAr_id(resultSet->getString(1));
		data.setCreate_time(resultSet->getString(2));
		data.setAcct_name(resultSet->getString(3));
		data.setAcct_type(resultSet->getString(4));
		data.setOwner_name(resultSet->getString(5));
		data.setReceivable_amount(resultSet->getString(6));
		data.setPrime_rate(resultSet->getString(7));
		data.setAmount(resultSet->getString(8));
		data.setRemark(resultSet->getString(9));
		data.setReceived_amount(resultSet->getString(10));
		data.setPage_name(resultSet->getString(11));
		data.setName(resultSet->getString(12));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrPrintInfoMapper : public Mapper<PtrAccountReceiptDO>
{
public:
	PtrAccountReceiptDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<AccountReceiptDO>();
		data->setAr_id(resultSet->getString(1));
		data->setCreate_time(resultSet->getString(2));
		data->setAcct_name(resultSet->getString(3));
		data->setAcct_type(resultSet->getString(4));
		data->setOwner_name(resultSet->getString(5));
		data->setReceivable_amount(resultSet->getString(6));
		data->setPrime_rate(resultSet->getString(7));
		data->setAmount(resultSet->getString(8));
		data->setRemark(resultSet->getString(9));
		data->setReceived_amount(resultSet->getString(10));
		data->setPage_name(resultSet->getString(11));
		return data;
	}
};

#endif