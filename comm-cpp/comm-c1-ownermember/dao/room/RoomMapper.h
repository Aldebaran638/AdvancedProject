#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _ROOM_MAPPER_
#define _ROOM_MAPPER_

#include "Mapper.h"
#include "domain/do/room/RoomDO.h"

/**
 * 示例表字段匹配映射
 */
class RoomMapper : public Mapper<RoomDO>
{
public:
	RoomDO mapper(ResultSet* resultSet) const override
	{
		RoomDO data;
		data.setRoom_num(resultSet->getString(1));
		data.setLayer(resultSet->getString(2));
		data.setBuilt_up_area(resultSet->getDouble(3));
		data.setState(resultSet->getString(4));
		data.setRoom_type(resultSet->getString(5));
		data.setRoom_rent(resultSet->getDouble(6));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrRoomMapper : public Mapper<PtrRoomDO>
{
public:
	PtrRoomDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RoomDO>();
		data->setRoom_num(resultSet->getString(1));
		data->setLayer(resultSet->getString(2));
		data->setBuilt_up_area(resultSet->getDouble(3));
		data->setState(resultSet->getString(4));
		data->setRoom_type(resultSet->getString(5));
		data->setRoom_rent(resultSet->getDouble(6));
		return data;
	}
};

#endif // !_ROOM_MAPPER_