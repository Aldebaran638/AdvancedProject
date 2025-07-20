/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/05/18 12:10:24

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
#include "PaymentAuditController.h"
#include "../../service/payment_reviews/PaymentAuditService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

PaymentAuditListJsonVO::Wrapper PaymentAuditController::execQueryPaymentAuditList(const PaymentAuditListQuery::Wrapper& query)
{
	PaymentAuditService service;
	// 查询数据
	auto result = service.getList(query);
	// 响应结果
	auto jvo = PaymentAuditListJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

PaymentAuditDetailJsonVO::Wrapper PaymentAuditController::execQueryPaymentAuditDetail(const String& id)
{
	// 定义返回数据对象
	auto jvo = PaymentAuditDetailJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	PaymentAuditService service;
	// 执行数据新增
	auto res = service.getDetail(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;
}

PaymentAuditHistoryJsonVO::Wrapper PaymentAuditController::execQueryPaymentAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query)
{
	PaymentAuditService service;
	// 查询数据
	auto result = service.getHistory(query);
	// 响应结果
	auto jvo = PaymentAuditHistoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


