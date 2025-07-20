#pragma once


#ifndef _COMMUNITYVENUEAPICLIENT_H_
#define _COMMUNITYVENUEAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

class CommunityVenueClient : public oatpp::web::client::ApiClient
{
  #include OATPP_CODEGEN_BEGIN(ApiClient)

	API_CLIENT_INIT(CommunityVenueClient);

	API_CALL(API_M_GET, "/venue/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));
	// 多条件查询
	API_CALL(API_M_GET, "/venue/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, name));

#include OATPP_CODEGEN_END(ApiClient)
};


#endif//!_COMMUNITYVENUEAPICLIENT_H_