#include "stdafx.h"
#include "ExpedetController.h"
#include "../../service/expedet/ExpeDetService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"



//房屋查询
BuildingExpedetPageJsonVO::Wrapper ExpedetController::executeQueryBuildingFeeDetaile(const oatpp::Object<ExpedetBuildingFeeDetailQuery>& query)
{
	// 定义一个Service
	ExpedetBuildingFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = BuildingExpedetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return BuildingExpedetJsonVO::Wrapper();
}
//房屋导出
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpedetController::execExportBuildingFeeDetaile(const ExpedetBuildingFeeDetailQuery::Wrapper& query)
{
	//定义一个service
	ExpedetBuildingFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	//将数据写入到excel中
	auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("expedet.get.buildingSummery"),
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("expedet.field.module1.house") ,
				ZH_WORDS_GETTER("expedet.field.module1.ow") ,
				ZH_WORDS_GETTER("expedet.field.module1.qianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.shishou") ,
				ZH_WORDS_GETTER("expedet.field.module1.wuye") ,
				ZH_WORDS_GETTER("expedet.field.module1.yajin") ,
				ZH_WORDS_GETTER("expedet.field.module1.tingche") ,
				ZH_WORDS_GETTER("expedet.field.module1.meiqi") ,
				ZH_WORDS_GETTER("expedet.field.module1.qunuan") ,
				ZH_WORDS_GETTER("expedet.field.module1.weixiu") ,
				ZH_WORDS_GETTER("expedet.field.module1.fuwu") ,
				ZH_WORDS_GETTER("expedet.field.module1.qita") ,
				ZH_WORDS_GETTER("expedet.field.module1.shuifei") ,
				ZH_WORDS_GETTER("expedet.field.module1.dianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.zujin") ,
				ZH_WORDS_GETTER("expedet.field.module1.gongtan")
				});
			// 写入数据
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->room_name);
				ex->setCellValue(row, col++, item->name);
				ex->setCellValue(row, col++, std::to_string(item->qianfei));
				ex->setCellValue(row, col++, std::to_string(item->wuye));
				ex->setCellValue(row, col++, std::to_string(item->yajin));
				ex->setCellValue(row, col++, std::to_string(item->tingche));
				ex->setCellValue(row, col++, std::to_string(item->meiqi));
				ex->setCellValue(row, col++, std::to_string(item->qunuan));
				ex->setCellValue(row, col++, std::to_string(item->weixiu));
				ex->setCellValue(row, col++, std::to_string(item->fuwu));
				ex->setCellValue(row, col++, std::to_string(item->qita));
				ex->setCellValue(row, col++, std::to_string(item->shuifei));
				ex->setCellValue(row, col++, std::to_string(item->dianfei));
				ex->setCellValue(row, col++, std::to_string(item->zujin));
				ex->setCellValue(row, col++, std::to_string(item->gongtan));

				ex->setRowProperties(row++);
			}
		});
	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "building-expedet-fee-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
	//return std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>();
}




