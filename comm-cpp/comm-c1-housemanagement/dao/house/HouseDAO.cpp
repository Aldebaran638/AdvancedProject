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
#include "HouseDAO.h"
#include "HouseMapper.h"
#include <sstream>


PtrHouseDO HouseDAO::selectById(std::string id)
{
	string sql = "SELECT house_id,house_name,house_num,house_area,create_time,house_phone FROM s_store_house WHERE `house_id`=?";
	PtrHouseMapper mapper;
	return sqlSession->executeQueryOne<PtrHouseDO>(sql, mapper, "%s", id);
}

std::list<HouseDO> HouseDAO::selectByName(const string& name)
{
	string sql = "SELECT house_id,house_name,house_num,house_area,create_time,house_phone FROM s_store_house WHERE `house_name` LIKE CONCAT('%',?,'%')";
	HouseMapper mapper;
	return sqlSession->executeQuery<HouseDO>(sql, mapper, "%s", name);
}

int HouseDAO::insert(const HouseDO& iObj)
{
	// 组装SQL语句
	// 注意：这里的字段名需要和数据库表中的字段名一致
	// 如果是MySQL数据库，字段名需要加上``
	// 如果是Oracle数据库，字段名需要加上""
	// 如果是SQL Server数据库，字段名需要加上[]
	// 
	//string house_num = iObj.getBuilding() + "-" + iObj.getUnit() + "-" + iObj.getFloor();
	/*std::cout << "house_id: " << iObj.getId() << std::endl;
	std::cout << "house_name: " << iObj.getName() << std::endl;
	std::cout << "house_num: " << iObj.getDoorNumber() << std::endl;
	std::cout << "house_area: " << iObj.getHouseArea() << std::endl;
	std::cout << "create_time: " << iObj.getCreateTime() << std::endl;*/

	
	string sql = "INSERT INTO `s_store_house` (`house_id`, `house_name`, `house_num`, `house_phone`,`house_area`,`fee_type_cd`,`fee_price`,`user_id`,`create_time`,`update_time`,`status_cd`) VALUES (?, ?, ?, '123456789', ?,'8001','1000','800625487', ?, ?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", iObj.getId(), iObj.getName(), iObj.getDoorNumber(), iObj.getHouseArea(), iObj.getCreateTime(), iObj.getCreateTime(),iObj.getState()); //插入时创建和更新时间相同
}

int HouseDAO::update(const HouseDO& uObj)
{
	//string house_num = uObj.getBuilding() + uObj.getUnit() + uObj.getFloor();
	string sql = "UPDATE `s_store_house` SET `house_name`=?, `house_num`=?, `house_phone`=?, `house_area`=?, WHERE `house_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s", uObj.getName(), uObj.getBuilding() + uObj.getUnit() + uObj.getFloor(), "123456789", uObj.getHouseArea(), uObj.getId());
}

int HouseDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `s_store_house` WHERE `house_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}