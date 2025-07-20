#pragma once
#ifndef _REPAIRWORKERNAMEDAO_H_
#define _REPAIRWORKERNAMEDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-worker-name/RepairWorkerNameDo.h"
#include "../../domain/query/repair-worker-name/RepairWorkerNameQuery.h"
/**
 * 查询师傅名称列表在repair_type_user表数据库操作实现
 */
class RepairWorkerNameDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryRepairWorkNameConditionBuilder
	// FullName:    RepairWorkerNameDAO::queryRepairWorkNameConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryRepairWorkNameConditionBuilder(const RepairWorkerNameQuery::Wrapper& query, SqlParams& params);
public:

	// 分页查询数据
	std::list<RepairWorkerNameDO> selectWithPage(const RepairWorkerNameQuery::Wrapper& query);

};
#endif // _REPAIRWORKERNAMEDAO_H_