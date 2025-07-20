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
#ifndef _REFUNDANDAUDITMAPPER_H_
#define _REFUNDANDAUDITMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/payment_reviews/RefundAndAuditDO.h"

/**
 * 退费申请数据映射
 */
class PtrApplyRefundMapper : public Mapper<PtrApplyRefundDO>
{
public:
	PtrApplyRefundDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ApplyRefundDO>();
		data->setFee_id(resultSet->getString(1));
		data->setCommunity_id(resultSet->getString(2));
		data->setB_id(resultSet->getString(3));
		data->setConfig_id(resultSet->getString(4));
		data->setFee_type_cd(resultSet->getString(5));
		data->setDetail_id(resultSet->getString(6));
		data->setCycles(resultSet->getDouble(7));
		data->setReceivable_amount(resultSet->getDouble(8));
		data->setReceived_amount(resultSet->getDouble(9));
		data->setPrime_rate(resultSet->getString(10));
		data->setRemark(resultSet->getString(11));
		data->setState(resultSet->getString(12));
		data->setStatus_cd(resultSet->getString(13));
		data->setCreate_time(resultSet->getString(14));
		data->setPay_time(resultSet->getString(15));
		return data;
	}
};

/**
 * 审核费用数据映射
 */
class PtrAuditFeeMapper : public Mapper<PtrAuditFeeDO>
{
public:
	PtrAuditFeeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<AuditFeeDO>();
		data->setAudit_id(resultSet->getString(1));
		data->setFee_id(resultSet->getString(2));
		data->setCommunity_id(resultSet->getString(3));
		data->setFee_detail_id(resultSet->getString(4));
		data->setState(resultSet->getString(5));
		data->setMessage(resultSet->getString(6));
		data->setAudit_user_id(resultSet->getString(7));
		data->setAudit_user_name(resultSet->getString(8));
		data->setCreate_time(resultSet->getString(9));
		data->setStatus_cd(resultSet->getString(10));
		return data;
	}
};

/**
 * 批量审核数据映射
 */
class PtrBatchAuditMapper : public Mapper<PtrBatchAuditDO>
{
public:
	PtrBatchAuditDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BatchAuditDO>();
		data->setBatch_id(resultSet->getString(1));
		data->setCommunity_id(resultSet->getString(2));
		data->setCreate_user_id(resultSet->getString(3));
		data->setCreate_user_name(resultSet->getString(4));
		data->setCreate_time(resultSet->getString(5));
		data->setStatus_cd(resultSet->getString(6));
		data->setState(resultSet->getString(7));
		data->setMsg(resultSet->getString(8));
		data->setRemark(resultSet->getString(9));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_