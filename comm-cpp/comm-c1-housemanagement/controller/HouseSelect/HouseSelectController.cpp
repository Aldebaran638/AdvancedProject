#include "stdafx.h"
#include "HouseSelectController.h"
#include "../../service/HouseSelect/HouseSelectService.h"
#include "../ApiDeclarativeServicesHelper.h"

HouseSelectPageJsonVO::Wrapper HouseSelectController::execQueryHouseSelect(const HouseSelectQuery::Wrapper& query)
{
    HouseSelectService service;
    auto result = service.listHouse(query);
    auto jvo = HouseSelectPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}