#pragma once

#ifndef _OWNEROAYMENT_MAPPER_
#define _OWNEROAYMENT_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/owner_payment/OwnerPaymentDO.h"


/**
 * 业主缴费表字段匹配映射
 */
class OwnerPaymentMapper : public Mapper<OwnerPaymentDO>
{
public:
	OwnerPaymentDO mapper(ResultSet* resultSet) const override
	{
		OwnerPaymentDO data;
		data.setFeeTypeCd(resultSet->getString(17));
		data.setConfigName(resultSet->getString(4));
		data.setRoomName(resultSet->getString(8));
		data.setOwnerName(resultSet->getString(3));
		data.setTotalAmount(resultSet->getDouble(14));
		data.setReceivableAmount(resultSet->getDouble(12));
		data.setReceivedAmount(resultSet->getDouble(13));

		/*for (int i = 1; i <= 12; ++i) {
			setPfMonthByIndex(data, i, 0);
		}*/
		setPfMonthByIndex(data, resultSet->getInt(16), resultSet->getDouble(13));

		return data;
	}
private:
	void setPfMonthByIndex(OwnerPaymentDO& data, int index, double value) const {
		switch (index) {
		case 1: data.setPfMonth1(value); break;
		case 2: data.setPfMonth2(value); break;
		case 3: data.setPfMonth3(value); break;
		case 4: data.setPfMonth4(value); break;
		case 5: data.setPfMonth5(value); break;
		case 6: data.setPfMonth6(value); break;
		case 7: data.setPfMonth7(value); break;
		case 8: data.setPfMonth8(value); break;
		case 9: data.setPfMonth9(value); break;
		case 10: data.setPfMonth10(value); break;
		case 11: data.setPfMonth11(value); break;
		case 12: data.setPfMonth12(value); break;
		}
	}
};

/**
 * 业主缴费表字段匹配映射-创建智能指针对象
 */
class PtrOwnerPaymentMapper : public Mapper<PtrOwnerPaymentDO>
{
public:
	PtrOwnerPaymentDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerPaymentDO>();
		data->setFeeTypeCd(resultSet->getString(17));
		data->setConfigName(resultSet->getString(4));
		data->setRoomName(resultSet->getString(8));
		data->setOwnerName(resultSet->getString(3));
		data->setTotalAmount(resultSet->getDouble(14));
		data->setReceivableAmount(resultSet->getDouble(12));
		data->setReceivedAmount(resultSet->getDouble(13));

		return data;
	}
};

// 费用大类列表映射
class OwnerPaymentFeeTypeListMapper : public Mapper<OwnerPaymentDO>
{
public:
	OwnerPaymentDO mapper(ResultSet* resultSet) const override
	{
		OwnerPaymentDO data;
		data.setFeeTypeName(resultSet->getString(1));
		data.setFeeTypeCd(resultSet->getString(2));
		return data;
	}
};
class PtrOwnerPaymentFeeTypeListMapper : public Mapper<PtrOwnerPaymentDO>
{
public:
	PtrOwnerPaymentDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerPaymentDO>();
		data->setFeeTypeName(resultSet->getString(1));
		data->setFeeTypeCd(resultSet->getString(2));
		return data;
	}
};

// 费用项目列表映射
class OwnerPaymentConfigNameListMapper : public Mapper<OwnerPaymentDO>
{
public:
	OwnerPaymentDO mapper(ResultSet* resultSet) const override
	{
		OwnerPaymentDO data;
		data.setConfigName(resultSet->getString(1));
		data.setConfigId(resultSet->getString(2));
		return data;
	}
};
class PtrOwnerPaymentConfigNameListMapper : public Mapper<PtrOwnerPaymentDO>
{
public:
	PtrOwnerPaymentDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerPaymentDO>();
		data->setConfigName(resultSet->getString(1));
		data->setConfigId(resultSet->getString(2));
		return data;
	}
};

#endif // !_OWNEROAYMENT_MAPPER_