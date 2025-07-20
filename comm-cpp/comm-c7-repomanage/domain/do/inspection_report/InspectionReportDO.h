#pragma once
#ifndef _INSPECTIONREPORT_DO_
#define _INSPECTIONREPORT_DO_
#include "do/DoInclude.h"

/**
 * 巡检报表数据库实体类
 */
class InspectionReportDO
{
	// 编号
	CC_SYNTHESIZE_VIRTUAL_GET(string, id, Id);

	// 巡检点ID->表business_inspection_task_detail.inspection_id
	CC_SYNTHESIZE_VIRTUAL_GET(string, inspectionId,InspectionId);

	// 巡检点名称->表business_inspection_task_detail.inspection_name
	CC_SYNTHESIZE_VIRTUAL_GET(string, inspectionName, InspectionName);

	// 巡检点开始时间->表business_inspection_task_detail.point_start_time
	CC_SYNTHESIZE_VIRTUAL_GET(string, pointStartTime, PointStartTime);

	// 巡检点结束时间->表business_inspection_task_detail.point_end_time
	CC_SYNTHESIZE_VIRTUAL_GET(string, pointEndTime, PointEndTime);

	// 巡检点状态->表business_inspection_task_detail.state
	CC_SYNTHESIZE_VIRTUAL_GET(string, inspectionState, InspectionState);

	// 实际巡检人员id->表business_inspection_task_detail.act_user_id
	CC_SYNTHESIZE_VIRTUAL_GET(string, actUseId, ActUseId);

	// 实际巡检人员姓名->表business_inspection_task_detail.act_user_name
	CC_SYNTHESIZE_VIRTUAL_GET(string, actUseName,ActUseName);

	//巡检人签到状态->表business_inspection_task_detail.inspection_state
	CC_SYNTHESIZE_VIRTUAL_GET(string, actState, ActState);

public:
	InspectionReportDO() {
		id = "";
		inspectionId = "";
		inspectionName = "";
		pointStartTime = "";
		pointEndTime = "";
		inspectionState = "";
		actUseId = "";
		actUseName = "";
		actState = "";
	}
};

// 给InspectionReportDO智能指针设定一个别名方便使用
typedef std::shared_ptr<InspectionReportDO> PtrInspectionReportDO;
#endif // !_INSPECTIONREPORT_DO_
