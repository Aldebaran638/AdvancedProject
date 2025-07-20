#pragma once
#ifndef _YARREARS_REMINDERSDAO_
#define _YARREARS_REMINDERSDAO_
#include "BaseDAO.h"
#include "domain/do/arrears_reminders/YArrears_RemindersDO.h"
#include "../../domain/query/arrears_reminders/YArrears_RemindersQuery.h"

/**
 * 示例表数据库操作实现
 */
class YArrears_RemindersDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const YArrears_RemindersQuery::Wrapper& query, SqlParams& params);
public:
	// 催缴登记
	int add(const YArrears_RemindersDO& uObj);
	// 统计数据条数
	uint64_t count(const YArrears_RemindersQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_
