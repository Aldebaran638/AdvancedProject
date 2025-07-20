#pragma once
#ifndef _RAINDISTYPESDAO_H_
#define _RAINDISTYPESDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/discount_types/RainDisTypesDO.h"
#include "../../domain/query/discount_types/RainDisTypesQuery.h"

/**
 * 示例表数据库操作实现
 */
class RainDisTypesDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    RainDisTypesDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const RainDisTypesQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据RainDisTypesQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const RainDisTypesQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const RainDisTypesQuery::Wrapper& query);
	// 分页查询数据
	std::list<RainDisTypesDO> selectWithPage(const RainDisTypesQuery::Wrapper& query);
	//// 通过类型编号查询数据
	//std::list<RainDisTypesDO> selectById(std::string id);
	//// 通过类型名称查询数据
	std::list<RainDisTypesDO> selectByName(const string& name);
	// 插入数据
	int insert(const RainDisTypesDO& iObj);
};
#endif // !_RAINDISTYPESDAO_H_
