#pragma once
#ifndef SUP_RECEPIT_MAPPER
#define SUP_RECEPIT_MAPPER

#include"Mapper.h"
#include"../../domain/do/reprint_vouchers/SupRecepitDO.h"

class SupRecepitMapper : public Mapper<SupRecepitDO> {
public:
	SupRecepitDO mapper(ResultSet* resultset)const override {
		SupRecepitDO data;
		data.setRecepitId(resultset->getString(1));
		data.setRecepitCode(resultset->getString(2));
		data.setObjType(resultset->getString(3));
		data.setFeeName(resultset->getString(4));
		data.setRoomName(resultset->getString(5));
		data.setOwnerName(resultset->getString(6));
		data.setCarPark(resultset->getString(7));
		data.setReceviableAmount(resultset->getDouble(8));
		data.setCreateTime(resultset->getString(9));
		return data;
	}
};

class PtrSupRecepitMapper : public Mapper<PtrSupRecepitDO> {
public:
	PtrSupRecepitDO mapper(ResultSet* resultset)const override {
		auto data = std::make_shared<SupRecepitDO>();
		data->setRecepitId(resultset->getString(1));
		data->setRecepitCode(resultset->getString(2));
		data->setObjType(resultset->getString(3));
		data->setFeeName(resultset->getString(4));
		data->setRoomName(resultset->getString(5));
		data->setOwnerName(resultset->getString(6));
		data->setCarPark(resultset->getString(7));
		data->setReceviableAmount(resultset->getDouble(8));
		data->setCreateTime(resultset->getString(9));
		return data;
	}
};

class ReprintSupRecepitMapper : public Mapper<ReprintSupRecepitDO>{
public:
	ReprintSupRecepitDO mapper(ResultSet* resultset)const override {
		ReprintSupRecepitDO data;
		data.setOwnerName(resultset->getString(1));
		data.setObjName(resultset->getString(2));
		data.setFeeName(resultset->getString(3));
		data.setStartTime(resultset->getString(4));
		data.setCreateTime(resultset->getString(5));
		data.setEndTime(resultset->getString(6));
		data.setNeedPay(resultset->getDouble(7));
		data.setPay(resultset->getDouble(8));
		data.setRecepitId(resultset->getString(9));
		data.setRecepitPayId(resultset->getString(10));
		data.setCashierName(resultset->getString(11));
		return data;
	}
};

class PtrReprintSupRecepitMapper : public Mapper<PtrReprintSupRecepitDO> {
public:
	PtrReprintSupRecepitDO mapper(ResultSet* resultset)const override {
		auto data = std::make_shared<ReprintSupRecepitDO>();
		data->setOwnerName(resultset->getString(1));
		data->setObjName(resultset->getString(2));
		data->setFeeName(resultset->getString(3));
		data->setStartTime(resultset->getString(4));
		data->setCreateTime(resultset->getString(5));
		data->setEndTime(resultset->getString(6));
		data->setNeedPay(resultset->getDouble(7));
		data->setPay(resultset->getDouble(8));
		data->setRecepitId(resultset->getString(9));
		data->setRecepitPayId(resultset->getString(10));
		data->setCashierName(resultset->getString(11));
		return data;
	}
};

class ReprintSupRecepit2Mapper : public Mapper<ReprintSupRecepit2DO> {
public:
	ReprintSupRecepit2DO mapper(ResultSet* resultset)const override {
		ReprintSupRecepit2DO data;
		data.setRecepitCode(resultset->getString(1));
		data.setPayOrderId(resultset->getString(2));
		data.setObjName(resultset->getString(3));
		data.setPayObjName(resultset->getString(4));
		data.setCreateTime(resultset->getString(5));
		data.setFeeName(resultset->getString(6));
		data.setStartTime(resultset->getString(7));
		data.setEndTime(resultset->getString(8));
		data.setSquarePrice(resultset->getString(9));
		data.setArea(resultset->getString(10));
		data.setPrimeRate(resultset->getDouble(11));
		data.setPayableAmount(resultset->getDouble(12));
		data.setDiscountAmount(resultset->getDouble(13));
		data.setRemark(resultset->getString(14));
		data.setReceivedAmount(resultset->getDouble(15));
		data.setCashierName(resultset->getString(16));
		return data;
	}
};

class PtrReprintSupRecepit2Mapper : public Mapper<PtrReprintSupRecepit2DO> {
public:
	PtrReprintSupRecepit2DO mapper(ResultSet* resultset)const override {
		auto data = std::make_shared<ReprintSupRecepit2DO>();
		data->setRecepitCode(resultset->getString(1));
		data->setPayOrderId(resultset->getString(2));
		data->setObjName(resultset->getString(3));
		data->setPayObjName(resultset->getString(4));
		data->setCreateTime(resultset->getString(5));
		data->setFeeName(resultset->getString(6));
		data->setStartTime(resultset->getString(7));
		data->setEndTime(resultset->getString(8));
		data->setSquarePrice(resultset->getString(9));
		data->setArea(resultset->getString(10));
		data->setPrimeRate(resultset->getDouble(11));
		data->setPayableAmount(resultset->getDouble(12));
		data->setDiscountAmount(resultset->getDouble(13));
		data->setRemark(resultset->getString(14));
		data->setReceivedAmount(resultset->getDouble(15));
		data->setCashierName(resultset->getString(16));
		return data;
	}
};

#endif // !SUP_RECEPIT_MAPPER

