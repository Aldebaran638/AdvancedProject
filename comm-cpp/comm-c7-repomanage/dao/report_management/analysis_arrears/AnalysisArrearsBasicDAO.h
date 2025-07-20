#pragma once
#ifndef _ANALYSIS_ARREARS_BASIC_DAO_H_
#define _ANALYSIS_ARREARS_BASIC_DAO_H_

#include "AnalysisArrearsDAO.h"
/**
 * 欠费管理未收情况表数据库操作实现
 */
class AnalysisArrearsBasicDAO : public AnalysisArrearsDAO
{
private:
	// 构建查询未收情况表的临时表
	std::string virtualBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// 构建查询未收情况表的基本SQL语句
	std::string selectBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询未收情况表数据
	std::list<AnalysisArrearsDO> selectBasicWithPage(const AnalysisArrearsQuery::Wrapper& query);
	// 统计未收情况表数据条数
	uint64_t countBasic(const AnalysisArrearsQuery::Wrapper& query);
	// 分页查询未收明细表数据
};

#endif // !_ANALYSIS_ARREARS_BASIC_DAO_H_