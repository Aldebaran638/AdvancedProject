#pragma

#ifndef _FLOOR_MAPPER_
#define _FLOOR_MAPPER_

#include "Mapper.h"
#include "../../domain/do/floor/FloorDO.h"

/**
 * f_floor表(楼栋表)字段匹配映射
 */
class FloorMapper :public Mapper<FloorDO>
{
public:
	FloorDO mapper(ResultSet* resultSet)const override {
		FloorDO data;
		data.setFloor_id(resultSet->getString("floor_id"));
		data.setB_id(resultSet->getString("b_id"));
		data.setFloor_num(resultSet->getString("floor_num"));
		data.setName(resultSet->getString("name"));
		data.setUser_id(resultSet->getString("user_id"));
		data.setCommunity_id(resultSet->getString("community_id"));
		data.setFloor_area(resultSet->getString("floor_area"));
		data.setSeq(resultSet->getInt("seq"));
		return data;
	}
};

/*
 * f_floor表(楼栋表)字段匹配映射-创建智能指针对象
 */
class PtrFloorMapper :public Mapper<PtrFloorDO>
{
public:
	PtrFloorDO mapper(ResultSet* resultSet)const override
	{
		auto data = std::make_shared<FloorDO>();
		data->setFloor_id(resultSet->getString(1));
		data->setB_id(resultSet->getString(2));
		data->setFloor_num(resultSet->getString(3));
		data->setName(resultSet->getString(4));
		data->setUser_id(resultSet->getString(5));
		data->setCommunity_id(resultSet->getString(6));
		data->setFloor_area(resultSet->getString(7));
		data->setSeq(resultSet->getInt(8));
		return data;
	}
};



#endif