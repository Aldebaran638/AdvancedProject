#include "stdafx.h"
#include "SummfeeDAO.h"
#include "SummfeeMapper.h"
#include <sstream>
inline std::string SummfeeDAO::queryConditionBuilder(const SummfeeQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->create_time) {
        std::string dateStr = query->create_time.getValue("");
        // 检查输入格式并构建条件
        if (dateStr.length() == 4) { // 年份格式 YYYY
            sqlCondition << " AND YEAR(create_time) = ?";
            SQLPARAMS_PUSH(params, "s", std::string, dateStr);
        }
        else if (dateStr.length() == 7) { // 年月格式 YYYY-MM
            sqlCondition << " AND DATE_FORMAT(create_time, '%Y-%m') = ?";
            SQLPARAMS_PUSH(params, "s", std::string, dateStr);
        }
        else if (dateStr.length() == 10) { // 完整日期格式 YYYY-MM-DD
            sqlCondition << " AND DATE(create_time) = ?";
            SQLPARAMS_PUSH(params, "s", std::string, dateStr);
        }
        else {
            // 无效日期格式处理
            throw std::invalid_argument("Invalid date format: " + dateStr);
        }
    }

    return sqlCondition.str();
}
uint64_t SummfeeDAO::count(const SummfeeQuery::Wrapper& query)
{ 
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM fee_receipt";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<SummfeeDO> SummfeeDAO::selectWithPage(const SummfeeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = R"(
        SELECT 
            create_time,
            obj_id,
            obj_name,
            receivable_amount,
            amount
        FROM 
            fee_receipt
    )";

    // 构建查询条件
    sql += queryConditionBuilder(query, params);

    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) +
        "," + std::to_string(query->pageSize);

    // 执行查询
    SummfeeMapper mapper;
    return sqlSession->executeQuery<SummfeeDO>(sql, mapper, params);
}
