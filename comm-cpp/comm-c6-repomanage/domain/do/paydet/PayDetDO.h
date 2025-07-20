#pragma once
#ifndef _PAYDET_DO_
#define _PAYDET_DO_
#include "../DoInclude.h"

/**
 * 缴费明细数据对象（DO）
 * 用于与数据库表结构进行一一映射，在数据持久层与业务逻辑层之间传输数据源对象。
 */

class PayDetDO
{
	// 订单号
	CC_SYNTHESIZE(string, on, OrderNumber);
	// 房号/业主
	CC_SYNTHESIZE(string, hnpo, HouseNumberPropertyOwner);
	// 费用类型项目
	CC_SYNTHESIZE(string, eti, ExpenseTypeItem);
	// 费用状态
	CC_SYNTHESIZE(string, etatus, ExpenseStatus);
	// 支付方式
	CC_SYNTHESIZE(string, pm, PaymentMethod);
	// 缴费周期
	CC_SYNTHESIZE(string, pps, PaymentPeriod);
	// 缴费时间
	CC_SYNTHESIZE(string, payt, PaymentTime);
	// 收银员
	CC_SYNTHESIZE(string, chier, Cashier);
	// 应缴 / 应收金额
	CC_SYNTHESIZE(double, dra, DueReceiveAmount);
	// 实收金额
	CC_SYNTHESIZE(double, ard, AmountReceived);
	// 用户抵扣
	CC_SYNTHESIZE(double, ad, AccountDeduction);
	// 优惠 / 减免金额
	CC_SYNTHESIZE(double, dwa, DiscountWaiverAmount);
	// 赠送金额
	CC_SYNTHESIZE(double, ga, GiftAmount);
	// 滞纳金
	CC_SYNTHESIZE(double, lpf, LatePaymentFee);
	// 面积
	CC_SYNTHESIZE(double, ar, Area);
	// 车位
	CC_SYNTHESIZE(string, ps, ParkingSpace);
	// 说明
	CC_SYNTHESIZE(string, rem, Remarks);

public:
	PayDetDO()
	{
		on = "";
		hnpo = "";
		eti = "";
		etatus = "";
		pm = "";
		pps = "";
		payt = "";
		chier = "";
		dra = 0.0;
		ard = 0.0;
		ad = 0.0;
		dwa = 0.0;
		ga = 0.0;
		lpf = 0.0;
		ar = 0.0;
		ps = "";
		rem = "";
	}
};
#endif // !_PAYDET_DO_