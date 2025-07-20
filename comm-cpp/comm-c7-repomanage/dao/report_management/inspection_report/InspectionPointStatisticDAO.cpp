//InspectionPointStatisticDAO

#include "stdafx.h"
#include "InspectionPointStatisticDAO.h"
#include "InspectionPointStatisticMapper.h"
#include <sstream>

std::string InspectionPointStatisticDAO::queryConditionBuilder(const InspectionPointStatisticQuery::Wrapper& query, SqlParams& params)
{
    //cout << "正在构建WHERE语句" << endl;
    //cout << "传入的条件：" << query->startDate.getValue("") << " " << query->deadline.getValue("") << "  " << query->community_id.getValue("") << endl;
	std::stringstream sqlCondition;
	sqlCondition << " AND 1=1 ";
	if (query->startDate && query->deadline) {
		sqlCondition << " AND it.create_time BETWEEN STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s') AND STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "s", std::string, query->startDate.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->deadline.getValue(""));
	}
	else if (query->startDate) {
		sqlCondition << " AND it.create_time >= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "s", std::string, query->startDate.getValue(""));
	}
	else if (query->deadline) {
		sqlCondition << " AND it.create_time <= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "s", std::string, query->deadline.getValue(""));
	}
    //cout << "构建完成" << endl;
	return sqlCondition.str();
    
}

std::list<InspectionPointStatisticDO> InspectionPointStatisticDAO::selectWithPage(
    const InspectionPointStatisticQuery::Wrapper& query)
{
    //cout << "正在执行sql语句" << endl;
    SqlParams params;
    // 预生成条件字符串避免重复调用
    std::string condition = queryConditionBuilder(query, params);
    queryConditionBuilder(query, params);
    queryConditionBuilder(query, params);//插入条件
    std::stringstream sql;
    sql << "SELECT "
        << "t.inspection_name AS inspectionPointName, "
        << "t.point_obj_name AS pointObjName, "
        << "ips.staff_name AS staffName, "
        << "(SELECT COUNT(1) "
        << " FROM inspection_task it "
        << " INNER JOIN inspection_task_detail itd ON it.task_id = itd.task_id "
        << " AND itd.status_cd = '0' "
        << " WHERE itd.inspection_id = t.inspection_id "
        << " AND it.plan_user_id = ips.staff_id "
        << " AND itd.act_user_id IS NOT NULL "
        << condition // 复用条件
        << ") AS inspectEd, "
        << "(SELECT COUNT(1) "
        << " FROM inspection_task it "
        << " INNER JOIN inspection_task_detail itd ON it.task_id = itd.task_id "
        << " AND itd.status_cd = '0' "
        << " WHERE itd.inspection_id = t.inspection_id "
        << " AND it.plan_user_id = ips.staff_id "
        << " AND itd.act_user_id IS NULL "
        << condition // 复用条件
        << ") AS unInspection, "
        << "(SELECT itd.description "
        << " FROM inspection_task it "
        << " INNER JOIN inspection_task_detail itd ON it.task_id = itd.task_id "
        << " AND itd.status_cd = '0' "
        << " WHERE itd.inspection_id = t.inspection_id "
        << " AND it.plan_user_id = ips.staff_id "
        << " AND itd.act_user_id IS NOT NULL "
        << condition // 复用条件
        << " LIMIT 1) AS state "
        << "FROM inspection_point t "
        << "LEFT JOIN inspection_route_point_rel irpr ON t.inspection_id = irpr.inspection_id "
        << "AND irpr.status_cd = '0' "
        << "LEFT JOIN inspection_plan ip ON ip.inspection_route_id = irpr.inspection_route_id "
        << "AND ip.status_cd = '0' "
        << "LEFT JOIN inspection_plan_staff ips ON ip.inspection_plan_id = ips.inspection_plan_id "
        << "AND ips.status_cd = '0' "
        << "WHERE ips.staff_name IS NOT NULL "
        << "AND t.status_cd = '0' ";

    // 安全添加community_id参数
    if (query->community_id) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
    }

    sql << "GROUP BY t.inspection_name, t.point_obj_name, ips.staff_name, "
        << "t.inspection_id, ips.staff_id "
        << "ORDER BY IFNULL(t.inspection_name, '') DESC " // 修正IFNULL语法
        << "LIMIT ?, ?"; // 参数化分页

    // 添加分页参数
    v_int64 offset = (query->pageIndex - 1) * query->pageSize;
    SQLPARAMS_PUSH(params, "i", v_int64, offset);
    SQLPARAMS_PUSH(params, "i", v_int64, query->pageSize);
    //cout <<"params.size=" << params.size() << endl;
    //cout << "执行sql语句中。。。" << endl;
    // 执行查询
    InspectionPointStatisticMapper mapper;
    return sqlSession->executeQuery<InspectionPointStatisticDO>(sql.str(), mapper, params);
}

std::list<InspectionPointStatisticDO> InspectionPointStatisticDAO::listAllDO()
{
    return std::list<InspectionPointStatisticDO>();
}

uint64_t InspectionPointStatisticDAO::count(const InspectionPointStatisticQuery::Wrapper& query) {
    SqlParams params;
    std::stringstream sql;
    //cout << "开始执行count函数" << endl;

    // 构建子查询：完全复用主查询的分组逻辑
    sql << "SELECT COUNT(1) FROM ("
        << "SELECT t.inspection_id, ips.staff_id "
        << "FROM inspection_point t "
        << "LEFT JOIN inspection_route_point_rel irpr ON t.inspection_id = irpr.inspection_id AND irpr.status_cd = '0' "
        << "LEFT JOIN inspection_plan ip ON ip.inspection_route_id = irpr.inspection_route_id AND ip.status_cd = '0' "
        << "LEFT JOIN inspection_plan_staff ips ON ip.inspection_plan_id = ips.inspection_plan_id AND ips.status_cd = '0' "
        << "WHERE ips.staff_name IS NOT NULL "
        << "AND t.status_cd = '0' ";

    // 添加community_id条件
    if (query->community_id) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
    }

    sql << "GROUP BY t.inspection_name, t.point_obj_name, ips.staff_name, t.inspection_id, ips.staff_id"
        << ") AS grouped_data"; // 子查询别名

    return sqlSession->executeQueryNumerical(sql.str(), params);
}