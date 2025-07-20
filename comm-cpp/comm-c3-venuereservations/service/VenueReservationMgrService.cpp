#include "stdafx.h"
#include "../comm-c3-venuereservations/dao/VenueReservationMgrDAO.h"
#include "../comm-c3-venuereservations/service/VenueReservationMgrService.h"
#include "id/UuidFacade.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "algorithm"
//service层实现
VenueReservationMgrPageDTO::Wrapper VenueReservationMgrService::listAll(const VenueReservationMgrQuery::Wrapper& query)
{

	// 构建返回对象
	auto pages = VenueReservationMgrPageDTO::createShared();
	
	VenueReservationMgrDAO dao;
	

	list<VenueReservationMgrDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (VenueReservationMgrDO sub : result)
	{
		auto dto = VenueReservationMgrDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, venueName, VenueName);
		pages->addData(dto);
	}
	return pages;
}

std::string VenueReservationMgrService::saveData(const VenueReservationMgrDTO::Wrapper& dto)
{
	// 组装DO数据
	VenueReservationMgrDO data;
	data.setPersonName(dto->personName.getValue({}));
	data.setPersonTel(dto->personTel.getValue({}));
	data.setReceivableAmount(dto->receivableAmount.getValue({}));
	data.setReceivedAmount(dto->receivedAmount.getValue({}));;
	data.setPayWay(dto->payWay.getValue({}));
	data.setAppointmentTime(dto->appointmentTime.getValue({}));
	data.setRemark(dto->remark.getValue({}));
	// 生成ID
	SnowFlake sf(1, 1);
	data.setOrderId(std::to_string(sf.nextId()));
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	VenueReservationMgrDAO dao;
	return dao.insert(data) == 1 ? data.getOrderId() : "";
}
