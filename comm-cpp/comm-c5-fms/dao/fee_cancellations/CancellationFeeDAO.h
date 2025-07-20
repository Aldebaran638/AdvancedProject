#ifndef _CANCELLATIONFEE_DAO_
#define _CANCELLATIONFEE_DAO_
#include "BaseDAO.h"
#include "../../domain/query/fee_cancellations/CancellationFeeQuery.h"
#include"../../domain/do/fee_cancellations/CancellationFeeDO.h"
/*
** pay_fee_batch数据库操作实现
*/
class CancellationFeeDAO :public BaseDAO
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
	inline std::string queryConditionBuilder(const CancellationFeeQuery::Wrapper& query, SqlParams& params);
	//将前端传来的状态映射为常量字符串
	inline const std::string stateMapper(const std::string& state);
public:
	// 统计数据条数
	uint64_t count(const CancellationFeeQuery::Wrapper& query);
	// 分页查询数据
	std::list<CancellationFeeDO> selectWithPage(const CancellationFeeQuery::Wrapper& query);
	// 修改数据
	int update(const CancellationFeeDO& uObj);
};
#endif