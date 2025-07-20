#include "stdafx.h"
#include "HouseNameService.h"
#include "../../dao/HouseName/HouseNameDAO.h"

oatpp::List<HouseNameDTO::Wrapper> HouseNameService::listHouseName(const HouseNameQuery::Wrapper& query)
{
    HouseNameDAO dao;
    list<HouseNameDO> result = dao.selectHouseName(query);
    auto dtoList = oatpp::List<HouseNameDTO::Wrapper>::createShared();

    for (HouseNameDO sub : result)
    {
        auto dto = HouseNameDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
            house_num, House_num,
            owner_name, Owner_name,
            floor_num, Floor_num,
            unit_num, Unit_num);
        dtoList->push_back(dto);
    }
    return dtoList;
}