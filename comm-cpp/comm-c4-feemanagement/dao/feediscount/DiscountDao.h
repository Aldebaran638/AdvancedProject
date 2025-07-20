#ifndef _DISCOUNT_DAO_H_
#define _DISCOUNT_DAO_H_

#include "BaseDAO.h"
#include "../../domain/do/feediscount/DiscountDo.h"
#include "../../domain/query/feediscount/DiscountQuery.h"

/**
 * 示例表数据库操作实现
 */
class DiscountDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const DiscountQuery::Wrapper& query, SqlParams& params);
public:
	int count();
	uint64_t insert(const DiscountDo& iObj);
	uint64_t update(const DiscountDo& uObj);
	uint64_t delete_(const DiscountDo& dObj);
	// 分页查询数据
	std::vector<DiscountDo> selectWithPage(const DiscountQuery::Wrapper& query);

};


#endif