//业主查询
OwnerExpedetPageJsonVO::Wrapper ExpedetController::executeQueryOwnerFeeDetaile(const oatpp::Object<ExpedetOwnerFeeDetailQuery>& query)
{
	// 定义一个Service
	ExpedetOwnerFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = OwnerExpedetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return OwnerExpedetJsonVO::Wrapper();
}
//业主导出
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpedetController::execExportOwnerFeeDetaile(const ExpedetOwnerFeeDetailQuery::Wrapper& query)
{
	//定义一个service
	ExpedetOwnerFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	//将数据写入到excel中
	auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("expedet.get.ownerSummery"),
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("expedet.field.module1.ow") ,
				ZH_WORDS_GETTER("expedet.field.module1.house") ,
				ZH_WORDS_GETTER("expedet.field.module1.qianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.shishou") ,
				ZH_WORDS_GETTER("expedet.field.module1.wuye") ,
				ZH_WORDS_GETTER("expedet.field.module1.yajin") ,
				ZH_WORDS_GETTER("expedet.field.module1.tingche") ,
				ZH_WORDS_GETTER("expedet.field.module1.meiqi") ,
				ZH_WORDS_GETTER("expedet.field.module1.qunuan") ,
				ZH_WORDS_GETTER("expedet.field.module1.weixiu") ,
				ZH_WORDS_GETTER("expedet.field.module1.fuwu") ,
				ZH_WORDS_GETTER("expedet.field.module1.qita") ,
				ZH_WORDS_GETTER("expedet.field.module1.shuifei") ,
				ZH_WORDS_GETTER("expedet.field.module1.dianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.zujin") ,
				ZH_WORDS_GETTER("expedet.field.module1.gongtan")
				});
			// 写入数据
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->name);
				ex->setCellValue(row, col++, item->room_name);
				ex->setCellValue(row, col++, std::to_string(item->qianfei));
				ex->setCellValue(row, col++, std::to_string(item->wuye));
				ex->setCellValue(row, col++, std::to_string(item->yajin));
				ex->setCellValue(row, col++, std::to_string(item->tingche));
				ex->setCellValue(row, col++, std::to_string(item->meiqi));
				ex->setCellValue(row, col++, std::to_string(item->qunuan));
				ex->setCellValue(row, col++, std::to_string(item->weixiu));
				ex->setCellValue(row, col++, std::to_string(item->fuwu));
				ex->setCellValue(row, col++, std::to_string(item->qita));
				ex->setCellValue(row, col++, std::to_string(item->shuifei));
				ex->setCellValue(row, col++, std::to_string(item->dianfei));
				ex->setCellValue(row, col++, std::to_string(item->zujin));
				ex->setCellValue(row, col++, std::to_string(item->gongtan));

				ex->setRowProperties(row++);
			}
		});
	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "owner-expedet-fee-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
	//return std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>();
}




//合同查询
ContractExpedetPageJsonVO::Wrapper ExpedetController::executeQueryContractFeeDetaile(const oatpp::Object<ExpedetContractFeeDetailQuery>& query)
{
	// 定义一个Service
	ExpedetContractFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ContractExpedetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ContractExpedetJsonVO::Wrapper();
}
//合同导出
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpedetController::execExportContractFeeDetaile(const ExpedetContractFeeDetailQuery::Wrapper& query)
{
	//定义一个service
	ExpedetContractFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	//将数据写入到excel中
	auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("expedet.get.contractSummery"),
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("expedet.field.module1.hetong") ,
				ZH_WORDS_GETTER("expedet.field.module1.ow") ,
				ZH_WORDS_GETTER("expedet.field.module1.qianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.shishou") ,
				ZH_WORDS_GETTER("expedet.field.module1.wuye") ,
				ZH_WORDS_GETTER("expedet.field.module1.yajin") ,
				ZH_WORDS_GETTER("expedet.field.module1.tingche") ,
				ZH_WORDS_GETTER("expedet.field.module1.meiqi") ,
				ZH_WORDS_GETTER("expedet.field.module1.qunuan") ,
				ZH_WORDS_GETTER("expedet.field.module1.weixiu") ,
				ZH_WORDS_GETTER("expedet.field.module1.fuwu") ,
				ZH_WORDS_GETTER("expedet.field.module1.qita") ,
				ZH_WORDS_GETTER("expedet.field.module1.shuifei") ,
				ZH_WORDS_GETTER("expedet.field.module1.dianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.zujin") ,
				ZH_WORDS_GETTER("expedet.field.module1.gongtan")
				});
			// 写入数据
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->contract_name);
				ex->setCellValue(row, col++, item->name);
				ex->setCellValue(row, col++, std::to_string(item->qianfei));
				ex->setCellValue(row, col++, std::to_string(item->wuye));
				ex->setCellValue(row, col++, std::to_string(item->yajin));
				ex->setCellValue(row, col++, std::to_string(item->tingche));
				ex->setCellValue(row, col++, std::to_string(item->meiqi));
				ex->setCellValue(row, col++, std::to_string(item->qunuan));
				ex->setCellValue(row, col++, std::to_string(item->weixiu));
				ex->setCellValue(row, col++, std::to_string(item->fuwu));
				ex->setCellValue(row, col++, std::to_string(item->qita));
				ex->setCellValue(row, col++, std::to_string(item->shuifei));
				ex->setCellValue(row, col++, std::to_string(item->dianfei));
				ex->setCellValue(row, col++, std::to_string(item->zujin));
				ex->setCellValue(row, col++, std::to_string(item->gongtan));

				ex->setRowProperties(row++);
			}
		});
	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "contract-expedet-fee-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
	//return std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>();
}



