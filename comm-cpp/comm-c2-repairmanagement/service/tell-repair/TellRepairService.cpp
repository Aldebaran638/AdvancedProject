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
#include "TellRepairService.h"
#include "../../dao/tell-repair/TellRepairDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"
TellRepairPageDTO::Wrapper TellRepairService::listAll(const TellRepairQuery::Wrapper &query)
{
	// 构建返回对象
	auto pages = TellRepairPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	TellRepairDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TellRepairDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TellRepairDO sub : result)
	{
		auto dto = TellRepairDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			repair_id, RepairId,
			repair_obj_name, RepairObjName,
			repair_name, RepairName,
			tel, Tel,
			repair_type, RepairType,
			repair_type_txt, RepairTypeTxt, 
			appointment_time, AppointmentTime,
			create_time, CreateTime,
			state, State,
			state_txt, StateTxt);

		//组装超时时间
		{
			std::tm tm = {};
			std::istringstream ss(dto->appointment_time ? dto->appointment_time->c_str() : "");
			ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
			if (!ss.fail())
			{
				std::time_t t = std::mktime(&tm);
				t += 24 * 60 * 60;
				std::tm* timeout_tm = std::localtime(&t);
				char buf[20];
				std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeout_tm);
				dto->timeout_time = buf;
			}
			else
			{
				dto->timeout_time = "";
			}
		}
		pages->addData(dto);
	}
	return pages;
}

std::string TellRepairService::saveData(const TellRepairAddDTO::Wrapper &dto)
{
	// 组装DO数据
	TellRepairDO data;
	data.setCommunityId(dto->community_id.getValue(""));
	data.setRepairObjType(dto->repair_obj_type.getValue(""));
	data.setRepairObjName(dto->repair_obj_name.getValue(""));
	data.setRepairType(dto->repair_type.getValue(""));
	data.setRepairName(dto->repair_name.getValue(""));
	data.setTel(dto->tel.getValue(""));
	data.setAppointmentTime(dto->appointment_time.getValue(""));
	data.setContext(dto->context.getValue(""));
	// 雪花算法生成ID
	SnowFlake sf(1, 1);
	data.setRepairId(std::to_string(sf.nextId()));
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 设置默认状态
	data.setState("1100");
	// 执行数据添加
	TellRepairDAO dao;
	return dao.insert(data) == 1 ? data.getRepairId() : "";
}

bool TellRepairService::updateData(const TellRepairUpdateDTO::Wrapper &dto)
{
	// 组装DO数据，只映射需要更新的字段
	TellRepairDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
							RepairType, repair_type,
							RepairName, repair_name,
							Tel, tel,
							AppointmentTime, appointment_time,
							Context, context,
							RepairId, repair_id);
	// 执行数据修改
	TellRepairDAO dao;
	return dao.update(data) == 1;
}

bool TellRepairService::removeData(const oatpp::List<oatpp::String> &ids)
{
	TellRepairDAO dao;
	// 开启事务
	dao.getSqlSession()->beginTransaction();
	// 循环删除
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one);
	}
	// 判断是否全部删除成功
	if (rows == ids->size())
	{
		// 提交事务
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// 回滚事务
	dao.getSqlSession()->rollbackTransaction();
	return false;
}
