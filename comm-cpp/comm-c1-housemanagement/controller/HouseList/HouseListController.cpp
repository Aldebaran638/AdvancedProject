#include "stdafx.h"
#include "HouseListController.h"
#include "../../service/HouseList/HouseListService.h"
#include "../ApiDeclarativeServicesHelper.h"

HouseListPageJsonVO::Wrapper HouseListController::execQueryHouseList(const HouseListQuery::Wrapper& query)
{
    HouseListService service;
    auto result = service.listHouse(query);
    auto jvo = HouseListPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}