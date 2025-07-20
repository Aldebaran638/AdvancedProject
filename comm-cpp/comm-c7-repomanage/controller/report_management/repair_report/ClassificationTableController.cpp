#include "stdafx.h"
#include "ClassificationTableController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../comm-c7-repomanage/service/report_management/repair_report/ClassificationTableService.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
ClassificationTablePageJsonVO::Wrapper ClassificationTableController::execQueryClassificationTable(const ClassificationTableQuery::Wrapper& query)
{
	ClassificationTableService service;
	auto result = service.listAll(query);
	auto jvo = ClassificationTablePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ClassificationTableController::execExportExcel(const String &filename)
{
	ClassificationTableService server;
	auto ClassificationTableList = server.listAllExport();

	vector<vector<string>> data;
	data.push_back({
		ZH_WORDS_GETTER("repair_report.classificationtable.public_area"),
		ZH_WORDS_GETTER("repair_report.classificationtable.repair_type"),
		ZH_WORDS_GETTER("repair_report.classificationtable.num") ,
	});

	for (auto& record : ClassificationTableList) {
		std::vector<std::string> row;
		row.push_back(record.getPublicArea());
		row.push_back(record.getRepairTypeName());
		row.push_back(std::to_string(record.getTypeCount()));
		data.push_back(row);
	}

	ExcelComponent excel;
	auto sheetName = ZH_WORDS_GETTER("repair_report.classificationtable.sheet");
	auto buff = excel.writeVectorToBuff(sheetName, data);


	if (buff.empty()) {
		OATPP_LOGE("ClassificationTableController", "Failed to generate Excel file");
		return createResponse(Status::CODE_500, "Internal Server Error");
	}

	const char* tsData = reinterpret_cast<const char*>(buff.data());
	
	auto fstring = String(tsData, buff.size());
	if (!fstring) {
		std::cerr << "Failed to generate Excel file: " << std::strerror(errno) << std::endl;
		return createResponse(oatpp::web::protocol::http::Status::CODE_500, "File generation failed");
	}
	auto response = createResponse(Status::CODE_200, fstring);
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
}