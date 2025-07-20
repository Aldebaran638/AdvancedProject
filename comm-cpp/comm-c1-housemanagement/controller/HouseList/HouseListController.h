#pragma once
#ifndef _HOUSELIST_CONTROLLER_
#define _HOUSELIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/HouseList/HouseListQuery.h"
#include "domain/dto/HouseList/HouseListDTO.h"
#include "domain/vo/HouseList/HouseListVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class HouseListController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(HouseListController);
public:
    ENDPOINT_INFO(queryHouseList)
    {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("houselist.get.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(HouseListPageJsonVO);
        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "house_id", ZH_WORDS_GETTER("houselist.field.house_id"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "status_cd", ZH_WORDS_GETTER("houselist.field.status_cd"), "0", false);
        API_DEF_ADD_QUERY_PARAMS(String, "floor_num", ZH_WORDS_GETTER("houselist.field.floor_num"), "1", true);
        API_DEF_ADD_QUERY_PARAMS(String, "unit_num", ZH_WORDS_GETTER("houselitst.field.unit_num"), "1", false);
        
    }
    ENDPOINT(API_M_GET, "/house/query-house-list", queryHouseList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, HouseListQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryHouseList(query));
    }

private:
    HouseListPageJsonVO::Wrapper execQueryHouseList(const HouseListQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif