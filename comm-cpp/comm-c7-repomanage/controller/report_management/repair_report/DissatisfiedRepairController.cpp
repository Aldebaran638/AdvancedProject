#include "stdafx.h"
#include "DissatisfiedRepairController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../comm-c7-repomanage/service/report_management/repair_report/DissatisfiedRepairService.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

DissatisfiedRepairPageJsonVO::Wrapper DissatisfiedRepairController::execQueryAll(const DissatisfiedRepairQuery::Wrapper& query) {
	DissatisfiedRepairService service;
	auto result = service.listAll(query);
	auto jvo = DissatisfiedRepairPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DissatisfiedRepairController::execExport(const String& filename)
{
	DissatisfiedRepairService server;
	auto DissatisfiedRepairList = server.listAllExport();

	vector<vector<string>> data;
	data.push_back({
		ZH_WORDS_GETTER("dissatisfied-repair.field.repair-time"),
		ZH_WORDS_GETTER("dissatisfied-repair.field.repair-location"),
		ZH_WORDS_GETTER("dissatisfied-repair.field.repair-id"),
		ZH_WORDS_GETTER("dissatisfied-repair.field.status"),
		ZH_WORDS_GETTER("dissatisfied-repair.field.reason"),
		});

	for (auto& record : DissatisfiedRepairList) {
		std::vector<std::string> row;
		row.push_back(record.getRepairTime());
		row.push_back(record.getRepairLocation());
		row.push_back(record.getRepairId());
		row.push_back(record.getStatus());
		row.push_back(record.getReason());
		data.push_back(row);
	}

	ExcelComponent excel;
	auto sheetName = ZH_WORDS_GETTER("dissatisfied-repair.export.sheet");
	auto buff = excel.writeVectorToBuff(sheetName, data);

	if (buff.empty()) {
		OATPP_LOGE("DissatisfiedRepairController", "Failed to generate Excel file");
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