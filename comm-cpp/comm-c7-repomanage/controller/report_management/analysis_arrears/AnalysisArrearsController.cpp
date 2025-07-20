#include "stdafx.h"
#include "AnalysisArrearsController.h"
#include "../../../service/report_management/analysis_arrears/AnalysisArrearsService.h"
#include <iostream>
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

AnalysisArrearsBasicPageJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsBasic(const AnalysisArrearsQuery::Wrapper& query)
{
	// 定义一个Service
	AnalysisArrearsService service;
	// 查询数据
	auto result = service.listAllBasic(query);
	// 响应结果
	auto jvo = AnalysisArrearsBasicPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsDetailPageJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsDetail(const AnalysisArrearsQuery::Wrapper& query)
{
	// 定义一个Service
	AnalysisArrearsService service;
	// 查询数据
	auto result = service.listAllDetail(query);
	// 响应结果
	auto jvo = AnalysisArrearsDetailPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsMonthPageJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsMonth(const AnalysisArrearsQuery::Wrapper& query)
{
	// 定义一个Service
	AnalysisArrearsService service;
	// 查询数据
	auto result = service.listAllMonth(query);
	// 响应结果
	auto jvo = AnalysisArrearsMonthPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsFeeTypeListJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsFeeType(void)
{
	// 定义一个Service
	AnalysisArrearsService service;
	// 查询数据
	auto result = service.listFeeType();
	// 响应结果
	auto jvo = AnalysisArrearsFeeTypeListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsBuildingNumListJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsBuildingNum(const AnalysisArrearsQuery::Wrapper& query)
{
	// 定义一个Service
	AnalysisArrearsService service;
	// 查询数据
	auto result = service.listBuildingNum(query);
	// 响应结果
	auto jvo = AnalysisArrearsBuildingNumListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}