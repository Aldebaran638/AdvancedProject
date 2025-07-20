#pragma once

#ifndef _ANALYSISARREARS_DAO_
#define _ANALYSISARREARS_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/analysis_arrears/AnalysisArrearsDO.h"
#include "../../../domain/query/analysis_arrears/AnalysisArrearsQuery.h"

/**
 * 欠费管理数据库操作实现
 */
class AnalysisArrearsDAO : public BaseDAO
{
public:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    AnalysisArrearsDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const AnalysisArrearsQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据AnalysisArrearsQuery对象动态构建查询条件相关参数
	//************************************
	std::string queryConditionBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// 获取服务器当前日期
	std::string getCurrentTime(void);
	// 获取收费类型列表
	std::list<AnalysisArrearsDO> selectFeeType(void);

	std::list<AnalysisArrearsDO> selectBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query);
};
#endif // !_ANALYSISARREARS_DAO_
