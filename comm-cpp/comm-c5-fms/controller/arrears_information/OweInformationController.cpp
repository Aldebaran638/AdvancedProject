#include "OweInformationController.h"
#include "stdafx.h"
#include "../../service/arrears_information/OweInformationService.h"
#include "OweInformationController.h"

#include "../../../lib-common/include/ExcelComponent.h"
#include <iostream>

//导出欠费报表
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> OweInformationController::downloadOweInformation(const String& filename)
{
	//1.定义一个Service,查询数据 此时得到的数据时DTO 从数据库读取到的数据
	OweInformationService service;
	//2得到查询到的dto数据
	auto dtoList = service.getTtoData();

	// 3.检查 dto 是否为空  判空处理这一步很重要，否者报权限错误*****
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}

	// 4 将 DTO数据转换为二维数组
	std::vector<std::vector<std::string>> data;
	//5.添加表头
	std::vector<std::string> header = {
	ZH_WORDS_GETTER("owe.download.info1"),
	ZH_WORDS_GETTER("owe.download.info2"),
	ZH_WORDS_GETTER("owe.download.info3"),
	ZH_WORDS_GETTER("owe.download.info4"),
	ZH_WORDS_GETTER("owe.download.info5"),
	ZH_WORDS_GETTER("owe.download.info6"),
	ZH_WORDS_GETTER("owe.download.info7"),
	ZH_WORDS_GETTER("owe.download.info8") };

	data.push_back(header); // 添加表头
	//7.将DTO对象填充到二维数组中
	for (const auto& dto : dtoList) {
		std::vector<std::string> row;
		row.push_back(std::to_string(dto->owe_id));
		row.push_back(dto->payer_obj_name);
		row.push_back(dto->owner_name);
		row.push_back(dto->owner_tel);
		row.push_back(dto->create_time);
		row.push_back(dto->deadline_time);
		row.push_back(std::to_string(dto->bill_amount_owed));
		row.push_back(dto->fee_end_time);
		data.push_back(row); // 将每一行数据添加到二维数组中
	}
	///3. 使用 ExcelComponent 将数据写入 Excel 文件
	ExcelComponent excle;
	auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("owe.download.summary2"), data); // 生成 Excel 文件
	// 4. 返回 Excel 文件给前端
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	//5. 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}
	//6. 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue("") + ".xlsx");

	// 影响成功结果
	return response;
}
CombineOweInformationJsonVO::Wrapper OweInformationController::execOweQuery(const OweInformationQuery::Wrapper& query)
{
	// 定义一个Service
	OweInformationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CombineOweInformationJsonVO::createShared();
	jvo->success(result);
	return jvo;
}