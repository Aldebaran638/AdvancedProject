#pragma once
#ifndef _YYYCDISTYPESDAO_
#define _YYYCDISTYPESDAO_
#include "BaseDAO.h"
#include "../../domain/do/discount_types/YyycDisTypesDO.h"
#include "../../domain/query/discount_types/YyycDisTypesQuery.h"

/**
 * 示例表数据库操作实现
 */
class YyycDisTypesDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const YyycDisTypesUpdateQuery::Wrapper& query, SqlParams& params);
public:
	// 修改数据
	int update(const YyycDisTypesDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string id);
};
#endif // !_SAMPLE_DAO_
