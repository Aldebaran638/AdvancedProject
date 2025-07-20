#pragma once

#ifndef _HOUSE_APY_FEE_MAPPER_H_
#define _HOUSE_APY_FEE_MAPPER_H_
#include "Mapper.h"
#include "../../domain/do/house_pay_fee/HousePayFeeDO.h"
class FindCommunityDOMapper : public Mapper<FindCommunityDO>
{
public:
	FindCommunityDO mapper(ResultSet* resultSet) const override
	{
		FindCommunityDO data;
		data.setCommunity(resultSet->getString(1));
		data.setFeeTypeCd(resultSet->getString(2));
		data.setFeeFlag(resultSet->getString(3));
		return data;
	}
};
class HouseInfoDOMapper :public Mapper<HouseInfoDO>
{
public : 
	HouseInfoDO mapper(ResultSet* resultSet) const override
	{
		HouseInfoDO data;
		data.setRoomId(resultSet->getString(1));
		data.setRoomArea(resultSet->getDouble(2));
		data.setBuiltUpArea(resultSet->getDouble(3));
		return data;
	}
};

class FeeTypeIdDOMapper :public Mapper<FeeTypeIdDO>
{
public : 
	FeeTypeIdDO mapper(ResultSet* resultSet) const override
	{
		FeeTypeIdDO data;
		data.setFeeTypeCd(resultSet->getString(1));
		return data;
	}
};

class CalcHouseFeeDOMapper :public Mapper<CalcHouseFeeDO>
{
public : 
	CalcHouseFeeDO mapper(ResultSet* resultSet) const override
	{
		CalcHouseFeeDO data;
		data.setSquarePrice(resultSet->getDouble(1));
		data.setAdditionalAmount(resultSet->getDouble(2));
		data.setScale(resultSet->getInt(3));
		data.setDecimalPlace(resultSet->getInt(4));
		data.setUnits(resultSet->getString(5));
		data.setComputingFormula(resultSet->getString(6));
		return data;
	}
};
class DiscountDOMapper : Mapper<DiscountDO>
{
public : 
	DiscountDO mapper(ResultSet* resultSet) const override
	{
		DiscountDO data;
		data.setDiscountSmallType(resultSet->getInt(1));
		data.setRuleName(resultSet->getString(2));
		data.setSpecValue(resultSet->getDouble(3));
		return data;
	}
};


class MoidfyFeeInfoDOMapper : public Mapper<ModifyFeeInfoDO>
{
public :
	ModifyFeeInfoDO mapper(ResultSet* resultSet)  const override
	{
		ModifyFeeInfoDO data;
		data.setFourmulaValue(resultSet->getString(1));
		data.setSquarePrice(resultSet->getDouble(2));
		data.setAdditionalPrice(resultSet->getDouble(3));
		data.setBuildUpArea(resultSet->getDouble(4));
		data.setCommunityId(resultSet->getString(5));
		data.setFeeType(resultSet->getString(6));
		return data;
	 }
};

class StatusTimeDOMapper : public Mapper<StatusTimeDO>
{
public :
	StatusTimeDO mapper(ResultSet* resultSet) const override
	{
		StatusTimeDO data;
		data.setStatusCd(resultSet->getString(1));
		data.setState(resultSet->getString(2));
		data.setStartTime(resultSet->getString(3));
		data.setEndTime(resultSet->getString(4));
		data.setConfigId(resultSet->getString(5));
		return data;
	}
};

class DiscountInfoDOMapper : public Mapper<DiscountInfoDO>
{
public :
	DiscountInfoDO mapper(ResultSet* resultSet) const override
	{
		DiscountInfoDO data;
		data.setDiscountType(resultSet->getString(1));
		data.setSpecValue(resultSet->getDouble(2));
		return data;
	}
};
	/*class DiscountInfoDO {
	public:
		DiscountInfoDO() {
			discount_type = "";
			spec_value = 0;
		}

	public:
		CC_SYNTHESIZE(std::string, discount_type, DiscountType);
		CC_SYNTHESIZE(double, spec_value, SpecValue);
};*/
#endif
