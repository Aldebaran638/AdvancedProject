#pragma once
#ifndef _ANALYSIS_ARREARS_DAO_MONTH_H_
#define _ANALYSIS_ARREARS_DAO_MONTH_H_

#include "AnalysisArrearsDAO.h"

/**
 * 欠费管理当月收费情况表数据库操作实现
 */
class AnalysisArrearsMonthDAO : public AnalysisArrearsDAO
{
private:
	// 构建查询当月收费情况表的临时表
	std::string virtualMonthBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// 构建查询当月收费情况表的基本SQL语句
	std::string selectMonthBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询当月收费情况表数据
	std::list<AnalysisArrearsDO> selectMonthWithPage(const AnalysisArrearsQuery::Wrapper& query);
	// 统计当月收费情况表数据条数
	uint64_t countMonth(const AnalysisArrearsQuery::Wrapper& query);
};

#endif // !_ANALYSIS_ARREARS_DAO_MONTH_H_