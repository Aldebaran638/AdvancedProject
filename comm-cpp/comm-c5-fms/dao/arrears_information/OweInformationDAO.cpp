#include "OweInformationDAO.h"
#include "OweInformationMapper.h"
#include "OweInformationDAO.h"
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>
// 统计数据条数
uint64_t OweInformationDAO::count(const OweInformationQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM bill_owe_fee";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}
//构建查询条件
std::string OweInformationDAO::queryConditionBuilder(const OweInformationQuery::Wrapper& query, SqlParams& params) {
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    //  楼栋条件（building_owner_room_rel.b_id）
    if (query->b_id) {
        sqlCondition << " AND building_owner_room_rel.b_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->b_id.getValue(""));
    }

    // 单元条件（building_unit.unit_num）
    if (query->unit_num) {
        sqlCondition << " AND building_unit.unit_num=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->unit_num.getValue(""));
    }

    // 房屋编号条件（building_owner_room_rel.room_id）
    if (query->room_id) {
        sqlCondition << " AND building_owner_room_rel.room_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->room_id.getValue(""));
    }

    // 业主名称条件（bill_owe_fee.owner_name）
    if (query->owner_name) {
        sqlCondition << " AND bill_owe_fee.owner_name=?";
        SQLPARAMS_PUSH(params, "s", std::string,query->owner_name.getValue(""));
    }

    //付费对象类型条件（bill_owe_fee.payer_obj_type)
    if (query->payer_obj_type) {
        sqlCondition << " AND bill_owe_fee.payer_obj_type=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->payer_obj_type.getValue(""));
    }

    // 费用项条件（bill_owe_fee.fee_id）
    if (query->fee_id) {
        sqlCondition << " AND bill_owe_fee.fee_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->fee_id.getValue(""));
    }
    return sqlCondition.str();
}
//执行分页查询
std::list<OweInformationDo> OweInformationDAO::selectWithPage(const OweInformationQuery::Wrapper& query) {
    SqlParams params;

    //多表联合查询SQL
    string sql = R"(
        SELECT 
            bill_owe_fee.owe_id,
            bill_owe_fee.payer_obj_name,
            bill_owe_fee.owner_name,
            bill_owe_fee.owner_tel,
            bill_owe_fee.create_time,
            bill_owe_fee.deadline_time,
            bill_owe_fee.bill_amount_owed,
            bill_owe_fee.fee_end_time
        FROM 
            bill_owe_fee
        LEFT JOIN 
            building_owner_room_rel  ON bill_owe_fee.owner_id = building_owner_room_rel.owner_id
        LEFT JOIN 
            building_unit ON building_owner_room_rel.b_id = building_unit.b_id
    )";

    // 构建动态条件
    sql += queryConditionBuilder(query, params);
    //分页逻辑
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
    //执行查询
    OweInformationMapper mapper;
    return sqlSession->executeQuery<OweInformationDo>(sql, mapper, params);
}

//查询需要导出的数据
std::list<OweInformationDo> OweInformationDAO::getAll()
{
	std::string sql = "select owe_id,payer_obj_name,owner_id,owner_tel,create_time,deadline_time,bill_amount_owed,fee_end_time from bill_owe_fee";
	OweInformationMapper mapper;
	return sqlSession->executeQuery<OweInformationDo, OweInformationMapper>(sql, mapper);
}