#pragma once
#ifndef _INSPECTION_POINT_STATISTIC_DO_H_
#define _INSPECTION_POINT_STATISTIC_DO_H_
#include "../DoInclude.h"
//InspectionPointStatisticDO
/**
 * 巡检点统计列表数据库实体类
 */
class InspectionPointStatisticDO
{
	// 巡检点名称->inspection_name
	CC_SYNTHESIZE(string, inspectionPointName, InspectionPointName);
	//巡检位置->point_obj_name
	CC_SYNTHESIZE(string, pointObjName, PointObjName); 
	//员工->staff_name
	CC_SYNTHESIZE(string, staffName, StaffName);
	//已巡检个数
	CC_SYNTHESIZE(int, inspectEd, InspectEd);
	//未巡检个数
	CC_SYNTHESIZE(int, unInspection, UnInspection);
	//状态（可以理解为备注描述）
	CC_SYNTHESIZE(string, state, State);
	
public:
	InspectionPointStatisticDO() {
		inspectionPointName = "";
		pointObjName = "";
		staffName = "";
		state = "";
		inspectEd = 0;
		unInspection = 0;
	}
};

// 给InspectionPointStatisticDO智能指针设定一个别名方便使用
typedef std::shared_ptr<InspectionPointStatisticDO> PtrInspectionPointStatisticDO;
#endif // !_INSPECTION_POINT_STATISTIC_DO_H_
