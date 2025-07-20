/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "TellRepairController.h"
#include "../../service/tell-repair/TellRepairService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

TellRepairPageJsonVO::Wrapper TellRepairController::execQuery(const TellRepairQuery::Wrapper &query)
{
	// 定义一个Service
	TellRepairService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = TellRepairPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper TellRepairController::execAdd(const TellRepairAddDTO::Wrapper &dto, const PayloadDTO &payload)
{
	auto jvo = StringJsonVO::createShared();
	// 非空校验
	if (!dto->community_id || !dto->repair_obj_type || !dto->repair_obj_name ||
			!dto->repair_type || !dto->repair_name || !dto->tel ||
			!dto->appointment_time || !dto->context)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效性校验
	if (dto->community_id->empty() || dto->repair_obj_type->empty() || dto->repair_obj_name->empty() ||
			dto->repair_type->empty() || dto->repair_name->empty() || dto->tel->empty() ||
			dto->appointment_time->empty() || dto->context->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 组装payload
	dto->setPayload(&payload);

	// 调用Service
	TellRepairService service;
	std::string id = service.saveData(dto);
	if (!id.empty())
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	return jvo;
}

StringJsonVO::Wrapper TellRepairController::execModify(const TellRepairUpdateDTO::Wrapper &dto, const PayloadDTO &payload)
{
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->repair_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 组装payload（如有需要）
	dto->setPayload(&payload);
	// 定义一个Service
	TellRepairService service;
	// 执行数据修改
	if (service.updateData(dto))
	{
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	return jvo;
}

ListJsonVO<String>::Wrapper TellRepairController::execRemove(const List<String> &ids)
{
	auto jvo = ListJsonVO<String>::createShared();
	// 参数校验
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TellRepairService service;
	// 执行数据删除
	if (service.removeData(ids))
	{
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	return jvo;
}