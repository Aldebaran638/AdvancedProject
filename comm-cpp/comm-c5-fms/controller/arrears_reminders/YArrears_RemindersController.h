#pragma once
#ifndef _YARREARS_REMINDERSCONTROLLER_H_
#define _YARREARS_REMINDERSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/arrears_reminders/YArrears_RemindersQuery.h"
#include "domain/dto/arrears_reminders/YArrears_RemindersDTO.h"
#include "domain/vo/arrears_reminders/YArrears_RemindersVO.h"

//  定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

class YArrears_RemindersController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(YArrears_RemindersController);
public:
	
	// 3.1 定义登记缴费描述
	ENDPOINT_INFO(addReminder) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("payremind.post1.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义登记缴费接口处理
	ENDPOINT(API_M_POST, "/c5-feemanage/payremind/add-registerpay", addReminder, BODY_DTO(YArrears_RemindersAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddReminder(dto, authObject->getPayload()));
	}
private:
	StringJsonVO::Wrapper execAddReminder(const YArrears_RemindersAddDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
