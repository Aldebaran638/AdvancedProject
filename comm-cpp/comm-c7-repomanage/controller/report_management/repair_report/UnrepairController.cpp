#include "stdafx.h"
#include "UnrepairController.h"
#include <service/report_management/repair_report/UnrepairService.h>
#include <ExcelComponent.h>
#include <SimpleDateTimeFormat.h>

// 分页查询报修未完成数据
UnrepairPageJsonVO::Wrapper UnrepairController::execQueryAll(const UnrepairQuery::Wrapper& query) {
	UnrepairService service;
	auto result = service.listAll(query);
	auto jvo = UnrepairPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// 导出报修未完成数据
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> UnrepairController::execExportAll(const UnrepairQuery::Wrapper& query)
{// 定义一个Service
	UnrepairService service;
	// 查询数据
	auto result = service.listAll(query);

	// 将数据写入到Excel中
	auto buff = ExcelComponent().writeVectorToBuff("unrepair",
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("Unrepair.repairId") ,
				ZH_WORDS_GETTER("Unrepair.createTime") ,
				ZH_WORDS_GETTER("Unrepair.repairName") ,
				ZH_WORDS_GETTER("Unrepair.tel"),
				ZH_WORDS_GETTER("Unrepair.repairObjName") ,
				ZH_WORDS_GETTER("Unrepair.staffName") ,
				ZH_WORDS_GETTER("Unrepair.endTime") ,
				ZH_WORDS_GETTER("Unrepair.state")
				});
			// 写入数据
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->repairId);
				ex->setCellValue(row, col++, item->createTime);
				ex->setCellValue(row, col++, item->repairName);
				ex->setCellValue(row, col++, item->tel);
				ex->setCellValue(row, col++, item->repairObjName);
				ex->setCellValue(row, col++, item->staffName);
				ex->setCellValue(row, col++, item->endTime);
				ex->setCellValue(row, col++, item->state);
				ex->setRowProperties(row++);
			}
		});

	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "unrepair-export-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
}
