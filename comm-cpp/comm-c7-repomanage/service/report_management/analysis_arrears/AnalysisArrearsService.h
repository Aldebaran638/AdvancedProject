#pragma once

#ifndef _ANALYSIS_ARREARS_SERVICE_H_
#define _ANALYSIS_ARREARS_SERVICE_H_
#include "../../../domain/vo/analysis_arrears/AnalysisArrearsVO.h"
#include "../../../domain/query/analysis_arrears/AnalysisArrearsQuery.h"
#include "../../../domain/dto/analysis_arrears/AnalysisArrearsDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AnalysisArrearsService
{
public:
	// 分页查询所有数据
	AnalysisArrearsBasicListPageDTO::Wrapper listAllBasic(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsDetailListPageDTO::Wrapper listAllDetail(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsMonthListPageDTO::Wrapper listAllMonth(const AnalysisArrearsQuery::Wrapper& query);
	// 查询收费类型列表
	AnalysisArrearsFeeTypeListDTO::Wrapper listFeeType(void);
	// 查询楼栋编号列表
	AnalysisArrearsBuildingNumListDTO::Wrapper listBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query);
};

#endif // !_ANALYSIS_ARREARS_SERVICE_H_
