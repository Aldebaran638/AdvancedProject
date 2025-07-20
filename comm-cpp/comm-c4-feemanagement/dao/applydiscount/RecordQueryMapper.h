#pragma once
#ifndef _RECORD_QUERY_MAPPER_
#define _RECORD_QUERY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/applydiscount/RecordQueryDO.h"

/**
 * apply_room_discount_record表字段匹配映射
 */
class RecordQueryMapper : public Mapper<RecordQueryDO>
{
public:
	RecordQueryDO mapper(ResultSet* resultSet) const override
	{
		RecordQueryDO data;
		data.setArdr_id(resultSet->getString(1));
		data.setRoom_name(resultSet->getString(2));
		data.setCreate_user_name(resultSet->getString(3));
		data.setCreate_time(resultSet->getString(4));
		data.setState(resultSet->getString(5));
		data.setIs_true(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));

		return data;
	}
};

/**
 * apply_room_discount表字段匹配映射-创建智能指针对象
 */
class PtrRecordQueryMapper : public Mapper<PtrRecordQueryDO>
{
public:
	PtrRecordQueryDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RecordQueryDO>();
		data->setArdr_id(resultSet->getString(1));
		data->setRoom_name(resultSet->getString(2));
		data->setCreate_user_name(resultSet->getString(3));
		data->setCreate_time(resultSet->getString(4));
		data->setState(resultSet->getString(5));
		data->setIs_true(resultSet->getString(6));
		data->setRemark(resultSet->getString(7));
		return data;
	}
};

#endif // !_RECORD_QUERY_MAPPER_