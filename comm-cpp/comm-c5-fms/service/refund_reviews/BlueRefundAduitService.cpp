/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/25 15:45:11

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
#include "BlueRefundAduitService.h"
#include "../../dao/refund_reviews/BlueRefundAduitDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

ReviewPageDTO::Wrapper ReviewPageService::listAll(const FeeReviewQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ReviewPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ReviewPageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ReviewPageDO> result = dao.selectReviewPage(query);
	// 将DO转换成DTO
	for (ReviewPageDO sub : result)
	{
		auto dto = ReviewDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, return_fee_id, Return_fee_id, detail_id, Detail_id, fee_type_cd, Fee_type_cd, cycles, Cycles, create_time, Create_time, reason, Reason, state, State);
		pages->addData(dto);
	}
	return pages;
}

FeeDetailDTO::Wrapper ReviewPageService::getById(std::string id)
{
	// 查询数据
	ReviewPageDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	//if (!res)
	//	return nullptr;

	// 查询到数据转换成DTO
	auto dto = FeeDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, res, detail_id, Detail_id, fee_label, Fee_label, fee_type, Fee_type, fee_object, Fee_object, fee_item, Fee_item, fee_state, Fee_state);
	return dto;
}

FeeHistoryDTO::Wrapper FeeHistoryService::listAll(const FeeHistoryQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = FeeHistoryDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	FeeHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FeeHistoryDO> result = dao.selectFeeHistory(query);
	// 将DO转换成DTO
	for (FeeHistoryDO sub : result)
	{
		auto dto = HistoryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, detail_id, Detail_id, prime_rate, Prime_rate, create_time, Create_time, pay_time, Pay_time);
		pages->addData(dto);
	}
	return pages;
}

