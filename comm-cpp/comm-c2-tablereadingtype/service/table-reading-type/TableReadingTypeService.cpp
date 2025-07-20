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
#include "TableReadingTypeService.h"
#include "../../dao/table-reading-type/TableReadingTypeDAO.h"
#include "../../../lib-common/include/id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"

//分页查询全部
TableReadingTypePageDTO::Wrapper TableReadingTypeService::listAll(const TableReadingTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TableReadingTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	TableReadingTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TableReadingTypeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TableReadingTypeDO sub : result)
	{
		auto dto = TableReadingTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, type_id, TypeId, type_name, TypeName, remark, Remark, create_time, CreateTime);
		pages->addData(dto);
	}
	return pages;
}
//写入数据
std::string TableReadingTypeService::saveData(const TableReadingTypeAddDTO::Wrapper& dto)
{
	// 组装DO数据
	TableReadingTypeDO data;
	SnowFlake sf(1,1);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TypeName, type_name, Remark, remark, CommunityId, community_id);
	data.setTypeId(std::to_string(sf.nextId()));
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	TableReadingTypeDAO dao;
	return dao.insert(data) == 1 ? data.getTypeId() : "";
}
//更新数据
bool TableReadingTypeService::updateData(const TableReadingTypeUpdateDTO::Wrapper& dto)
{
	// 组装DO数据
	TableReadingTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TypeId, type_id, TypeName, type_name, Remark, remark);
	// 执行数据修改
	TableReadingTypeDAO dao;
	return dao.update(data) == 1;
}

bool TableReadingTypeService::removeData(const TableReadingTypeRemoveDTO::Wrapper& dto)
{
	// 组装DO数据
	TableReadingTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TypeId, type_id);
	// 执行数据修改
	TableReadingTypeDAO dao;
	return dao.remove(data) == 1;
}
