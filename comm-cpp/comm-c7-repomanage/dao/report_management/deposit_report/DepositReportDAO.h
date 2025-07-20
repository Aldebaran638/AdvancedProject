#pragma once

#ifndef _DEPOSIT_REPORT_DAO_
#define _DEPOSIT_REPORT_DAO_
#include "BaseDAO.h"
#include "domain/do/deposit_report/DepositReportDO.h"
#include "domain/query/deposit_report/DepositReportQuery.h"

/**
 * 示例表数据库操作实现
 */
class DepositReportDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const DepositReportQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const DepositReportQuery::Wrapper& query);
	// 分页查询数据
	std::list<DepositReportDO> selectWithPage(const DepositReportQuery::Wrapper& query);
	// 根据ID查询数据
	list<DepositReportDO> selectByCommunityId(const oatpp::String& community_id);
};
#endif // !_DEPOSIT_REPORT_DAO_
