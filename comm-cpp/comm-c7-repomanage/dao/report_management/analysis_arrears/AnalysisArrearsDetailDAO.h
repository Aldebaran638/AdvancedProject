#pragma once
#ifndef _ANALYSIS_ARREARS_DAO_DETAIL_H_
#define _ANALYSIS_ARREARS_DAO_DETAIL_H_

#include "AnalysisArrearsDAO.h"
/**
 * 欠费管理未收明细表数据库操作实现
 */
class AnalysisArrearsDetailDAO : public AnalysisArrearsDAO
{
private:
	// 构建查询未收明细表的临时表
	std::string virtualDetailBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// 构建查询未收明细表的基本SQL语句
	std::string selectDetailBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询未收明细表数据
	std::list<AnalysisArrearsDO> selectDetailWithPage(const AnalysisArrearsQuery::Wrapper& query);
	// 统计未收明细表数据条数
	uint64_t countDetail(const AnalysisArrearsQuery::Wrapper& query);
};

#endif // !_ANALYSIS_ARREARS_DAO_DETAIL_H_