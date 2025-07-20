#include "stdafx.h"
#include "DepositReportController.h"
#include "service/report_management/deposit_report/DepositReportService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
DepositReportPageJsonVO::Wrapper DepositReportController::execQueryDepositReport(const DepositReportQuery::Wrapper& query)
{
	// 定义一个JsonVO对象
	auto vo = DepositReportPageJsonVO::createShared();

	// 定义一个Service
	DepositReportService service;
	// 调用service层 查询押金报表数据
	auto res = service.listAll(query);

	vo->success(res);
	return vo;
}

//std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>  DepositReportController::execExportDepositReport(const String& community_id)
//{
//
//	// 调用Service层获取数据
//	auto service = std::make_shared<DepositReportService>();
//	auto dataList = service->listByCommunityId(community_id);
//
//	// 创建Excel组件
//	ExcelComponent excel;
//
//	// 将dataList转换为vector<vector<string>>格式
//	std::vector<std::vector<std::string>> vectorData;
//
//	// 添加表头
//	std::vector<std::string> headerRow;
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.fee_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.fee_type_cd"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.start_time"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.end_time"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.create_time"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.income_obj_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.payer_obj_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.pay_state"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.community_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.location_obj_name"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.owner_name"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.config_name"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.receivable_amount"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.return_state"));
//
//
//	vectorData.push_back(headerRow);
//
//	// 添加数据行
//	for (auto dto : *dataList->rows.get())
//	{
//		std::vector<std::string> row;
//		row.push_back(dto->fee_id.getValue(""));
//		row.push_back(dto->fee_type_cd.getValue(""));
//		row.push_back(dto->start_time.getValue(""));
//		row.push_back(dto->end_time.getValue(""));
//		row.push_back(dto->create_time.getValue(""));
//		row.push_back(dto->income_obj_id.getValue(""));
//		row.push_back(dto->payer_obj_id.getValue(""));
//		row.push_back(dto->pay_state.getValue(""));
//		row.push_back(dto->community_id.getValue(""));
//		row.push_back(dto->location_obj_name.getValue(""));
//		row.push_back(dto->owner_name.getValue(""));
//		row.push_back(dto->config_name.getValue(""));
//		row.push_back(dto->receivable_amount.getValue(""));
//		row.push_back(dto->return_state.getValue(""));
//
//
//		vectorData.push_back(row);
//	}
//
//	// 写入数据
//	string fileName = "depositReport.xlsx";
//	string filePath = "C:\\temp\\" + fileName;
//
//	excel.writeVectorToFile(filePath, fileName, vectorData);
//
//
//	// 使用FastDFS上传文件
//	FastDfsClient fastdfs("192.168.110.145");
//
//	// 上传到FastDFS
//	String fileUrl = fastdfs.uploadFile(filePath);
//
//	if (fileUrl == "") {
//		return createDtoResponse(Status::CODE_500, DepositReportExportVO::createShared());
//	}
//	else {
//		// 返回FastDFS文件URL
//		auto jsonResponse = DepositReportExportVO::createShared();
//		jsonResponse->data->fileUrl = fileUrl;
//		jsonResponse->data->fileName = fileName;
//
//		return createDtoResponse(Status::CODE_200, jsonResponse);
//	}
//}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>
DepositReportController::execExportDepositReport(const String& community_id)
{
    // 调用Service层获取数据
    auto service = std::make_shared<DepositReportService>();
    auto dataList = service->listByCommunityId(community_id);

    // 创建Excel组件并写入内存缓冲区
    auto buff = ExcelComponent().writeVectorToBuff("depositReport",
        [dataList](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("depositReport.fee_id"),
                ZH_WORDS_GETTER("depositReport.fee_type_cd"),
                ZH_WORDS_GETTER("depositReport.start_time"),
                ZH_WORDS_GETTER("depositReport.end_time"),
                ZH_WORDS_GETTER("depositReport.create_time"),
                ZH_WORDS_GETTER("depositReport.income_obj_id"),
                ZH_WORDS_GETTER("depositReport.payer_obj_id"),
                ZH_WORDS_GETTER("depositReport.pay_state"),
                ZH_WORDS_GETTER("depositReport.community_id"),
                ZH_WORDS_GETTER("depositReport.location_obj_name"),
                ZH_WORDS_GETTER("depositReport.owner_name"),
                ZH_WORDS_GETTER("depositReport.config_name"),
                ZH_WORDS_GETTER("depositReport.receivable_amount"),
                ZH_WORDS_GETTER("depositReport.return_state")
                });

            // 写入数据
            int row = 2;
            for (auto dto : *dataList->rows.get()) {
                int col = 1;
                ex->setCellValue(row, col++, dto->fee_id.getValue(""));
                ex->setCellValue(row, col++, dto->fee_type_cd.getValue(""));
                ex->setCellValue(row, col++, dto->start_time.getValue(""));
                ex->setCellValue(row, col++, dto->end_time.getValue(""));
                ex->setCellValue(row, col++, dto->create_time.getValue(""));
                ex->setCellValue(row, col++, dto->income_obj_id.getValue(""));
                ex->setCellValue(row, col++, dto->payer_obj_id.getValue(""));
                ex->setCellValue(row, col++, dto->pay_state.getValue(""));
                ex->setCellValue(row, col++, dto->community_id.getValue(""));
                ex->setCellValue(row, col++, dto->location_obj_name.getValue(""));
                ex->setCellValue(row, col++, dto->owner_name.getValue(""));
                ex->setCellValue(row, col++, dto->config_name.getValue(""));
                ex->setCellValue(row, col++, dto->receivable_amount.getValue(""));
                ex->setCellValue(row, col, dto->return_state.getValue(""));
                ex->setRowProperties(row++);
            }
        });

    // 组装响应数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应并设置HTTP头
    auto response = createResponse(Status::CODE_200, fstring);
    std::string filename = "rp-deposit-report-" + SimpleDateTimeFormat::format() + ".xlsx";

    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    return response;
}