#pragma once
#ifndef _REPAIRSTATISTIC_DO_
#define _REPAIRSTATISTIC_DO_
#include "../DoInclude.h"

class RepairStatisticsDO {
	// 定义受保护的变量，并提供get、set方法
	CC_SYNTHESIZE(string, community_id, CID);             // 小区id
	CC_SYNTHESIZE(int, publicAreaTotal, PublicAreaTotal);             // 公共区总数量
	CC_SYNTHESIZE(int, nonPublicAreaTotal, NonPublicAreaTotal);       // 非公共区总数量
	CC_SYNTHESIZE(int, dispatchedOrders, DispatchedOrders);           // 已派单数
	CC_SYNTHESIZE(int, returnVisitCount, ReturnVisitCount);           // 回访数
	CC_SYNTHESIZE(int, unreturnedVisitCount, UnreturnedVisitCount);   // 未回访数
	CC_SYNTHESIZE(int, publicAreaUnfinished, PublicAreaUnfinished);   // 公共区未完成
	CC_SYNTHESIZE(int, nonPublicAreaUnfinished, NonPublicAreaUnfinished); // 非公共区未完成
	CC_SYNTHESIZE(double, repairReceivable, RepairReceivable);        // 维修应收
	CC_SYNTHESIZE(double, repairReceived, RepairReceived);            // 维修实收
	CC_SYNTHESIZE(double, nonPublicAreaCompletionRate, NonPublicAreaCompletionRate); // 非公区完成平均值
	CC_SYNTHESIZE(double, publicAreaCompletionRate, PublicAreaCompletionRate); // 公区完成平均值

public:
	RepairStatisticsDO() : community_id(""), publicAreaTotal(0), nonPublicAreaTotal(0), dispatchedOrders(0),
		returnVisitCount(0), unreturnedVisitCount(0), publicAreaUnfinished(0),
		nonPublicAreaUnfinished(0), repairReceivable(0.0), repairReceived(0.0),
		nonPublicAreaCompletionRate(0.0), publicAreaCompletionRate(0.0) {
	}
};
// 给RepairStatisticsDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairStatisticsDO> PtrRepairStatisticsDO;
#endif // !_REPAIRSTATISTIC_DO_