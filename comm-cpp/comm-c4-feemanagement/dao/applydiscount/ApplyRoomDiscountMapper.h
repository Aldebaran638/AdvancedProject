#pragma once
#ifndef _APPLY_ROOM_DISCOUNT_MAPPER_
#define _APPLY_ROOM_DISCOUNT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/applydiscount/ApplyRoomDiscountDO.h"

/**
 * apply_room_discount表字段匹配映射
 */
class ApplyRoomDiscountMapper : public Mapper<ApplyRoomDiscountDO>
{
public:
	ApplyRoomDiscountDO mapper(ResultSet* resultSet) const override
	{
		ApplyRoomDiscountDO data;
		data.setArd_id(resultSet->getString(1));
		data.setCommunity_id(resultSet->getString(2));
		data.setRoom_id(resultSet->getString(3));
		data.setRoom_name(resultSet->getString(4));
		data.setDiscount_id(resultSet->getString(5));
		data.setApply_type(resultSet->getString(6));
		data.setStart_time(resultSet->getString(7));
		data.setEnd_time(resultSet->getString(8));
		data.setCreate_user_name(resultSet->getString(9));
		data.setCreate_user_tel(resultSet->getString(10));
		data.setCheck_user_id(resultSet->getString(11));
		data.setReview_user_id(resultSet->getString(12));
		data.setState(resultSet->getString(13));
		data.setCreate_remark(resultSet->getString(14));
		data.setCheck_remark(resultSet->getString(15));
		data.setReview_remark(resultSet->getString(16));
		data.setCreate_time(resultSet->getString(17));
		data.setStatus_cd(resultSet->getString(18));
		data.setIn_use(resultSet->getString(19));
		data.setB_id(resultSet->getString(20));
		data.setFee_id(resultSet->getString(21));
		data.setReturn_way(resultSet->getString(22));
		data.setReturn_amount(resultSet->getString(23));
		
		return data;
	}
};

/**
 * apply_room_discount表字段匹配映射-创建智能指针对象
 */
class PtrApplyRoomDiscountMapper : public Mapper<PtrApplyRoomDiscountDO>
{
public:
	PtrApplyRoomDiscountDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ApplyRoomDiscountDO>();
		data->setArd_id(resultSet->getString(1));
		data->setCommunity_id(resultSet->getString(2));
		data->setRoom_id(resultSet->getString(3));
		data->setRoom_name(resultSet->getString(4));
		data->setDiscount_id(resultSet->getString(5));
		data->setApply_type(resultSet->getString(6));
		data->setStart_time(resultSet->getString(7));
		data->setEnd_time(resultSet->getString(8));
		data->setCreate_user_name(resultSet->getString(9));
		data->setCreate_user_tel(resultSet->getString(10));
		data->setCheck_user_id(resultSet->getString(11));
		data->setReview_user_id(resultSet->getString(12));
		data->setState(resultSet->getString(13));
		data->setCreate_remark(resultSet->getString(14));
		data->setCheck_remark(resultSet->getString(15));
		data->setReview_remark(resultSet->getString(16));
		data->setCreate_time(resultSet->getString(17));
		data->setStatus_cd(resultSet->getString(18));
		data->setIn_use(resultSet->getString(19));
		data->setB_id(resultSet->getString(20));
		data->setFee_id(resultSet->getString(21));
		data->setReturn_way(resultSet->getString(22));
		data->setReturn_amount(resultSet->getString(23));
		return data;
	}
};

#endif // !_APPLY_DISCOUNT_RECORD_MAPPER_