#include "stdafx.h"
#include "RepairStatisticsController.h"
#include "../../../service/report_management/repair_report/RepairStatisticsService.h"
#include "../../../domain/vo/repair_report/RepairStatisticsVO.h"
#include "../../../domain/dto/repair_report/RepairStatisticsDTO.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

QueryRepairStatisticsJsonVO::Wrapper RepairStatisticsController::execQueryRepairStatistics(const QueryRepairStatisticsQuery::Wrapper& query) {
	RepairStatisticsService service;
	auto result = service.countRepairStatistics(query);
	// 创建响应对象
	auto responseVO = QueryRepairStatisticsJsonVO::createShared();
	responseVO->success(result);
	return responseVO;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RepairStatisticsController::execExportRepairStatistic(const QueryRepairStatisticsQuery::Wrapper& query)
{
	// 定义一个Service
	RepairStatisticsService service;
	// 查询数据
	auto result = service.countRepairStatistics(query);

	// 将数据写入到Excel中
	auto buff = ExcelComponent().writeVectorToBuff("sample",
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("jiusui.repair.public_count") ,
				ZH_WORDS_GETTER("jiusui.repair.private_count") ,
				ZH_WORDS_GETTER("jiusui.repair.assigned_count") ,
				ZH_WORDS_GETTER("jiusui.repair.revisit_count") ,
				ZH_WORDS_GETTER("jiusui.repair.unrevisit_count") ,
				ZH_WORDS_GETTER("jiusui.repair.public_incomplete") ,
				ZH_WORDS_GETTER("jiusui.repair.private_incomplete") ,
				ZH_WORDS_GETTER("jiusui.repair.repair_pay") ,
				ZH_WORDS_GETTER("jiusui.repair.repair_payed") ,
				ZH_WORDS_GETTER("jiusui.repair.private_incomplete_average") ,
				ZH_WORDS_GETTER("jiusui.repair.public_incomplete_average") ,
				});
			// 写入数据
			int row = 2;
			int col = 1;
			//for (auto item : *(result->data)) {
			//	col = 1;
				ex->setCellValue(row, col++, std::to_string(result->public_count));
				ex->setCellValue(row, col++, std::to_string(result->private_count));
				ex->setCellValue(row, col++, std::to_string(result->assigned_count));
				ex->setCellValue(row, col++, std::to_string(result->revisit_count));
				ex->setCellValue(row, col++, std::to_string(result->unrevisit_count));
				ex->setCellValue(row, col++, std::to_string(result->public_incomplete));
				ex->setCellValue(row, col++, std::to_string(result->private_incomplete));
				ex->setCellValue(row, col++, std::to_string(result->repair_pay));
				ex->setCellValue(row, col++, std::to_string(result->repair_payed));
				ex->setCellValue(row, col++, std::to_string(result->private_incomplete_average));
				ex->setCellValue(row, col, std::to_string(result->public_incomplete_average));
				ex->setRowProperties(row++);
			//}
		});

	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "rp-RepairStatistics-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
}