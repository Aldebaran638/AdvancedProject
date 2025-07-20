#pragma 
#ifndef _APPLY_DISCOUNT_RECORD_DAO_
#define _APPLY_DISCOUNT_RECORD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/applydiscount/ApplyRoomDiscountRecordDO.h"
#include "../../domain/do/applydiscount/ApplyRoomDiscountDO.h"
#include "../../domain/do/applydiscount/RecordQueryDO.h"
#include "../../domain/query/applydiscount/ApplyDiscountRecordQuery.h"

class ApplyDiscountRecordDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ApplyDiscountRecordQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ApplyDiscountRecordQuery::Wrapper& query);
	// 分页查询数据
	//std::list<ApplyRoomDiscountRecordDO> selectWithRecordPage(const ApplyDiscountRecordQuery::Wrapper& query);
	//std::list<ApplyRoomDiscountDO> selectWithPage(const ApplyDiscountRecordQuery::Wrapper& query);
	std::list<RecordQueryDO> selectWithPage(const ApplyDiscountRecordQuery::Wrapper& query);
	// 修改数据
	int updateState(const ApplyRoomDiscountDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string id);
};
#endif // !_APPLY_DISCOUNT_RECORD_DAO_
