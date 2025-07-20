#include "stdafx.h"

#include "InspectionPointStatisticController.h"
#include "service/report_management/inspection_report/InspectionPointStatisticService.h"
#include <SimpleDateTimeFormat.h>
#include "ExcelComponent.h"
#include "FastDfsClient.h"
InspectionPointStatisticPageJsonVO::Wrapper InspectionReporStatisticsController::execQueryAll(const InspectionPointStatisticQuery::Wrapper& query)
{
	// 定义一个Service
	InspectionPointStatisticService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InspectionPointStatisticPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>
InspectionReporStatisticsController::execExportInspectionStatisticsTable(const InspectionPointStatisticQuery::Wrapper& query)
{
	// 1. 获取分组数据
	InspectionPointStatisticService service;
	auto exportData = service.listAllExport(query);

	
	// 2. 生成Excel文件
	auto buff = ExcelComponent().writeVectorToBuff("inspection_stats",
		[exportData](ExcelComponent* ex) {

			// 设置多语言表头
			ex->addHeader({
				ZH_WORDS_GETTER("inspection-report.field.point-id"),
				ZH_WORDS_GETTER("inspection-report.field.master-name"),
				ZH_WORDS_GETTER("inspection-report.field.master-inspected")+'/' + ZH_WORDS_GETTER("inspection-report.field.master-uninspection")
				});
			// 动态列结构处理
			//设置最大列号
			int max_col = 2;
			int row = 2;//第二行开始
			for (auto& point : *exportData) {
				// 第一列：巡检点名称
				ex->setCellValue(row, 1, point->inspectionPointName);

				// 动态写入职工数据
				int col = 2;
				for (auto& staff : *point->staffs) {
					// 1. 职工姓名直接传递（已经是String类型）
					ex->setCellValue(row, col++, staff->staffName);
					// 2. 整数类型转换为字符串
					string vl = std::to_string(*staff->inspectEd) + '/' + std::to_string(*staff->unInspection);
					ex->setCellValue(row, col++,vl);  
					
				}
				ex->setRowProperties(row++);
				max_col = max(max_col, col);
				
			}
			//在第一行加入标题
			//cout << "最大列号为:" << max_col << endl;
			for (int i = 4; i <= max_col-2 ; )
			{
				ex->setCellValue(1, i++, 
					ZH_WORDS_GETTER("inspection-report.field.master-name"));

				ex->setCellValue(1, i++,
					ZH_WORDS_GETTER("inspection-report.field.master-inspected") 
					+ '/' 
					+ ZH_WORDS_GETTER("inspection-report.field.master-uninspection"));
			}
		});

	// 3. 构建响应
	auto response = createResponse(Status::CODE_200,
		String(reinterpret_cast<const char*>(buff.data()), buff.size()));

	// 4. 设置下载头
	std::string filename = "rp-InspectionReporStatistics- " + SimpleDateTimeFormat::format("%Y%m%d") + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE,"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	return response;
}
