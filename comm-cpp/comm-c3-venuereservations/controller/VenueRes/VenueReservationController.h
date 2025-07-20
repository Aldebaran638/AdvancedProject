#pragma once
#ifndef _VENUERESERVATIONCONTROLLER_H_
#define _VENUERESERVATIONCONTROLLER_H_
#include "domain/GlobalInclude.h" 
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/VenueReservationMgrVO.h"
#include "domain/dto/VenueReservationMgrDTO.h"
#include "domain/query/VenueReservationMgrQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class VenueReservationController : public oatpp::web::server::api::ApiController
{
    //定义控制器访问入口
    API_ACCESS_DECLARE(VenueReservationController);

    // 获取场馆场地预约列表接口声明
    ENDPOINT_INFO(queryAllReservations)
    {

        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("VenueReservationMgr.get.summary"), VenueReservationMgrPageJsonVO::Wrapper);
        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "appointmentTime", ZH_WORDS_GETTER("VenueReservationMgr.field.appointmentTime"), "Y", false);
        API_DEF_ADD_RSP_JSON_WRAPPER(VenueReservationMgrPageJsonVO);
    }
    ENDPOINT(API_M_GET, "/c3-venueres/query-page", queryAllReservations, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, VenueReservationMgrQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryAllReservations(query));
    }

    // 添加预约接口声明
    ENDPOINT_INFO(addReservation)
    {
        // 定义接口标题
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("VenueReservationMgr.add.summary"), VenueReservationMgrJsonVO::Wrapper);
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
        API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("VenueReservationMgr.field.personName"), "123", true);
        API_DEF_ADD_QUERY_PARAMS(String, "personTel", ZH_WORDS_GETTER("VenueReservationMgr.field.fee_type"), "13258925253", true);
        API_DEF_ADD_QUERY_PARAMS(Int64, "receivableAmount", ZH_WORDS_GETTER("VenueReservationMgr.field.receivableAmount"), 1, false);
        API_DEF_ADD_QUERY_PARAMS(Int64, "receivedAmount", ZH_WORDS_GETTER("VenueReservationMgr.field.receivedAmount"), 1, false);
        API_DEF_ADD_QUERY_PARAMS(String, "payWay", ZH_WORDS_GETTER("VenueReservationMgr.field.payWay"), "1", true);
        API_DEF_ADD_QUERY_PARAMS(String, "appointmentTime", ZH_WORDS_GETTER("VenueReservationMgr.field.appointmentTime"), "12", true);
        API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("VenueReservationMgr.field.remark"), "666", true);
    }   

    ENDPOINT(API_M_POST, "/c3-venueres/add", addReservation, BODY_DTO(VenueReservationMgrDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) 
    {
        API_HANDLER_RESP_VO(execAddReservation(dto, authObject->getPayload()));
    }



private:
    VenueReservationMgrPageJsonVO::Wrapper execQueryAllReservations(const VenueReservationMgrQuery::Wrapper& query);
    StringJsonVO::Wrapper execAddReservation(const VenueReservationMgrDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_VENUERESERVATIONCONTROLLER_H_