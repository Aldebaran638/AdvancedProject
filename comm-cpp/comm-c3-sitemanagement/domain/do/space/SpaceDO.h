#pragma once

#ifndef _SPACE_DO_
#define _SPACE_DO_
#include "../DoInclude.h"

/**
 * 场地信息实体类
 */
class SpaceDO
{
	// 场地Id
	CC_SYNTHESIZE(string, spaceId, SpaceId);
	// 场地名称
	CC_SYNTHESIZE(string, name, Name);
	// 预约开始时间
	CC_SYNTHESIZE(string, startTime, StartTime);
	// 预约结束时间
	CC_SYNTHESIZE(string, endTime, EndTime);
	// 每小时预约费用
	CC_SYNTHESIZE(double, feeMoney, FeeMoney);
	// 管理员姓名
	CC_SYNTHESIZE(string, adminName, AdminName);
	// 管理员电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 小区Id
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// 场地状态
	CC_SYNTHESIZE(string, state, State);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 数据状态
	CC_SYNTHESIZE(string, statusCd, StatusCd);
	// 场馆Id
	CC_SYNTHESIZE(string, venueId, VenueId);
public:
	SpaceDO() {
		spaceId = "";
		name = "";
		startTime = "";
		endTime = "";
		feeMoney = 0.0;
		adminName = "";
		tel = "";
		communityId = "";
		state = "";
		createTime = "";
		statusCd = "";
		venueId = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<SpaceDO> PtrSpaceDO;
#endif // !_SPACE_DO_
