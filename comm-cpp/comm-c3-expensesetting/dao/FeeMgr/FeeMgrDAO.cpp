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
#include "FeeMgrDAO.h"
#include "FeeMgrMapper.h"
#include <sstream>


PtrFeeMgrDO FeeMgrDAO::selectById(std::string id)
{
	//string sql = "SELECT discount_id,discount_name,fee_flag,discount_type,status FROM fee_discount WHERE `discount_id`=?";
	string sql = "SELECT * FROM fee_discount WHERE `discount_id`=?";

	PtrFeeMgrMapper mapper;
	return sqlSession->executeQueryOne<PtrFeeMgrDO>(sql, mapper, "%s", id);
}

std::list<FeeMgrDO> FeeMgrDAO::selectByName(const string& name)
{
	string sql = "SELECT discount_id,discount_name,fee_flag,discount_type,status FROM fee_discount WHERE `discount_name` LIKE CONCAT('%',?,'%')";
	FeeMgrMapper mapper;
	return sqlSession->executeQuery<FeeMgrDO>(sql, mapper, "%s", name);
}

int FeeMgrDAO::insert(const FeeMgrDO& iObj)
{
	// 组装SQL语句
	// 注意：这里的字段名需要和数据库表中的字段名一致
	// 如果是MySQL数据库，字段名需要加上``
	// 如果是Oracle数据库，字段名需要加上""
	// 如果是SQL Server数据库，字段名需要加上[]

	string sql = "INSERT INTO `fee_discount` (`discount_id`, `discount_name`, `fee_flag`, `discount_type`,`status`,`create_time`,`update_time`) VALUES ('132025051652540020',?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", iObj.getDiscount_id(), iObj.getDiscount_name(), iObj.getFee_flag(), iObj.getDiscount_type(), iObj.getFee_status(), iObj.getCreateTime(), iObj.getCreateTime()); //插入时创建和更新时间相同
}

int FeeMgrDAO::update(const FeeMgrDO& uObj)
{
	string sql = "UPDATE `fee_discount` SET `discount_name`=?, `fee_flag`=?, `discount_type`=?,WHERE `discount_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getDiscount_name(), uObj.getFee_flag(), uObj.getDiscount_type(), uObj.getDiscount_id());
}

int FeeMgrDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `fee_discount` WHERE `discount_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}