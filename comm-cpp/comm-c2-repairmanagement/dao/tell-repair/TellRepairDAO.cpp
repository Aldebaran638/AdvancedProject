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
#include "TellRepairDAO.h"
#include "TellRepairMapper.h"
#include <sstream>

std::string TellRepairDAO::queryConditionBuilder(const TellRepairQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    sqlCondition << " AND rp.community_id=?";  
    sqlCondition << " AND rp.repair_channel= 'T'";  
    SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));

    if (query->repair_id)
    {
        sqlCondition << " AND rp.repair_id=?";  
        SQLPARAMS_PUSH(params, "s", std::string, query->repair_id.getValue(""));
    }
    if (query->repair_name)
    {
        sqlCondition << " AND rp.repair_name=?";  
        SQLPARAMS_PUSH(params, "s", std::string, query->repair_name.getValue(""));
    }
    if (query->tel)
    {
        sqlCondition << " AND rp.tel=?"; 
        SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue(""));
    }
    if (query->repair_type)
    {
        sqlCondition << " AND rp.repair_type=?";  
        SQLPARAMS_PUSH(params, "s", std::string, query->repair_type.getValue(""));
    }
    if (query->state)
    {
        sqlCondition << " AND rp.state=?";  
        SQLPARAMS_PUSH(params, "i", uint64_t, query->state.getValue(0));
    }
    sqlCondition << " AND rp.status_cd=0";  
    return sqlCondition.str();
}

uint64_t TellRepairDAO::count(const TellRepairQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM r_repair_pool rp ";  
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<TellRepairDO> TellRepairDAO::selectWithPage(const TellRepairQuery::Wrapper& query)
{
    SqlParams params;
    string sql = R"(
    SELECT 
        rp.repair_id,
        rp.repair_type,
        rs.repair_type_name AS repair_type_txt,  -- 修改：从r_repair_setting取repair_type_name
        rp.repair_name,
        rp.tel,
        rp.appointment_time,
        rp.create_time,
        rp.state,
        dict_state.name AS state_txt
    FROM 
        r_repair_pool rp
    LEFT JOIN 
        r_repair_setting rs
    ON 
        rs.repair_type = rp.repair_type  -- 修改：关联r_repair_setting表
    LEFT JOIN 
        t_dict dict_state 
    ON 
        dict_state.table_name = 'r_repair_pool' 
        AND dict_state.table_columns = 'state' 
        AND dict_state.status_cd = CAST(rp.state AS CHAR)
)";

    // 添加动态查询条件
    sql += queryConditionBuilder(query, params);
    sql += " ORDER BY rp.repair_id DESC ";
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 使用 Mapper 映射字段
    TellRepairMapper mapper;
    return sqlSession->executeQuery<TellRepairDO>(sql, mapper, params);
}



int TellRepairDAO::insert(const TellRepairDO& iObj)
{
    string sql = "INSERT INTO `r_repair_pool` "
        "(`repair_id`, `repair_obj_id`, `community_id`, `repair_obj_type`, `repair_obj_name`, `repair_type`, `repair_name`, `tel`, `appointment_time`, `context` ,`state`, `repair_channel`) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ? ,? ,'T')";
    return sqlSession->executeUpdate(
        sql,
        "%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRepairId(),
		iObj.getRepairObjId(),
        iObj.getCommunityId(),
        iObj.getRepairObjType(),
        iObj.getRepairObjName(),
        iObj.getRepairType(),
        iObj.getRepairName(),
        iObj.getTel(),
        iObj.getAppointmentTime(),
        iObj.getContext(),
		iObj.getState()
    );
}

int TellRepairDAO::update(const TellRepairDO &uObj)
{
	string sql = "UPDATE `r_repair_pool` SET "
							 "`repair_type`=?, "
							 "`repair_name`=?, "
							 "`tel`=?, "
							 "`appointment_time`=?, "
							 "`context`=? "
							 "WHERE `repair_id`=?";
	return sqlSession->executeUpdate(
			sql,
			"%s%s%s%s%s%s",
			uObj.getRepairType(),
			uObj.getRepairName(),
			uObj.getTel(),
			uObj.getAppointmentTime(),
			uObj.getContext(),
			uObj.getRepairId());
}

int TellRepairDAO::deleteById(std::string id)
{
	string sql = "UPDATE `r_repair_pool` SET `status_cd`= '1' WHERE `repair_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}