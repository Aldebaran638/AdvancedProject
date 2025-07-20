/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 15:25:42

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
#include "BlueRefundAudit.h"
#include "stdafx.h"
#include "../../service/refund_reviews/BlueRefundAduitService.h"

//获取退费审核列表
ReviewPageJsonVO::Wrapper BlueRefundAduitController::execQueryFeeReview(const FeeReviewQuery::Wrapper& query)
{
	// 定义一个Service
	ReviewPageService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ReviewPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//获取退费审核详情
FeeDetailJsonVO::Wrapper BlueRefundAduitController::execQueryFeeDetail(const String& id)
{
	// 定义返回数据对象
	auto jvo = FeeDetailJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ReviewPageService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;
}
//获取缴费历史列表
FeeHistoryJsonVO::Wrapper BlueRefundAduitController::execQueryFeeHistory(const FeeHistoryQuery::Wrapper& query)
{
	// 定义一个Service
	FeeHistoryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FeeHistoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
