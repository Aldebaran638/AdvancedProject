/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "RepairReportSummaryController.h"
#include "../../../service/report_management/repair_report_summary/RepairReportSummaryService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

RepairReportSummaryPageJsonVO::Wrapper RepairReportSummaryController::execQueryRepairReportSummary(const RepairReportSummaryQuery::Wrapper& query)
{
	// 定义一个Service
	RepairReportSummaryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RepairReportSummaryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RepairReportSummaryController::execExportRepairReportSummary(const RepairReportSummaryQuery::Wrapper& query)
{
	// 定义一个Service
	RepairReportSummaryService service;
	// 查询数据
	auto result = service.listAll(query);
	
	// 将数据写入到Excel中
	auto buff = ExcelComponent().writeVectorToBuff("repairReportSummary",
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("repair.staff.id") ,
				ZH_WORDS_GETTER("repair.staff.name") ,
				ZH_WORDS_GETTER("repair.list.deal") ,
				ZH_WORDS_GETTER("repair.list.send"),
				ZH_WORDS_GETTER("repair.list.transfer"),
				ZH_WORDS_GETTER("repair.list.back"),
				ZH_WORDS_GETTER("repair.list.returnVisit"),
				ZH_WORDS_GETTER("repair.list.finish"),
				ZH_WORDS_GETTER("repair.staff.grade")
				});
			// 写入数据
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->staffId);
				ex->setCellValue(row, col++, item->staffName);
				ex->setCellValue(row, col++, std::to_string(item->deal));
				ex->setCellValue(row, col++, std::to_string(item->sendList));
				ex->setCellValue(row, col++, std::to_string(item->transferList));
				ex->setCellValue(row, col++, std::to_string(item->chargeback));
				ex->setCellValue(row, col++, std::to_string(item->returnVisit));
				ex->setCellValue(row, col++, std::to_string(item->finish));
				ex->setCellValue(row, col, item->examineValue);
				ex->setRowProperties(row++);
			}
		});

	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "repair-report-summary" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
}
