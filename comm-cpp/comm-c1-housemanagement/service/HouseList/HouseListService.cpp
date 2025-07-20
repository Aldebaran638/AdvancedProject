#include "stdafx.h"
#include "HouseListService.h"
#include "../../dao/HouseList/HouseListDAO.h"

HouseListPageDTO::Wrapper HouseListService::listHouse(const HouseListQuery::Wrapper& query)
{
    auto pages = HouseListPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    HouseListDAO dao;
    uint64_t count = dao.count(query);
    pages->total = count;
    pages->calcPages();

    list<HouseListDO> result = dao.selectHouseList(query);
    for (HouseListDO sub : result)
    {
        auto dto = HouseListDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
            house_id, House_id,
            room_num, Room_num,
            floor_num, Floor_num,
            unit_num, Unit_num,
            status_cd, Status_cd,
            owner_count, Owner_count,
            car_count, Car_count,
            complaint_count, Complaint_count);
        pages->addData(dto);
    }
    return pages;
}