#include "stdafx.h"
#include "OrderController.h"
#include "service/venue-reservation/OrderService.h"

OrderPageJsonVO::Wrapper OrderController::execQueryOrder(const OrderQuery::Wrapper& query) {
	/*OATPP_LOGI("execQueryOrder",
		"communityId: %s, spaceId: %s, state: %s, personName: %s, personTel: %s, appointmentTime: %s",
		query->communityId, query->spaceId, query->state, query->personName, query->personTel, query->appointmentTime);*/
	OrderService service;
	auto result =  service.listAll(query);
	auto jvo = OrderPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper OrderController::execRemoveOrder(const OrderIdDTO::Wrapper& dto) {
	auto jvo = StringJsonVO::createShared();
	OrderService service;
	if (service.removeData(dto->cspId))
	{
		jvo->success("success");
	}
	else
	{
		jvo->fail("fail");
	}
	return jvo;
}