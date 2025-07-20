#include "stdafx.h"
#include "OrderService.h"
#include "dao/venue-reservation/OrderDAO.h"

OrderPageDTO::Wrapper OrderService::listAll(const OrderQuery::Wrapper& query)
{
	auto pages = OrderPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	OrderDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrderDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OrderDO sub : result)
	{
		auto dto = OrderDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, cspId, CspId, venueName, VenueName,\
			spaceName, SpaceName, personName, PersonName, personTel, PersonTel,\
			appointmentTime, AppointmentTime, times, Times, receivableAmount,\
			ReceivableAmount, receivedAmount, ReceivedAmount, payWay, PayWay,\
			state, State, createTime, CreateTime, remark, Remark);
		if (dto->payWay == "1")
		{
			dto->payWayName = ZH_WORDS_GETTER("venue-reservation.value.payWayName.1");
		}
		else if (dto->payWay == "2") {
			dto->payWayName = ZH_WORDS_GETTER("venue-reservation.value.payWayName.2");
		}
		else if (dto->payWay == "3") {
			dto->payWayName = ZH_WORDS_GETTER("venue-reservation.value.payWayName.3");
		}
		if (dto->state == "S")
		{
			dto->stateName = ZH_WORDS_GETTER("venue-reservation.value.stateName.S");
		}
		else if (dto->state == "F") {
			dto->stateName = ZH_WORDS_GETTER("venue-reservation.value.stateName.F");
		}
		else if (dto->state == "W") {
			dto->stateName = ZH_WORDS_GETTER("venue-reservation.value.stateName.W");
		}
		else if (dto->state == "CL") {
			dto->stateName = ZH_WORDS_GETTER("venue-reservation.value.stateName.CL");
		}
		pages->addData(dto);
	}
	return pages;
}

bool OrderService::removeData(const oatpp::String& cspId)
{
	OrderDAO dao;
	int result = dao.update(cspId);
	if (result == 0)
	{
		return true;
	}
	else {
		return false;
	}
}