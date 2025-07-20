#include "stdafx.h"
#include "UnpaidHouseController.h"
#include "service/report_management/unpaid_house/UnpaidHouseService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"



UnpaidHousePageJsonVO::Wrapper UnpaidHouseController::execQueryUnpaidHouse(const UnpaidHouseQuery::Wrapper& query)
{
	// 定义一个Service
	UnpaidHouseService service;
	// 查询数据
	auto result = service.listWithPage(query);
	// 响应结果
	auto jvo = UnpaidHousePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> UnpaidHouseController::execExportUnpaidHouse(const UnpaidHouseQuery::Wrapper& query)
{
	// 定义一个Service
	UnpaidHouseService service;
	
	// 查询数据
	auto result = service.listAll(query);

	// 将数据写入到Excel中
	auto buff = ExcelComponent().writeVectorToBuff("unpaid-house",
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("unpaid-house.field.row-id") ,
				ZH_WORDS_GETTER("unpaid-house.field.floor-num") ,
				ZH_WORDS_GETTER("unpaid-house.field.unit-num") ,
				ZH_WORDS_GETTER("unpaid-house.field.room-num") ,
				ZH_WORDS_GETTER("unpaid-house.field.owner-name"),
				ZH_WORDS_GETTER("unpaid-house.field.link")
				});
			// 写入数据
			int row = 2;
			int col = 1;
			for (auto& item : *result) {
				col = 1;
				ex->setCellValue(row, col++, std::to_string(row-1));
				ex->setCellValue(row, col++, item->floorNum);
				ex->setCellValue(row, col++, item->unitNum);
				ex->setCellValue(row, col++, item->roomNum);
				ex->setCellValue(row, col++, item->ownerName);
				ex->setCellValue(row, col, item->link);
				ex->setRowProperties(row++);
			}
		});

	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "rp-unpaid-house-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
}

FloorJsonVO::Wrapper UnpaidHouseController::execQueryFloor(const FloorQuery::Wrapper& query)
{
	// 定义一个Service
	FloorService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FloorJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

UnitJsonVO::Wrapper UnpaidHouseController::execQueryUnit(const UnitQuery::Wrapper& query)
{
	// 定义一个Service
	UnitService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = UnitJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

RoomJsonVO::Wrapper UnpaidHouseController::execQueryRoom(const RoomQuery::Wrapper& query)
{
	// 定义一个Service
	RoomService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RoomJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
