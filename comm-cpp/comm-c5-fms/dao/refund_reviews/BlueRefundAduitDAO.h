#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/25 15:12:49

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
#ifndef _BLUEREFUNDADUITDAO_
#define _BLUEREFUNDADUITDAO_
#include "BaseDAO.h"
#include "../../domain/do/refund_reviews/BlueRefundAduitDO.h"
#include "../../domain/query/refund_reviews/BlueRefundAduitQuery.h"

/**
 * 示例表数据库操作实现
 */
class ReviewPageDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const FeeReviewQuery::Wrapper& query, SqlParams& params);
public:
	// 获取退费审核列表
	std::list<ReviewPageDO> selectReviewPage(const FeeReviewQuery::Wrapper& query);
	uint64_t count(const FeeReviewQuery::Wrapper& query);
	// 通过ID查询数据
	FeeDetailDO selectById(std::string id);
};


class FeeHistoryDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const FeeHistoryQuery::Wrapper& query, SqlParams& params);
public:
	// 获取退费审核列表
	std::list<FeeHistoryDO> selectFeeHistory(const FeeHistoryQuery::Wrapper& query);
	uint64_t count(const FeeHistoryQuery::Wrapper& query);
};

#endif 
