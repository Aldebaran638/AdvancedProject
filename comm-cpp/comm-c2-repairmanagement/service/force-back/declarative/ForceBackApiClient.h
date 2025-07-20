#pragma once
#ifndef _FORCEBACKAPICLIENT_H_
#define _FORCEBACKAPICLIENT_H_

// 1 导入必须头文件
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 书写示例ApiClient来演示定义声明式服务
 */
class ForceBackApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{
	// 3 定义ApiClient控制器使用宏---开始
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 初始化定义
	API_CLIENT_INIT(ForceBackApiClient);

	// 5 使用API_CALL或API_CALL_ASYNC声明调用服务接口

	// 通过ID查询
	//API_CALL(API_M_GET, "/force-back/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));
	// 多条件查询
	API_CALL(API_M_GET, "/force-back/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, repair_name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 取消ApiClient控制器使用宏---结束
};

#endif // !_FORCEBACKAPICLIENT_H_
