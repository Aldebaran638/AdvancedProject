#include "stdafx.h"
#include "UnpaidHouseService.h"
#include "dao/report_management/unpaid_house/UnpaidHouseDAO.h"
#include "domain/do/unpaid_house/UnpaidHouseDO.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "../../../../lib-oatpp/include/oatpp/core/data/mapping/type/List.hpp"


UnpaidHousePageDTO::Wrapper UnpaidHouseService::listWithPage(const UnpaidHouseQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = UnpaidHousePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	UnpaidHouseDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<UnpaidHouseDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (UnpaidHouseDO sub : result)
	{
		auto dto = UnpaidHouseDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomId, RoomId, floorNum, FloorNum, unitNum, UnitNum, roomNum, RoomNum, ownerId, OwnerId, ownerName, OwnerName, link, Link);
		pages->addData(dto);
	}
	return pages;

}

oatpp::List<UnpaidHouseDTO::Wrapper> UnpaidHouseService::listAll(const UnpaidHouseQuery::Wrapper& query)
{
	// 构建返回对象
	auto rows = oatpp::List<UnpaidHouseDTO::Wrapper>::createShared();
	// 查询数据
	UnpaidHouseDAO dao;
	list<UnpaidHouseDO> result = dao.selectAll(query);
	// 将DO转换成DTO
	for (UnpaidHouseDO sub : result)
	{
		auto dto = UnpaidHouseDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomId, RoomId, floorNum, FloorNum, unitNum, UnitNum, roomNum, RoomNum, ownerId, OwnerId, ownerName, OwnerName, link, Link);
		rows->push_back(dto);
	}
	return rows;
}

oatpp::List<FloorDTO::Wrapper> FloorService::listAll(const FloorQuery::Wrapper& query)
{
	// 构建返回对象
	auto rows = oatpp::List<FloorDTO::Wrapper>::createShared();
	// 查询数据
	FloorDAO dao;
	list<FloorDO> result = dao.selectAll(query);
	// 将DO转换成DTO
	for (FloorDO sub : result)
	{
		auto dto = FloorDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, floorId, FloorId, floorNum, FloorNum);
		rows->push_back(dto);
	}
	return rows;
}

oatpp::List<UnitDTO::Wrapper> UnitService::listAll(const UnitQuery::Wrapper& query)
{
	// 构建返回对象
	auto rows = oatpp::List<UnitDTO::Wrapper>::createShared();
	// 查询数据
	UnitDAO dao;
	list<UnitDO> result = dao.selectAll(query);
	// 将DO转换成DTO
	for (UnitDO sub : result)
	{
		auto dto = UnitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, unitId, UnitId, unitNum, UnitNum);
		rows->push_back(dto);
	}
	return rows;
}

oatpp::List<RoomDTO::Wrapper> RoomService::listAll(const RoomQuery::Wrapper& query)
{
	// 构建返回对象
	auto rows = oatpp::List<RoomDTO::Wrapper>::createShared();
	// 查询数据
	RoomDAO dao;
	list<RoomDO> result = dao.selectAll(query);
	// 将DO转换成DTO
	for (RoomDO sub : result)
	{
		auto dto = RoomDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomId, RoomId, roomNum, RoomNum);
		rows->push_back(dto);
	}
	return rows;
}
