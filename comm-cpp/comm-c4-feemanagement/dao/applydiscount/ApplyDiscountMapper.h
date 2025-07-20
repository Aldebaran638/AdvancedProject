#pragma once

#ifndef _APPLY_DISCOUNT_MAPPER_H_
#define _APPLY_DISCOUNT_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/applydiscount/ApplyDiscountDO.h"

// 数据表apply_room_discount字段匹配映射
class ApplyDiscountMapper : public Mapper<ApplyDiscountDO> {
public:
	ApplyDiscountDO mapper(ResultSet* resultSet) const override {
		ApplyDiscountDO data;
		data.setRoomName(resultSet->getString(1));
		data.setDiscountId(resultSet->getString(2));
		data.setApplyType(resultSet->getString(3));
		data.setCreateUserName(resultSet->getString(4));
		data.setCreateUserTel(resultSet->getString(5));
		data.setStartTime(resultSet->getString(6));
		data.setEndTime(resultSet->getString(7));
		data.setInUse(resultSet->getString(8));
		data.setReturnWay(resultSet->getString(9));
		data.setReturnAmount(resultSet->getString(10));

		return data;
	}

};

// 数据表apply_room_discount字段匹配映射-创建智能指针对象
class PtrApplyDiscountMapper : public Mapper<PtrApplyDiscountDO> {
public:
	PtrApplyDiscountDO mapper(ResultSet* resultSet) const override {
		auto data = std::make_shared<ApplyDiscountDO>();
		data->setRoomName(resultSet->getString(1));
		data->setDiscountId(resultSet->getString(2));
		data->setApplyType(resultSet->getString(3));
		data->setCreateUserName(resultSet->getString(4));
		data->setCreateUserTel(resultSet->getString(5));
		data->setStartTime(resultSet->getString(6));
		data->setEndTime(resultSet->getString(7));
		data->setInUse(resultSet->getString(8));
		data->setReturnWay(resultSet->getString(9));
		data->setReturnAmount(resultSet->getString(10));

		return data;
	}
};
#endif // !_SAMPLE_MAPPER_