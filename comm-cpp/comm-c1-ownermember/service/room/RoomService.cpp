
#include "stdafx.h"
#include "RoomService.h"
#include "../../dao/room/RoomDAO.h"
//#include "id/UuidFacade.h"
//#include "SimpleDateTimeFormat.h"

RoomPageDTO::Wrapper RoomService::listAll(const RoomQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RoomPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RoomDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RoomDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RoomDO sub : result)
	{
		auto dto = RoomDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, room_num, Room_num, layer, Layer, built_up_area, Built_up_area, state, State, room_type, Room_type, room_rent, Room_rent);
		pages->addData(dto);
	}
	return pages;
}

//RoomDTO::Wrapper RoomService::getById(std::string id)
//{
//	// 查询数据
//	RoomDAO dao;
//	auto res = dao.selectById(id);
//
//	// 没有查询到数据
//	if (!res)
//		return nullptr;
//
//	// 查询到数据转换成DTO
//	auto dto = RoomDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, room_num, Room_num, layer, Layer, built_up_area, Built_up_area, state, State, room_type, Room_type, room_rent, Room_rent);
//	return dto;
//}


