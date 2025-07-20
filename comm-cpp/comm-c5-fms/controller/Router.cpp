/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h" 
#include "../controller/arrears_information/OweInformationController.h"
#include "../controller/arrears_reminders/PayRemainBuController.h"
#include "../controller/refund_reviews/RefundReview.h"
#include "controller/payment_reviews/RefundAndAuditController.h"
#include "controller/fee_summary_report/SummfeeController.h"
#include "controller/arrears_reminders/ExRmremindersController.h"
#include "../controller/discount_types/YyycDisTypesController.h"
#include "../controller/refund_reviews/YyycReviewsController.h"
#include "../controller/arrears_reminders/YArrears_RemindersController.h"
#include "controller/refund_reviews/BlueRefundAudit.h"
#include"./controller/reprint_vouchers/SupRecepitController.h"
#include "payment_reviews/PaymentAuditController.h"
#include "controller/fee_cancellations/CancellationFeeController.h"
#include "controller/discount_types/RainDisTypesController.h"
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
	
	ROUTER_SIMPLE_BIND(OweInformationController);
	ROUTER_SIMPLE_BIND(BlueRefundAduitController);
	ROUTER_SIMPLE_BIND(YyycDisTypesController);
	ROUTER_SIMPLE_BIND(YyycReviewsController);
	ROUTER_SIMPLE_BIND(YArrears_RemindersController);
	ROUTER_SIMPLE_BIND(PayRemainBuController);
	ROUTER_SIMPLE_BIND(RefundReviewController);
	ROUTER_SIMPLE_BIND(SupRecepitController);
	ROUTER_SIMPLE_BIND(CancellationFeeController);
	ROUTER_SIMPLE_BIND(PaymentAuditController);
	ROUTER_SIMPLE_BIND(SummfeeController);
	ROUTER_SIMPLE_BIND(RmremindersController);
	ROUTER_SIMPLE_BIND(RefundAndAuditController);
	ROUTER_SIMPLE_BIND(RainDisTypesController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制器
	ROUTER_SIMPLE_BIND(FileController);
	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif
