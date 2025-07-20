#include "stdafx.h"
#include "OwnerPayExpController.h"
#include "../../../../service/report_management/owner_payment/OwnerPaymentService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> OwnerPaymentExpController::execExport(const OwnerPaymentQuery::Wrapper& userQuery)
{
	// 定义一个Service
	OwnerPaymentService service;
	// 查询数据
	auto result = service.listAllExport();

	vector<vector<string>> data;
	data.push_back({
		ZH_WORDS_GETTER("owner-payment-detail.field.ownerName"),
		ZH_WORDS_GETTER("owner-payment-detail.field.roomName"),
		ZH_WORDS_GETTER("owner-payment-detail.field.configId") ,
		std::string("1") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("2") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("3") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("4") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("5") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("6") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("7") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("8") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("9") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("10") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("11") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		std::string("12") + ZH_WORDS_GETTER("owner-payment-export.field.month") ,
		ZH_WORDS_GETTER("owner-payment-detail.field.totalAmount") ,
		ZH_WORDS_GETTER("owner-payment-detail.field.receivableAmount") ,
		ZH_WORDS_GETTER("owner-payment-detail.field.receivedAmount") ,
		});

	for (auto& record : result) {
		std::vector<std::string> row;
		row.push_back(record.getOwnerName());
		row.push_back(record.getRoomName());
		row.push_back(record.getConfigName());
		row.push_back(std::to_string(record.getPfMonth1()));
		row.push_back(std::to_string(record.getPfMonth2()));
		row.push_back(std::to_string(record.getPfMonth3()));
		row.push_back(std::to_string(record.getPfMonth4()));
		row.push_back(std::to_string(record.getPfMonth5()));
		row.push_back(std::to_string(record.getPfMonth6()));
		row.push_back(std::to_string(record.getPfMonth7()));
		row.push_back(std::to_string(record.getPfMonth8()));
		row.push_back(std::to_string(record.getPfMonth9()));
		row.push_back(std::to_string(record.getPfMonth10()));
		row.push_back(std::to_string(record.getPfMonth11()));
		row.push_back(std::to_string(record.getPfMonth12()));
		row.push_back(std::to_string(record.getTotalAmount()));
		row.push_back(std::to_string(record.getReceivableAmount()));
		row.push_back(std::to_string(record.getReceivedAmount()));
		data.push_back(row);
	}

	ExcelComponent excel;
	auto sheetName = ZH_WORDS_GETTER("owner-payment-export.field.sheet");
	auto buff = excel.writeVectorToBuff(sheetName, data);


	if (buff.empty()) {
		OATPP_LOGE("OwnerPayExpController", "Failed to generate Excel file");
		return createResponse(Status::CODE_500, "Internal Server Error");
	}

	const char* tsData = reinterpret_cast<const char*>(buff.data());

	auto fstring = String(tsData, buff.size());
	if (!fstring) {
		std::cerr << "Failed to generate Excel file: " << std::strerror(errno) << std::endl;
		return createResponse(oatpp::web::protocol::http::Status::CODE_500, "File generation failed");
	}
	auto response = createResponse(Status::CODE_200, fstring);
	string filename = "rp-owner-payment-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
	
}
