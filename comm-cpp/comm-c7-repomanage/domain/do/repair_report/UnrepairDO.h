#ifndef _UNREPAIRDO_DO_
#define _UNREPAIRDO_DO_
#include "../DoInclude.h"


/**
 * 示例数据库实体类
 */
class UnrepairDO
{
	//社区ID
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// 订单号
	CC_SYNTHESIZE(string, repairId, RepairId);
	// 报修日期
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 报修人
	CC_SYNTHESIZE(string, repairName, RepairName);
	// 报修电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 报修位置
	CC_SYNTHESIZE(string, repairObjName, RepairObjName);
	// 当前处理人
	CC_SYNTHESIZE(string, staffName, StaffName);
	// 结单时间
	CC_SYNTHESIZE(string, endTime, EndTime);
	// 订单状态
	CC_SYNTHESIZE(string, state, State);
public:
	UnrepairDO() {}
	UnrepairDO(string communityId, string  repairId, string createTime, string repairName, string tel, string repairObjName, string staffName, string endTime, string state)
	{
		this->communityId = communityId;
		this->repairId = repairId;
		this->createTime = createTime;
		this->repairName = repairName;
		this->tel = tel;
		this->repairObjName = repairObjName;
		this->staffName = staffName;
		this->endTime = endTime;
		this->state = state;
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<UnrepairDO> PtrUnrepairDO;
#endif // !_UNREPAIRDO_DO_