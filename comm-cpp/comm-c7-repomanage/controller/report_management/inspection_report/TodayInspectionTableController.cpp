#include "stdafx.h"


#include "TodayInspectionTableController.h"
#include "service/report_management/inspection_report/InspectionPointStatisticService.h"
#include <SimpleDateTimeFormat.h>
#include "ExcelComponent.h"
#include<map>

InspectionPointStatisticPageJsonVO::Wrapper TodayInspectionTableController::execQueryAll
(const TodayInspectionTableQuery::Wrapper& query)
{
	InspectionPointStatisticService service;

	// 使用createShared()初始化定义一个InspectionPointStatisticQuery对象
	auto ISquery = InspectionPointStatisticQuery::createShared();
	ISquery->pageIndex = query->pageIndex;
	ISquery->pageSize = query->pageSize;
	ISquery->startDate = query->todayDate;
	ISquery->deadline = query->todayDate;
	ISquery->community_id = query->community_id;

	auto result = service.listAll(ISquery);
	auto jvo = InspectionPointStatisticPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>TodayInspectionTableController::execExportTodayInspectionTable(const TodayInspectionTableQuery::Wrapper& query)
{
	//定义一个InspectionPointStatisticQuery
	auto ISquery = InspectionPointStatisticQuery::createShared();
	ISquery->pageIndex = query->pageIndex;
	ISquery->pageSize = query->pageSize;
	ISquery->startDate = query->todayDate;
	ISquery->deadline = query->todayDate;
	ISquery->community_id = query->community_id;

	// 1. 获取分组数据
	InspectionPointStatisticService service;
	auto exportData = service.listAllExport(ISquery);

	// 2. 生成Excel文件
	auto buff = ExcelComponent().writeVectorToBuff("inspection_stats",
		[exportData](ExcelComponent* ex) {
			//<员工，放员工的行号>,<巡检点，放员工的列号>
			unordered_map<string, int>mp_staff,mp_inspectionPoint;
			
			 //设置多语言表头
			ex->addHeader({
				ZH_WORDS_GETTER("inspection-report.field.staff"),
				});

			//初始行=2，初始列=1
			int row = 2,col=2;
			for (auto& point : *exportData) {
				
				string k1 = point->inspectionPointName;
				if (mp_inspectionPoint[k1] == 0) 
				{
					ex->setCellValue(1, col, k1 
						+ ZH_WORDS_GETTER("inspection-report.field.state"));
					mp_inspectionPoint[k1] = col++;
				}
				for (auto& staff : *point->staffs) {
					string k2 = staff->staffName;
					if (mp_staff[k2] == 0)
					{
						ex->setCellValue(row,1, k2);
						mp_staff[k2] = row++;
						ex->setRowProperties(row);
					}

					string vl = std::to_string(*staff->inspectEd) + '/' + std::to_string(*staff->unInspection);
					ex->setCellValue(mp_staff[k2],mp_inspectionPoint[k1], vl);

				}
			}
		});

	// 3. 构建响应
	auto response = createResponse(Status::CODE_200,
		String(reinterpret_cast<const char*>(buff.data()), buff.size()));

	// 4. 设置下载头
	std::string filename = "rp-TodayInspectionTable- " + SimpleDateTimeFormat::format("%Y%m%d") + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	return response;
}