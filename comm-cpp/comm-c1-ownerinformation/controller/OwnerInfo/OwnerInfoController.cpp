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
#include "OwnerInfoController.h"
#include "../../service/OwnerInfo/OwnerInfoService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

// 入住房屋的实现
StringJsonVO::Wrapper OwnerInfoController::execAddIntoHouse(const OwnerInfoAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->room_num || !dto->layer || !dto->room_id || !dto->built_up_area || !dto->apartment || !dto->section)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->room_num->empty() || dto->layer->empty() || dto->room_id->empty() || dto->built_up_area < 0 || dto->apartment->empty() || dto->section < 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	OwnerInfoService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	// 响应结果
	return jvo;
}

// 解除绑定房屋的实现
//StringJsonVO::Wrapper OwnerInfoController::execModifyOutHouse(const OwnerInfoDTO::Wrapper& dto, const PayloadDTO& payload) 
//{
//	// 定义返回数据对象
//	auto jvo = StringJsonVO::createShared();
//	// 参数校验
//	if (!dto->rel_id)
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	OwnerInfoService service;
//	// 执行数据修改
//	dto->setPayload(&payload);
//	if (service.updateData(dto)) 
//	{
//		jvo->success(dto->rel_id);
//	}
//	else
//	{
//		jvo->fail(dto->rel_id);
//	}
//	//响应结果
//	return jvo;
//}


// 解除绑定房屋的实现
ListJsonVO<String>::Wrapper OwnerInfoController::execRemoveOutHouse(const List<String>& ids)
{
	// 定义返回数据对象
	auto jvo = ListJsonVO<String>::createShared();
	// 参数校验
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	OwnerInfoService service;
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
