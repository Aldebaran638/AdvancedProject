#pragma once
#ifndef _VENUERESERVATIONMGRDTO_H_
#define _VENUERESERVATIONMGRDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class VenueReservationMgrDTO : public oatpp::DTO
{
    DTO_INIT(VenueReservationMgrDTO, DTO);
    // 场地ID
    API_DTO_FIELD_DEFAULT(String, spaceId, ZH_WORDS_GETTER("VenueReservationMgr.field.spaceId"));
    // 场馆ID
    API_DTO_FIELD_DEFAULT(String, venueId, ZH_WORDS_GETTER("VenueReservationMgr.field.venueId"));
    // 预约人
    API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("VenueReservationMgr.field.personName"));
    // 预约电话
    API_DTO_FIELD_DEFAULT(String, personTel, ZH_WORDS_GETTER("VenueReservationMgr.field.personTel"));
    // 预约日期
    API_DTO_FIELD_DEFAULT(String, appointmentDate, ZH_WORDS_GETTER("VenueReservationMgr.field.appointmentDate"));
    // 预约时间
    API_DTO_FIELD_DEFAULT(String, appointmentTime, ZH_WORDS_GETTER("VenueReservationMgr.field.appointmentTime"));
    // 应收金额
    API_DTO_FIELD_DEFAULT(Int32, receivableAmount, ZH_WORDS_GETTER("VenueReservationMgr.field.receivableAmount"));
    // 实收金额
    API_DTO_FIELD_DEFAULT(Int32, receivedAmount, ZH_WORDS_GETTER("VenueReservationMgr.field.receivedAmount"));
    // 支付方式
    API_DTO_FIELD_DEFAULT(String, payWay, ZH_WORDS_GETTER("VenueReservationMgr.field.payWay"));
    // 状态
    API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("VenueReservationMgr.field.reservationStatus"));
    // 备注
    API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("VenueReservationMgr.field.remark"));
    // 订单编号
    API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("VenueReservationMgr.field.orderId"));
    // 创建时间
    API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("VenueReservationMgr.field.createTime"));
    // 场馆名称
    API_DTO_FIELD_DEFAULT(String, venueName, ZH_WORDS_GETTER("VenueReservationMgr.field.venueName"));
    // 场地名称
    API_DTO_FIELD_DEFAULT(String, spaceName, ZH_WORDS_GETTER("VenueReservationMgr.field.spaceName"));


    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class VenueReservationMgrPageDTO : public PageDTO<VenueReservationMgrDTO::Wrapper>
{
    DTO_INIT(VenueReservationMgrPageDTO, PageDTO<VenueReservationMgrDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif