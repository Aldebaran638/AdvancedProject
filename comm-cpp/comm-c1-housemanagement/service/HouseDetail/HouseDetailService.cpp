#include "stdafx.h"
#include "HouseDetailService.h"
#include "../../dao/HouseDetail/HouseDetailDAO.h"

HouseDetailDTO::Wrapper HouseDetailService::getHouseDetail(const HouseDetailQuery::Wrapper& query)
{
    HouseDetailDAO dao;
    HouseDetailDO data = dao.selectById(query);

    auto dto = HouseDetailDTO::createShared();
    ZO_STAR_DOMAIN_DO_TO_DTO(dto, data,
        house_id, House_id,
        house_num, House_num,
        unit_id, Unit_id,
        floor_num, Floor_num,
        owner_name, Owner_name,
        owner_phone, Owner_phone,
        house_type, House_type,
        built_area, Built_area,
        inner_area, Inner_area,
        rent_amount, Rent_amount,
        house_status, House_status,
        check_in_date, Check_in_date);

    return dto;
}