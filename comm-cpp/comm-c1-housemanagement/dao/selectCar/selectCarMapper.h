#pragma once

#ifndef _SELECTCAR_MAPPER_
#define _SELECTCAR_MAPPER_

#include "Mapper.h"
#include "../../domain/do/car/CarDO.h"

/**
 * ≥µ¡æ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class selectCarMapper : public Mapper<CarDO>
{
public:
	CarDO mapper(ResultSet* resultSet) const override
	{
		CarDO data;
		data.setCar_num(resultSet->getString(1));
		//data.setMember_car_num(resultSet->getInt(2));
		//data.setRoom_num(resultSet->getString(3));
		data.setLease_type(resultSet->getString(2));
		data.setCar_type(resultSet->getString(3));
		data.setCar_color(resultSet->getString(4));
		data.setName(resultSet->getString(5));
		std::string num = resultSet->getString(6) + ZH_WORDS_GETTER("cardao.area") + resultSet->getString(7) + ZH_WORDS_GETTER("cardao.place");
		data.setNum(num);
		data.setValid_time(resultSet->getString(8));
		//data.setState(resultSet->getString(10));
		//data.setRemark(resultSet->getString(11));
		return data;
	}
};
class PtrselectCarMapper : public Mapper<PtrCarDO>
{
public:
	PtrCarDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CarDO>();
		data->setCar_num(resultSet->getString(1));
		//data->setMember_car_num(resultSet->getInt(2));
		//data->setRoom_num(resultSet->getString(3));
		data->setLease_type(resultSet->getString(4));
		data->setCar_type(resultSet->getString(5));
		data->setCar_color(resultSet->getString(6));
		data->setName(resultSet->getString(7));
		std::string num = resultSet->getString(8) + ZH_WORDS_GETTER("cardao.area") + resultSet->getString(12) + ZH_WORDS_GETTER("cardao.place");
		data->setNum(num);
		data->setValid_time(resultSet->getString(9));
		//data->setState(resultSet->getString(10));
		//data->setRemark(resultSet->getString(11));
		return data;
	}
};
#endif
