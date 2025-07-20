#pragma once
#ifndef _INSPECTION_POINT_STATISTIC_H_
#define _INSPECTION_POINT_STATISTIC_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 小区巡检职工数据传输对象
 */
class MaintenanceMasterDTO : public oatpp::DTO
{   
	DTO_INIT(MaintenanceMasterDTO, DTO);
	// 小区巡检职工名
	API_DTO_FIELD_DEFAULT(String, staffName, ZH_WORDS_GETTER("inspection-report.field.master-name"));
	//已巡检的个数
	API_DTO_FIELD_DEFAULT(Int64, inspectEd, ZH_WORDS_GETTER("inspection-report.field.master-inspected"));
	//未巡检的个数
	API_DTO_FIELD_DEFAULT(Int64, unInspection, ZH_WORDS_GETTER("inspection-report.field.master-uninspection"));
};
/**
 * 巡检点统计数据传输对象
 */
class InspectionPointStatisticDTO : public oatpp::DTO
{
	DTO_INIT(InspectionPointStatisticDTO, DTO);
	// 巡检点名称  //例如1号巡检点
	API_DTO_FIELD_DEFAULT(String, inspectionPointName, ZH_WORDS_GETTER("inspection-report.field.point-id"));
	//小区巡检职工及状态
	API_DTO_FIELD_DEFAULT(List<MaintenanceMasterDTO::Wrapper>, staffs, ZH_WORDS_GETTER("inspection-report.field.masters"));
	// 添加构造函数确保列表初始化
	InspectionPointStatisticDTO() {
		staffs = List<MaintenanceMasterDTO::Wrapper>::createShared();
	}
};


/**
 * 巡检点统计分页传输对象
 */
class InspectionPointStatisticPageDTO : public PageDTO<InspectionPointStatisticDTO::Wrapper>
{
	DTO_INIT(InspectionPointStatisticPageDTO, PageDTO<InspectionPointStatisticDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INSPECTION_POINT_STATISTIC_H_