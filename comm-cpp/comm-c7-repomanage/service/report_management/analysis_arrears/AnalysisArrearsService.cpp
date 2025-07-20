#include "stdafx.h"
#include "AnalysisArrearsService.h"
#include "../../../dao/report_management/analysis_arrears/AnalysisArrearsBasicDAO.h"
#include "../../../dao/report_management/analysis_arrears/AnalysisArrearsDetailDAO.h"
#include "../../../dao/report_management/analysis_arrears/AnalysisArrearsMonthDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

AnalysisArrearsFeeTypeListDTO::Wrapper AnalysisArrearsService::listFeeType(void)
{
	// 构建返回对象
	auto page = AnalysisArrearsFeeTypeListDTO::createShared();
	// 查询数据总条数
	AnalysisArrearsDAO dao;
	
	list<AnalysisArrearsDO> result = dao.selectFeeType();
	// 将DO转换成DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsFeeTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, feeType, FeeType, feeTypeName, FeeTypeName);
		page->addData(dto);
	}
	return page;
}

AnalysisArrearsBuildingNumListDTO::Wrapper AnalysisArrearsService::listBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query)
{
	// 构建返回对象
	auto page = AnalysisArrearsBuildingNumListDTO::createShared();
	// 查询数据总条数
	AnalysisArrearsDAO dao;

	list<AnalysisArrearsDO> result = dao.selectBuildingNum(query);
	// 将DO转换成DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsBuildingNumDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, buildingId, BuildingId);
		page->addData(dto);
	}
	return page;
}

AnalysisArrearsBasicListPageDTO::Wrapper AnalysisArrearsService::listAllBasic(const AnalysisArrearsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = AnalysisArrearsBasicListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	AnalysisArrearsBasicDAO dao;
	uint64_t count = dao.countBasic(query);
	cout << count << endl;
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AnalysisArrearsDO> result = dao.selectBasicWithPage(query);
	// 将DO转换成DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsBasicDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, totalArrear, TotalArrear, thisYearTotalArrear, ThisYearTotalArrear, beforeTotalArrear, BeforeTotalArrear);
		pages->addData(dto);
	}
	return pages;
}

AnalysisArrearsDetailListPageDTO::Wrapper AnalysisArrearsService::listAllDetail(const AnalysisArrearsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = AnalysisArrearsDetailListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	AnalysisArrearsDetailDAO dao;
	uint64_t count = dao.countDetail(query);
	cout << count << endl;
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AnalysisArrearsDO> result = dao.selectDetailWithPage(query);
	// 将DO转换成DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, roomNum, RoomNum, roomArea, RoomArea, feeName, FeeName, feeStartTime, FeeStartTime, feeEndTime, FeeEndTime, totalArrear, TotalArrear, thisYearTotalArrear, ThisYearTotalArrear, beforeTotalArrear, BeforeTotalArrear);
		pages->addData(dto);
	}
	return pages;
}

AnalysisArrearsMonthListPageDTO::Wrapper AnalysisArrearsService::listAllMonth(const AnalysisArrearsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = AnalysisArrearsMonthListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	AnalysisArrearsMonthDAO dao;
	uint64_t count = dao.countMonth(query);
	cout << count << endl;
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AnalysisArrearsDO> result = dao.selectMonthWithPage(query);
	// 将DO转换成DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsMonthDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, everyMonthArrear, EveryMonthArrear, \
			thisMonthCollect, ThisMonthCollect, thisMonthCollectForThisYear, ThisMonthCollectForThisYear, \
			thisMonthCollectForThisMonth, ThisMonthCollectForThisMonth, thisMonthCollectForNextMonth, \
			ThisMonthCollectForNextMonth, thisMonthCollectForBefore, ThisMonthCollectForBefore);
		pages->addData(dto);
	}
	return pages;
}

