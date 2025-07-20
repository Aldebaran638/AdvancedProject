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
#include "TableReadingTypeController.h"
#include "../../service/table-reading-type/TableReadingTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "SimpleDateTimeFormat.h"

TableReadingTypePageJsonVO::Wrapper TableReadingTypeController::execQueryTableReadingType(const TableReadingTypeQuery::Wrapper& query)
{
	// 提前创建 jvo，避免重复实例化
	auto jvo = TableReadingTypePageJsonVO::createShared();

	// 正常逻辑
	TableReadingTypeService service;
	auto result = service.listAll(query);
	jvo->success(result);  // 复用已创建的 jvo

	return jvo;
}

StringJsonVO::Wrapper TableReadingTypeController::execModifyTableReadingType(const TableReadingTypeUpdateDTO::Wrapper& dto)
{
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 参数校验
	if (!dto->type_id || !dto->remark || !dto->type_name) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 有效值校验
	if (dto->type_id->size() > 30 || dto->remark->size() > 200 || dto->type_name->size() > 12)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// 定义一个Service
	TableReadingTypeService service;
	
	if (service.updateData(dto)) {
		jvo->success(dto->type_id);
	}
	else
	{
		jvo->fail(dto->type_id);
	}
	
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper TableReadingTypeController::execAddTableReadingType(const TableReadingTypeAddDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->community_id || !dto->remark || !dto->type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->community_id->size() > 30 || dto->remark->size() > 200 || dto->type_name->size() > 12 )
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	TableReadingTypeService service;

	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//响应结果
	return jvo;

}

StringJsonVO::Wrapper TableReadingTypeController::execRemoveTableReadingType(const TableReadingTypeRemoveDTO::Wrapper& dto)
{
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 参数校验
	if (!dto->type_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	TableReadingTypeService service;
	if (service.removeData(dto)) {
		jvo->success(dto->type_id);
	}
	else
	{
		jvo->fail(dto->type_id);
	}
	// 响应结果
	return jvo;
}
