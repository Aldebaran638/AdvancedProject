#include "stdafx.h"
#include "HouseDetailController.h"
#include "../../service/HouseDetail/HouseDetailService.h"

HouseDetailJsonVO::Wrapper HouseDetailController::execGetHouseDetail(const HouseDetailQuery::Wrapper& query)
{
    HouseDetailService service;
    auto result = service.getHouseDetail(query);
    auto jvo = HouseDetailJsonVO::createShared();
    jvo->success(result);
    return jvo;
}