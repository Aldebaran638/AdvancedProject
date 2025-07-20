#pragma once
#ifndef _REPAIRRETURNDAO_H_
#define _REPAIRRETURNDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-return/RepairReturnDO.h"
#include "../../domain/query/repair-return/RepairReturnQuery.h"

/**
 * 示例表数据库操作实现
 */
class RepairReturnDAO : public BaseDAO
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
	inline std::string RepairReturn_queryConditionBuilder(const RepairReturnQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t RepairReturn_count(const RepairReturnQuery::Wrapper& query);
	// 分页查询数据 r_repair_pool表、r_repair_setting表、t_dict表 
	std::list<RepairReturnDO> RepairReturn_selectWithPage(const RepairReturnQuery::Wrapper& query);
	// 插入数据 r_repair_return_visit表
	int RepairReturn_insert(const RepairReturnDO& iObj);

	// 修改数据 r_repair_return_visit表
	//int RepairReturn_update(const RepairReturnDO& uObj);
};
#endif // !_REPAIRRETURNDAO_H_
