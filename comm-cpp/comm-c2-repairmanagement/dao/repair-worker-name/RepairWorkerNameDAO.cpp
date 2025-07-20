#include "stdafx.h"
#include "RepairWorkerNameDAO.h"
#include "RepairWorkerNameMapper.h"
#include <sstream>

//根据Query构建查询维修师傅名称列表的查询条件 Where部分
std::string RepairWorkerNameDAO::queryRepairWorkNameConditionBuilder(const RepairWorkerNameQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";

	// 维修池表的 repair_id 作为查询条件
	if (query->repair_id) {
		sqlCondition << " AND r_repair_pool.repair_id=?"; // 指定表名
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_id.getValue(""));
	}

	// 维修类型用户表的 community_id 作为查询条件
	if (query->community_id) {
		sqlCondition << " AND r_repair_type_user.community_id=?"; // 指定表名
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	sqlCondition << " AND r_repair_type_user.status_cd='0' AND r_repair_type_user.state='9999'";
	return sqlCondition.str();
}

std::list<RepairWorkerNameDO> RepairWorkerNameDAO::selectWithPage(const RepairWorkerNameQuery::Wrapper& query)
{
	SqlParams params;

	// 核心变化：通过 JOIN 联表查询
	string sql = R"(
        SELECT r_repair_type_user.staff_name 
        FROM r_repair_pool
        INNER JOIN r_repair_type_user 
            ON r_repair_pool.repair_type = r_repair_type_user.repair_type
    )";

	// 添加条件
	sql += queryRepairWorkNameConditionBuilder(query, params);

	// 排序和分页（保持原逻辑）
	sql += " ORDER BY r_repair_type_user.staff_id DESC ";
	/*sql += " LIMIT " + ... */

	// 执行查询
	RepairWorkerNameMapper mapper;
	return sqlSession->executeQuery<RepairWorkerNameDO>(sql, mapper, params);
}
