#pragma once
#ifndef _SUMMFEE_DAO_
#define _SUMMFEE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/fee_summary_report/SummfeeDO.h"
#include "../../domain/query/fee_summary_report/SummfeeQuery.h"

/**
 * 示例表数据库操作实现
 */
class SummfeeDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const SummfeeQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const SummfeeQuery::Wrapper& query);
	// 分页查询数据
	std::list<SummfeeDO> selectWithPage(const SummfeeQuery::Wrapper& query);

};
#endif // !_SUMMFEE_DAO_
