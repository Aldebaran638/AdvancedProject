#include "stdafx.h"
#include "YArrears_RemindersDAO.h"
#include <sstream>
inline std::string YArrears_RemindersDAO::queryConditionBuilder(const YArrears_RemindersQuery::Wrapper& query, SqlParams& params)
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

// 插入方法
int YArrears_RemindersDAO::add(const YArrears_RemindersDO& iObj)
{
	// 更新SQL插入语句，添加所有新字段
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