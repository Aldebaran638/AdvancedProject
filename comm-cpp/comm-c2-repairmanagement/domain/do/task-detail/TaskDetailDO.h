#ifndef _TASKDETAIL_DO_
#define _TASKDETAIL_DO_
#include "../DoInclude.h"

/**
 * 工单详情数据库实体类
 */
class TaskDetailGetDO
{
    // 工单编号
    CC_SYNTHESIZE(string, repairId, RepairId);
    // 工单类型
    CC_SYNTHESIZE(string, repairType, RepairType);
    // 工单类型文本
    CC_SYNTHESIZE(string, repairTypeTxt, RepairTypeTxt);
    // 报修人
    CC_SYNTHESIZE(string, repairName, RepairName);
    // 联系方式
    CC_SYNTHESIZE(string, tel, Tel);
    // 报修位置名称
    CC_SYNTHESIZE(string, repairObjName, RepairObjName);
    // 预约时间
    CC_SYNTHESIZE(string, appointmentTime, AppointmentTime);
    // 状态
    CC_SYNTHESIZE(string, state, State);
    // 状态文本
    CC_SYNTHESIZE(string, stateTxt, StateTxt);
    // 保修内容
    CC_SYNTHESIZE(string, context, Context);
    // 创建时间
    CC_SYNTHESIZE(string, createTime, CreateTime);

public:
    TaskDetailGetDO()
    {
        repairId = "";
        repairType = "";
        repairTypeTxt = ""; // 初始化 repairTypeTxt
        repairName = "";
        tel = "";
        repairObjName = "";
        appointmentTime = "";
        state = "";
        stateTxt = ""; // 初始化 stateTxt
        context = "";
        createTime = "";
    }
};

/**
 * 工单详情数据库实体类
 */
class TaskDetailDO
{
	// 工单编号（前端传入）
	CC_SYNTHESIZE(string, repairId, RepairId);
	// 报修师傅
	CC_SYNTHESIZE(string, staffName, StaffName);
	// 处理意见
	CC_SYNTHESIZE(string, context, Context);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime)
		// 报修派单ID
		CC_SYNTHESIZE(string, ruId, RuId);
	// 业务ID
	CC_SYNTHESIZE(string, bId, BId);
	// 报修类型
	CC_SYNTHESIZE(string, repairType, RepairType);
	// 小区编号
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// 报修师傅ID
	CC_SYNTHESIZE(string, staffId, StaffId);

	// 打印 工单详情 
	// 报修人
	CC_SYNTHESIZE(string, repairName, RepairName);
	// 联系电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 位置	
	CC_SYNTHESIZE(string, repairObjName, RepairObjName);
	// 报修内容
	CC_SYNTHESIZE(string, taskContext, TaskContext);
	// 报修类型(多表)
	CC_SYNTHESIZE(string, repairTypeName, RepairTypeName);
	// 维修类型（多表）
	CC_SYNTHESIZE(string, maintenanceTypeName, MaintenanceTypeName);

	// 打印 工单流转
	// 状态
	CC_SYNTHESIZE(string, state, State);
	// 处理时间
	CC_SYNTHESIZE(string, startTime, StartTime);
	// 耗时
	CC_SYNTHESIZE(string, cost, Cost);
	//意见
	CC_SYNTHESIZE(string, userContext, UserContext);
public:
	TaskDetailDO()
	{
		repairId = "";
		staffName = "";
		context = "";
		createTime = "";
		ruId = "";
		bId = "";
		repairType = "";
		communityId = "";
		staffId = "";
		repairName = "";
		tel = "";
		repairObjName = "";
		taskContext = "";
		repairTypeName = "";
		maintenanceTypeName = "";
		state = "";
		startTime = "";
		cost = "";
		userContext = "";
	}

};

typedef std::shared_ptr<TaskDetailDO> PtrTaskDetailDO;

// 给 TaskDetailGETDO 智能指针设定一个别名方便使用
typedef std::shared_ptr<TaskDetailGetDO> PtrTaskDetailGetDO;

#endif // !_TASKDETAIL_DO_
