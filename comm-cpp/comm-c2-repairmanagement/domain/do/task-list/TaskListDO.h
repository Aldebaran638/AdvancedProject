#pragma once
#ifndef _TASKLISTDO_H_
#define _TASKLISTDO_H_
#include "../DoInclude.h"

/**
 * 工单池工单列表数据库实体类
 */
class TaskListDO
{
	//小区编号
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// 工单编码
	CC_SYNTHESIZE(string, repairId, RepairId);
	// 位置	
	CC_SYNTHESIZE(string, repairObjName, RepairObjName);
	// 报修类型(多表)
	CC_SYNTHESIZE(string, repairTypeName, RepairTypeName);
	// 维修类型（多表）
	CC_SYNTHESIZE(string, maintenanceTypeName, MaintenanceTypeName);
	// 报修人
	CC_SYNTHESIZE(string, repairName, RepairName);
	// 联系方式
	CC_SYNTHESIZE(string, tel, Tel);
	// 预约时间
	CC_SYNTHESIZE(string, appointmentTime, AppointmentTime);
	// 提交时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 状态（多表）
	CC_SYNTHESIZE(string, stateName, StateName);
	// 报修内容
	CC_SYNTHESIZE(string, context, Context);
	// 维修类型中文映射
	CC_SYNTHESIZE(string, maintenanceTypeTxt, MaintenanceTypeTxt);
	// 状态中文映射
	CC_SYNTHESIZE(string, stateTxt, StateTxt);
public:
	TaskListDO() 
	{
		communityId = "";
		repairId = "";
		repairObjName = "";
		repairTypeName = "";
		maintenanceTypeName = "";
		repairName = "";
		tel = "";
		appointmentTime = "";
		createTime = "";
		stateName = "";
		context = "";
	}
	
};

typedef std::shared_ptr<TaskListDO> PtrTaskListDO;
#endif // !_TASKLISTDO_H_