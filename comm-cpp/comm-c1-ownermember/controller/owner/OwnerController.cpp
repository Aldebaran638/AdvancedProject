#include "stdafx.h"//之前没加
#include "OwnerController.h"
#include "domain/dto/owner/OwnerDTO.h"
#include "service/owner/OwnerService.h"
#include "../ApiDeclarativeServicesHelper.h"
using namespace oatpp::web::server::api;

OwnerJsonVO::Wrapper OwnerController::execQueryById(const String& id)
{
    // 响应对象
    auto jvo = OwnerJsonVO::createShared();

    if (id == nullptr || id->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID); //RS_PARAMS_INVALID->错误码
        return jvo;
    }


    return jvo;
}