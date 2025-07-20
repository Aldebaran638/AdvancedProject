#pragma once
#ifndef _OWEINFORMATIONCONTROLLER_H_
#define _OWEINFORMATIONCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/query/arrears_information/OweInformationQuery.h"
#include "../../domain/vo/arrears_information/OweInformationVo.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class OweInformationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(OweInformationController);
public:
	// 1.1 定义查询接口描述
	ENDPOINT_INFO(queryOweIn) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("owe.get.summary3"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CombineOweInformationJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("owe.building"), ZH_WORDS_GETTER("owe.lou"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "unit", ZH_WORDS_GETTER("owe.unit"), ZH_WORDS_GETTER("owe.uu"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "home", ZH_WORDS_GETTER("owe.home"), ZH_WORDS_GETTER("owe.rr"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "b_type", ZH_WORDS_GETTER("owe.b_type"), ZH_WORDS_GETTER("owe.type"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "owner_name", ZH_WORDS_GETTER("owe.owner_name"), ZH_WORDS_GETTER("owe.name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_type", ZH_WORDS_GETTER("owe.payer_obj_type"), ZH_WORDS_GETTER("owe.ob"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee", ZH_WORDS_GETTER("owe.fee"), ZH_WORDS_GETTER("owe.fe"), false);
	}
	// 1.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c5-feemanage/owe/get-owe", queryOweIn, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(OweQuery, OweInformationQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execOweQuery(OweQuery));
	}
	//1.1描述导出欠费信息 
	ENDPOINT_INFO(downloadOweIn) {
		//ui的显示
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owe.download.summary1"), Void);
		//参数的描述
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("owe.download.summary2"), "owe_information.xlsx", false);
		//加凭证
		API_DEF_ADD_AUTH();
	}
	//1.2描述端点
	ENDPOINT(API_M_GET, "/c5-feemanage/owe/download-owe", downloadOweIn, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return downloadOweInformation(filename);
	}
private:
	//1.导出欠费信息excle文件
	std::shared_ptr<OutgoingResponse> downloadOweInformation(const String& filename);
	//分页查询产品属性
	CombineOweInformationJsonVO::Wrapper execOweQuery(const OweInformationQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWEINFORMATIONCONTROLLER_H_