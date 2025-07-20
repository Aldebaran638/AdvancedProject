#pragma once

#ifndef _ROOM_CONTROLLER_
#define _ROOM_CONTROLLER_

#include "domain/dto/room/RoomDTO.h"
#include "domain/query/room/RoomQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/room/RoomVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class RoomController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RoomController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryRoom) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("room.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RoomPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("room.query-all.field.room_num"), "1001", false);
		////////////
		// 定义通用描述
		/*API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("room.query-by-id.summary"), RoomJsonVO::Wrapper);*/
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/room", queryRoom, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, RoomQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRoom(userQuery));

	}


	
	//// 3.1 定义ID查询接口描述
	//ENDPOINT_INFO(queryRoomById) {
	//	// 定义通用描述
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("room.query-by-id.summary"), RoomJsonVO::Wrapper);
	//	// 定义参数描述
	//	API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("room.field.room_num"), "752024010438310020", true);
	//}
	//// 3.2 定义ID查询接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/room/query-by-id", queryRoomById, QUERY(String, room_num), execQueryById(room_num));

private://定义接口执行函数
	//分页查询数据
	RoomPageJsonVO::Wrapper execQueryRoom(const RoomQuery::Wrapper& query);
	//房屋编号查询数据
	/*RoomJsonVO::Wrapper execQueryById(const String& id);*/
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_