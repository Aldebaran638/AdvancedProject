#pragma once
#ifndef _ORDER_DO_
#define _ORDER_DO_
#include "../DoInclude.h"


class OrderDO
{
	// cspId
	CC_SYNTHESIZE(string, cspId, CspId);
	// 场馆名
	CC_SYNTHESIZE(string, venueName, VenueName);
	// 场地名
	CC_SYNTHESIZE(string, spaceName, SpaceName);
	// 预约人名字
	CC_SYNTHESIZE(string, personName, PersonName);
	// 预约人电话
	CC_SYNTHESIZE(string, personTel, PersonTel);
	// 预约日期
	CC_SYNTHESIZE(string, appointmentTime, AppointmentTime);
	// 预约时间段
	CC_SYNTHESIZE(string, times, Times);
	// 应收金额
	CC_SYNTHESIZE(string, receivableAmount, ReceivableAmount);
	// 实收金额
	CC_SYNTHESIZE(string, receivedAmount, ReceivedAmount);
	// 支付方式：1为现金 2为微信 3为支付宝
	CC_SYNTHESIZE(string, payWay, PayWay);
	// 场馆场地预约订单状态：S为预约成功 F为预约失败 W为待审核 F为待支付 CL为已删除
	CC_SYNTHESIZE(string, state, State);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	OrderDO() {
		
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OrderDO> PtrOrderDO;
#endif // !_ORDER_DO_