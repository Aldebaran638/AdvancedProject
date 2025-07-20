#pragma once
#ifndef _YYYCREVIEWSDAO_
#define _YYYCREVIEWSDAO_
#include "BaseDAO.h"
#include "../../domain/do/refund_reviews/YyycReviewsDO.h"
#include "../../domain/query/refund_reviews/YyycReviewsQuery.h"

/**
 * 示例表数据库操作实现
 */
class YyycRevewsDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const YyycReviewsQuery::Wrapper& query, SqlParams& params);
public:
	// 修改数据
	int update(const YyycReviewsDO& uObj);
	
};
#endif // !_SAMPLE_DAO_
