#pragma once
#ifndef _REMITFEEMAPPER_H_
#define  _REMITFEEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/dos/RemitFeeDO.h"

class RemitFeeMapper :public Mapper<RemitFeeDO>
{
public:
	RemitFeeDO mapper(ResultSet* resultSet) const override
	{
		RemitFeeDO data;
		data.setDETAIL_ID(resultSet->getString(1));
		data.setRECEIPT_ID(resultSet->getString(2));
		data.setPAY_OBJ(resultSet->getString(3));
		data.setCYCLE(resultSet->getDouble(4));
		//data.setRECEIVABLE_AMOUNT(resultSet->getDouble(5));
		//data.setAMOUNT(resultSet->getDouble(6));
		string receive = resultSet->getString(5);
		string received = resultSet->getString(6);
		string r_rd = receive + "/" + received;
		data.setRECEIVE_RECEIVED(r_rd);

		data.setPAY_PATH(resultSet->getString(7));
		//data.setSTART_TIME(resultSet->getString(8));
		//data.setEND_TIME(resultSet->getString(9));
		string p_p = resultSet->getString(8).substr(0, 10) + "~" + resultSet->getString(9).substr(0, 10);
		data.setPAY_PERIOD(p_p);
		data.setPAY_TIME(resultSet->getString(10));
		data.setRECEIVE_ID(resultSet->getString(11));
		data.setSTATUS_CD(resultSet->getString(12));
		data.setREMARK(resultSet->getString(13));
		data.setOPT("详情");

		return data;

	}
};
class PtrRemitFeeMapper :public Mapper<PtrRemitFeeDO>
{
public:
	PtrRemitFeeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RemitFeeDO>();
		data->setDETAIL_ID(resultSet->getString(1));
		data->setRECEIPT_ID(resultSet->getString(2));
		data->setPAY_OBJ(resultSet->getString(3));
		data->setCYCLE(resultSet->getDouble(4));
		//data.setRECEIVABLE_AMOUNT(resultSet->getDouble(5));
		//data.setAMOUNT(resultSet->getDouble(6));
		double receive = resultSet->getDouble(5);
		double received = resultSet->getDouble(6);
		string r_rd = std::to_string(receive) + "/" + std::to_string(received);
		data->setRECEIVE_RECEIVED(r_rd);
		data->setPAY_PATH(resultSet->getString(7));
		//data.setSTART_TIME(resultSet->getString(8));
		//data.setEND_TIME(resultSet->getString(9));
		string p_p = resultSet->getString(8).substr(0, 10) + "~" + resultSet->getString(9).substr(0, 10);
		data->setPAY_PERIOD(p_p);
		data->setPAY_TIME(resultSet->getString(10));
		data->setRECEIVE_ID(resultSet->getString(11));
		data->setSTATUS_CD(resultSet->getString(12));
		data->setREMARK(resultSet->getString(13));
		data->setOPT("详情");
		return data;
	}
};
#endif