#pragma once
#ifndef _REPAIRDONEDO_H_
#define _REPAIRDONEDO_H_
#include "../DoInclude.h"
/**
 * 示例数据库实体类
 * 前端可以操作的字段：maintenance-type、repair_name、tel、repair_type、state
 * 后端自动生成其他字段
 */
class RepairDoneDO
{
	// 工单编码 （C++数据类型，mysql中表名，大驼峰命名法）
	CC_SYNTHESIZE(string, repair_id, RepairId);
	//位置
	CC_SYNTHESIZE(string, repair_obj_name, RepairObjName);
	// 报修类型 
	CC_SYNTHESIZE(string, repair_type, RepairType);
	//维修类型
	CC_SYNTHESIZE(string, maintenance_type, MaintenanceType);
	// 报修人
	CC_SYNTHESIZE(string, repair_name, RepairName);
	//联系方式
	CC_SYNTHESIZE(string, tel, Tel);
	//预约时间
	CC_SYNTHESIZE(string, appointment_time, AppointmentTime);
	//报修状态
	CC_SYNTHESIZE(string, state, State);

	//报修状态-中文映射
	CC_SYNTHESIZE(string, state_detail, StateDetail);
	//位置-中文映射
	//CC_SYNTHESIZE(string, repair_obj_name_detail, RepairObjNameDetail);
	//维修类型-中文映射
	CC_SYNTHESIZE(string, maintenance_type_detail, MaintenanceTypeDetail);
	//报修类型-中文映射
	CC_SYNTHESIZE(string, repair_type_detail, RepairTypeDetail);

public:
	RepairDoneDO() {
		maintenance_type = "";
		repair_name = "";
		tel = "";
		repair_type = "";
		state = "";
	}
};
// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairDoneDO> PtrRepairDoneDO;
#endif // !_REPAIRDONEDO_H_