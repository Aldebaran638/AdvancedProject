#pragma once
#ifndef _HOUSE_DETAIL_CONTROLLER_
#define _HOUSE_DETAIL_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/HouseDetail/HouseDetailQuery.h"
#include "domain/dto/HouseDetail/HouseDetailDTO.h"
#include "domain/vo/HouseDetail/HouseDetailVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class HouseDetailController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(HouseDetailController);
public:
    ENDPOINT_INFO(getHouseDetail)
    {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house.get.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(HouseDetailJsonVO);
        API_DEF_ADD_QUERY_PARAMS(String, "house_id", ZH_WORDS_GETTER("house.field.house_id"), "", true);
    }
    ENDPOINT(API_M_GET, "/house/get-house-detail", getHouseDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, HouseDetailQuery, queryParams);
        API_HANDLER_RESP_VO(execGetHouseDetail(query));
    }

private:
    HouseDetailJsonVO::Wrapper execGetHouseDetail(const HouseDetailQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif