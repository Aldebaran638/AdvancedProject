#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/25 15:33:55

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
#ifndef _BLUEREFUNDADUITMAPPER_
#define _BLUEREFUNDADUITMAPPER_

#include "Mapper.h"
#include "../../domain/do/refund_reviews/BlueRefundAduitDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ReviewPageMapper : public Mapper<ReviewPageDO>
{
public:
	ReviewPageDO mapper(ResultSet* resultSet) const override
	{
		ReviewPageDO data;
		data.setReturn_fee_id(resultSet->getString(1));
		data.setDetail_id(resultSet->getString(2));
		data.setFee_type_cd(resultSet->getString(3));
		data.setCycles(resultSet->getInt(4));
		data.setCreate_time(resultSet->getString(5));
		data.setReason(resultSet->getString(6));
		data.setState(resultSet->getString(7));
		return data;
	}
};


class FeeDetailMapper : public Mapper<FeeDetailDO>
{
public:
	FeeDetailDO mapper(ResultSet* resultSet) const override
	{
		FeeDetailDO data;
		data.setDetail_id(resultSet->getString(1));
		data.setFee_label(resultSet->getString(2));
		data.setFee_type(resultSet->getString(3));
		data.setFee_object(resultSet->getString(4));
		data.setFee_item(resultSet->getString(5));
		data.setFee_state(resultSet->getString(6));
		return data;
	}
};

class FeeHistoryMapper : public Mapper<FeeHistoryDO>
{
public:
	FeeHistoryDO mapper(ResultSet* resultSet) const override
	{
		FeeHistoryDO data;
		data.setDetail_id(resultSet->getString(1));
		data.setPrime_rate(resultSet->getString(2));
		data.setCreate_time(resultSet->getString(3));
		data.setPay_time(resultSet->getString(4));
		return data;
	}
};
#endif 