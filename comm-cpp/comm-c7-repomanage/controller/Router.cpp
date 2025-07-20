#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"

#include "report_management/unpaid_house/UnpaidHouseController.h"
#include "report_management/owner_payment_mgr/payment_detail/OwnerPayController.h"
#include "report_management/owner_payment_mgr/payment_export/OwnerPayExpController.h"
#include "report_management/analysis_arrears/AnalysisArrearsController.h"
#include"report_management/inspection_report/InspectionPointStatisticController.h"

#include"report_management/inspection_report/TodayInspectionTableController.h"
#include "report_management/deposit_report/DepositReportController.h"
#include "report_management/repair_report_summary/RepairReportSummaryController.h"

#include "report_management/repair_report/UnrepairController.h"
#include "report_management/repair_report/ClassificationTableController.h"
#include "report_management/repair_report/RepairReportFeeController.h"
#include "report_management/repair_report/RepairStatisticsController.h"
#include "report_management/repair_report/DissatisfiedRepairController.h"
#include "report_management/repair_report/RepairDetailsController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif


// 如果定义了关闭Swagger文档宏
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(RepairReportSummaryController);
	ROUTER_SIMPLE_BIND(InspectionReporStatisticsController);
	ROUTER_SIMPLE_BIND(TodayInspectionTableController);
	ROUTER_SIMPLE_BIND(ClassificationTableController);
	ROUTER_SIMPLE_BIND(RepairReportFeeController);
	ROUTER_SIMPLE_BIND(AnalysisArrearsController);
	ROUTER_SIMPLE_BIND(OwnerPaymentController);
	ROUTER_SIMPLE_BIND(OwnerPaymentExpController);
	ROUTER_SIMPLE_BIND(UnrepairController);
	ROUTER_SIMPLE_BIND(DissatisfiedRepairController);
	ROUTER_SIMPLE_BIND(DepositReportController);
	ROUTER_SIMPLE_BIND(RepairStatisticsController);
	ROUTER_SIMPLE_BIND(UnpaidHouseController);
	ROUTER_SIMPLE_BIND(RepairDetailsController);
}

