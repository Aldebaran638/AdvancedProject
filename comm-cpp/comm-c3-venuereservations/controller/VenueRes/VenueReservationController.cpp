#include "stdafx.h"
#include "VenueReservationController.h"
#include "../comm-c3-venuereservations/service/VenueReservationMgrService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
VenueReservationMgrPageJsonVO::Wrapper VenueReservationController::execQueryAllReservations(const VenueReservationMgrQuery::Wrapper& query)
{
	// 定义一个Service
	VenueReservationMgrService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = VenueReservationMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper VenueReservationController::execAddReservation(const VenueReservationMgrDTO::Wrapper& dto,const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->personName || !dto->venueName)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if ( dto->personName->empty() || dto->venueName->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	String newId = "generated-venue_reservation-id";
	jvo->success(newId);
	//响应结果
	return jvo;
	

}