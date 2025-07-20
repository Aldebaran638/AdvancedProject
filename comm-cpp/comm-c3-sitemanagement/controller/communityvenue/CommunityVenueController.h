#pragma once
#ifndef _COMMUNITYVENUE_CONTROLLER_H_
#define _COMMUNITYVENUE_CONTROLLER_H_

#include "domain/GlobalInclude.h" 
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/communityvenue/CommunityVenueQuery.h"
#include "domain/dto/communityvenue/CommunityVenueAddDTO.h"
#include "domain/dto/communityvenue/CommunityVenueModifyDTO.h"
#include "domain/dto/communityvenue/CommunityVenueDeleteDTO.h"
#include "domain/vo/communityvenue/CommunityVenueVO.h"
#include "domain/dto/communityvenue/CommunityVenuePageDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CommunityVenueController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(CommunityVenueController); // → /api/venue

public:
    /*--- 分页查询场馆 ---*/
    ENDPOINT_INFO(queryVenue) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("venue.get.summary"), CommunityVenuePageJsonVO::Wrapper);
        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("venue.field.name"), "", true);
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("venue.field.id"), "d934050a8bb373e8f8eed0bf7507ec17", true);
    }
    ENDPOINT(API_M_GET, "/c3-pacemgr/query-stadium-page", queryVenue,
        QUERIES(QueryParams, qps),
        API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(q, CommunityVenueQuery, qps);
        API_HANDLER_RESP_VO(execQueryVenue(q));
    }


    /*--- 新增场馆 ---*/
    ENDPOINT_INFO(addVenue) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("venue.post.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    // 3.2 定义新增接口处理
    ENDPOINT(API_M_POST, "/c3-pacemgr/add-stadium", addVenue, BODY_DTO(CommunityVenueAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execAddVenue(dto, authObject->getPayload()));
    }

    /*--- 修改场馆 ---*/
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("venue.put.summary"), modifyVenue, StringJsonVO::Wrapper);
    // 3.2 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c3-pacemgr/modify-stadium", modifyVenue, BODY_DTO(CommunityVenueModifyDTO::Wrapper, dto), execModifyVenue(dto, authObject->getPayload()));

    /*--- 删除场馆 ---*/
    // 3.1 定义删除接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("venue.delete.summary"), deleteVenue, ListJsonVO<String>::Wrapper);
    // 3.2 定义删除接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-pacemgr/delete-stadium", deleteVenue, BODY_DTO(List<String>, ids), execDeleteVenue(ids));

private:
    CommunityVenuePageJsonVO::Wrapper execQueryVenue(const CommunityVenueQuery::Wrapper& query);
    CommunityVenueJsonVO::Wrapper execQueryById(const String& id);
    StringJsonVO::Wrapper execAddVenue(const CommunityVenueAddDTO::Wrapper& dto, const PayloadDTO& payload);
    StringJsonVO::Wrapper execModifyVenue(const CommunityVenueModifyDTO::Wrapper& dto, const PayloadDTO& payload);
    ListJsonVO<String>::Wrapper execDeleteVenue(const List<String>& ids);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // _COMMUNITYVENUE_CONTROLLER_H_
