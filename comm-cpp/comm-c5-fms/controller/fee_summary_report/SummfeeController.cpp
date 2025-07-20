#include"stdafx.h"
#include"SummfeeController.h"
#include "../../service/fee_summary_report/SummfeeService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

FeeSummaryPageJsonVO::Wrapper SummfeeController::execQueryAll(const SummfeeQuery::Wrapper& query)
{
	// 定义一个Service
	SummfeeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FeeSummaryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
