#pragma once

#ifndef _PAYFEE_MAPPER_
#define _PAYFEE_MAPPER_

#include "Mapper.h"
#include "../domain/do/PayFeeDO.h"

class PayFeeMapper : public Mapper<PayFeeDO>
{
public:
	PayFeeDO mapper(ResultSet* resultSet) const override
	{
		PayFeeDO data;
		data.setConfig_id(resultSet->getString(1));
		data.setFee_type_cd(resultSet->getString(2));
		data.setFee_name(resultSet->getString(3));
		data.setFee_flag(resultSet->getString(4));
		data.setPayment_cd(resultSet->getString(5));
		data.setPayment_cycle(resultSet->getInt(6));
		data.setStart_time(resultSet->getString(7));
		data.setEnd_time(resultSet->getString(8));
		data.setComputing_formula(resultSet->getString(9));
		data.setSquare_price(resultSet->getString(10));
		data.setAdditional_amount(resultSet->getString(11));
		data.setDeduct_from(resultSet->getString(12));

		return data;
	}
};

//class PtrPayFeeMapper : public Mapper<PtrPayFeeDO>
//{
//	PtrPayFeeDO mapper(ResultSet* resultSet) const override
//	{
//		auto data = std::make_shared<PayFeeDO>();
//		data->setConfig_id(resultSet->getString(1));
//		data.setFee_type_cd(resultSet->getString(2));
//		data.setFee_flag(resultSet->getString(3));
//		data.setPayment_cycle(resultSet->getInt(4));
//		data.setFee_name(resultSet->getString(5));
//		data.setPayment_cd(resultSet->getString(6));
//		data.setPrepayment_period(resultSet->getString(7));
//		data.setStart_time(resultSet->getString(8));
//		data.setEnd_time(resultSet->getString(9));
//		data.setUnits(resultSet->getString(10));
//		data.setDeduct_from(resultSet->getString(11));
//		data.setPay_online(resultSet->getString(12));
//		data.setScale(resultSet->getString(13));
//		data.setDecimal_place(resultSet->getInt(14));
//		data.setComputing_formula(resultSet->getString(15));
//		data.setSquare_price(resultSet->getString(16));
//		data.setAdditional_amount(resultSet->getString(17));
//		
//		return data;
//	}
//};



class ChargeItemMapper : public Mapper<ChargeItemDO>
{
public:
	ChargeItemDO mapper(ResultSet* resultSet) const override
	{
		ChargeItemDO data;
		data.setConfig_id(resultSet->getString(1));
		data.setFee_type_cd(resultSet->getString(2));
		data.setChargeItem(resultSet->getString(3));
		return data;
	}
};

#endif