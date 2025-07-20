#pragma once
#ifndef _HOUSESELECT_CONTROLLER_
#define _HOUSESELECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/HouseSelect/HouseSelectQuery.h"
#include "domain/dto/HouseSelect/HouseSelectDTO.h"
#include "domain/vo/HouseSelect/HouseSelectVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class HouseSelectController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(HouseSelectController);
public:
    ENDPOINT_INFO(queryHouseSelect)
    {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("houseselect.get.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(HouseSelectPageJsonVO);
        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "floor_num", ZH_WORDS_GETTER("houseselect.field.floor_num"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "unit_num", ZH_WORDS_GETTER("houseselect.field.unit_num"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("houseselect.field.room_num"), "", false);
    }
    ENDPOINT(API_M_GET, "/house/get-house-select", queryHouseSelect, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, HouseSelectQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryHouseSelect(query));
    }

private:
    HouseSelectPageJsonVO::Wrapper execQueryHouseSelect(const HouseSelectQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif