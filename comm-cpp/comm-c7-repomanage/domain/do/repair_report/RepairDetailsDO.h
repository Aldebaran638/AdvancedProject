#pragma once
#ifndef _REPAIRDETAILS_DO_
#define _REPAIRDETAILS_DO_
#include "../DoInclude.h"

class RepairDetailsDO
{
	CC_SYNTHESIZE(string, communityId, CommunityId);					// 社区id
	CC_SYNTHESIZE(string, workOrderId, WorkOrderId);					// 工单号
	CC_SYNTHESIZE(string, repairType, RepairType);						// 报修类型
	CC_SYNTHESIZE(string, requesterName, RequesterName);				// 报修人
	CC_SYNTHESIZE(string, requestLocation, RequestLocation);			// 报修位置
	CC_SYNTHESIZE(string, requesterTelephone, RequesterTelephone);		// 报修电话
	CC_SYNTHESIZE(string, workOrderStatus, WorkOrderStatus);			// 工单状态
	CC_SYNTHESIZE(string, requestTime, RequestTime);					// 报修时间
	CC_SYNTHESIZE(string, previousProcessor, PreviousProcessor);		// 上一处理人
	CC_SYNTHESIZE(string, currentProcessor, CurrentProcessor);			// 当前处理人
	CC_SYNTHESIZE(string, dispatchingTime, DispatchingTime);			// 派单时间
	CC_SYNTHESIZE(string, handleTime, HandleTime);						// 处理时间
	CC_SYNTHESIZE(string, processorStatus, ProcessorStatus);			// 处理人状态
	CC_SYNTHESIZE(string, requestContent, RequestContent);				// 报修内容

public:
	RepairDetailsDO() {
		communityId = "";
		workOrderId = "";
		repairType = "";
		requesterName = "";
		requestLocation = "";
		requesterTelephone = "";
		workOrderStatus = "";
		requestTime = "";
		previousProcessor = "";
		currentProcessor = "";
		dispatchingTime = "";
		handleTime = "";
		processorStatus = "";
		requestContent = "";
	}
	RepairDetailsDO(string communityId, string workOrderId, string repairType, string requesterName,
		string requestLocation, string requesterTelephone, string workOrderStatus, string requestTime,
		string previousProcessor, string currentProcessor, string dispatchingTime, string handleTime, string processorStatus, string requestContent)
	{
		this->communityId = communityId;
		this->workOrderId = workOrderId;
		this->repairType = repairType;
		this->requesterName = requesterName;
		this->requestLocation = requestLocation;
		this->requesterTelephone = requesterTelephone;
		this->workOrderStatus = workOrderStatus;
		this->requestTime = requestTime;
		this->previousProcessor = previousProcessor;
		this->currentProcessor = currentProcessor;
		this->dispatchingTime = dispatchingTime;
		this->handleTime = handleTime;
		this->processorStatus = processorStatus;
		this->requestContent = requestContent;
	}
};

// 给RepairDetailsDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairDetailsDO> PtrRepairDetailsDO;
#endif // !_REPAIRDETAILS_DO_
