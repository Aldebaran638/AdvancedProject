#include "stdafx.h"
#include "HouseSelectService.h"
#include "../../dao/HouseSelect/HouseSelectDAO.h"

HouseSelectPageDTO::Wrapper HouseSelectService::listHouse(const HouseSelectQuery::Wrapper& query)
{
    auto pages = HouseSelectPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    HouseSelectDAO dao;
    uint64_t count = dao.count(query);
    pages->total = count;
    pages->calcPages();

    list<HouseSelectDO> result = dao.selectHouse(query);
    for (HouseSelectDO sub : result)
    {
        auto dto = HouseSelectDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
            house_id, House_id,
            room_num, Room_num,
            floor_num, Floor_num,
            unit_num, Unit_num,
            layer_num, Layer_num);
        pages->addData(dto);
    }
    return pages;
}