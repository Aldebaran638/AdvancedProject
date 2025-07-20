#include "stdafx.h"
#include "ClassificationTableDAO.h"
#include "ClassificationTableMapper.h"
#include <sstream>

std::string ClassificationTableDAO::queryConditionBuilder(const ClassificationTableQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";
    cout << query->community_id.getValue("") << endl;
    if (query->community_id && query->community_id) {
        sqlCondition << " AND r.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
    }
    else if (query->start_date && query->end_date) {
        sqlCondition << " AND r.create_time BETWEEN STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s') AND STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
        SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue(""));
        SQLPARAMS_PUSH(params, "s", std::string, query->end_date.getValue(""));
    }
    else if (query->start_date) {
        sqlCondition << " AND r.create_time >= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
        SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue(""));
    }
    else if (query->end_date) {
        sqlCondition << " AND r.create_time <= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
        SQLPARAMS_PUSH(params, "s", std::string, query->end_date.getValue(""));
    }
    return sqlCondition.str();
}
std::list<ClassificationTableDO> ClassificationTableDAO::selectWithPage(const ClassificationTableQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT r.repair_type_name, t.name AS public_area, COUNT(r.repair_type_name) AS type_count "
        "FROM r_repair_setting r "
        "JOIN t_dict t ON r.public_area = t.status_cd ";
    sql += queryConditionBuilder(query, params);
    sql += "AND t.table_name = 'r_repair_setting' ";
    sql += " GROUP BY r.repair_type_name, t.name ";
    if (query->pageIndex > 0 && query->pageSize > 0) {
        sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
    }
    std::cout <<" "+ sql << std::endl;
    ClassificationTableMapper mapper;
    return sqlSession->executeQuery<ClassificationTableDO>(sql, mapper, params);
}

std::list<ClassificationTableDO> ClassificationTableDAO::listAllDO()
{
    string sql = "SELECT r.repair_type_name, t.name AS public_area, COUNT(r.repair_type_name) AS type_count "
        "FROM r_repair_setting r "
        "LEFT JOIN t_dict t ON r.public_area = t.status_cd "
        "WHERE t.table_name = 'r_repair_setting' "
        "GROUP BY r.repair_type_name, t.name;";
    ClassificationTableMapper mapper;
    return sqlSession->executeQuery<ClassificationTableDO>(sql, mapper);
}

uint64_t ClassificationTableDAO::count(const ClassificationTableQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(DISTINCT r.repair_type_name, t.name) "
        "FROM r_repair_setting r "
        "JOIN t_dict t ON r.public_area = t.status_cd "
        "WHERE t.table_name = 'r_repair_setting' ";
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}