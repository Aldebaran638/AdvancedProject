#pragma once

#ifndef _UNPAIDHOUSECONTROLLER_
#define _UNPAIDHOUSECONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/unpaid_house/UnpaidHouseQuery.h"
#include "domain/dto/unpaid_house/UnpaidHouseDTO.h"
#include "domain/vo/unpaid_house/UnpaidHouseVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 未收费房屋
 */
class UnpaidHouseController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(UnpaidHouseController);
public: // 3 定义接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryUnpaidHouse) {
		// 定义通用描述（授权、标题、响应）
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("unpaid-house.get.summary"), UnpaidHousePageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 楼栋ID
		API_DEF_ADD_QUERY_PARAMS(String, "floorId", ZH_WORDS_GETTER("unpaid-house.field.floor-id"), "732025052809640133", false);
		// 楼栋编号
		//API_DEF_ADD_QUERY_PARAMS(String, "floorNum", ZH_WORDS_GETTER("unpaid-house.field.floor-num"), "", false);
		// 单元ID
		API_DEF_ADD_QUERY_PARAMS(String, "unitId", ZH_WORDS_GETTER("unpaid-house.field.unit-id"), "742025052876120134", false);
		// 单元编号
		//API_DEF_ADD_QUERY_PARAMS(String, "unitNum", ZH_WORDS_GETTER("unpaid-house.field.unit-num"), "", false);
		// 房屋ID
		API_DEF_ADD_QUERY_PARAMS(String, "roomId", ZH_WORDS_GETTER("unpaid-house.field.room-id"), "752025052884790135", false);
		// 房屋编号
		//API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("unpaid-house.field.room-num"), "", false);
		// 业主姓名
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("unpaid-house.field.owner-name"), "Li Hua", false);
		// 联系电话
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("unpaid-house.field.link"), "13111111111", false);
		// 小区ID（必填）
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/unpaid-house", queryUnpaidHouse, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, UnpaidHouseQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnpaidHouse(userQuery));
	}

	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportUnpaidHouse) {
		// 定义通用描述（授权、标题、响应）
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("unpaid-house.export.summary"), Void);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "floorId", ZH_WORDS_GETTER("unpaid-house.field.floor-id"), "732025052809640133", false);
		API_DEF_ADD_QUERY_PARAMS(String, "unitId", ZH_WORDS_GETTER("unpaid-house.field.unit-id"), "742025052876120134", false);
		API_DEF_ADD_QUERY_PARAMS(String, "roomId", ZH_WORDS_GETTER("unpaid-house.field.room-id"), "752025052884790135", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("unpaid-house.field.owner-name"), "Li Hua", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("unpaid-house.field.link"), "13111111111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/c7-repomanage/unpaid-house/export", exportUnpaidHouse, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, UnpaidHouseQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportUnpaidHouse(userQuery);
	}

	// 3.1 定义查询条件接口描述-楼栋
	ENDPOINT_INFO(queryFloor) {
		// 定义通用描述（授权、标题、响应）
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("query-condition.get.floor"), FloorJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
	}

	ENDPOINT(API_M_GET, "/c7-repomanage/query-condition/floor", queryFloor, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, FloorQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFloor(userQuery));
	}

	// 3.1 定义查询条件接口描述-单元
	ENDPOINT_INFO(queryUnit) {
		// 定义通用描述（授权、标题、响应）
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("query-condition.get.unit"), UnitJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "floorId", ZH_WORDS_GETTER("unpaid-house.field.floor-id"), "732025052809640133", true);
	}

	ENDPOINT(API_M_GET, "/c7-repomanage/query-condition/unit", queryUnit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, UnitQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnit(userQuery));
	}

	// 3.1 定义查询条件接口描述-房屋
	ENDPOINT_INFO(queryRoom) {
		// 定义通用描述（授权、标题、响应）
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("query-condition.get.room"), RoomJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "unitId", ZH_WORDS_GETTER("unpaid-house.field.unit-id"), "742025052876120134", false);
	}

	ENDPOINT(API_M_GET, "/c7-repomanage/query-condition/room", queryRoom, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, RoomQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRoom(userQuery));
	}

private: // 3.3 定义接口执行函数
	// 分页查询数据
	UnpaidHousePageJsonVO::Wrapper execQueryUnpaidHouse(const UnpaidHouseQuery::Wrapper& query);
	// 导出数据
	std::shared_ptr<OutgoingResponse> execExportUnpaidHouse(const UnpaidHouseQuery::Wrapper& query);
	// 查询条件-楼栋
	FloorJsonVO::Wrapper execQueryFloor(const FloorQuery::Wrapper& query);
	UnitJsonVO::Wrapper execQueryUnit(const UnitQuery::Wrapper& query);
	RoomJsonVO::Wrapper execQueryRoom(const RoomQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_UNPAIDHOUSECONTROLLER_
