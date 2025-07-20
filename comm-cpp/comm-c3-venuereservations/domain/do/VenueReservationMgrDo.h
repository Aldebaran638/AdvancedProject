#pragma once
#ifndef _VENUERESERVATIONMGRDO_H_
#define _VENUERESERVATIONMGRDO_H_
#include "DoInclude.h"

class VenueReservationMgrDO
{
    CC_SYNTHESIZE(string, cspId, CspId); // 预约ID
    CC_SYNTHESIZE(string, spaceId, SpaceId); // 场地ID
    CC_SYNTHESIZE(string, venueId, VenueId); // 场馆ID
    CC_SYNTHESIZE(string, personName, PersonName); // 预约人
    CC_SYNTHESIZE(string, personTel, PersonTel); // 预约电话
    CC_SYNTHESIZE(string, appointmentDate, AppointmentDate); // 预约日期
    CC_SYNTHESIZE(string, appointmentTime, AppointmentTime); // 预约时间
    CC_SYNTHESIZE(double, receivableAmount, ReceivableAmount); // 应收金额
    CC_SYNTHESIZE(double, receivedAmount, ReceivedAmount); // 实收金额
    CC_SYNTHESIZE(string, payWay, PayWay); // 支付方式
    CC_SYNTHESIZE(string, reservationStatus, ReservationStatus); // 状态
    CC_SYNTHESIZE(string, remark, Remark); // 备注
    CC_SYNTHESIZE(string, orderId, OrderId); // 订单编号
    CC_SYNTHESIZE(string, createTime, CreateTime); // 创建时间
    CC_SYNTHESIZE(string, venueName, VenueName); // 场馆名称
    CC_SYNTHESIZE(string, spaceName, SpaceName); // 场地名称
public:
	VenueReservationMgrDO() {
        cspId = "";
        spaceId = "";
        venueId = "";
        personName = "";
        personTel = "";
        appointmentDate = "";
        appointmentTime = "";
        receivableAmount = 0.0;
        receivedAmount = 0.0;
        payWay = "";
        reservationStatus = "";
        remark = "";
        orderId = "";
        createTime = "";
        venueName = "";
        spaceName = "";
	}
};

// 给智能指针设定一个别名方便使用
typedef std::shared_ptr<VenueReservationMgrDO> PtrVenueReservationMgrDO;

#endif//_VENUERESERVATIONMGRDO_H_