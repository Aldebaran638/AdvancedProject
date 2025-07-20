#include "RefundReview.h"
#include "stdafx.h"
#include "../../service/refund_reviews/BuRefundService.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include <iostream>
//导出退费审核报表
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RefundReviewController::downloadRefundReview(const String& filename)
{
	//1.定义一个Service,查询数据 此时得到的数据时DTO 从数据库读取到的数据
	BuRefundService service;
	//2得到查询到的dto数据
	auto dtoList = service.getDtoData();

	// 3.检查 dto 是否为空  判空处理这一步很重要，否者报权限错误*****
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}

	// 4 将 DTO数据转换为二维数组
	std::vector<std::vector<std::string>> data;
	//5.添加表头
	std::vector<std::string> header = {
	ZH_WORDS_GETTER("refund.return_fee_id"),
	ZH_WORDS_GETTER("refund.b_id"),
	ZH_WORDS_GETTER("refund.fee_type_cd"),
	ZH_WORDS_GETTER("refund.fee_id"),
	ZH_WORDS_GETTER("refund.cycles"),
	ZH_WORDS_GETTER("refund.received_amount"),
	ZH_WORDS_GETTER("refund.create_time"),
	ZH_WORDS_GETTER("refund.reason"),
    ZH_WORDS_GETTER("refund.apply_person_name"),
	ZH_WORDS_GETTER("refund.state"),
	ZH_WORDS_GETTER("refund.audit_person_name"),
	ZH_WORDS_GETTER("refund.status_cd")
	};

	data.push_back(header); // 添加表头
	//7.将DTO对象填充到二维数组中
	for (const auto& dto : dtoList) {
		std::vector<std::string> row;
		row.push_back(dto->return_fee_id);
		row.push_back(dto->b_id);
		row.push_back(dto->fee_type_cd);
		row.push_back(dto->fee_id);
		row.push_back(dto->cycles);
		row.push_back(std::to_string(dto->received_amount));
		row.push_back(dto->create_time);
		row.push_back(dto->reason);
		row.push_back(dto->apply_person_name);
		row.push_back(dto->state);
		row.push_back(dto->audit_person_name);
		row.push_back(dto->status_cd);
		data.push_back(row); // 将每一行数据添加到二维数组中
	}
	///3. 使用 ExcelComponent 将数据写入 Excel 文件
	ExcelComponent excle;
	auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("refund.download.summary2"), data); // 生成 Excel 文件
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