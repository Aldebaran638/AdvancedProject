#include "stdafx.h"
#include "RepairWorkerDAO.h"
#include "RepairWorkerMapper.h"
#include <sstream>

std::string RepairWorkerDAO::queryRepairWorkerConditionBuilder(const RepairWorkerQuery::Wrapper& query, SqlParams& params)  
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	// 使用r_repair_setting表的repair_type_name作为查询条件
	if (query->repair_type_name) {
		sqlCondition << " AND r_repair_setting.repair_type_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_type_name.getValue(""));
	}
	// r_repair_type_user表的community_id作为查询条件
	if (query->community_id) {
		sqlCondition << " AND r_repair_type_user.community_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	sqlCondition << " AND r_repair_type_user.status_cd='0'";
	return sqlCondition.str();
}


//用于查找维修师傅的分页
uint64_t RepairWorkerDAO::count(const RepairWorkerQuery::Wrapper& query)
{
	SqlParams params;
	// 核心：保持与分页查询相同的表连接和过滤条件
	string sql = R"(
        SELECT COUNT(*)
        FROM r_repair_setting
        INNER JOIN r_repair_type_user 
            ON r_repair_setting.repair_type = r_repair_type_user.repair_type
        INNER JOIN t_dict 
            ON r_repair_type_user.state = t_dict.status_cd 
            AND t_dict.table_name = 'r_repair_type_user'
    )";

	// 复用相同的条件构建器
	sql += queryRepairWorkerConditionBuilder(query, params); // 非queryConditionBuilder

	return sqlSession->executeQueryNumerical(sql, params);
}


std::list<RepairWorkerQueryDO> RepairWorkerDAO::selectWithPage(const RepairWorkerQuery::Wrapper& query)
{
	SqlParams params;

	// 联查三表的SQL语句
	string sql = R"(
        SELECT 
            r_repair_type_user.staff_id,
            r_repair_type_user.staff_name,
            r_repair_setting.repair_type,
            r_repair_setting.repair_type_name,
            r_repair_type_user.state,
            t_dict.name AS state_txt,
            r_repair_type_user.remark,
            r_repair_type_user.create_time
        FROM r_repair_setting
        INNER JOIN r_repair_type_user 
            ON r_repair_setting.repair_type = r_repair_type_user.repair_type
        INNER JOIN t_dict 
            ON r_repair_type_user.state = t_dict.status_cd 
            AND t_dict.table_name = 'r_repair_type_user'
    )";

	// 添加动态条件
	sql += queryRepairWorkerConditionBuilder(query, params);

	// 排序和分页
	sql += " ORDER BY r_repair_type_user.staff_id DESC ";
	/*sql += " LIMIT " + ... */
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// 执行查询
	RepairWorkerQueryMapper mapper;
	return sqlSession->executeQuery<RepairWorkerQueryDO>(sql, mapper, params);
}
//用于更新状态
int RepairWorkerDAO::update(const RepairWorkerModifyDO& uObj)
{
	string sql = R"(
        UPDATE r_repair_type_user rt
        JOIN r_repair_setting rs ON rs.repair_type = rt.repair_type
           AND rs.community_id = ?  -- 添加此关联
        SET 
            rt.state = ?,
            rt.remark = ?
        WHERE 
            rt.staff_id = ? 
            AND rt.community_id = ? 
            AND rs.repair_type_name = ?
            AND rt.status_cd = '0'
    )";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s",
		uObj.getCommunityId(),  // rs.community_id
		uObj.getState(),
		uObj.getRemark(),
		uObj.getStaffId(),
		uObj.getCommunityId(),  // rt.community_id
		uObj.getRepairTypeName()
	);
}


int RepairWorkerDAO::deleteById(std::string type_user_id)
{
	string sql = "UPDATE `r_repair_type_user` SET `status_cd`='1' WHERE `type_user_id`=? AND `status_cd` = '0' ";
	return sqlSession->executeUpdate(sql, "%s", type_user_id);
}

bool RepairWorkerDAO::isDuplicate(const std::string& repairTypeName,
	const std::string& staffName,
	const std::string& communityId,
	const std::string& orgName)
{
		SqlParams params;
		// 核心：保持与分页查询相同的表连接和过滤条件
		string sql = 
         R"(
            SELECT COUNT(*)
            FROM r_repair_type_user
            WHERE repair_type = (
                    SELECT repair_type 
                    FROM r_repair_setting 
                    WHERE repair_type_name = ')" + repairTypeName + R"(' 
                      AND community_id = ')" + communityId + R"(' 
                    LIMIT 1
                )
                AND staff_id = (
                    SELECT u.user_id 
                    FROM u_user u 
                    INNER JOIN u_org_staff_rel rel ON u.user_id = rel.staff_id 
                    INNER JOIN u_org o ON rel.org_id = o.org_id 
                    WHERE u.name = ')" + staffName + R"(' 
                      AND o.org_name = ')" + orgName + R"(' 
                    LIMIT 1
                )
                AND community_id = ')" + communityId + R"('
                AND status_cd = '0'
            )";
		return (sqlSession->executeQueryNumerical(sql, params) > 0);
}
int RepairWorkerDAO::insert(const RepairWorkerAddDO& iObj)
{
		// ***** 步骤 1: 确保 SQL 语句是干净的 *****
		// 强烈建议手动重新输入或仔细检查以下 SQL 字符串，
		// 以确保没有隐藏的、不可见的字符（如零宽度空格等）。
		// 特别关注 'FROM u_user u' 这一行及其周围的空白字符。

		const std::string sql = R"(
        INSERT INTO r_repair_type_user (
            type_user_id,
            b_id,
            repair_type,
            staff_id,
            staff_name,
            community_id,
            state,
            remark,
            status_cd,
            create_time
        ) VALUES (
            ?, ?,
            (SELECT repair_type FROM r_repair_setting WHERE repair_type_name = ? AND community_id = ? LIMIT 1),
            (SELECT u.user_id
             FROM u_user u
             INNER JOIN u_org_staff_rel rel ON u.user_id = rel.staff_id
             INNER JOIN u_org o ON rel.org_id = o.org_id
             WHERE u.name = ? AND o.org_name = ?
             LIMIT 1),
            ?,
            ?,
            ?,
            ?,
            '0',
            ?
        )
    )";
		return sqlSession->executeUpdate(
			sql,
			"%s%s%s%s%s%s%s%s%s%s%s",
			iObj.getTypeUserId(), iObj.getBId(), iObj.getRepairTypeName(), 
			iObj.getCommunityId(),iObj.getStaffName(),
			iObj.getOrgName(), iObj.getStaffName(), iObj.getCommunityId(), iObj.getState(),
			iObj.getRemark(), iObj.getCreateTime()
		);
		
}