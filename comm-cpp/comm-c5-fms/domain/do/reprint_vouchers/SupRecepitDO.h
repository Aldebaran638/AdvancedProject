#pragma once
#ifndef _SUP_RECEPIT_DO_
#define _SUP_RECEPIT_DO_
#include "../DoInclude.h"
#include<string>

class SupRecepitDO {
	CC_SYNTHESIZE(string, recepitId, RecepitId);//收据id
	CC_SYNTHESIZE(string, recepitCode, RecepitCode);//收据编号
	CC_SYNTHESIZE(string, objType, ObjType);//费用类型
	CC_SYNTHESIZE(string, feeName, FeeName);//费用项
	CC_SYNTHESIZE(string, roomName, RoomName);//房屋
	CC_SYNTHESIZE(string,ownerName,OwnerName);//业主
	CC_SYNTHESIZE(string, carPark, CarPark);//车位
	CC_SYNTHESIZE(double, receviableAmount, ReceviableAmount);//总金额
	CC_SYNTHESIZE(string, createTime, CreateTime);//创建时间
public:
	SupRecepitDO() {
		recepitId = "";
		recepitCode = "";
		objType = "";
		feeName = "";
		roomName = "";
		ownerName = "";
		carPark = "";
		receviableAmount = 0.0;
		createTime = "";
	}
};

class ReprintSupRecepitDO
{
	CC_SYNTHESIZE(string, ownerName, OwnerName);//业主
	CC_SYNTHESIZE(string, objName, ObjName);//对象名称
	CC_SYNTHESIZE(string, feeName, FeeName);//费用项
	CC_SYNTHESIZE(string, startTime, StartTime);//开始时间
	CC_SYNTHESIZE(string, createTime, CreateTime);//创建时间
	CC_SYNTHESIZE(string, endTime, EndTime);//结束时间
	CC_SYNTHESIZE(double, needPay, NeedPay);//应收
	CC_SYNTHESIZE(double, pay, Pay);//实收
	CC_SYNTHESIZE(string, recepitId, RecepitId);//收据id
	CC_SYNTHESIZE(string, recepitPayId, RecepitPayId);//支付订单id
	CC_SYNTHESIZE(string, cashierName,CashierName);//收银员
public:
	ReprintSupRecepitDO() {
		ownerName = "";
		objName = "";
		feeName = "";
		startTime = "";
		createTime = "";
		endTime = "";
		needPay = 0.0;
		pay = 0.0;
		recepitId = "";
		recepitPayId = "";
		cashierName = "";
	}
};

class ReprintSupRecepit2DO {
	CC_SYNTHESIZE(string, recepitCode, RecepitCode);//收据编号
	CC_SYNTHESIZE(string, payOrderId, PayOrderId);//支付订单id
	CC_SYNTHESIZE(string, objName, ObjName);//对象名称
	CC_SYNTHESIZE(string, payObjName, PayObjName);//付费人名称
	CC_SYNTHESIZE(string, createTime, CreateTime);//创建时间
	CC_SYNTHESIZE(string, feeName, FeeName);//费用名称
	CC_SYNTHESIZE(string, startTime, StartTime);//开始时间
	CC_SYNTHESIZE(string, endTime, EndTime);//结束时间
	CC_SYNTHESIZE(string, squarePrice, SquarePrice);//单价/固定费
	CC_SYNTHESIZE(string, area, Area);//面积
	CC_SYNTHESIZE(double, primeRate, PrimeRate);//支付方式
	CC_SYNTHESIZE(double, payableAmount, PayableAmount);//应缴金额
	CC_SYNTHESIZE(double, discountAmount, DiscountAmount);//优惠金额
	CC_SYNTHESIZE(string, remark, Remark);//备注
	CC_SYNTHESIZE(double, receivedAmount, ReceivedAmount);//应收金额
	CC_SYNTHESIZE(string, cashierName, CashierName);//收银员
public:
	ReprintSupRecepit2DO() {
		recepitCode = "";
		payOrderId = "";
		objName = "";
		payObjName = "";
		createTime = "";
		feeName = "";
		startTime = "";
		endTime = "";
		squarePrice = "";
		area = "";
		primeRate = 0.0;
		payableAmount = 0.0;
		discountAmount = 0.0;
		remark = "";
		receivedAmount = 0.0;
		cashierName = "";
	}
};

typedef std::shared_ptr<SupRecepitDO> PtrSupRecepitDO;
typedef std::shared_ptr<ReprintSupRecepitDO> PtrReprintSupRecepitDO;
typedef std::shared_ptr<ReprintSupRecepit2DO> PtrReprintSupRecepit2DO;
#endif
