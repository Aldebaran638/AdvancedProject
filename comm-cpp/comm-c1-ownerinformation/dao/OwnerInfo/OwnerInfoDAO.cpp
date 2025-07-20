/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "stdafx.h"
#include "OwnerInfoDAO.h"
//#include "IntoHouseMapper.h"
#include <sstream>

int OwnerInfoDAO::insert(const BuildingRoomDO& iObj) {
	string sql = "INSERT INTO `building_room` (`room_num`, `layer`, `room_id`, `built_up_area`, `apartment`, `section`, `b_id`, `unit_id`, `fee_coefficient`, `user_id`, `remark`, `create_time`, `status_cd`, `state`, `community_id`, `room_type`, `room_sub_type`, `room_area`, `room_rent`)"
		" VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%d%s%d%s%s%d%s%s%s%s%s%s%s%s%d%d", iObj.getRoom_num(), iObj.getLayer(), iObj.getRoom_id(), iObj.getBuilt_up_area(), iObj.getApartment(), iObj.getSection(), iObj.getB_id(),
		iObj.getUnit_id(), iObj.getFee_coefficient(), iObj.getUser_id(), iObj.getRemark(), iObj.getCreate_time(), iObj.getStatus_cd(), iObj.getState(), iObj.getCommunity_id(), iObj.getRoom_type(), iObj.getRoom_sub_type(),
		iObj.getRoom_area(), iObj.getRoom_rent());
}

//int OwnerInfoDAO::update(const BuildingRoomDO& uObj)
//{
//	string sql = "UPDATE `building_room` SET `owner_id`=?, `room_id`=?, `state`=?, `user_id`=?, `remark`=?, `status_cd`=? WHERE `rel_id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", uObj.getOwner_id(), uObj.getRoom_id(), uObj.getState(),uObj.getUser_id(), uObj.getRemark(), 
//		uObj.getStatus_cd(), uObj.getRel_id());
//}
int OwnerInfoDAO::deleteById(std::string id) {
	string sql = "DELETE FROM `building_room WHERE `room_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}