#include"stdafx.h"
#include "ExRmremindersController.h"
#include "../../service/arrears_reminders/ExRmremindersService.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include <iostream>
// 删除欠费催缴
ListJsonVO<String>::Wrapper RmremindersController::execRemoveSample(const List<String>& ids)
{
	// 定义返回数据对象
	auto jvo = ListJsonVO<String>::createShared();
	// 参数校验
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ExRmremindersService service;
	// 执行数据删除
	if (service.removeData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// 响应结果
	return jvo;
}

// 导出欠费催缴
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>RmremindersController::downloadPayRemind(const String& filename)
{
	//1.定义一个Service,查询数据 此时得到的数据时DTO 从数据库读取到的数据
	ExRmremindersService service;
	//2得到查询到的dto数据
	auto dtoList = service.getData();

	// 3.检查 dto 是否为空  判空处理这一步很重要，否者报权限错误*****
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}

	// 4 将 DTO数据转换为二维数组
	std::vector<std::vector<std::string>> data;
	//5.添加表头
	std::vector<std::string> header = {
	ZH_WORDS_GETTER("axing.ofc_id"),
	ZH_WORDS_GETTER("axing.owner_name"),
	ZH_WORDS_GETTER("axing.payer_obj_name"),
	ZH_WORDS_GETTER("axing.fee_name"),
	ZH_WORDS_GETTER("axing.amountd_owed"),
	ZH_WORDS_GETTER("axing.callable_way"),
	ZH_WORDS_GETTER("axing.start_time"),
	ZH_WORDS_GETTER("axing.staff_name"),
	ZH_WORDS_GETTER("axing.state"),
	ZH_WORDS_GETTER("axing.create_time"),
	ZH_WORDS_GETTER("axing.remark")};

	data.push_back(header); // 添加表头
	//7.将DTO对象填充到二维数组中
	for (const auto& dto : dtoList) {
		std::vector<std::string> row;
		row.push_back(dto->ofc_id);
		row.push_back(dto->owner_name);
		row.push_back(dto->payer_obj_name);
		row.push_back(dto->fee_name);
		row.push_back(dto->amountd_owed);
		row.push_back(dto->callable_way);
		row.push_back(dto->start_time);
		row.push_back(dto->staff_name);
		row.push_back(dto->state);
		row.push_back(dto->create_time);
		row.push_back(dto->remark);
	
		data.push_back(row); // 将每一行数据添加到二维数组中
	}
	///3. 使用 ExcelComponent 将数据写入 Excel 文件
	ExcelComponent excle;
	auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("axing.download.summary"), data); // 生成 Excel 文件
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
