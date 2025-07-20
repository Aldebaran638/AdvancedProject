#pragma once
#ifndef _DETAILMAPPER_H_
#define _DETAILMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/dos/detailDO.h"
class detailMapper :public Mapper<detailDO>
{
public:
	detailDO mapper(ResultSet* resultSet) const override
	{
		detailDO data;
		data.setFEE_ID(resultSet->getString(1));
		data.setCYCLE(resultSet->getString(2));
		data.setPAY_PATH(resultSet->getString(3));
		data.setRECEIVABLE_AMOUNT(resultSet->getString(4));
		data.setAMOUNT(resultSet->getString(5));
		data.setPAY_TIME(resultSet->getString(6));
		data.setSTART_TIME(resultSet->getString(7).substr(0,10));
		data.setEND_TIME(resultSet->getString(8).substr(0, 10));
		data.setRECEIVE_ID(resultSet->getString(9));
		data.setSTATUS_CD(resultSet->getString(10));
		data.setREMARK(resultSet->getString(11));
		data.setOPT("申请退款-折扣");
		return data;
	}
};
class PtrdetailMapper :public Mapper<PtrdetailDO>
{
public:
	PtrdetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<detailDO>();
		data->setFEE_ID(resultSet->getString(1));
		data->setCYCLE(resultSet->getString(2));
		data->setPAY_PATH(resultSet->getString(3));
		data->setRECEIVABLE_AMOUNT(resultSet->getString(4));
		data->setAMOUNT(resultSet->getString(5));
		data->setPAY_TIME(resultSet->getString(6));
		data->setSTART_TIME(resultSet->getString(7).substr(0, 10));
		data->setEND_TIME(resultSet->getString(8).substr(0, 10));
		data->setRECEIVE_ID(resultSet->getString(9));
		data->setSTATUS_CD(resultSet->getString(10));
		data->setREMARK(resultSet->getString(11));
		data->setOPT("申请退款-折扣");
		return data;
	}
};
#endif