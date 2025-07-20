#pragma once
#ifndef _REPAIRSETTINGDO_DO_
#define _REPAIRSETTINGDO_DO_
#include "../DoInclude.h"
/**
 * 报修类型数据库实体类
 */
class RepairSettingDO
{
	// 工单设置ID
	CC_SYNTHESIZE(string, setting_id, SettingId);
	// 报修类型(KEY值)
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// 报修类型名称
	CC_SYNTHESIZE(string, repair_type_name, RepairTypeName);
	// 派单方式 100 抢单 200 指派 300 轮训
	CC_SYNTHESIZE(string, repair_way, RepairWay);
	// 区域（小区分片ID）
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 说明（备注）
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 房屋内外 (是否为公共区域)
	CC_SYNTHESIZE(string, public_area, PublicArea);
	// 是否回访 回访标识 001 都不回访 002 已评价不回访 003 都回访
	CC_SYNTHESIZE(string, return_visit_flag, ReturnVisitFlag);
	// 报修设置类型(100保洁单 200维修单)
	CC_SYNTHESIZE(string, repair_setting_type, RepairSettingType);
	// 业主端展示 Y 是  N 否
	CC_SYNTHESIZE(string, is_show, IsShow);
	// 通知方式，SMS 短信 WECHAT 微信
	CC_SYNTHESIZE(string, notify_way, NotifyWay);
public:
	RepairSettingDO() {}
};
// 给RepairSettingDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairSettingDO> PtrRepairSettingDO;
#endif // _REPAIRSETTINGDO_H_