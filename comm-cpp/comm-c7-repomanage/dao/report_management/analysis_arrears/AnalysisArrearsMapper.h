#pragma once
#ifndef _ANALYSIS_ARREARS_MAPPER_H_
#define _ANALYSIS_ARREARS_MAPPER_H_

#include "Mapper.h"
#include "../../../domain/do/analysis_arrears/AnalysisArrearsDO.h"

// 楼栋编号映射
class AnalysisArrearsBuildingNumMapper : public Mapper<AnalysisArrearsDO>
{
public:
	AnalysisArrearsDO mapper(ResultSet* resultSet) const override
	{
		AnalysisArrearsDO data;
		data.setBuildingNum(resultSet->getString(1));
		data.setBuildingId(resultSet->getString(2));
		return data;
	}
};

// 欠费分析收费类型映射
class AnalysisArrearsFeeTypeMapper : public Mapper<AnalysisArrearsDO>
{
public:
	AnalysisArrearsDO mapper(ResultSet* resultSet) const override
	{
		AnalysisArrearsDO data;
		data.setFeeTypeName(resultSet->getString(1));
		data.setFeeType(resultSet->getString(2));
		return data;
	}
};

/**
 * 欠费分析未收情况表字段匹配映射
 */
class AnalysisArrearsBasicMapper : public Mapper<AnalysisArrearsDO>
{
public:
	AnalysisArrearsDO mapper(ResultSet* resultSet) const override
	{
		AnalysisArrearsDO data;
		data.setBuildingNum(resultSet->getString(1));
		data.setTotalArrear(resultSet->getDouble(2));
		data.setThisYearTotalArrear(resultSet->getDouble(3));
		data.setBeforeTotalArrear(resultSet->getDouble(4));
		return data;
	}
};

/**
 * 欠费分析未收明细表字段匹配映射
 */
class AnalysisArrearsDetailMapper : public Mapper<AnalysisArrearsDO>
{
public:
	AnalysisArrearsDO mapper(ResultSet* resultSet) const override
	{
		AnalysisArrearsDO data;
		data.setBuildingNum(resultSet->getString(1));
		data.setRoomNum(resultSet->getString(2));
		data.setRoomArea(resultSet->getDouble(3));
		data.setFeeName(resultSet->getString(4));
		data.setFeeStartTime(resultSet->getString(5));
		data.setFeeEndTime(resultSet->getString(6));
		data.setTotalArrear(resultSet->getDouble(7));
		data.setThisYearTotalArrear(resultSet->getDouble(8));
		data.setBeforeTotalArrear(resultSet->getDouble(9));
		return data;
	}
};

/**
 * 欠费分析当月未收情况表字段匹配映射
 */
class AnalysisArrearsMonthMapper : public Mapper<AnalysisArrearsDO>
{
public:
	AnalysisArrearsDO mapper(ResultSet* resultSet) const override
	{
		AnalysisArrearsDO data;
		data.setBuildingNum(resultSet->getString(1));
		data.setEveryMonthArrear(resultSet->getDouble(2));
		data.setThisMonthCollect(resultSet->getDouble(3));
		data.setThisMonthCollectForThisYear(resultSet->getDouble(4));
		data.setThisMonthCollectForThisMonth(resultSet->getDouble(5));
		data.setThisMonthCollectForNextMonth(resultSet->getDouble(6));
		data.setThisMonthCollectForBefore(resultSet->getDouble(7));
		return data;
	}
};

#endif // !_ANALYSIS_ARREARS_MAPPER_H_