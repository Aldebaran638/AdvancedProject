#ifndef _FLOORCONTROLLER_H_
#define _FLOORCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/floor/FloorQuery.h"
#include "domain/dto/floor/FloorDTO.h"
#include "domain/vo/floor/FloorVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)


class FloorController :public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(FloorController);

public:
	//定义查询接口描述
	ENDPOINT_INFO(queryFloor) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("floor.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FloorPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "floor_num", ZH_WORDS_GETTER("floor.field.floor_num"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("floor.field.name"), ZH_WORDS_GETTER("floor.params.name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("floor.field.community_id"), "2023052267100146", false);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/floor/query", queryFloor, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(floorQuery, FloorQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFloor(floorQuery));
	}


	//定义ID查询接口描述
	ENDPOINT_INFO(queryFloorById) {
		//定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("floor.query-by-id.summary"), FloorJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "Floor_id", ZH_WORDS_GETTER("floor.field.floor_id"), "d934050a8bb373e8f8eed0bf7507ec17", true);
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/floor/query-by-id", queryFloorById, QUERY(String, Floor_id), execQueryById(Floor_id));


	//定义新增接口描述
	ENDPOINT_INFO(addFloor) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("floor.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//定义新增接口处理
	ENDPOINT(API_M_POST, "/floor/add-floor", addFloor, BODY_DTO(FloorAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		//呼叫执行函数相应结果
		API_HANDLER_RESP_VO(execAddFloor(dto, authObject->getPayload()));
	}


	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("floor.put.summary"), modifyFloor, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/floor/modify-floor", modifyFloor, BODY_DTO(FloorDTO::Wrapper, dto), execModifyFloor(dto, authObject->getPayload()));

private:
	//floor_id查询数据
	FloorJsonVO::Wrapper execQueryById(const String& id);
	//分页查询数据
	FloorPageJsonVO::Wrapper execQueryFloor(const FloorQuery::Wrapper& query);
	//新增数据
	StringJsonVO::Wrapper execAddFloor(const FloorAddDTO::Wrapper& dto, const PayloadDTO& payload);
	//修改数据
	StringJsonVO::Wrapper execModifyFloor(const FloorDTO::Wrapper& dto, const PayloadDTO& payload);
};




#endif