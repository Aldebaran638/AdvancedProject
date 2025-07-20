/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/17 20:01:50

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
#include "FeeItemController.h"
#include "../../../service/FeeItem/FeeItemService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include OATPP_CODEGEN_BEGIN(ApiController) 
FeeItemPageJsonVO::Wrapper FeeItemController::execQueryAll(const FeeItemQuery::Wrapper& query)
{
	// 定义一个Service
    FeeItemService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FeeItemPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper FeeItemController::execAdditemlog(const FeeItemAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
    	auto jvo = StringJsonVO::createShared();
    
    	// 非空校验（你可以视需要再扩展）
        //别忘了拓展
    	if (!dto->fee_type_cd || dto->fee_type_cd->empty() ||
    		!dto->fee_name || dto->fee_name->empty() ||
    		!dto->payment_cd || dto->payment_cd->empty() ||
    		!dto->start_time || dto->start_time->empty() ||
    		!dto->end_time || dto->end_time->empty())
    	{
    		jvo->init(nullptr, RS_PARAMS_INVALID);
    		return jvo;
    	}
    
    	// 执行新增
    	FeeItemService service;
    	dto->setPayload(&payload);
    	std::string id = service.saveData(dto);
    
    	if (!id.empty()) {
    		jvo->success(id);
    	}
    	else {
    		jvo->fail("");
    	}
    
    	return jvo;
}
StringJsonVO::Wrapper FeeItemController::execModifyitemlog(const FeeItemModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
    OATPP_LOGD("ModifyItem", "Got modify request");
    	auto jvo = StringJsonVO::createShared();
    
    	if (!dto->config_id || dto->config_id->empty()) {
    		jvo->init(nullptr, RS_PARAMS_INVALID);
    		return jvo;
    	}
    
    	FeeItemService service;
    	dto->setPayload(&payload);
        //dto->user_id = payload.id;

    	if (service.updateData(dto)) {
    		jvo->success(dto->config_id);
    	}
    	else {
    		jvo->fail(dto->config_id);
    	}
    
    	return jvo;
}
StringJsonVO::Wrapper FeeItemController::execRemoveitemlog(const FeeItemDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
    auto jvo = StringJsonVO::createShared();

    if (!dto->config_id || dto->config_id->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    FeeItemService service;
    // 传递权限信息（如果需要）
    // dto->setPayload(&payload);  // 如果FeeItemDeleteDTO无此方法，去掉

    if (service.removeData(dto)) {
        jvo->success(dto->config_id);
    }
    else {
        jvo->fail(dto->config_id);
    }

    return jvo;
}




//FeeItemPageJsonVO::Wrapper FeeItemController::execQueryAll(const FeeItemQuery::Wrapper& query)
//{
//	// 创建服务
//	FeeItemService service;
//
//	// 调用 service 获取分页结果
//	auto pageResult = service.listAll(query);
//
//	// 包装为标准 Json 返回结构
//	auto vo = FeeItemPageJsonVO::createShared();
//	vo->success(pageResult);
//	return vo;
//} 


//StringJsonVO::Wrapper FeeItemController::execAdditemlog(const FeeItemAddDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//
//	// 非空校验（你可以视需要再扩展）
//	if (!dto->fee_type_cd || dto->fee_type_cd->empty() ||
//		!dto->fee_name || dto->fee_name->empty() ||
//		!dto->payment_cd || dto->payment_cd->empty() ||
//		!dto->start_time || dto->start_time->empty() ||
//		!dto->end_time || dto->end_time->empty())
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// 执行新增
//	FeeItemService service;
//	dto->setPayload(&payload);
//	std::string id = service.saveData(dto);
//
//	if (!id.empty()) {
//		jvo->success(id);
//	}
//	else {
//		jvo->fail("");
//	}
//
//	return jvo;
//}
//
//
//StringJsonVO::Wrapper FeeItemController::execModifyitemlog(const FeeItemDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//
//	if (!dto->config_id || dto->config_id->empty()) {
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	FeeItemService service;
//	dto->setPayload(&payload);
//
//	if (service.updateData(dto)) {
//		jvo->success(dto->config_id);
//	}
//	else {
//		jvo->fail(dto->config_id);
//	}
//
//	return jvo;
//}
//
//ListJsonVO<String>::Wrapper FeeItemController::execRemoveitem(const List<String>& ids)
//{
//	// 定义返回数据对象
//	auto jvo = ListJsonVO<String>::createShared();
//	// 参数校验
//	if (ids->empty())
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	FeeItemService service;
//	// 执行数据删除
//	if (service.removeData(ids)) {
//		jvo->success(ids);
//	}
//	else
//	{
//		jvo->fail(nullptr);
//	}
//	// 响应结果
//	return jvo;
//}
//FeeItemPageJsonVO::Wrapper FeeItemController::execQueryAll(const FeeItemQuery::Wrapper& query)
//{
    //// 创建服务对象
    //FeeItemService service;

    //// 查询分页数据（内部根据 config_id 判断是否进行过滤）
    //auto pageResult = service.listAll(query);

    //// 包装为 Json 响应结构
    //auto vo = FeeItemPageJsonVO::createShared();
    //vo->success(pageResult);

    //return vo;
   // return{};
//}


#include OATPP_CODEGEN_END(ApiController) 
