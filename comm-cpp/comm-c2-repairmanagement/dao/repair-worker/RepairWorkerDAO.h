#pragma once
#ifndef _REPAIRWORKERDAO_H_
#define _REPAIRWORKERDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-worker/RepairWorkerDO.h"
#include "../../domain/query/repair-worker/RepairWorkerQuery.h"
/**
 * 查询师傅名称列表在repair_type_user表数据库操作实现
 */
class RepairWorkerDAO : public BaseDAO
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
	//sql语句builder，难道是建造者模式
	inline std::string queryRepairWorkerConditionBuilder(const RepairWorkerQuery::Wrapper& query, SqlParams& params);
public:
	//返回条数
	uint64_t count(const RepairWorkerQuery::Wrapper& query);
	// 分页查询数据
	std::list<RepairWorkerQueryDO> selectWithPage(const RepairWorkerQuery::Wrapper& query);
	// 插入数据
	int insert(const RepairWorkerAddDO& uObj);
	// 修改数据
	int update(const RepairWorkerModifyDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string type_user_id);
	//用于查重
	bool isDuplicate(const std::string& repairTypeName, const std::string& staffName, const std::string& communityId, const std::string& orgName);
};
#endif // _REPAIRWORKERDAO_H_