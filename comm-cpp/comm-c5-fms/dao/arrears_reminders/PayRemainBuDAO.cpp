#include "PayRemainBuDAO.h"
#include "PayRemainQuBUMapper.h"
#include "PayRemainBuMapper.h"
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>
inline std::string PayRemainBuDAO::queryConditionBuilder(const PayRemainBuQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->owner_name) {
        sqlCondition << " AND owner_name=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->owner_name.getValue(""));
    }

    if (query->fee_name) {
        sqlCondition << " AND fee_name=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->fee_name.getValue(""));
    }

    if (query->callable_way) {
        sqlCondition << " AND callable_way=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->callable_way.getValue(""));
    }

    if (query->staff_name) {
        sqlCondition << " AND staff_name=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->staff_name.getValue(""));
    }
    if (query->state) {
        sqlCondition << " AND state=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
    }
    return sqlCondition.str();
}
// 统计数据条数
uint64_t PayRemainBuDAO::count(const PayRemainBuQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM owe_fee_callable";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}
//条件和分页查询
std::list<PayRemainBuDO> PayRemainBuDAO::selectWithPage(const PayRemainBuQuery::Wrapper& query)
{
    SqlParams params;

    string sql = R"(
        SELECT 
            ofc_id,
            owner_name,
            payer_obj_name,
            fee_name,
            amountd_owed,
            start_time,
            callable_way,
            staff_name,
            state,
            remark,
            create_time
        FROM 
            owe_fee_callable
    )";

    // 构建动态条件
    sql += queryConditionBuilder(query, params);
    //分页逻辑
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
    //执行查询
    PayRemainQuBUMapper mapper;
    return sqlSession->executeQuery<PayRemainBuDO>(sql, mapper, params);
}
// 插入方法
int PayRemainBuDAO::insert(const PayRemainBuDO& iObj)
{
    // 更新SQL插入语句，添加所有新字段
    string sql = R"(
        INSERT INTO `owe_fee_callable` (
            `ofc_id`, 
            `community_id`,    -- 新增字段
            `owner_name`, 
            `owner_id`,        -- 新增字段
            `payer_obj_name`,
            `payer_obj_id`,    -- 新增字段
            `config_id`,       -- 新增字段
            `fee_id`,          -- 新增字段
            `fee_name`,
            `payer_obj_type`,  -- 新增字段
            `amountd_owed`, 
            `start_time`, 
            `callable_way`, 
            `staff_id`,        -- 新增字段
            `staff_name`, 
            `state`, 
            `end_time`,        -- 新增字段
            `remark`, 
            `create_time`,
            `status_cd`        -- 新增字段
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    )";

    // 执行更新，添加所有新字段
    return sqlSession->executeUpdate(
        sql,
        "%i%s%s%s%s%s%s%s%s%s%i%s%s%s%s%s%s%s%s%s",
        iObj.getOfc_Id(),
        iObj.getCommunity_Id(),    // 新增
        iObj.getOwner_Name(),
        iObj.getOwner_Id(),        // 新增
        iObj.getPayer_Obj_Name(),
        iObj.getPayer_Obj_Id(),    // 新增
        iObj.getConfig_Id(),       // 新增
        iObj.getFee_Id(),          // 新增
        iObj.getFee_Name(),
        iObj.getPayer_Obj_Type(),  // 新增
        iObj.getAmountd_Owed(),
        iObj.getStart_Time(),
        iObj.getCallable_Way(),
        iObj.getStaff_Id(),        // 新增
        iObj.getStaff_Name(),
        iObj.getState(),
        iObj.getEnd_Time(),        // 新增
        iObj.getRemark(),
        iObj.getCreate_Time(),
        iObj.getStatus_Cd()        // 新增
    );
}