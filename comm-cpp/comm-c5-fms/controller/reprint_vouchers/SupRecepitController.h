#pragma once
#ifndef _SUP_RECEPIT_CONTROLLER_
#define _SUP_RECEPIT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/reprint_vouchers/SupRecepitQuery.h"
#include "domain/dto/reprint_vouchers/SupRecepitDTO.h"
#include "domain/vo/reprint_vouchers/SupRecepitVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

class SupRecepitController : public oatpp::web::server::api::ApiController {

	API_ACCESS_DECLARE(SupRecepitController);
	//查询补打收据信息
	ENDPOINT_INFO(querySupRecepit) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplementrecepit.filed.select"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SupRecepitPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "recepitId", ZH_WORDS_GETTER("supplementrecepit.filed.recepitid"), "832025051582830021", false);
		API_DEF_ADD_QUERY_PARAMS(String, "message", ZH_WORDS_GETTER("supplementrecepit.filed.message"), "001-1-101", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeDetail", ZH_WORDS_GETTER("supplementrecepit.filed.feetype"), ZH_WORDS_GETTER("supplementrecepit.filed.feetypedetail"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "startTime", ZH_WORDS_GETTER("supplementrecepit.filed.starttime"), "2025-06-04", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("supplementrecepit.filed.endtime"), "2025-06-04", false);
	}
	// 定义查询补打收据接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/reprint/get-reprintlist", querySupRecepit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, SupRecepitQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySupRecepit(userQuery));
	}
	//补打收据
	ENDPOINT_INFO(exportSupRecepit) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("supplementrecepit.export.reprint"), Void);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "recepitId", ZH_WORDS_GETTER("supplementrecepit.filed.recepitid"), "832025051582830021", true);
	}
	// 定义补打收据处理
	ENDPOINT(API_M_GET, "/c5-feemanage/reprint/get-recv", exportSupRecepit, QUERY(String, recepitId), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		return execExportSupRecepit(recepitId);
	}
	//补打小票
	ENDPOINT_INFO(exportSupRecepit2) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("supplementrecepit.export.reprint2"), Void);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "recepitId", ZH_WORDS_GETTER("supplementrecepit.filed.recepitid"), "832025051582830021", true);
	}
	// 定义补打小票处理
	ENDPOINT(API_M_GET, "/c5-feemanage/reprint/get-reprint", exportSupRecepit2, QUERY(String, recepitId), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		return execExportSupRecepit2(recepitId);
	}

private:
	SupRecepitPageJsonVO::Wrapper execQuerySupRecepit(const SupRecepitQuery::Wrapper& query);
	std::shared_ptr<OutgoingResponse> execExportSupRecepit(const String& id);
	std::shared_ptr<OutgoingResponse> execExportSupRecepit2(const String& id);

	std::string BigChineseChange(int flag, std::string s);
	std::string splitNum(std::string s);
	std::string replaceAll(std::string src, std::string regex, std::string replacement);
	std::string cleanZero(std::string s);
};

#include OATPP_CODEGEN_END(ApiController) 
#endif 