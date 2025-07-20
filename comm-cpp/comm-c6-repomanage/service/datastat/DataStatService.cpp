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

#include <stdafx.h>
#include <dao/datastat/DataStatDAO.h>

#include "DataStatService.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"


ExpenseStatPageDTO::Wrapper DataStatService::getExpenseData(const ExpenseStatQuery::Wrapper& query) {
	auto pages = ExpenseStatPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 调用DAO获取汇总数据
	DataStatDao dao;
	auto expense = dao.queryExpense(query);

	if (expense) {
		pages->total = 1;
		pages->calcPages();
		pages->addData(expense);
	} else {
		pages->total = -1;
	}

	return pages;
}


WorkOrderStatPageDTO::Wrapper DataStatService::getWorkOrderData(const WorkOrderStatQuery::Wrapper& query) {
	auto pages = WorkOrderStatPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 调用DAO获取汇总数据
	DataStatDao dao;
	auto expense = dao.queryWorkOrder(query);

	if (expense) {
		pages->total = 1;
		pages->calcPages();
		pages->addData(expense);
	}
	else {
		pages->total = -1;
	}

	return pages;
}


AccessStatPageDTO::Wrapper DataStatService::getAccessData(const AccessStatQuery::Wrapper& query) {
	auto pages = AccessStatPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 调用DAO获取汇总数据
	DataStatDao dao;
	auto expense = dao.queryAccess(query);

	if (expense) {
		pages->total = 1;
		pages->calcPages();
		pages->addData(expense);
	}
	else {
		pages->total = -1;
	}

	return pages;
}


OtherStatPageDTO::Wrapper DataStatService::getOtherData(const OtherStatQuery::Wrapper& query) {
	auto pages = OtherStatPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 调用DAO获取汇总数据
	DataStatDao dao;
	auto expense = dao.queryOther(query);

	if (expense) {
		pages->total = 1;
		pages->calcPages();
		pages->addData(expense);
	}
	else {
		pages->total = -1;
	}

	return pages;
}


/* 2222222222222222222222222222222222                 */
DataStatMethodDTO::Wrapper DataStatService::listAllMethod(const oatpp::Object<DataStatALLSearchQuery>& query) {
	DataStatDao dao;
	auto res = dao.queryMethod(query);
	if (!res)return nullptr;
	return res;
}

oatpp::List<DataStatFinalCostDTO::Wrapper> DataStatService::listAllShishou(const oatpp::Object<DataStatALLSearchQuery>& query) {
	// 创建DAO对象
	DataStatDao dao;

	// 查询DO列表
	auto doList = dao.queryShishou(query);

	// 创建DTO列表
	auto dtoList = oatpp::List<DataStatFinalCostDTO::Wrapper>::createShared();

	// 将DO转换为DTO
	for (const auto& doItem : doList) {
		auto dto = DataStatFinalCostDTO::createShared();
		dto->house = doItem.getHouse();
		dto->hostnum = doItem.getHostnum();
		dto->costnum = doItem.getCostnum();
		dto->wuye = doItem.getWuye();
		dto->yajin = doItem.getYajin();
		dto->tingche = doItem.getTingche();
		dto->meiqi = doItem.getMeiqi();
		dto->qunuan = doItem.getQunuan();
		dto->weixiu = doItem.getWeixiu();
		dto->qita = doItem.getQita();
		dto->fuwu = doItem.getFuwu();
		dto->shuifei = doItem.getShuifei();
		dto->dianfei = doItem.getDianfei();
		dto->zujin = doItem.getZujin();
		dto->gongtan = doItem.getGongtan();
		dto->final = doItem.getFinal();
		dto->allfinal = doItem.getAllfinal();
		dtoList->push_back(dto);
	}

	return dtoList;
}

//DataStatQianfeiDTO::Wrapper DataStatService::listALLQianfei(const oatpp::Object<DataStatALLSearchQuery>& query)
//{
//	// 创建DAO对象
//	DataStatDao dao;
//	// 调用DAO层查询欠费统计数据
//	return dao.queryQianfei(query);
//}

