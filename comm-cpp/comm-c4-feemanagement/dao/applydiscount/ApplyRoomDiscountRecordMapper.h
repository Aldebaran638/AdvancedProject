#pragma once
#ifndef _APPLY_ROOM_DISCOUNT_RECORD_MAPPER_
#define _APPLY_ROOM_DISCOUNT_RECORD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/applydiscount/ApplyRoomDiscountRecordDO.h"

/**
 * apply_room_discount_record表字段匹配映射
 */
class ApplyRoomDiscountRecordMapper : public Mapper<ApplyRoomDiscountRecordDO>
{
public:
	ApplyRoomDiscountRecordDO mapper(ResultSet* resultSet) const override
	{
		ApplyRoomDiscountRecordDO data;
		data.setArdr_id(resultSet->getString(1));
		data.setArd_id(resultSet->getString(2));
		data.setB_id(resultSet->getString(3));
		data.setCommunity_id(resultSet->getString(4));
		data.setStatus_cd(resultSet->getString(5));
		data.setCreate_user_id(resultSet->getString(6));
		data.setCreate_user_name(resultSet->getString(7));
		data.setCreate_time(resultSet->getString(8));
		data.setRemark(resultSet->getString(9));
		data.setIs_true(resultSet->getString(10));
		data.setState(resultSet->getString(11));

		return data;
	}
};

/**
 * apply_room_discount表字段匹配映射-创建智能指针对象
 */
class PtrApplyRoomDiscountRecordMapper : public Mapper<PtrApplyRoomDiscountRecordDO>
{
public:
	PtrApplyRoomDiscountRecordDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ApplyRoomDiscountRecordDO>();
		data->setArdr_id(resultSet->getString(1));
		data->setArd_id(resultSet->getString(2));
		data->setB_id(resultSet->getString(3));
		data->setCommunity_id(resultSet->getString(4));
		data->setStatus_cd(resultSet->getString(5));
		data->setCreate_user_id(resultSet->getString(6));
		data->setCreate_user_name(resultSet->getString(7));
		data->setCreate_time(resultSet->getString(8));
		data->setRemark(resultSet->getString(9));
		data->setIs_true(resultSet->getString(10));
		data->setState(resultSet->getString(11));
		return data;
	}
};

#endif // !_APPLY_ROOM_DISCOUNT_RECORD_MAPPER_