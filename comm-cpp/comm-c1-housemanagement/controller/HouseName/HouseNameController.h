#pragma once
#ifndef _HOUSENAME_CONTROLLER_
#define _HOUSENAME_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/HouseName/HouseNameQuery.h"
#include "domain/dto/HouseName/HouseNameDTO.h"
#include "domain/vo/HouseName/HouseNameVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class HouseNameController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(HouseNameController);
public:
    ENDPOINT_INFO(queryHouseName)
    {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("housename.get.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(HouseNameJsonVO);
        API_DEF_ADD_QUERY_PARAMS(String, "floor_num", ZH_WORDS_GETTER("housename.field.floor_num"), "1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "unit_num", ZH_WORDS_GETTER("housename.field.unit_num"), "1", false);
    }
    ENDPOINT(API_M_GET, "/house/query-house-name", queryHouseName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, HouseNameQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryHouseName(query));
    }

private:
    HouseNameJsonVO::Wrapper execQueryHouseName(const HouseNameQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif