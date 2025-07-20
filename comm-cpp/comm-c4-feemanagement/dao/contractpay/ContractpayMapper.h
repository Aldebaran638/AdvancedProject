#pragma once

#ifndef _CONTRACTPAYMAPPER_H_
#define _CONTRACTPAYMAPPER_H_


#include "Mapper.h"
#include "../../domain/do/contractpay/ContractpayDO.h"

// 字段匹配映射
class ContractpayMapper : public Mapper<ContractpayDO> {
public:
	ContractpayDO mapper(ResultSet* resultSet) const override {
		ContractpayDO data;
		data.setFeeName(resultSet->getString(1));
		data.setFeeFlag(resultSet->getString(2));
		data.setFeeTypeCd(resultSet->getString(3));
		data.setAdditionalAmount(resultSet->getDouble(4));
		data.setStartTime(resultSet->getString(5));
		data.setStartTime(resultSet->getString(6));
		data.setEndTime(resultSet->getString(7));
		data.setSquarePrice(resultSet->getDouble(8));
		data.setState(resultSet->getString(9));
		return data;
	}
};

// 字段匹配映射-创建智能指针对象
class PtrContractpayMapper : public Mapper<PtrContractpayDO> {
public:
	PtrContractpayDO mapper(ResultSet* resultSet) const override {
		auto data = std::make_shared<ContractpayDO>();
		data->setFeeName(resultSet->getString(1));
		data->setFeeFlag(resultSet->getString(2));
		data->setFeeTypeCd(resultSet->getString(3));
		data->setAdditionalAmount(resultSet->getDouble(4));
		data->setStartTime(resultSet->getString(5));
		data->setStartTime(resultSet->getString(6));
		data->setEndTime(resultSet->getString(7));
		data->setSquarePrice(resultSet->getDouble(8));
		data->setState(resultSet->getString(9));
		return data;
	}
};

class ContractpayRecordMapper : public Mapper<ContractpayDO> {
public:
	ContractpayDO mapper(ResultSet* resultSet) const override {
		ContractpayDO data;
		data.setFeeId(resultSet->getString(1));
		data.setFeeName(resultSet->getString(2));
		data.setContractName(resultSet->getString(3));
		data.setCycle(resultSet->getString(4));
		data.setReceivable(resultSet->getString(5));
		data.setReceived(resultSet->getString(6));
		data.setChargeWay(resultSet->getString(7));
		data.setStartTime(resultSet->getString(8));
		data.setEndTime(resultSet->getString(9));
		data.setCreateTime(resultSet->getString(10));
		data.setCashierName(resultSet->getString(11));
		data.setStateCharge(resultSet->getString(12));
		data.setRemark(resultSet->getString(13));
		data.setPayerObjId(resultSet->getString(14));
		return data;
	}
};

// 字段匹配映射-创建智能指针对象
class PtrContractpayRecordMapper : public Mapper<PtrContractpayDO> {
public:
	PtrContractpayDO mapper(ResultSet* resultSet) const override {
		auto data = std::make_shared<ContractpayDO>();
		data->setFeeId(resultSet->getString(1));
		data->setFeeName(resultSet->getString(2));
		data->setContractName(resultSet->getString(3));
		data->setCycle(resultSet->getString(4));
		data->setReceivable(resultSet->getString(5));
		data->setReceived(resultSet->getString(6));
		data->setChargeWay(resultSet->getString(7));
		data->setStartTime(resultSet->getString(8));
		data->setEndTime(resultSet->getString(9));
		data->setCreateTime(resultSet->getString(10));
		data->setCashierName(resultSet->getString(11));
		data->setStateCharge(resultSet->getString(12));
		data->setRemark(resultSet->getString(13));
		data->setPayerObjId(resultSet->getString(14));
		return data;
	}
};


#endif // !_CONTRACTPAYMAPPER_H_
