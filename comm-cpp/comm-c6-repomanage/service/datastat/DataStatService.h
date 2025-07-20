/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2024/5/24 

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

#ifndef DATASTATSERVICE_H
#define DATASTATSERVICE_H

#include <domain/dto/datastat/DataStatDTO.h>
#include <domain/query/datastat/DataStatQuery.h>
#include <domain/vo/datastat/DataStatVO.h>

/*
 * 数据统计，工单统计，出入统计，其他统计的服务类
 */
class DataStatService {
public:
	// 数据统计类查询
	ExpenseStatPageDTO::Wrapper getExpenseData(const ExpenseStatQuery::Wrapper& query);

	// 工单统计类查询
	WorkOrderStatPageDTO::Wrapper getWorkOrderData(const WorkOrderStatQuery::Wrapper& query);

	// 出入统计类查询
	AccessStatPageDTO::Wrapper getAccessData(const AccessStatQuery::Wrapper& query);

	// 其他服务类的查询
	OtherStatPageDTO::Wrapper getOtherData(const OtherStatQuery::Wrapper& query);


	/*   2222222222222222222222 */
	//收款方式查询
	DataStatMethodDTO::Wrapper listAllMethod(const oatpp::Object<DataStatALLSearchQuery>& query);
	//实收费用查询 - 返回列表
	oatpp::List<DataStatFinalCostDTO::Wrapper> listAllShishou(const oatpp::Object<DataStatALLSearchQuery>& query);
	//实收费用查询 - 返回分页数据
	DataStatShishouPageDTO::Wrapper listShishouWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);
	////是否欠费查询
	//DataStatQianfeiDTO::Wrapper listALLQianfei(const oatpp::Object<DataStatALLSearchQuery>& query);
	//详细查询
	DataStatShishouDetailPageDTO::Wrapper listShishouDetailWithPage(const DataStatDetailSearchQuery::Wrapper& query);
	//欠费统计分页查询
	DataStatQianfeiPageDTO::Wrapper listQianfeiWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);
};

/*              数据统计-3            */
/**
 * 欠费明细服务实现
 */
class DatastatFeeDetailService
{
public:
	// 分页查询所有数据
	DatastatFeeDetailPageDTO::Wrapper listAll(const DatastatFeeDetailQuery::Wrapper& query);
};

/**
 * 收缴情况服务实现
 */
class DatastatChargeDetailService
{
public:
	// 分页查询所有数据
	DatastatChargeDetailPageDTO::Wrapper listAll(const DatastatChargeDetailQuery::Wrapper& query);
};


/**
 * 月实收明细服务实现
 */
class DatastatMonthDetailService
{
public:
	// 分页查询所有数据
	DatastatMonthDetailPageDTO::Wrapper listAll(const DatastatMonthDetailQuery::Wrapper& query);
};

/**
 * 月欠费明细服务实现
 */
class DatastatMonthFeeService
{
public:
	// 分页查询所有数据
	DatastatMonthFeePageDTO::Wrapper listAll(const DatastatMonthFeeQuery::Wrapper& query);
};

#endif // !DATASTATSERVICE_H