DataStatShishouDetailPageDTO::Wrapper DataStatService::listShishouDetailWithPage(const DataStatDetailSearchQuery::Wrapper& query) {
	// 创建DAO对象
	DataStatDao dao;

	// 创建分页DTO
	auto pageDto = DataStatShishouDetailPageDTO::createShared();

	// 查询总数
	uint64_t total = dao.countShiShouDetail(query);
	pageDto->total = total;

	// 设置分页信息
	pageDto->pageIndex = query->pageIndex.getValue(1);
	pageDto->pageSize = query->pageSize.getValue(10);
	cout << "ShiShou Detail Total: " << total << endl;

	// 如果有数据，查询分页数据
	if (total > 0) {
		// 查询DO列表
		auto doList = dao.queryShiShouDetailWithPage(query);

		// 创建DTO列表
		auto dtoList = oatpp::List<DataStatDetailCostDTO::Wrapper>::createShared();

		// 将DO转换为DTO - 完整的字段映射
		for (const auto& doItem : doList) {
			auto dto = DataStatDetailCostDTO::createShared();

			// 基本信息字段
			dto->house = doItem.getHouse();          // 楼栋单元房间信息
			dto->host = doItem.getHost();            // 业主姓名

			// 各费用类型实收金额（继承自DataStatCostDTO的12个字段）
			dto->wuye = doItem.getWuye();           // 物业费
			dto->yajin = doItem.getYajin();         // 押金
			dto->tingche = doItem.getTingche();     // 停车费
			dto->meiqi = doItem.getMeiqi();         // 煤气费
			dto->qunuan = doItem.getQunuan();       // 取暖费
			dto->weixiu = doItem.getWeixiu();       // 维修费
			dto->qita = doItem.getQita();           // 其他费用
			dto->fuwu = doItem.getFuwu();           // 服务费
			dto->shuifei = doItem.getShuifei();     // 水费
			dto->dianfei = doItem.getDianfei();     // 电费
			dto->zujin = doItem.getZujin();         // 租金
			dto->gongtan = doItem.getGongtan();     // 公摊费

			// 实收总额
			dto->final = doItem.getFinal();         // 该房间实收总额

			dtoList->push_back(dto);
		}

		pageDto->rows = dtoList;
	}
	else {
		// 没有数据时返回空列表
		pageDto->rows = oatpp::List<DataStatDetailCostDTO::Wrapper>::createShared();
	}

	return pageDto;
}

DataStatShishouPageDTO::Wrapper DataStatService::listShishouWithPage(const oatpp::Object<DataStatALLSearchQuery>& query) {
	// 创建DAO对象
	DataStatDao dao;

	// 创建分页DTO
	auto pageDto = DataStatShishouPageDTO::createShared();

	// 查询总数
	uint64_t total = dao.countShishou(query);
	pageDto->total = total;

	// 设置分页信息
	pageDto->pageIndex = query->pageIndex.getValue(1);
	pageDto->pageSize = query->pageSize.getValue(10);
	cout << total << endl;
	// 如果有数据，查询分页数据
	if (total > 0) {
		// 查询DO列表
		auto doList = dao.queryShishouWithPage(query);

		// 创建DTO列表
		auto dtoList = oatpp::List<DataStatFinalCostDTO::Wrapper>::createShared();

		// 将DO转换为DTO
		for (const auto& doItem : doList) {
			auto dto = DataStatFinalCostDTO::createShared();
			dto->house = doItem.getHouse();
			dto->hostnum = doItem.getHostnum();
			dto->costnum = doItem.getCostnum();
			dto->wuye = doItem.getWuye();
			dto->yajin = doItem.getYajin();
			dto->tingche = doItem.getTingche();
			dto->meiqi = doItem.getMeiqi();
			dto->qunuan = doItem.getQunuan();
			dto->weixiu = doItem.getWeixiu();
			dto->qita = doItem.getQita();
			dto->fuwu = doItem.getFuwu();
			dto->shuifei = doItem.getShuifei();
			dto->dianfei = doItem.getDianfei();
			dto->zujin = doItem.getZujin();
			dto->gongtan = doItem.getGongtan();
			dto->final = doItem.getFinal();
			dto->allfinal = doItem.getAllfinal();
			dtoList->push_back(dto);
		}

		pageDto->rows = dtoList;
	}
	else {
		// 没有数据时返回空列表
		pageDto->rows = oatpp::List<DataStatFinalCostDTO::Wrapper>::createShared();
	}

	return pageDto;
}