//车辆查询
CarExpedetPageJsonVO::Wrapper ExpedetController::executeQueryCarFeeDetaile(const oatpp::Object<ExpedetCarFeeDetailQuery>& query)
{
	// 定义一个Service
	ExpedetCarFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CarExpedetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return CarExpedetJsonVO::Wrapper();
}
//车辆导出
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpedetController::execExportCarFeeDetaile(const ExpedetCarFeeDetailQuery::Wrapper& query)
{
	//定义一个service
	ExpedetCarFeeDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	//将数据写入到excel中
	auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("expedet.get.carSummery"),
		[result](ExcelComponent* ex) {
			// 写入表头
			ex->addHeader({
				ZH_WORDS_GETTER("expedet.field.module1.car") ,
				ZH_WORDS_GETTER("expedet.field.module1.ow") ,
				ZH_WORDS_GETTER("expedet.field.module1.qianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.shishou") ,
				ZH_WORDS_GETTER("expedet.field.module1.wuye") ,
				ZH_WORDS_GETTER("expedet.field.module1.yajin") ,
				ZH_WORDS_GETTER("expedet.field.module1.tingche") ,
				ZH_WORDS_GETTER("expedet.field.module1.meiqi") ,
				ZH_WORDS_GETTER("expedet.field.module1.qunuan") ,
				ZH_WORDS_GETTER("expedet.field.module1.weixiu") ,
				ZH_WORDS_GETTER("expedet.field.module1.fuwu") ,
				ZH_WORDS_GETTER("expedet.field.module1.qita") ,
				ZH_WORDS_GETTER("expedet.field.module1.shuifei") ,
				ZH_WORDS_GETTER("expedet.field.module1.dianfei") ,
				ZH_WORDS_GETTER("expedet.field.module1.zujin") ,
				ZH_WORDS_GETTER("expedet.field.module1.gongtan")
				});
			// 写入数据
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->car_num);
				ex->setCellValue(row, col++, item->name);
				ex->setCellValue(row, col++, std::to_string(item->qianfei));
				ex->setCellValue(row, col++, std::to_string(item->wuye));
				ex->setCellValue(row, col++, std::to_string(item->yajin));
				ex->setCellValue(row, col++, std::to_string(item->tingche));
				ex->setCellValue(row, col++, std::to_string(item->meiqi));
				ex->setCellValue(row, col++, std::to_string(item->qunuan));
				ex->setCellValue(row, col++, std::to_string(item->weixiu));
				ex->setCellValue(row, col++, std::to_string(item->fuwu));
				ex->setCellValue(row, col++, std::to_string(item->qita));
				ex->setCellValue(row, col++, std::to_string(item->shuifei));
				ex->setCellValue(row, col++, std::to_string(item->dianfei));
				ex->setCellValue(row, col++, std::to_string(item->zujin));
				ex->setCellValue(row, col++, std::to_string(item->gongtan));

				ex->setRowProperties(row++);
			}
		});
	// 组装下发数据
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	std::string filename = "car-expedet-fee-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// 影响成功结果
	return response;
	//return std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>();
}

