#pragma once

#ifndef _MODIFY_MAPPER_
#define _MODIFY_MAPPER_
#include "Mapper.h"
#include "../../domain/do/dos/modifyDO.h"

class modifyMapper :public Mapper<modifyDO>
{
public:
	modifyDO mapper(ResultSet* resultSet) const override {
		modifyDO data;
		data.setFEE_ID(resultSet->getString(1));
		string f_p = resultSet->getString(2) + "(" + resultSet->getString(3) + ")";
		data.setFEE_PRO(f_p);

		//data.setPAY_TIME(resultSet->getString(4));
		data.setPAY_START(resultSet->getString(4));
		data.setPAY_END(resultSet->getString(5));
		data.setACTIONS(resultSet->getString(6));
		data.setOPORATOR(resultSet->getString(7));
		data.setOPT_TIME(resultSet->getString(8));
		return data;
	}
};

class PtrmodifyMapper :public Mapper<PtrmodifyDO>
{
public:
	PtrmodifyDO mapper(ResultSet* resultSet) const override {
		auto data = std::make_shared<modifyDO>();
		data->setFEE_ID(resultSet->getString(1));
	/*	data->setFEE_NAME(resultSet->getString(2));
		data->setObj_name(resultSet->getString(3));*/
		string f_p = resultSet->getString(2) + "(" + resultSet->getString(3) + ")";
		data->setFEE_PRO(f_p);

		//data->setPAY_TIME(resultSet->getString(4));
		data->setPAY_START(resultSet->getString(4));
		data->setPAY_END(resultSet->getString(5));
		data->setACTIONS(resultSet->getString(6));
		data->setOPORATOR(resultSet->getString(7));
		data->setOPT_TIME(resultSet->getString(8));
		return data;
	}
};

#endif