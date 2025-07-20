#pragma once
#ifndef _OWNERPAYMENT_DO_
#define _OWNERPAYMENT_DO_
#include "../DoInclude.h"


/**
 * 业主缴费明细数据库实体类
 */
class OwnerPaymentDO
{
	//业主名称
	CC_SYNTHESIZE(string, ownerName, OwnerName);
	// 费用id类型
	CC_SYNTHESIZE(string, feeTypeCd, FeeTypeCd);
	// 费用名称类型
	CC_SYNTHESIZE(string, feeTypeName, FeeTypeName);
	// 缴费年限
	CC_SYNTHESIZE(int, pfYear, PfYear);
	// 费用项ID
	CC_SYNTHESIZE(string, configName, ConfigName);
	// 费用项名称
	CC_SYNTHESIZE(string, configId, ConfigId);
	// 小区ID
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// 房屋编号
	CC_SYNTHESIZE(string, roomName, RoomName);
	// 合计费用
	CC_SYNTHESIZE(double, totalAmount, TotalAmount);
	// 应收费用
	CC_SYNTHESIZE(double, receivableAmount, ReceivableAmount);
	// 预收费用
	CC_SYNTHESIZE(double, receivedAmount, ReceivedAmount);
	// 费用类型 list
	//CC_SYNTHESIZE(string, feeTypeList, FeeTypeList);
	//// 费用项ID list
	//CC_SYNTHESIZE(string, configNameList, ConfigNameList);
	// 一月费用
	CC_SYNTHESIZE(double, pfMonth1, PfMonth1);
	// 二月费用
	CC_SYNTHESIZE(double, pfMonth2, PfMonth2);
	// 三百费用
	CC_SYNTHESIZE(double, pfMonth3, PfMonth3);
	// 四月费用
	CC_SYNTHESIZE(double, pfMonth4, PfMonth4);
	// 五月费用
	CC_SYNTHESIZE(double, pfMonth5, PfMonth5);
	// 六月费用
	CC_SYNTHESIZE(double, pfMonth6, PfMonth6);
	// 七月费用
	CC_SYNTHESIZE(double, pfMonth7, PfMonth7);
	// 八月费用
	CC_SYNTHESIZE(double, pfMonth8, PfMonth8);
	// 九月费用
	CC_SYNTHESIZE(double, pfMonth9, PfMonth9);
	// 十月费用
	CC_SYNTHESIZE(double, pfMonth10, PfMonth10);
	// 十一月费用
	CC_SYNTHESIZE(double, pfMonth11, PfMonth11);
	// 十二月费用
	CC_SYNTHESIZE(double, pfMonth12, PfMonth12);
	

public:
	OwnerPaymentDO() {
		ownerName = "";
		feeTypeCd = "";
		pfYear = -1;
		roomName = "";
		configName = "";
		communityId = "";
		pfMonth1 = 0;
		pfMonth2 = 0;
		pfMonth3 = 0;
		pfMonth4 = 0;
		pfMonth5 = 0;
		pfMonth6 = 0;
		pfMonth7 = 0;
		pfMonth8 = 0;
		pfMonth9 = 0;
		pfMonth10 = 0;
		pfMonth11 = 0;
		pfMonth12 = 0;
	}
};

// 给OwnerPaymentDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OwnerPaymentDO> PtrOwnerPaymentDO;
#endif // !_OWNERPAYMENT_DO_
