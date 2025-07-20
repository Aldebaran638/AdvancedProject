/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "PrintInfoService.h"
#include "../../dao/PrintInfo/PrintInfoDAO.h"
//#include "id/UuidFacade.h"
//#include "SimpleDateTimeFormat.h"

PrintInfoPageDTO::Wrapper PrintInfoService::listAll(const PrintInfoQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = PrintInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PrintInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AccountReceiptDO>result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (AccountReceiptDO sub : result) {
		auto dto = PrintInfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ar_id, Ar_id, create_time, Create_time, acct_name, Acct_name, acct_type, Acct_type);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owner_name, Owner_name, receivable_amount, Receivable_amount, prime_rate, Prime_rate);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, received_amount, Received_amount, remark, Remark, amount, Amount, page_name, Page_name, name, Name);
		pages->addData(dto);
	}
	return pages;
}