DataStatQianfeiPageDTO::Wrapper DataStatService::listQianfeiWithPage(const oatpp::Object<DataStatALLSearchQuery>& query)
{
	// 创建分页返回对象
	auto pages = DataStatQianfeiPageDTO::createShared();

	// 创建DAO对象
	DataStatDao dao;

	// 查询总数
	uint64_t count = dao.countQianfei(query);

	// 如果没有数据，直接返回空结果
	if (count == 0) {
		pages->total = static_cast<v_int64>(0);
		pages->pageIndex = query->pageIndex.getValue(1);
		pages->pageSize = query->pageSize.getValue(10);
		pages->rows = oatpp::List<DataStatQianfeiDTO::Wrapper>::createShared();
		return pages;
	}

	// 查询分页数据
	auto result = dao.queryQianfeiWithPage(query);

	// 计算总欠费金额（所有楼栋）
	double allQianfei = dao.queryallqianfei(query);

	// 转换DO到DTO
	auto rows = oatpp::List<DataStatQianfeiDTO::Wrapper>::createShared();
	for (auto& item : result) {
		auto dto = DataStatQianfeiDTO::createShared();
		dto->house = item.getHouse();
		dto->wuye = item.getWuye();
		dto->yajin = item.getYajin();
		dto->tingche = item.getTingche();
		dto->meiqi = item.getMeiqi();
		dto->qunuan = item.getQunuan();
		dto->weixiu = item.getWeixiu();
		dto->qita = item.getQita();
		dto->fuwu = item.getFuwu();
		dto->shuifei = item.getShuifei();
		dto->dianfei = item.getDianfei();
		dto->zujin = item.getZujin();
		dto->gongtan = item.getGongtan();
		dto->qianfei = item.getQianfei();
		dto->allqianfei = allQianfei;  // 设置总欠费
		rows->push_back(dto);
	}

	// 设置分页信息
	pages->total = static_cast<v_int64>(count);
	pages->pageIndex = query->pageIndex.getValue(1);
	pages->pageSize = query->pageSize.getValue(10);
	pages->rows = rows;

	return pages;
}

/*              数据统计-3            */
DatastatFeeDetailPageDTO::Wrapper DatastatFeeDetailService::listAll(const DatastatFeeDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DatastatFeeDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	DatastatFeeDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DatastatFeeDetailDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DatastatFeeDetailDO sub : result)
	{
		auto dto = DatastatFeeDetailDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, house, Room_name, ow, Name, qianfei, Qianfei, wuye, Wuye, yajin, Yajin, tingche, Tingche, meiqi, Meiqi);

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

		pages->addData(dto);
	}
	return pages;
}


DatastatChargeDetailPageDTO::Wrapper DatastatChargeDetailService::listAll(const DatastatChargeDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DatastatChargeDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	DatastatChargeDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DatastatChargeDetailDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DatastatChargeDetailDO sub : result)
	{
		auto dto = DatastatChargeDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, building, Building, num_for_house, Num_for_house, num_for_chargeable_house, Num_for_chargeable_house, arrears_history, Arrears_history, all_arrears, All_arrears, num_for_paid_house_today, Num_for_paid_house_today, cost_for_paid_today, Cost_for_paid_today);

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, num_for_notpaid_house_history, Num_for_notpaid_house_history, cost_for_arrears_history, Cost_for_arrears_history, num_for_paid_house_month, Num_for_paid_house_month, num_for_last_house, Num_for_last_house, percentage_for_paid_house, Percentage_for_paid_house, fees_for_received_month, Fees_for_received_month, fees_for_notreceived_month, Fees_for_notreceived_month, charge_rate, Charge_rate);

		pages->addData(dto);
	}
	return pages;
}

DatastatMonthDetailPageDTO::Wrapper DatastatMonthDetailService::listAll(const DatastatMonthDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DatastatMonthDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	DatastatMonthDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DatastatMonthDetailDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DatastatMonthDetailDO sub : result)
	{
		auto dto = DatastatMonthDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, house, House, ow, Ow, final, Final, name_fee, Name_fee, time_income, Time_income, cashier, Cashier, time_pay, Time_pay);



		pages->addData(dto);
	}
	return pages;
}


DatastatMonthFeePageDTO::Wrapper DatastatMonthFeeService::listAll(const DatastatMonthFeeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DatastatMonthFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	DatastatMonthFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DatastatMonthFeeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DatastatMonthFeeDO sub : result)
	{
		auto dto = DatastatMonthFeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, house, House, ow, Ow, arrears_name, Arrears_name, arrears_time, Arrears_time, arrears_num, Arrears_num);



		pages->addData(dto);
	}
	return pages;
}
