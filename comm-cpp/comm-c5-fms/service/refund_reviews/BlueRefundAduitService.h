#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/25 15:45:56

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
#ifndef _BLUEREFUNDADUITSERVICE_
#define _BLUEREFUNDADUITSERVICE_
#include "domain/vo/refund_reviews/BlueRefundAduitVO.h"
#include "domain/query/refund_reviews/BlueRefundAduitQuery.h"
#include "domain/dto/refund_reviews/BlueRefundAduitDTO.h"

//获取退费审核列表
class ReviewPageService
{
public:
	// 分页查询所有数据
	ReviewPageDTO::Wrapper listAll(const FeeReviewQuery::Wrapper& query);
	// 通过ID查询单个数据
	FeeDetailDTO::Wrapper getById(std::string id);
};

//获取缴费列表
class FeeHistoryService
{
public:
	// 分页查询所有数据
	FeeHistoryDTO::Wrapper listAll(const FeeHistoryQuery::Wrapper& query);
};

#endif 


