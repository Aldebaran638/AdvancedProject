#pragma once
#ifndef _REPAIRDONEDAO_H_
#define _REPAIRDONEDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-done/RepairDoneDO.h"
#include "../../domain/query/repair-done/RepairDoneQuery.h"

/**
 * 示例表数据库操作实现
 */
class RepairDoneDAO : public BaseDAO
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
	inline std::string RepairDone_queryConditionBuilder(const RepairDoneQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数 r_repair_pool表
	uint64_t RepairDone_count(const RepairDoneQuery::Wrapper& query);
	// 分页查询数据  r_repair_pool表、r_repair_setting表、t_dict表
	std::list<RepairDoneDO> RepairDone_selectWithPage(const RepairDoneQuery::Wrapper& query);

};
#endif // !_REPAIRDONEDAO_H_