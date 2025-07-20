#pragma once
#ifndef _REPAIRWORKERDO_H_
#define _REPAIRWORKERDO_H_
#include "../DoInclude.h"
/**
 * 维修师傅表r_repair_type_user数据库实体类
 */
class RepairWorkerQueryDO
{
	// 工单设置ID（这个表的唯一标识）
	CC_SYNTHESIZE(string, type_user_id, TypeUserId);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, BId);
	// 报修类型(实则是维修类型id)
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// 报修类型(实则是维修类型名称)
	CC_SYNTHESIZE(string, repair_type_name, RepairTypeName);
	// 员工ID
	CC_SYNTHESIZE(string, staff_id, StaffId);
	// 员工名称
	CC_SYNTHESIZE(string, staff_name, StaffName);
	// 小区分片ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 报修师傅状态 9999 在线 8888 离线 t_dict 表
	CC_SYNTHESIZE(string, state, State);
	// 报修师傅状态文本 9999 在线 8888 离线 t_dict 表
	CC_SYNTHESIZE(string, state_txt, StateTxt);
	// 描述，一般为状态变更描述
	CC_SYNTHESIZE(string, remark, Remark);
	// 数据状态 1应该为无效
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	//创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
public:
	RepairWorkerQueryDO() {
		type_user_id = "";
		b_id = "-1";
		repair_type = "";
		staff_id = "";
		staff_name = "";
		repair_type_name = "";
		community_id = "";
		state = "9999";
		state_txt = "在线";
		status_cd = "0";
		remark = "";
	}
};

// 给RepairWorkerName_RepairTypeUserDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairWorkerQueryDO> PtrRepairWorkerQueryDO;
//用于修改的DO
class RepairWorkerModifyDO
{

	// 员工ID
	CC_SYNTHESIZE(string, staff_id, StaffId);
	// 报修师傅状态 9999 在线 8888 离线 t_dict 表
	CC_SYNTHESIZE(string, state, State);
	// 描述，一般为状态变更描述
	CC_SYNTHESIZE(string, remark, Remark);
	// 小区分片ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 报修类型(实则是维修类型名称)
	CC_SYNTHESIZE(string, repair_type_name, RepairTypeName);
public:
	RepairWorkerModifyDO() {
		state = "9999";
		remark = "";
		staff_id = "";
		community_id = "";
		repair_type_name = "";
	}
};

// 给RepairWorkerName_RepairTypeUserDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairWorkerModifyDO> PtrRepairWorkerModifyDO;

class RepairWorkerAddDO
{
	// 工单设置ID（这个表的唯一标识）
	CC_SYNTHESIZE(string, type_user_id, TypeUserId);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, BId);
	// 报修类型(实则是维修类型id)
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// 报修类型(实则是维修类型名称)
	CC_SYNTHESIZE(string, repair_type_name, RepairTypeName);
	// 组织名称
	CC_SYNTHESIZE(string, org_name, OrgName);
	// 员工ID
	CC_SYNTHESIZE(string, staff_id, StaffId);
	// 员工名称
	CC_SYNTHESIZE(string, staff_name, StaffName);
	// 小区分片ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 报修师傅状态 9999 在线 8888 离线 t_dict 表
	CC_SYNTHESIZE(string, state, State);
	// 描述，一般为状态变更描述
	CC_SYNTHESIZE(string, remark, Remark);
	// 数据状态 1应该为无效
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	//创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
public:
	RepairWorkerAddDO() {
		type_user_id = "";
		org_name = "";
		b_id = "-1";
		repair_type = "";
		staff_id = "";
		staff_name = "";
		repair_type_name = "";
		community_id = "";
		state = "9999";
		status_cd = "0";
		remark = "";
	}
};

// 给RepairWorkerName_RepairTypeUserDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairWorkerAddDO> PtrRepairWorkerAddDO;
#endif//_REPAIRWORKERNAMEDO_H_