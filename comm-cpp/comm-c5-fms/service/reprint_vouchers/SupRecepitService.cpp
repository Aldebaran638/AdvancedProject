#include"SupRecepitService.h"
#include "stdafx.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include"dao/reprint_vouchers/SupRecepitDAO.h"
#include"../comm-c5-fms//controller/reprint_vouchers//SupRecepitController.h"

std::string SupRecepitService::roomName(list<SupRecepitForRoomDO> roomlist) {
	std::string result("");
	for (SupRecepitForRoomDO sub : roomlist) {
		result = result + sub.getFloor() + sub.getUnit() + ZH_WORDS_GETTER("supplementrecepit.roommessage.unit") +
			sub.getRoom() + ZH_WORDS_GETTER("supplementrecepit.roommessage.room");
		result += "/";
	}
	int n = result.length();
	if (result.at(n - 1) == '/') {
		result.erase(n - 1, 1);
	}
	return result;
}

SupRecepitPageDTO::Wrapper SupRecepitService::SupRecepitListAll(const SupRecepitQuery::Wrapper& query) {
	auto pages = SupRecepitPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	SupRecepitDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	pages->total = count;
	pages->calcPages();
	list<SupRecepitDO> result = dao.selectWithPage(query);

	for (SupRecepitDO sub : result)
	{
		auto getstr = sub.getObjType();
		if (getstr == "3333") {
			sub.setObjType(ZH_WORDS_GETTER("supplementrecepit.objtype.room"));
		}
		else {
			sub.setObjType(ZH_WORDS_GETTER("supplementrecepit.objtype.car"));
			list<SupRecepitForRoomDO> tempselect = dao.selectForRoom(sub.getRoomName());
			std::string needchange = this->roomName(tempselect);
			sub.setRoomName(needchange);
		}
		auto dto = SupRecepitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, recepitId,RecepitId, recepitCode, RecepitCode, objType, ObjType,
			feeName, FeeName, roomName, RoomName, ownerName, OwnerName, carPark, CarPark, receviableAmount, 
			ReceviableAmount, createTime, CreateTime);
		pages->addData(dto);
	}
	return pages;
}

ReprintSupRecepitDTO::Wrapper SupRecepitService::ReprintRecepit(std::string id) {
	SupRecepitDAO dao;
	auto res = dao.selectForReprint1(id);
	if (!res) {
		return nullptr;
	}
	auto dto = ReprintSupRecepitDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, ownerName, OwnerName, objName, ObjName, feeName, FeeName, startTime, StartTime, createTime, CreateTime,
		endTime, EndTime, needPay, NeedPay, pay, Pay, recepitId, RecepitId, recepitPayId, RecepitPayId, cashierName, CashierName);
	return dto;
}

ReprintSupRecepit2DTO::Wrapper SupRecepitService::ReprintRecepit2(std::string id) {
	SupRecepitDAO dao;
	auto res = dao.selectForReprint2(id);
	if (!res) {
		return nullptr;
	}
	auto dto = ReprintSupRecepit2DTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, recepitCode, RecepitCode, payOrderId, PayOrderId, objName, ObjName, payObjName, PayObjName, createTime, CreateTime,
		feeName, FeeName, startTime, StartTime, endTime,EndTime, squarePrice, SquarePrice, area,Area, primeRate,PrimeRate, payableAmount, PayableAmount,
		discountAmount, DiscountAmount, remark, Remark, receivedAmount, ReceivedAmount, cashierName, CashierName);
	return dto;
}
