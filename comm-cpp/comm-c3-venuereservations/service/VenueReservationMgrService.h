#pragma once
#ifndef _VENUERESERVATIONMGRSERVICE_H_
#define _VENUERESERVATIONMGRSERVICE_H_
#include "../comm-c3-venuereservations/domain/vo/VenueReservationMgrVO.h"
#include "../comm-c3-venuereservations/domain/query/VenueReservationMgrQuery.h"
#include "../comm-c3-venuereservations/domain/dto/VenueReservationMgrDTO.h"

/**
 * 
 */
class VenueReservationMgrService
{
public:
	// 分页查询预约订单
	VenueReservationMgrPageDTO::Wrapper listAll(const VenueReservationMgrQuery::Wrapper& query);
	//保存数据
	std::string saveData(const VenueReservationMgrDTO::Wrapper& dto);
	
};

#endif // !_VENUERESERVATIONMGRSERVICE_H_