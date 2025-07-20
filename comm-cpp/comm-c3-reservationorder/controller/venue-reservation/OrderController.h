#pragma once
#ifndef _ORDER_CONTROLLER_H_
#define _ORDER_CONTROLLER_H_

#include "domain/query/venue-reservation/OrderQuery.h"
#include "domain/vo/venue-reservation/OrderVO.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrderController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(OrderController);

public:
	// 定义场地预约订单分页查询接口描述
	ENDPOINT_INFO(queryOrder) {
		// 定义接口标题、添加响应数据、添加安全认证
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("venue-reservation.query-order.summary"), OrderPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("venue-reservation.field.communityId"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "spaceId", ZH_WORDS_GETTER("venue-reservation.field.spaceId"), "102025051649290124", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("venue-reservation.field.state"), "S", false);
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("venue-reservation.field.personName"), ZH_WORDS_GETTER("venue-reservation.example.personName"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "personTel", ZH_WORDS_GETTER("venue-reservation.field.personTel"), "12345678910", false);
		API_DEF_ADD_QUERY_PARAMS(String, "appointmentTime", ZH_WORDS_GETTER("venue-reservation.field.appointmentTime"), "2025-05-21 23:59:59", false);
	}
	// 定义场地预约订单分页查询接口处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c3-paceapp/query-order-page", queryOrder, OrderQuery, execQueryOrder(query));

	// 定义取消预约接口描述
	ENDPOINT_INFO(removeOrder) {
		// 定义接口标题、添加响应数据、添加安全认证
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("venue-reservation.remove-order.summary"), StringJsonVO::Wrapper);
	}
	// 定义取消预约接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-paceapp/remove-order", removeOrder, BODY_DTO(OrderIdDTO::Wrapper, dto), execRemoveOrder(dto));

	// 定义场地预约订单分页查询接口执行函数
	OrderPageJsonVO::Wrapper execQueryOrder(const OrderQuery::Wrapper& query);
	// 定义取消预约接口执行函数
	StringJsonVO::Wrapper execRemoveOrder(const OrderIdDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ORDER_CONTROLLER_H_

