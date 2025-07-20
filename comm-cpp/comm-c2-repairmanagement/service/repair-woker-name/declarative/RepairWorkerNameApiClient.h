#pragma once

#ifndef _REPAIRWORKERNAMEAPICLIENT_H_
#define _REPAIRWORKERNAMEAPICLIENT_H_

// 1 导入必须头文件
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 书写示例ApiClient来演示定义声明式服务
 */
class RepairWorkerApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{
	// 3 定义ApiClient控制器使用宏---开始
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 初始化定义
	API_CLIENT_INIT(SampleApiClient);

	// 5 使用API_CALL或API_CALL_ASYNC声明调用服务接口

	API_CALL(API_M_GET, "/repair-worker-name/query-all", queryAll,
		API_HANDLER_AUTN_HEADER,           // 认证头（对应 API_HANDLER_AUTH_PARAME）
		QUERY(String, repair_type_name),  // 查询参数 repair_type_name
		QUERY(String, repair_id),         // 查询参数 repair_id
		QUERY(String, community_id)       // 查询参数 community_id
	);
#include OATPP_CODEGEN_END(ApiClient)
	// 3 取消ApiClient控制器使用宏---结束
};

#endif // !_REPAIRWORKERNAMEAPICLIENT_H_