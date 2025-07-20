#pragma once
#ifndef _REPAIRRETURNDO_H_
#define _REPAIRRETURNDO_H_
#include "../DoInclude.h"
/**
 * 示例数据库实体类
 * 前端可以操作的字段：setting_id、repair_type_name、repair_name、tel、return_visit_flag
 * 后端自动生成其他字段
 */
class RepairReturnDO
{
	// 工单编码  （C++数据类型，mysql中表名，大驼峰命名法）
	CC_SYNTHESIZE(string, repair_id, RepairId);
	//位置
	CC_SYNTHESIZE(string, repair_obj_name, RepairObjName);
	// 报修类型 
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// 报修人
	CC_SYNTHESIZE(string, repair_name, RepairName);
	//联系方式
	CC_SYNTHESIZE(string, tel, Tel);
	//预约时间
	CC_SYNTHESIZE(string, appointment_time, AppointmentTime);
	//回访状态
	CC_SYNTHESIZE(string, state, State);
	//满意度
	CC_SYNTHESIZE(string, visit_type, VisitType);
	//回访内容
	CC_SYNTHESIZE(string, context, Context);

	//回访id
	CC_SYNTHESIZE(string, visit_id, VisitId);
	//小区id
	CC_SYNTHESIZE(string, community_id, CommunityId);
	//回访人id
	CC_SYNTHESIZE(string, visit_person_id, VisitPersonId);
	//回访人
	CC_SYNTHESIZE(string, visit_person_name, VisitPersonName);
	//创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//数据状态
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	//报修类型-中文映射
	CC_SYNTHESIZE(string, repair_type_detail, RepairTypeDetail);
	//报修状态-中文映射
	CC_SYNTHESIZE(string, state_detail, StateDetail);
public:
	RepairReturnDO() {
		repair_id = "";
		repair_type = "";
		repair_name = "";
		tel = "";
		state = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairReturnDO> PtrRepairReturnDO;
#endif // !_REPAIRRETURNDO_H_
