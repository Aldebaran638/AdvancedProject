#include "stdafx.h"
#include "DissatisfiedRepairDAO.h"
#include "DissatisfiedRepairMapper.h"
#include <sstream>

std::string DissatisfiedRepairDAO::queryConditionBuilder(const DissatisfiedRepairQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;

    sqlCondition << " WHERE 1=1 ";
    cout << query->community_id.getValue("") << endl;

    if (query->community_id && !query->community_id->empty()) {
        sqlCondition << " AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
    }

    if (query->start_date && query->end_date) {
        sqlCondition << " AND t.create_time BETWEEN STR_TO_DATE(?, '%Y-%m-%d') AND STR_TO_DATE(?, '%Y-%m-%d')";
        SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue(""));
        SQLPARAMS_PUSH(params, "s", std::string, query->end_date.getValue(""));
    }
    else if (query->start_date) {
        sqlCondition << " AND t.create_time >= STR_TO_DATE(?, '%Y-%m-%d')";
        SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue(""));
    }
    else if (query->end_date) {
        sqlCondition << " AND t.create_time <= STR_TO_DATE(?, '%Y-%m-%d')";
        SQLPARAMS_PUSH(params, "s", std::string, query->end_date.getValue(""));
    }
    return sqlCondition.str();
}
std::list<DissatisfiedRepairDO> DissatisfiedRepairDAO::selectWithPage(const DissatisfiedRepairQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT "
        "DATE_FORMAT(t.create_time, '%Y-%m-%d') AS repair_time, "
        "t.repair_obj_name AS repair_location, "
        "t.repair_id AS repair_id, "
        "td.name AS status, "
        "rrv.context AS reason "
        "FROM r_repair_pool t "
        "INNER JOIN r_repair_return_visit rrv ON t.repair_id = rrv.repair_id AND rrv.status_cd = '0' "
        "LEFT JOIN t_dict td ON td.table_name = 'r_repair_pool' "
        "    AND td.table_columns = 'state' "
        "    AND td.status_cd = t.state ";
    sql += queryConditionBuilder(query, params);
  
    if (query->pageIndex > 0 && query->pageSize > 0) {
        sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
    }

    std::cout << "Query SQL: " << sql << std::endl;
    DissatisfiedRepairMapper mapper;
    return sqlSession->executeQuery<DissatisfiedRepairDO>(sql, mapper, params);
}

std::list<DissatisfiedRepairDO> DissatisfiedRepairDAO::listAllDO()
{
    string sql = "SELECT "
        "DATE_FORMAT(t.create_time, '%Y-%m-%d') AS repair_time, "
        "t.repair_obj_name AS repair_location, "
        "t.repair_id AS repair_id, "
        "td.name AS status, "
        "rrv.context AS reason "
        "FROM r_repair_pool t "
        "INNER JOIN r_repair_return_visit rrv ON t.repair_id = rrv.repair_id AND rrv.status_cd = '0' "
        "LEFT JOIN t_dict td ON td.table_name = 'r_repair_pool' "
        "    AND td.table_columns = 'state' "
        "    AND td.status_cd = t.state ";
    DissatisfiedRepairMapper mapper;
    return sqlSession->executeQuery<DissatisfiedRepairDO>(sql, mapper);
}

uint64_t  DissatisfiedRepairDAO::count(const  DissatisfiedRepairQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) "
        "FROM r_repair_pool t "
        "INNER JOIN r_repair_return_visit rrv ON t.repair_id = rrv.repair_id AND rrv.status_cd = '0' "
        "LEFT JOIN t_dict td ON td.table_name = 'r_repair_pool' "
        "    AND td.table_columns = 'state' "
        "    AND td.status_cd = t.state ";

    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}