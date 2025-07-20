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
#include "FeeMgrService.h"
#include "../../dao/FeeMgr/FeeMgrDAO.h"
#include "id/UuidFacade.h"
#include "../../domain/do/FeeMgrDO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "SimpleDateTimeFormat.h"
#include "algorithm"



FeeMgrDTO::Wrapper FeeMgrService::getById(std::string id)
{
	// 查询数据
	FeeMgrDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = FeeMgrDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, discount_id, Discount_id, discount_name, Discount_name, discount_type, Discount_type);
	return dto;
}

std::string FeeMgrService::saveData(const FeeMgrAddDTO::Wrapper& dto)
{
	// 组装DO数据
	FeeMgrDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Discount_name, discount_name, Discount_type, discount_type);
	// 生成ID
	UuidFacade uf;
	//auto raw = uf.genUuid();
	//raw.erase(std::remove(raw.begin(), raw.end(), '-'), raw.end()); // 去掉UUID中的'-'字符
	data.setDiscount_id(uf.genUuid());
	// 设置创建人
	// data.setName(dto->getPayload()->getUsername());
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format()); // 用写好的SimpleDateTimeFormat接口即可
	// 执行数据添加
	FeeMgrDAO dao;
	return dao.insert(data) == 1 ? data.getDiscount_id() : "";
}


bool FeeMgrService::removeData(const oatpp::List<oatpp::String>& ids)
{
	FeeMgrDAO dao;
	// 开启事务
	dao.getSqlSession()->beginTransaction();
	// 循环删除
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// 判断是否全部删除成功
	if (rows == ids->size()) {
		// 提交事务
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// 回滚事务
	dao.getSqlSession()->rollbackTransaction();
	return false;
}
